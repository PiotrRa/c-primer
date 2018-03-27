/*
 * chapter_07.h
 *
 *  Created on: Mar 27, 2018
 *      Author: piotrra
 */

#ifndef SRC_CHAPTER_07_CHAPTER_07_H_
#define SRC_CHAPTER_07_CHAPTER_07_H_

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

namespace chapter_7{
	namespace classes{
		class Sales_data {
		public:
			std::string bookNo = "";
			unsigned units_sold = 0;
			//double unit_price;
			double revenue = 0;

			Sales_data() = default;
			Sales_data(const std::string& str);
			Sales_data(const std::string& str, const unsigned& u, const double& price);
			Sales_data(std::istream& is, std::ostream& os);

			double avg_price() const;
			std::string isbn() const;
			Sales_data& combine(const Sales_data& other);
		};
		//class interface:

		bool read (std::istream& is,std::ostream& os, Sales_data& item);
		std::ostream& print (std::ostream& os, const Sales_data& item);
		Sales_data add(const Sales_data& lhs, const Sales_data& rhs);


		void classes();
	};
	namespace constructors{

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

	bool read (std::istream& is,std::ostream& os, Sales_data& item);
	std::ostream& print (std::ostream& os, const Sales_data& item);
	Sales_data add(const Sales_data& lhs, const Sales_data& rhs);


		class NoDefault {
		public:
			//no default constructor after defining parametrised one
			NoDefault(int i = 0){}
		};

		class C {
		public:
			C(): mem() {};

			NoDefault mem;
		};

		class Account {
		public:
			void calculate() {amount+=amount*interestRate;}
			//static member is part of a class not an object, accessible to all objects of the class
			static double rate() { return interestRate;}
			static void rate(double);
		private:
			std::string owner;
			double amount;
			static double interestRate;
			static double initRate();
			//static member can be in-class initialized only with constrexpresion initializer
			static constexpr int period = 30;
		//in-class initialized static members can be used to initialise othet class members
			double daily_tbl[period];

		};
	void constructors();
	};
	namespace special_features {
		class Screen;
		class Windowmgr {
		public:
			Windowmgr();
			Windowmgr(Screen &s);
			typedef std::vector<Screen>::size_type screenId;
			//declaration needed before definition to make this member o friend function for 'Screen' class
			void clear(screenId);
		private:
			std::vector<Screen> screens;

		};
		class Screen {
			friend void Windowmgr::clear(screenId);
		public:
			typedef std::string::size_type pos;
		public:
			Screen() = default;
			Screen(pos h, pos w);
			Screen(pos h, pos w, char c);
			char get() const;
			char get(pos h, pos w) const;
			Screen& move(pos row, pos col);
			Screen& set(char c) {contents[cursor] = c; return *this;};
			Screen& set(pos row, pos col, char c) {contents[row*width+col] = c; return *this;}
			//display is overloaded whether object is const or not
			inline Screen& display(std::ostream& os) {do_display(os); return *this; }
			inline const Screen& display(std::ostream& os) const {do_display(os); return *this; }

		private:
			pos cursor = 0;
			pos height = 0;
			pos width = 0;
			std::string contents;
			mutable unsigned access_ctr = 0;

			void do_display(std::ostream& os) const;
		};
		void special_features();

	};
};




#endif /* SRC_CHAPTER_07_CHAPTER_07_H_ */
