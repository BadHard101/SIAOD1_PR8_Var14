#include <iostream>
#include <ctime>
using namespace std;

void simple_insert_sort(int* arr, int n) {
	long long int counter = 0;
	srand(time(0));
	for (int i = 1; i < n; i++)
		for (int j = i; j > 0 && arr[j - 1] > arr[j]; j--) { // пока j>0 и элемент j-1 > j, x-массив int
			swap(arr[j - 1], arr[j]);        // меняем местами элементы j и j-1
			counter++;
		}
	cout << "difficulty = " << counter << endl;
}

void arr_print(int* arr, int n) {
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
}

void merge_arr_print(int* arr, int n) {
	for (int i = 1; i < n+1; i++)
		cout << arr[i] << " ";
}

long long int merge_permutation = 0;
long long int merge_comparison = 0;

void Merge(int* A, int first, int last)
{
	int middle, start, final, j;
	int* mas = new int[1000000];
	middle = (first + last) / 2; //вычисление среднего элемента
	start = first; //начало левой части
	final = middle + 1; //начало правой части
	for (j = first; j <= last; j++) //выполнять от начала до конца
		if ((start <= middle) && ((final > last) || (A[start] < A[final])))
		{
			merge_comparison += 5;
			merge_permutation++;
			mas[j] = A[start];
			start++;
		}
		else
		{
			merge_comparison += 5;
			merge_permutation++;
			mas[j] = A[final];
			final++;
		}
	//возвращение результата в список
	for (j = first; j <= last; j++) {
		merge_permutation++;
		A[j] = mas[j];
	}
	delete[]mas;
};
//рекурсивная процедура сортировки
void MergeSort(int* A, int first, int last)
{
	{
		if (first < last)
		{
			merge_comparison += 1;
			MergeSort(A, first, (first + last) / 2); //сортировка левой части
			MergeSort(A, (first + last) / 2 + 1, last); //сортировка правой части
			Merge(A, first, last); //слияние двух частей
		}
	}
};

void shellSort(int* arr, int n)
{
	long int counter = 0;
	int j;
	int step = n / 2;
	while (step > 0)
	{
		for (int i = 0; i < (n - step); i++)
		{
			j = i;
			while ((j >= 0) && (arr[j] > arr[j + step]))
			{
				int tmp = arr[j];
				arr[j] = arr[j + step];
				arr[j + step] = tmp;
				j -= step;
				counter++;
			}
		}
		step = step / 2;
	}
	cout << "difficulty = " << counter << endl;
};



void gon(int *ptr, int n) {

	int *arr = new int[n];

	unsigned int start_time;
	unsigned int end_time;

	cout << "Array with " << n << " elements:\n\n";



	cout << "Simple insert sort: " << endl;

	for (int i = 0; i < n; i++)
		arr[i] = ptr[i];

	start_time = clock();
	simple_insert_sort(arr, n);
	end_time = clock();

	cout << "time: "
		<< (end_time - start_time) / 1000.0
		<< " sec\n\n";


	
	cout << "Shell sort: " << endl;

	for (int i = 0; i < n; i++)
		arr[i] = ptr[i];

	start_time = clock();
	shellSort(arr, n);
	end_time = clock();
	cout << "time: "
		<< (end_time - start_time) / 1000.0
		<< " sec\n\n";


	cout << "Shell sort (for sorted array): " << endl;

	start_time = clock();
	shellSort(arr, n);
	end_time = clock();
	cout << "time: "
		<< (end_time - start_time) / 1000.0
		<< " sec\n\n";



	cout << "Shell sort (for sorted array in reverse order): " << endl;

	int j = n-1;
	for (int i = 0; i < n; i++) {
		arr[i] = j;
		j--;
	}

	start_time = clock();
	shellSort(arr, n);
	end_time = clock();
	cout << "time: "
		<< (end_time - start_time) / 1000.0
		<< " sec\n\n";



	cout << "Merge sort: " << endl;

	for (int i = 0; i < n; i++)
		arr[i] = ptr[i];

	start_time = clock();
	MergeSort(arr, 0, n);
	end_time = clock();

	cout << "time: "
		<< (end_time - start_time) / 1000.0
		<< " sec" << endl;
	cout << "C: " << merge_permutation
		<< " M: " << merge_comparison
		<< endl;
	cout << endl;



	cout << "Merge sort (for sorted array): " << endl;

	merge_permutation = 0;
	merge_comparison = 0;

	start_time = clock();
	MergeSort(arr, 0, n);
	end_time = clock();

	cout << "time: "
		<< (end_time - start_time) / 1000.0
		<< " sec" << endl;
	cout << "C: " << merge_permutation
		<< " M: " << merge_comparison
		<< endl;
	cout << endl;



	cout << "Merge sort (for sorted array in reverse order): " << endl;

	j = n - 1;
	for (int i = 0; i < n; i++) {
		arr[i] = j;
		j--;
	}
	
	merge_permutation = 0;
	merge_comparison = 0;

	start_time = clock();
	MergeSort(arr, 0, n);
	end_time = clock();

	cout << "time: "
		<< (end_time - start_time) / 1000.0
		<< " sec" << endl;
	cout << "C: " << merge_permutation
		<< " M: " << merge_comparison
		<< endl;
	cout << endl;
}

int main()
{
	const int n1 = 10000;
	const int n2 = 50000;
	const int n3 = 100000;

	int *ptr1 = new int[n1];
	int *ptr2 = new int[n2];
	int *ptr3 = new int[n3];

	//диапазон генерации случайных чисел [a,b]
	int a = -999;
	int b = 999;

	srand(time(NULL));
	//заполнение массивов случайными числами

	for (int i = 0; i < n1; i++)
		ptr1[i] = rand() % (b - a + 1) + a;

	for (int i = 0; i < n2; i++)
		ptr2[i] = rand() % (b - a + 1) + a;

	for (int i = 0; i < n3; i++)
		ptr3[i] = rand() % (b - a + 1) + a;

	gon(ptr1, n1);
	cout << endl << endl;
	gon(ptr2, n2);
	cout << endl << endl;
	gon(ptr3, n3);
	system("pause");
}