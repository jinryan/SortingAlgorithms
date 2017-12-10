//============================================================================
// Name        : Selection Sort vs. Insertion Sort.cpp
// Author      : Ryan Jin
// Version     : 1.0
// Copyright   : All Rights Reserved
// Description : Selection Sort and Insertion Sort Code
//============================================================================

#include <iostream>
#include <vector>

using namespace std;

void selectionSort(int array[], int size);
void insertionSort(int array[], int size);
void outputArray(int array[], int size);

int main() {
	int array[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	// selectionSort(array, 10);
	insertionSort(array, 10);
	return 0;
}

void selectionSort(int array[], int size) {
	/***** ALGORITHM OF SELECTION SORT *******
	1. Find smallest
	2. Swap with first
	3. Find second smallest
	4. Swap with second
	5. Repeat until entire array is sorted
	*****************************************/
	int *start = &array[0]; // First item in array
	for (; start != &array[size]; start++) {
		int *checker = start + 1; // Start checking from the second item
		for (; checker != &array[size]; checker++) {
			// Loop checker through the entire array excluding the items in front of it
			if (*checker < *start) { // If checker is smaller than the item it is comparing with, swap
				int exStart = *start;
				*start = *checker;
				*checker = exStart;
			}
		}
	}
	outputArray(array, size);
	return;
}

void insertionSort(int array[], int size) {
	/***** ALGORITHM OF INSERTION SORT *******
		1. Start with the second element
		2. Compare the element with its left
		3. If smaller, swap
		4. If reach the end, move on to the next element
		5. Repeat
		*****************************************/
	int *start = &array[0];
	for (; start != &array[size]; start++) {
		int *checker = (start + 1);
		while (checker > &array[0] && *checker < *(checker-1)) {
			// cout << "Checker is " << *checker << " while checker - 1 is " << *(checker-1) << endl;
			int ex = *(checker-1);
			*(checker-1) = *checker;
			*checker = ex;
			// cout << "After changing, checker is " << *checker << " while checker - 1 is " << *(checker-1) << endl;
			checker--;
		}
	}
	outputArray(array, size);
	return;
}

// Not so important stuff

void outputArray(int array[], int size) {
	int *start = &array[0];
	for (; start != &array[size]; start++) {
		cout << *start << " ";
	}
	cout << endl;
	return;
}
