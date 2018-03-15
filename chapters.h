/*
 * chapters.h
 *
 *  Created on: 6 Mar 2018
 *      Author: osboxes
 */

#ifndef CHAPTERS_H_
#define CHAPTERS_H_

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <initializer_list>
#include <cassert>
#include <sstream>
#include <fstream>



namespace chapter_1 {
	class Sales_item {
	// these declarations are explained section 7.2.1, p. 270
	// and in chapter 14, pages 557, 558, 561
	friend std::istream& operator>>(std::istream&, chapter_1::Sales_item&);
	friend std::ostream& operator<<(std::ostream&, const chapter_1::Sales_item&);
	friend bool operator==(const chapter_1::Sales_item&, const chapter_1::Sales_item&);
	public:
	    // constructors are explained in section 7.1.4, pages 262 - 265
	    // default constructor needed to initialize members of built-in type
	    Sales_item() = default;
	    Sales_item(const std::string &book): bookNo(book) { }
	    Sales_item(std::istream &is) { is >> *this; }
	public:
	    // operations on Sales_item objects
	    // member binary operator: left-hand operand bound to implicit this pointer
	    chapter_1::Sales_item& operator+=(const chapter_1::Sales_item&);

	    // operations on Sales_item objects
	    std::string isbn() const { return bookNo; }
	    double avg_price() const
	    {
	        if (units_sold)
	            return revenue/units_sold;
	        else
	            return 0;
	    }// private members as before
	private:
	    std::string bookNo;      // implicitly initialized to the empty string
	    unsigned units_sold = 0; // explicitly initialized
	    double revenue = 0.0;
	};

	inline bool operator==(const chapter_1::Sales_item &lhs, const chapter_1::Sales_item &rhs) {
		// must be made a friend of Sales_item
		return lhs.units_sold == rhs.units_sold && lhs.revenue == rhs.revenue
				&& lhs.isbn() == rhs.isbn();
	}
	inline std::istream& operator>>(std::istream& in, chapter_1::Sales_item& s) {

		double price;
		in >> s.bookNo;
		if (s.bookNo == "*") {
			in.setstate(std::ios::failbit);
		} else {
			in >> s.units_sold >> price;

		}
		// check that the inputs succeeded

		if (in)
			s.revenue = s.units_sold * price;
		else
			s = Sales_item();  // input failed: reset object to default state
		return in;
	}
	inline std::ostream& operator<<(std::ostream& out, const chapter_1::Sales_item& s) {
		out << s.isbn() << " " << s.units_sold << " " << s.revenue << " "
				<< s.avg_price();
		return out;
	}

	inline bool compareIsbn(const chapter_1::Sales_item &lhs, const chapter_1::Sales_item &rhs);
	void bookstore();


};
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

namespace chapter_4 {
	namespace expresions{
		int* getPtr();
		void expresions();
	};
};

namespace chapter_5{
	namespace exceptions {
		void exceptions();
	};
	namespace statements {

	void gradesIfElse();
	void gradesOperator();
	void vowelCounting();
	void countRepeated();
	void findPrefix();
	};
};

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

namespace chapter_9{};



#endif /* CHAPTER1_H_ */
