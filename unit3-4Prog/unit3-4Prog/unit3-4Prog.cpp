/**********************************************************************
* unit3-4Prog.cpp - This program will store in miniVector v a list of 
* 15 random integers from 0 to 99, then it will output the vector, 
* sort the vector, then output it again sorted. 
**********************************************************************/
#include <iostream>
#include "d_vector.h"
#include "d_random.h"

// function prototype
template <typename T>
void writeMiniVector(const miniVector<T>& v);
// function prototype
template <typename T> 
void sortMiniVector(miniVector<T>& v);

int main() {
	// Declare: miniVector<int> v
	miniVector<int> v;
	// Declare: randomNumber rnd
	randomNumber rnd;
	// call v.push_back(rnd.random(100)); to push 15 entries from 0-99 onto the vector
	for (int i = 0; i < 15; i++) {
		v.push_back(rnd.random(100));
	}
	// call writeMiniVector to output vector
	std::cout << "Original: ";
	writeMiniVector(v);
	// call sortMiniVector to sort the vector
	sortMiniVector(v);
	// call writeMiniVector to output the sorted vector
	std::cout << "Sorted: ";
	writeMiniVector(v);
	std::cout << std::endl;

	system("PAUSE");
	return 0;
} // end main

// iterate through the vector v and output each element to the screen.
template <typename T>
void writeMiniVector(const miniVector<T>& v) {
	// variable declarations
	int i, n = v.size();
	// iterate through the vector v
	for ( i = 0; i < n; i++) {
		// output each element to the screen and space in between elements
		std::cout << v[i] << " ";
	}
	std::cout << std::endl;
} // end writeMiniVector

// sort the elements of vector v
template <typename T>
void sortMiniVector(miniVector<T>& v) {
	// variable declarations
	int i, j, n = v.size();
	// temporary variable
	T target;
	// i starts at 1, i is less than v.size and increases by one
	for (i = 1; i < n; i++) {
		j = i;
		target = v[j];
		// sorting the elements of vector v locate insertion point by scanning  
		// as long as target > v[j-1]
		while (j > 0 && target > v[j-1]) {
			// shift elements up list to make room for insertion and when location is found inserts target
			v[j] = v[j - 1];
			v[j - 1] = target;
			j--;
		}
	}
} // end sortMiniVector


