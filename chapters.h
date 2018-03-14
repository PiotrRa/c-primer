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

namespace chapter_5{};

namespace chapter_6{};

namespace chapter_7{};

namespace chapter_8{};

namespace chapter_9{};



#endif /* CHAPTER1_H_ */
