/*
 * chapter_02.h
 *
 *  Created on: Mar 27, 2018
 *      Author: piotrra
 */

#ifndef SRC_CHAPTER_02_CHAPTER_02_H_
#define SRC_CHAPTER_02_CHAPTER_02_H_

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

namespace chapter_2 {
	namespace built_in_types {
		void autoExamples();
		void decltypeExamples();
		void typeConversion();
		void initialization();
		void scopeLevels();
		void unsignedTypes();
	};
	namespace data_structures {
		void stack();
	};
	namespace literals {
		void escapeCharacters();
		void values();
	};
	namespace pointers {
		void compoundDeclarations();
		void doublePointers();
		void references();
	};
};




#endif /* SRC_CHAPTER_02_CHAPTER_02_H_ */
