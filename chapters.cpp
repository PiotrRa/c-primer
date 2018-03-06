/*
 * chapters.cpp
 *
 *  Created on: 6 Mar 2018
 *      Author: osboxes
 */

#include "chapters.h"

void chapter_1::bookstore() {
	std::cout << "\n---" << __FUNCTION__ << "---\n" << std::endl;

	Sales_item total;
	if (std::cin >> total) {
		Sales_item trans;
		while (std::cin >> trans) {
			if (total.isbn() == trans.isbn()) {
				total += trans;
			} else {
				std::cout << total << std::endl;
				total = trans;
			}

		}
		std::cout << total << std::endl;
		std::cin.clear(std::cin.rdstate() & ~std::istream::failbit);
	}
}
// used in chapter 10
bool chapter_1::compareIsbn(const Sales_item &lhs, const Sales_item &rhs) {
	return lhs.isbn() == rhs.isbn();
}


inline chapter_1::Sales_item& chapter_1::Sales_item::operator+=(const chapter_1::Sales_item& rhs) {
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}
void chapter_2::built_in_types::autoExamples() {

	std::cout << "\n---" << __FUNCTION__ << "---\n" << std::endl;

	int i = 0, &r = i;

	const int ci = i, &cr = ci;

	auto a = r; 		// a is an int (r is an aliis for i which is an int)
	auto b = ci;	// b is an int (top level const in ci is dropped by auto)
	auto c = cr;// c is an int (cr ia an alia to ci, ci's top level const is dropped)
	auto d = &i;		// d is an int* (& of an int object is int* type)
	auto e = &ci;// e is a  const int* (& of const object is low-level const not dropped)
	auto &g = ci;		// g is a  const int& (bound to ci)
	//auto &h = 42		// error can't bound plain reference to literal
	const auto &j = 0;	// no error, can bound const referenct to literal

	std::cout << "\na: " << a << "\nb: " << b << "\nc: " << c << "\nd: " << d
			<< "\ne: " << e << "\ng: " << g << "\nj: " << j << std::endl;

}
void chapter_2::built_in_types::decltypeExamples() {

	std::cout << "\n---" << __FUNCTION__ << "---\n" << std::endl;

	int a = 3, b = 4;
	decltype(a) c = a;		// c is an int
	decltype((a)) d = a;	// d is an int& because of (a)

	std::cout << "\na: " << a << "\nb: " << b << "\nc: " << c << "\nd: " << d
			<< std::endl;

	++c;
	++d;

	std::cout << "\na: " << a << "\nb: " << b << "\nc: " << c << "\nd: " << d
			<< std::endl;

	int e = 5, f = 6;
	decltype(e) g = e;		// g is an int
	decltype(e=f ) h = e;	// h is an int&, operator= return int&

	std::cout << "\ne: " << e << "\nf: " << f << "\ng: " << g << "\nh: " << h
			<< std::endl;
	++g;
	++h;
	std::cout << "\ne: " << e << "\nf: " << f << "\ng: " << g << "\nh: " << h
			<< std::endl;

}
void chapter_2::built_in_types::typeConversion() {

	std::cout << "\n---" << __FUNCTION__ << "---\n" << std::endl;

	int i = 42;
	std::cout << i << std::endl; // prints 42
	if (i) // condition will evaluate as true
		i = 0;
	std::cout << i << std::endl; // prints 0
	bool b = 42;            // b is true
	std::cout << b << std::endl; // prints 1

	int j = b;              // j has value 1
	std::cout << j << std::endl; // prints 1

	double pi = 3.14;       // pi has value 3.14
	std::cout << pi << std::endl; // prints 3.14

	j = pi;                 // j has value 3
	std::cout << j << std::endl; // prints 3

	unsigned char c = -1;   // assuming 8-bit chars, c has value 255
	i = c;  // the character with value 255 is an unprintable character
			// assigns value of c (i.e., 255) to an int
	std::cout << i << std::endl; // prints 255
}
void chapter_2::built_in_types::initialization() {

	std::cout << "\n---" << __FUNCTION__ << "---" << std::endl;
	int v1(1024);    // direct-initialization, functional form
	int v2 { 1024 };    // direct-initialization, list initializer form
	int v3 = 1024;   // copy-initialization
	int v4 = { 1024 }; // copy-initialization, list initializer form

	// alternative ways to initialize string from a character string literal
	std::string titleA = "C++ Primer, 5th Ed.";
	std::string titleB("C++ Primer, 5th Ed.");
	std::string all_nines(10, '9');  // all_nines = "9999999999"

}

void chapter_2::built_in_types::unsignedTypes() {

	std::cout << "\n---" << __FUNCTION__ << "---\n" << std::endl;

	unsigned u = 10, u2 = 42;
	std::cout << u2 - u << std::endl;
	std::cout << u - u2 << std::endl;

	int i = 10, i2 = 42;
	std::cout << i2 - i << std::endl;
	std::cout << i - i2 << std::endl;

	u = 42;
	i = 10;
	std::cout << i - u << std::endl;
	std::cout << u - i << std::endl;

	u = 10;
	i = -42;
	std::cout << i + i << std::endl;  // prints -84
	std::cout << u + i << std::endl;  // if 32-bit ints, prints 4294967264

	i = 10;
	std::cout << "good" << std::endl;
	while (i >= 0) {
		std::cout << i << std::endl;
		--i;
	}

	for (int i = 10; i >= 0; --i)
		std::cout << i << std::endl;

	for (unsigned u = 0; u <= 10; ++u)
		std::cout << u << std::endl;  // prints 0 . . . 10

	/* NOTE: the condition in the following loop
	 will run indefinitely
	 // WRONG: u can never be less than 0; the condition will always succeed
	 for (unsigned u = 10; u >= 0; --u)
	 std::cout << u << std::endl;
	 */
	u = 11; // start the loop one past the first element we want to print
	while (u > 0) {
		--u;        // decrement first, so that the last iteration will print 0
		std::cout << u << std::endl;
	}

	// be wary of comparing ints and unsigned
	u = 10;
	i = -42;
	if (i < u)               // false: i is converted to unsigned
		std::cout << i << std::endl;
	else
		std::cout << u << std::endl;   // prints 10

	u = 42;
	u2 = 10;
	std::cout << u - u2 << std::endl; // ok: result is 32
	std::cout << u2 - u << std::endl; // ok: but the result will wrap around
}
void chapter_2::literals::escapeCharacters() {

	std::cout << "\n---" << __FUNCTION__ << "---" << std::endl;

	std::cout << '\n';       // prints a newline
	std::cout << "\tHi!\n";  // prints a tab followd by "Hi!" and a newline
	std::cout << "Hi \x4dO\115!\n"; // prints Hi MOM! followed by a newline
	std::cout << '\115' << '\n';    // prints M followed by a newline
}
void chapter_2::literals::values() {

	std::cout << "\n---" << __FUNCTION__ << "---\n" << std::endl;

	std::cout << "Hello World!";  // simple character string literal
	std::cout << "";              // empty character string literal
	// literal using newlines and tabs
	std::cout << "\nCC\toptions\tfile.[cC]\n";

    // multiline string literal
    std::cout << "a really, really long string literal "
	             "that spans two lines" << std::endl;

	// three ways to print a capital M
	std::cout << 'M' << " " << '\115' << " " << '\x4d' << std::endl;

    unsigned long long bigVal = -1ULL;
    std::cout << bigVal << std::endl;

}
void chapter_2::pointers::compoundDeclarations() {

	std::cout << "\n---" << __FUNCTION__ << "---\n" << std::endl;

	// i is an int; p is a pointer to int; r is a reference to int
	int i = 1024, *p = &i, &r = i;

	// three ways to print the value of i
	std::cout << i << " " << *p << " " << r << std::endl;

	int j = 42, *p2 = &j;
	int *&pref = p2;  // pref is a reference to the pointer p2

	// prints the value of j, which is the int to which p2 points
	std::cout << *pref << std::endl;

	// pref refers to a pointer; assigning &i to pref makes p point to i
	pref = &i;
	std::cout << *pref << std::endl; // prints the value of i

	// dereferencing pref yields i, the int to which p2 points;
	*pref = 0;  // changes i to 0

	std::cout << i << " " << *pref << std::endl;
}
void chapter_2::pointers::doublePointers() {

	std::cout << "\n---" << __FUNCTION__ << "---\n" << std::endl;

	int ival = 1024;
	int *pi = &ival;   // pi points to an int
	int **ppi = &pi;   // ppi points to a pointer to an int
	std::cout << "The value of ival\n" << "direct value: " << ival << "\n"
			<< "indirect value: " << *pi << "\n" << "doubly indirect value: "
			<< **ppi << std::endl;

	int i = 2;
	int *p1 = &i;     // p1 points to i
	*p1 = *p1 * *p1;  // equivalent to i = i * i
	std::cout << "i  = " << i << std::endl;

	*p1 *= *p1;       // equivalent to i *= i
		std::cout << "i  = " << i << std::endl;
}
void chapter_2::pointers::references(){

	std::cout << "\n---" << __FUNCTION__ << "---\n" << std::endl;

	int i = 0, &ri = i;  // ri is a reference to i
	// ri is just another name for i;
	// this statement prints the value of i twice
	std::cout << i << " " << ri << std::endl;

	i = 5; // changing i is reflected through ri as well
	std::cout << i << " " << ri << std::endl;

	ri = 10; // assigning to ri actually assigns to i
	std::cout << i << " " << ri << std::endl;

}
