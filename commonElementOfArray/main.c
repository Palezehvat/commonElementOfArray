#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int scanOne();

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

	int* arrayElements = (int*)calloc(maxElement - minElement, sizeof(int));
	int countElements = 0;
	int copyElement = 0;
	if (arrayOut != NULL && arrayElements != NULL) {
		for (int i = 0; i < size; ++i) {

		}
	}
	return copyElement;
}

int main() {
	setlocale("LC_ALL", "RUS");

	printf("%s", "Введите размер массива: \n");

	const int size = ScanOne();

	printf("%s", "Введите элементы массива: \n");
	int* arrayOut = (int*)calloc(size, sizeof(int));
	if (arrayOut != NULL) {
		for (int i = 0; i < size; ++i) {
			arrayOut[i] = scanOne();
		}
	}

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