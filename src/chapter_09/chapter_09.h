/*
 * chapter_09.h
 *
 *  Created on: Mar 27, 2018
 *      Author: piotrra
 */

#ifndef SRC_CHAPTER_09_CHAPTER_09_H_
#define SRC_CHAPTER_09_CHAPTER_09_H_

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

namespace chapter_9{
	namespace seq_containers {
		//utils for overview();
		typedef std::vector<int>::iterator intVecIterator_t;
		bool findNumberInVector1 (std::vector<int>& vec, const int& number);
 		intVecIterator_t findNumberInVector2 (std::vector<int>& vec, const int& number);
		void overview();

		//utils for operation
		void insertString(std::forward_list<std::string>& flist, const std::string& key, const std::string& item);
		void operation();

		//utils for stringOperation();
		void stringReplace1(std::string& s, const std::string& oldVal, const std::string& newVal);
		void stringReplace2(std::string& s, const std::string& oldVal, const std::string& newVal);
		void stringAppend1(std::string& name, const std::string& prefix, const std::string& suffix);
		void stringFindNumber1(const std::string& s);
		void stringFindCharacter1(const std::string& s);
		void stringFindNumber2(const std::string& s);
		void stringFindCharacter2(const std::string& s);

		class date {
		private:
			unsigned day;
			unsigned month;
			unsigned year;
		public:
			date():day(0), month(0), year(0){}
			date(const std::string& string);
			void print();
		};
		void stringOperation();
	};
};



#endif /* SRC_CHAPTER_09_CHAPTER_09_H_ */
