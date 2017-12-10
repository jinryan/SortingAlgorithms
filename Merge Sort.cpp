//============================================================================
// Name        : Merge Sort.cpp
// Author      : Ryan Jin
// Version     : 1.0
// Copyright   : All rights reserved
// Description : Merge Sort in C++
/* Merge sort uses a divide-and-conquer method. I.e. dividing an array into sub-arrays and solving each of them
 * 1. Divide
 * 		Get the middle index of the array by performing (startIndex + endIndex) / 2
 * 		Divide the original array into subarray array(start...middle) and array(middle+1...end)
 * 2. Recursively divide until each array only has one item
 * 3. Combine those individual array by putting two together and evaluating which one is greater
 * 		i. First create a duplicate of the two subarrays, let's call them sub1 and sub2
 * 		ii. Have an index for each of them, let's call them j for sub1 and i for sub2
 * 		iii. Loop through the original array with an index, let's say k
 * 		iv. Look at the item at j for sub1 and item at i for sub2. Whatever is smaller goes to k at original array
 * 		v. If the item at j was chosen, then increment j by one so it goes to the next element. Vice versa for i
 * 		vi. If you loop out of any of the subarray or the main array, then you still need to check to make sure there's no leftover in the other array
 * 		vii. As a result, you go to each array and check if there's anything that remains, if so, append those items at the end. They are bigger than the rest anyway
 * 4. I think you are done
 */
//============================================================================

#include <iostream>
#include <vector>
#include <string>
using namespace std;

void printVector(string message, vector<int> *mVector);
void divideAndConquer(vector<int> *vector, int startIndex, int endIndex);
void combine(vector<int> *mVector, int vector1StartIndex, int vector2StartIndex, int endIndex);

int main() {
	int mArray[8] = {3, 5, 123, 4, 3, 67, 15, -23}; // Create an array
	vector<int> mVector(mArray, mArray+8); // Convert array to vector so I can pass them by reference
	printVector("Before sort:", &mVector);
	divideAndConquer(&mVector, 0, 7);
	printVector("After sort:", &mVector);
	return 0;
}

void divideAndConquer(vector<int> *vector, int startIndex, int endIndex) {
	// NOTE THAT WE AREN'T PHYSICALLY MAKING NEW ARRAYS, WE ARE JUST CHANGING THE INDEXES (START AND FINISH) TO IDENTIFY THE SUB-ARRAYS
	if (endIndex - startIndex > 0) { // If there's at least one item (if a sub-array only has one item, the start index and end index are the same)
		// Recursively divide
		int middle = (endIndex + startIndex) / 2;
		divideAndConquer(vector, startIndex, middle);
		divideAndConquer(vector, middle + 1, endIndex);

		// Combine
		combine(vector, startIndex, middle + 1, endIndex);
	}
	return;
}

void combine(vector<int> *mVector, int vector1StartIndex, int vector2StartIndex, int endIndex) {

	// Step 1: Convert the vector1StartIndex, vector2StartIndex, and endIndex into constant iterators so we can create sub-vectors
	vector<int>::const_iterator vector1Start = mVector->begin() + vector1StartIndex;
	vector<int>::const_iterator vector2Start = mVector->begin() + vector2StartIndex;
	vector<int>::const_iterator end = mVector->begin() + endIndex;

	// Step 2: Create duplicate sub-vectors
	// The reason we create duplicate is because we are going to change the values in the main array so we need somewhere to store the original values safe
	vector<int> tempVect1(vector1Start, vector2Start);
	vector<int> tempVect2(vector2Start, end + 1);

	// Step 3: Have iterator for each vector
	vector<int>::iterator v1Iterator = tempVect1.begin();
	vector<int>::iterator v2Iterator = tempVect2.begin();

	// Step 4: Loop through original vector
	int i = vector1StartIndex; // i is an index for looping through the original vector
	for (; i < endIndex && v1Iterator != tempVect1.end() && v2Iterator != tempVect2.end(); i++) {
		// If the first array's item at v1Iterator is smaller than the second's item at v2Iterator, put the value at v1Iterator into the main array and make v1Iterator move to the next item in the first array and do another comparison
		if (*v1Iterator < *v2Iterator) {
			mVector->at(i) = *v1Iterator;
			v1Iterator++;
		} else { // Vice versa for v2Iterator
			mVector->at(i) = *v2Iterator;
			v2Iterator++;
		}
	}

	// Add whatever's left in the original vector
	if (v1Iterator != tempVect1.end()) {
		for (; v1Iterator != tempVect1.end(); v1Iterator++) {
			mVector->at(i) = *v1Iterator;
			i++;
		}
	} else if (v2Iterator != tempVect2.end()) {
		v2Iterator++;
		for (; v2Iterator != tempVect2.end(); v2Iterator++) {
			mVector->at(i) = *v2Iterator;
			i++;
		}
	}
	return;
}


// =========== Other stuff ==========
void printVector(string message, vector<int> *vector1) {
	cout << message << " ";
	vector <int>::iterator c1_iterator = vector1->begin();
	for (; c1_iterator != vector1->end(); c1_iterator++) {
		cout << *c1_iterator << " ";
	}
	cout << endl;
	return;
}
