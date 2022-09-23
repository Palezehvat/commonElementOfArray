#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>

int scanOne();

bool testTypicalValue() {
	int arrayOut1[5] = { 1, 2, 2, 3, 4 };
	int arrayOut2[5] = { -200, -20, -30, -30, 100 };
	return repeatabilityElements(arrayOut1, 5) == 2 && repeatabilityElements(arrayOut2, 5) == -30;
}

bool testAnotherValue() {
	int arrayOut[1] = { 1 };
	return repeatabilityElements(arrayOut, 1) == 1;
}

int repeatabilityElements(int* arrayOut, int size) {
	int maxElement = INT_MIN;
	int minElement = INT_MAX;

	if (arrayOut != NULL) {
		for (int i = 0; i < size; ++i) {
			if (arrayOut[i] < minElement) {
				minElement = arrayOut[i];
			}
			if (arrayOut[i] > maxElement) {
				maxElement = arrayOut[i];
			}
		}
	}

	maxElement = abs(maxElement);
	minElement = abs(minElement);

	int* arrayElements = (int*)calloc(maxElement + minElement + 1, sizeof(int));
	int countElements = 0;
	int copyElement = 0;
	
	if (arrayOut != NULL && arrayElements != NULL) {
		for (int i = 0; i < size; ++i) {
			++arrayElements[arrayOut[i] + minElement];
			if (arrayElements[arrayOut[i] + minElement] > countElements) {
				countElements = arrayElements[arrayOut[i] + minElement];
				copyElement = arrayOut[i];
			}
		}
	}

	free(arrayElements);
	
	return copyElement;
}

int main() {
	setlocale(LC_ALL, "RUS");
	if (!testAnotherValue() || !testTypicalValue()) {
		printf("%s", "Ошибки в тестах... \n");
	} else {
		printf("%s", "Ошибок в тестах не обнаруженно \n");
	}

	printf("%s", "Введите размер массива: \n");

	const int size = scanOne();

	printf("%s", "Введите элементы массива: \n");

	int* arrayOut = (int*)calloc(size, sizeof(int));
	if (arrayOut != NULL) {
		for (int i = 0; i < size; ++i) {
			arrayOut[i] = scanOne();
		}
	}

	int frequentElement = repeatabilityElements(arrayOut, size);

	printf("%s %d \n","Самый частый элемент масива: ", frequentElement);
	free(arrayOut);
}

int scanOne() {
	int number = 0;
	int checkScanf = scanf("%d", &number);

	while (checkScanf != 1) {
		while (getchar() != '\n') {
		}

		printf("%s", "Ошибка... Проверьте правильность ввода \n");
		checkScanf = scanf("%d", &number);
	}

	return number;
}