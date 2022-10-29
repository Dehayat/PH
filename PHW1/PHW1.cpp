// PHW1.cpp : Defines the entry point for the application.
//

#include <iostream>
#include <chrono>
#include <iomanip>

using namespace std;

const int N = 50;

int arr_g[N];

void FillArray(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		arr[i] = rand();
	}
}

void BubbleSort(int* arr, int size) {
	bool swapped = false;
	do {
		swapped = false;
		for (int i = 0; i < size - 1; i++) {
			if (arr[i] > arr[i + 1]) {
				int temp = arr[i + 1];
				arr[i + 1] = arr[i];
				arr[i] = temp;
				swapped = true;
			}
		}
	} while (swapped);
}

void SelectionSort(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		int minPos = i;
		//int minPos = 0; // Bug
		for (int j = i + 1; j < size; j++) {
			if (arr[j] < arr[minPos]) {
				minPos = j;
			}
		}
		int temp = arr[i];
		arr[i] = arr[minPos];
		arr[minPos] = temp;
	}
}

void InsertionSort(int* arr, int size) {
	for (int i = 1; i < size; i++) {
		//for (int j = i - 1; j >= 0; j++) { // Bug
		for (int j = i - 1; j >= 0; j--) {
			/*if (arr[i] < arr[j]) {
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}*/ //Bug

			if (arr[j + 1] < arr[j]) {
				int temp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

void PrintArray(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void Sieve(int* arr, int size) {
	arr[0] = 1;
	arr[1] = 1;
	for (int i = 2; i < size; i++) {
		for (int j = i * 2; j < size; j += i) {
			arr[j] = 1;
		}
	}
}

void PrintPrimes(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		if (arr[i] == 0) {
			cout << i << ",";
		}
	}
	cout << endl;
}


int main()
{
	srand(time(0));

	chrono::high_resolution_clock clock;

	//FillArray(arr_g, N);

	//BubbleSort(arr_g, N);
	//SelectionSort(arr_g, N);
	//InsertionSort(arr_g, N);

	//PrintArray(arr_g, N);

	auto t1 = clock.now();
	Sieve(arr_g, N);
	auto t2 = clock.now();

	PrintPrimes(arr_g, N);

	chrono::duration<double> duration = t2 - t1;

	std::cout << std::fixed << std::setprecision(10);
	cout << duration.count() << endl;



	return 0;
}
