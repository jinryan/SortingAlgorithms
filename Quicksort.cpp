//============================================================================
// Name        : Quicksort.cpp
// Author      : Ryan Jin
// Version     : 1.0
// Copyright   : All Rights Reserved
// Description : Quicksort in C++
/* Quicksort is, most of the time, the most efficient sorting algorithm
 * It uses divide-and-conquer and sorts recursively like merge sort
 * 1. Choosing an element called the pivot
 * 2. Rearrange the array by making everything smaller than pivot on its left and bigger numbers on its right
 * 3. Now we are sure that pivot is at its right spot, we will then look at the two chunks (subarray) we have separated
 * 4. Repeat 1 - 3 for those chunks
 * 5. Congrats you are done!!
 *
 * So how do we make everything smaller than pivot on its left and bigger ones on its right
 * 1. We choose the last element in an array as the pivot
 * 2. We create a variable named wall (it is an index), essentially, stuff before wall is smaller than pivot, and stuff after wall is bigger
 * 3. We create an another index to loop through the entire array, let's call it j
 * 4. If array at j is smaller than or equal to the pivot, let's put it before the wall.
 * 		How do we put it before the wall? We replace it with the element at wall, and increment the index wall by 1
 * 5. If an array at j is bigger than the pivot, ignore it, its after the wall anyways
 * 6. After j reaches the maximum index, meaning there's no more item to look at, let's put pivot into its right place
 * 		Where do we put it? Essentially everything before the wall is smaller right? So let's replace it with wall. Because the element at wall is bigger than the pivot anyway
 */
//============================================================================

#include <iostream>
#include <vector>
#include <string>
using namespace std;

void quickSort(vector<int> *vector, int startIndex, int endIndex);
int partition(vector<int> *vector, int startIndex, int endIndex);
void printVector(string message, vector<int> *vector);
void swap(vector<int> *vector, int index1, int index2);

int main() {
	int array[8] = {3, 5, 123, 4, 3, 67, 15, -23}; // Create an array
	vector<int> mVector(array, array+8); // Create a vector that has the elements of the above array

	printVector("Before sort:", &mVector);
	quickSort(&mVector, 0, 7);
	printVector("After sort:", &mVector);
	return 0;
}

void quickSort(vector<int> *vector, int startIndex, int endIndex) {
	// First, make sure there's actually stuff to sort
	if (endIndex > startIndex) {
		int pivot = partition(vector, startIndex, endIndex); // Return the pivot, i.e. the item that is sure to be at its right place
		// Recursive sorting. Split into two chunks (those smaller than the pivot, and those larger than the pivot)
		quickSort(vector, startIndex, pivot - 1);
		quickSort(vector, pivot + 1, endIndex);
	}
	return;
}

int partition(vector<int> *vector, int startIndex, int endIndex) {
	int pivot = vector->at(endIndex); // Use the last as pivot
	int wall = startIndex; // Anything to the left of wall are the numbers smaller than the pivot. Anything after wall and before j are the numbers bigger than the pivot. Values after j are the unsorted numbers
	for (int j = startIndex; j < endIndex; j++) {
		if (vector->at(j) < pivot) {
			// If there's a value smaller than the pivot, put it before the wall, which is essentially, replace it with the value at wall and move the index wall one up
			swap(vector, j, wall);
			wall++;
		}
	}
	swap(vector, endIndex, wall);
	return wall;
}


// =========== Other not so important functions ============

void printVector(string message, vector<int> *vector1) {
	cout << message << " ";
	vector <int>::iterator c1_iterator = vector1->begin();
	for (; c1_iterator != vector1->end(); c1_iterator++) {
		cout << *c1_iterator << " ";
	}
	cout << endl;
}

void swap(vector<int> *vector, int index1, int index2) {
	int temporaryIndex1Value = vector->at(index1);
	vector->at(index1) = vector->at(index2);
	vector->at(index2) = temporaryIndex1Value;
	return;
}
