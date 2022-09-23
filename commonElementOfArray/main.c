#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int scanOne();

int main() {
	setlocale("LC_ALL", "RUS");

	printf("%s", "Введите размер массива: \n");

	const int size = ScanOne();

	printf("%s", "Введите элементы массива: \n");
	int* arrayOut = (int*)calloc(size, sizeof(int));
	for (int i = 0; i < size; ++i) {
		arrayOut[i] = scanOne();
	}
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