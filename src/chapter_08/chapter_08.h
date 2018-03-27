/*
 * chapter_08.h
 *
 *  Created on: Mar 27, 2018
 *      Author: piotrra
 */

#ifndef SRC_CHAPTER_08_CHAPTER_08_H_
#define SRC_CHAPTER_08_CHAPTER_08_H_

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

namespace chapter_8{

	namespace io_classes{
	std::istream& print(std::istream& is);
	void io_classes();
	};
	namespace io_files{
		class Sales_data {
		public:
			std::string bookNo = "";
			unsigned units_sold = 0;
			//double unit_price;
			double revenue = 0;

			Sales_data(const std::string& str, const unsigned& u, const double& price);

			Sales_data();
			Sales_data(const std::string& str);
			Sales_data(std::istream& is, std::ostream& os);

			double avg_price() const;
			std::string isbn() const;
			Sales_data& combine(const Sales_data& other);
		};
		//class interface:

		bool read (std::istream& is, std::ostream& os, Sales_data& item);
		bool read (const std::string& fileName, std::vector<Sales_data>& vector);

		std::ostream& print (std::ostream& os, const Sales_data& item);
		void save (const std::string& fileName, const std::vector<Sales_data>& vector, const char& flag = ' ');

		Sales_data add(const Sales_data& lhs, const Sales_data& rhs);

		//utility for io_files();
		void readLines(std::ifstream& file, std::vector<std::string>& vec);
		void readWords(std::ifstream& file, std::vector<std::string>& vec);

		void io_files();
	};

};






#endif /* SRC_CHAPTER_08_CHAPTER_08_H_ */
