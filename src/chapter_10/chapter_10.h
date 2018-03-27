/*
 * chapter_10.h
 *
 *  Created on: Mar 27, 2018
 *      Author: piotrra
 */

#ifndef SRC_CHAPTER_10_CHAPTER_10_H_
#define SRC_CHAPTER_10_CHAPTER_10_H_

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

namespace chapter_10{
	namespace generic_algorithms {
	//utils for overview
	void countIntegers(const std::vector<int>& ivec);
	void countStrings(const std::list<std::string>& slist);

	void overview();
	void customOperations();
	void iterators();
	void genericALgorithms();
	void containerSpecAlgorithms();

	};

};

#endif /* SRC_CHAPTER_10_CHAPTER_10_H_ */
