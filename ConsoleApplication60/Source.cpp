#include <algorithm>
#include <cstdlib>
#include <ctime> 
#include <iostream>
using namespace std;

void fulfill_array(int* array, int n) {
	for (int i = 0; i < n; i++) {
		array[i] = rand() % 200 - 100;
	}
}

void bubble_sort(int* array, int n) {
	int i, j;
	for (i = 0; i < n - 1; i++)
		for (j = 0; j < n - i - 1; j++)
			if (array[j] > array[j + 1])
				swap(array[j], array[j + 1]);
}
void cocktail_sort(int* array, int n) {
	int left, right, i;
	left = 0;
	right = n - 1;
	while (left <= right) {
		for (i = right; i >= left; i--) {
			if (array[i - 1] > array[i]) {
				swap(array[i - 1], array[i]);
			}
		}
		left++;
		for (i = left; i <= right; i++) {
			if (array[i - 1] > array[i]) {
				swap(array[i - 1], array[i]);
			}
		}
		right--;
	}
}
void Merge(int* array, int first, int last, int n)
{
	int middle, start, final, j;
	middle = (first + last) / 2;
	start = first;
	final = middle + 1;
	int* mas = new int[n];
	for (j = first; j < last; j++) {
		if ((start <= middle) && ((final > last) || (array[start] < array[final]))) {
			mas[j - first] = array[start];
			start++;
		}
		else {
			mas[j - first] = array[final];
			final++;
		}
	}
	for (j = first; j < last; j++)
		array[j] = mas[j];
	delete[]mas;
}

void merge_sort(int* array, int first, int last, int n) {
	if (first < last)
	{
		merge_sort(array, first, (first + last) / 2, n); //сортировка левой части
		merge_sort(array, (first + last) / 2 + 1, last, n); //сортировка правой части
		Merge(array, first, last, n); //слияние двух частей
	}
}
void print_array(int array[], int n) {
	cout << "Массив: ";
	for (int i = 0; i < n; i++)
		cout << array[i] << " ";
	cout << endl;
}
int main()
{
	setlocale(LC_ALL, "Rus");
	cout << "Лабораторная работа №8 'Эффективные алгоритмы сортировки.'. Галиханова Эмилия ИКБО-09-21" << endl;
	int menu = -1;
	int array_1[100], array_2[1000], array_3[10000], array_test[15];
	srand(time(NULL));
	while (menu != 0) {
		//fulfill_array(array_1, sizeof(array_1) / 4);
		//fulfill_array(array_2, sizeof(array_2) / 4);
		//fulfill_array(array_3, sizeof(array_3) / 4);
		fulfill_array(array_test, sizeof(array_test) / 4);
		print_array(array_test, sizeof(array_test) / 4);
		cout << "Menu:" << endl;
		cout << "1. bubble sort" << endl;
		cout << "2. cocktail sort" << endl;
		cout << "3. merge sort" << endl;
		cin >> menu;
		switch (menu)
		{
		case 1:
			bubble_sort(array_test, sizeof(array_test) / 4);
			print_array(array_test, sizeof(array_test) / 4);
			/*bubble_sort(array_1, sizeof(array_1) / 4);
			bubble_sort(array_2, sizeof(array_2) / 4);
			bubble_sort(array_3, sizeof(array_3) / 4);*/
			break;
		case 2:
			cocktail_sort(array_test, sizeof(array_test) / 4);
			print_array(array_test, sizeof(array_test) / 4);
			/*cocktail_sort(array_1, sizeof(array_1) / 4);
			cocktail_sort(array_2, sizeof(array_2) / 4);
			cocktail_sort(array_3, sizeof(array_3) / 4);*/
			break;
		case 3:
			merge_sort(array_test, 1, sizeof(array_test) / 4, sizeof(array_test) / 4);
			print_array(array_test, sizeof(array_test) / 4);
			/*merge_sort(array_1, 0, sizeof(array_1) / 4, sizeof(array_1) / 4);
			merge_sort(array_2, 0, sizeof(array_2) / 4, sizeof(array_2) / 4);
			merge_sort(ar
ray_3, 0, sizeof(array_3) / 4, sizeof(array_3) / 4);*/
			break;

		}
	}
}