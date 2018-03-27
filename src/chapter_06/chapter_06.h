/*
 * chapter_06.h
 *
 *  Created on: Mar 27, 2018
 *      Author: piotrra
 */

#ifndef SRC_CHAPTER_06_CHAPTER_06_H_
#define SRC_CHAPTER_06_CHAPTER_06_H_

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

namespace chapter_6 {
	namespace functions {
	//utility for function matching()
	void f();
	void f(int);
	void f(int, int);
	void f(double, double = 3.14);
	void matching();

	//utility for passing_args()
	int factorial(int);
	void swap(int*, int*);
	void reset(int&);
	bool isCapital(const std::string&);
	void lowerCase(std::string&);
	int compare(const int, const int*);
	void swapPointers(int*&, int*&);
	//int sum(std::initializer_list<int>);
	void passing_args();


	//utility for pointers()
	int add(const int& v1, const int& v2);
	int subtruct(const int& v1, const int& v2);
	int multiply(const int& v1, const int& v2);
	int divide(const int& v1, const int& v2);
	//function that return function pointer
	auto getFunc(const char& c) -> int(*)(const int&, const int&);
	void pointers();

	//utility for passing_args()
	bool str_subrange(const std::string& str1, const std::string& str2);
	void printVecRecursive(std::vector<std::string> vec);
	using arr = int[10];
	int (*multiply1(int (*arr)[10], int val))[10] ;
	//typedef int arr[10];
	arr* multiply2(int (*arr)[10], int val);
	auto multiply3(int (*arr)[10], int val) -> int(*)[10] ;
	void return_val();


	//utility for special_features()
	std::string& make_plural(std::string& str, std::string postfix = "s");
	inline bool isShorter(const std::string& str1, const std::string& str2);
	void special_features();

	};
};



#endif /* SRC_CHAPTER_06_CHAPTER_06_H_ */
