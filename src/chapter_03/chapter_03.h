/*
 * chapter_03.h
 *
 *  Created on: Mar 27, 2018
 *      Author: piotrra
 */

#ifndef SRC_CHAPTER_03_CHAPTER_03_H_
#define SRC_CHAPTER_03_CHAPTER_03_H_

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <deque>
#include <array>
#include <forward_list>
#include <stdexcept>
#include <initializer_list>
#include <cassert>
#include <sstream>
#include <fstream>
#include <algorithm>

namespace chapter_3 {
	namespace arrays {
		void allZeros();
		void equalityTest();
		void copyArrtoVec();
		void copyVecToArr();
	};

	namespace iterators {
		void printVectors();
		void doubleVector();
		void sumUp();
		void clusterGrades();
	};

	namespace arrays2d {
		void printArray();
		void printArrayWithAuto();
		void printArrayWithAliases();
	};

	namespace strings {
		void readWords();
		void readLines();
		void areEqual();
		void areLength();
		void concatenate();
		void capitalize();
		void removePuncation();
	};
	namespace vectors {
		void readIntegers();
		void readStrings();
		void toUpper();
		void sumUp();
	};
};




#endif /* SRC_CHAPTER_03_CHAPTER_03_H_ */
