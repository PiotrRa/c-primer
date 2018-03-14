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
void chapter_3::arrays::allZeros(){
	std::cout << "\n---" << __FUNCTION__ << "---\n" << std::endl;

	int ARR_SIZE = 0;
	std::cout << "\nArray SIZE: " << std::endl;
	std::cin >> ARR_SIZE;

	int arr[ARR_SIZE];
	std::cout << "Reading array elements (Type more than " << ARR_SIZE
			<< " values or non-integer value to stop" << std::endl;
	//C++98
	//pbegin - pointer to the first arr element
	//pend - pointer to the off-the-end
	int *pbegin = &arr[0];
	int *pend = &arr[ARR_SIZE];
	int *pcurr = nullptr;

	//C++11
	//int *pbegin = begin(arr);
	//int *pend = end(arr);

	int tmp = 0;
	pcurr = pbegin;
	while (std::cin >> tmp && pcurr != pend) {
		*pcurr = tmp;
		++pcurr;
	}
	std::cin.clear();
	std::cin.ignore(999, '\n');
	std::cout << "\nArray with non-zero values: " <<std::endl;

	pcurr = pbegin;
	while (pcurr != pend) {
		std::cout << *pcurr << " ";
		++pcurr;
	}

	for (pcurr = pbegin; pcurr != pend; ++pcurr) {
		*pcurr = 0;
	}
	std::cout << "\nArray with all-zero values: " << std::endl;

	pcurr = pbegin;
	while (pcurr != pend) {
		std::cout << *pcurr << " ";
		++pcurr;
	}
}
void chapter_3::arrays::equalityTest(){
	std::cout << "\n---" << __FUNCTION__ << "---\n" << std::endl;

	int ARR_SIZE = 0;
	std::cout << "\nArray SIZE: " << std::endl;
	std::cin >> ARR_SIZE;

	int arr1[ARR_SIZE];
	int arr2[ARR_SIZE];

	int *pbegin1 = &arr1[0];
	int *pend1 = &arr1[ARR_SIZE];
	int *pcurr1 = nullptr;

	int *pbegin2 = &arr2[0];
	int *pend2 = &arr2[ARR_SIZE];
	int *pcurr2 = nullptr;

	std::cout << "\nReading first array elements: " << std::endl;
	pcurr1 = pbegin1;
	do {
		std::cin >> *pcurr1;
		++pcurr1;
	} while (pcurr1 != pend1);

	std::cout << "\nReading second array elements: " << std::endl;
	pcurr2 = pbegin2;
	do {
		std::cin >> *pcurr2;
		++pcurr2;
	} while (pcurr2 != pend2);

	std::cin.clear();
	std::cin.ignore(999, '\n');

	pcurr1 = pbegin1;
	pcurr2 = pbegin2;

	while (pcurr1 != pend1 && *pcurr1 == *pcurr2) {
		++pcurr1;
		++pcurr2;
	}
	if (pcurr1 == pend1) {
		std::cout << "Arrays are equal!" << std::endl;
	} else {
		std::cout << "Arrays are not equal!" << std::endl;
	}
}

void chapter_3::arrays::copyArrtoVec(){
	std::cout << "\n---" << __FUNCTION__ << "---\n" << std::endl;

	int ARR_SIZE = 0;
	std::cout << "\nArray SIZE: " << std::endl;
	std::cin >> ARR_SIZE;

	int arr[ARR_SIZE];

	int *pbegin = &arr[0];
	int *pend = &arr[ARR_SIZE];
	int *pcurr = nullptr;

	std::cout << "\nReading array elements: " << std::endl;
	pcurr = pbegin;
	do {
		std::cin >> *pcurr;
		++pcurr;
	} while (pcurr != pend);

	std::cin.clear();
	std::cin.ignore(999, '\n');

	std::vector<int> ivec(pbegin, pend);

	std::cout << "\nArray: " << std::endl;
	pcurr = pbegin;
	while (pcurr != pend) {
		std::cout << *pcurr << " ";
		++pcurr;
	}
	std::cout << "\nVector: " << std::endl;
	for (auto it = ivec.begin(); it != ivec.end(); ++it) {
		std::cout << *it << " ";
	}
}
void chapter_3::arrays::copyVecToArr(){

	std::cout << "\n---" << __FUNCTION__ << "---\n" << std::endl;

	int number;
	std::vector<int> ivec;
	std::cout << "\nReading Integers (type none integer value to stop reading)"
			<< std::endl;

	while (std::cin >> number) {
		ivec.push_back(number);
	}
	std::cin.clear();
	std::cin.ignore(999, '\n');

	int ARR_SIZE = ivec.size();
	int arr[ARR_SIZE];
	int *pbegin = &arr[0];
	int *pend = &arr[ARR_SIZE];
	int *pcurr = nullptr;

	pcurr = pbegin;
	for (auto it = ivec.cbegin(); it != ivec.cend(); ++it) {

		*pcurr = *it;
		++pcurr;
	}

	std::cout << "\nVector: " << std::endl;
	for (auto it = ivec.cbegin(); it != ivec.cend(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << "\nArray: " << std::endl;
	pcurr = pbegin;
	while (pcurr != pend) {
		std::cout << *pcurr << " ";
		++pcurr;
	}
}
void chapter_3::iterators::printVectors(){

	std::cout << "\n---" << __FUNCTION__ << "---\n" << std::endl;

	std::vector<int> v1;
	std::vector<int> v2(10);
	std::vector<int> v3(10, 42);
	std::vector<int> v4{10};
	std::vector<int> v5{10, 42};
	std::vector<std::string> v6{10};
	std::vector<std::string> v7{10, "hi"};

	std::cout << "\nV1: " << std::endl;
	for(auto it = v1.begin(); it!=v1.end(); ++it) {
		std::cout << *it << std::endl;
	}
	std::cout << "\nV2: " << std::endl;
	for(auto it = v2.begin(); it!=v2.end(); ++it) {
		std::cout << *it << std::endl;
	}
	std::cout << "\nV3: " << std::endl;
	for(auto it = v3.begin(); it!=v3.end(); ++it) {
		std::cout << *it << std::endl;
	}
	std::cout << "\nV4: " << std::endl;
	for(auto it = v4.begin(); it!=v4.end(); ++it) {
		std::cout << *it << std::endl;
	}
	std::cout << "\nV5: " << std::endl;
	for(auto it = v5.begin(); it!=v5.end(); ++it) {
		std::cout << *it << std::endl;
	}
	std::cout << "\nV6: " << std::endl;
	for(auto it = v6.begin(); it!=v6.end(); ++it) {
		std::cout << *it << std::endl;
	}
	std::cout << "\nV7: " << std::endl;
	for(auto it = v7.begin(); it!=v7.end(); ++it) {
		std::cout << *it << std::endl;
	}
}
void chapter_3::iterators::doubleVector(){

	std::cout << "\n---" << __FUNCTION__ << "---\n" << std::endl;

	const unsigned VECTOR_SIZE = 10;

		std::vector<int> ivec;

		for(unsigned i = 0; i!=VECTOR_SIZE; ++i) {
			std::cout << "Type element " << i+1 << std::endl;
			int elem = 0;
			std::cin >> elem;
			std::cin.clear();
			std::cin.ignore(999,'\n');
			ivec.push_back(elem);
		}

		for(auto it=ivec.begin(); it!=ivec.end(); ++it) {
			//begin(); end() return non-const iterator read-write access to objects
			*it+=*it;
		}
		std::cout << "Vector  with doubled element values: " << std::endl;
		for(auto it=ivec.cbegin(); it!=ivec.cend(); ++it) {
			//c++11 cbegin(); cend() return const iterator read-only access to objects
			std::cout << *it << std::endl;
		}
}
void chapter_3::iterators::sumUp() {

	std::cout << "\n---" << __FUNCTION__ << "---\n" << std::endl;

	int number;
	std::vector<int> ivec;
	std::cout << "Reading Integers (type none integer value to stop reading)"
			<< std::endl;

	while (std::cin >> number) {
		ivec.push_back(number);
	}
	std::cin.clear();
	std::cin.ignore(999, '\n');

	std::cout << "\n1 - sum adjacent elements\n2 - sum first and last" << std::endl;
	int choice;
	std::cin >> choice;
	std::cin.clear();
	std::cin.ignore(999, '\n');

	switch (choice) {
	case 1:
		for (auto it = ivec.cbegin(); it != ivec.cend(); ++it) {
			auto first = it;
			auto last = ++first;
			if (last != ivec.end()) {
				std::cout << *first + *last << " ";
			}
		}
		break;
	case 2:
		for (auto it = ivec.cbegin();
				it != ivec.cbegin() + ((ivec.cend() - ivec.cbegin()) / 2);
				++it) {
			auto first = it;
			auto last = ivec.cend() - (it - ivec.cbegin() + 1);
			std::cout << *first + *last << " ";
			//cout << *first << " " << *last << endl;;

		}
	}
}
void chapter_3::iterators::clusterGrades(){

	std::cout << "\n---" << __FUNCTION__ << "---\n" << std::endl;

	int number;
	std::vector<int> input;
	std::vector<int> scores(11, 0);
	std::cout << "Reading scores (type none integer value to stop reading)" << std::endl;

	while(std::cin >> number){
		input.push_back(number);
	}
	std::cin.clear();
	std::cin.ignore(999,'\n');

	 for(auto it = input.cbegin(); it != input.cend(); ++it) {
		 if (*it <= 100) {
			 auto score = scores.begin() + (*it/10);
			 ++(*score);
		 }
	 }
	 std::cout << "Clustered scores: " << std::endl;
	 for (auto it = scores.cbegin(); it != scores.cend(); ++it) {
		 std::cout << *it << " ";
	 }
}
void chapter_3::arrays2d::printArray() {

	std::cout << "\n---" << __FUNCTION__ << "---\n" << std::endl;
	// code to read into the array
	int ROW_NUM = 0;
	int COL_NUM = 0;

	std::cout << "Number of rows: " << std::endl;
	std::cin >> ROW_NUM;
	std::cout << "Number of columns: " << std::endl;
	std::cin >> COL_NUM;

	int ia[ROW_NUM][COL_NUM];
	ia[ROW_NUM][COL_NUM] = {0};

	for (int i = 0; i != ROW_NUM; ++i) {
		std::cout << "Reading the row: " << i << std::endl;
		for (int j = 0; j != COL_NUM; ++j) {
			std::cin >> ia[i][j];
		}
	}

	std::cin.clear();
	std::cin.ignore(999, '\n');

	std::cout << "\nPrinting 2D array using subscription";
	for (int i = 0; i != ROW_NUM; ++i) {
		std::cout << std::endl;
		for (int j = 0; j != COL_NUM; ++j) {
			std::cout << ia[i][j] << " ";
		}
	}
	std::cout << "\nPrinting 2D array using range for loop";
	for (int (&row)[COL_NUM] : ia) {
		// &row is (&int)[] reference to int array
		std::cout << std::endl;
		for (int &col : row) {
			//&col is int& reference to int
			std::cout << col << " ";
		}
	}
	std::cout << "\nPrinting 2D array using pointers";
	for (int (*p)[COL_NUM] = ia; p != ia + ROW_NUM; ++p) {
		//*p ia pointer to the array of ints
		std::cout << std::endl;
		for (int* q = *p; q != *p + COL_NUM; ++q) {
			//q = *p; dereference p to get first element int te p-th row
			std::cout << *q << " ";
		}
	}

}
void chapter_3::arrays2d::printArrayWithAuto() {

	std::cout << "\n---" << __FUNCTION__ << "---\n" << std::endl;

	// code to read into the array
	int ROW_NUM = 0;
	int COL_NUM = 0;

	std::cout << "Number of rows: " << std::endl;
	std::cin >> ROW_NUM;
	std::cout << "Number of columns: " << std::endl;
	std::cin >> COL_NUM;

	int ia[ROW_NUM][COL_NUM];
	ia[ROW_NUM][COL_NUM] = {0};
	for (int i = 0; i != ROW_NUM; ++i) {
		std::cout << "Reading the row: " << i << std::endl;
		for (int j = 0; j != COL_NUM; ++j) {
			std::cin >> ia[i][j];
		}
	}
	std::cin.clear();
	std::cin.ignore(999, '\n');

	std::cout << "\nPrinting 2D array using subscription and auto type";
	for (auto i = 0; i != ROW_NUM; ++i) {
		std::cout << std::endl;
		for (auto j = 0; j != COL_NUM; ++j) {
			std::cout << ia[i][j] << " ";
		}
	}
	std::cout << "\nPrinting 2D array using range for loop and auto";
	for (auto &row : ia) {
		//using &row to "force" auto to deduce row as an int[] reference,
		//otherwise it would deduce int* due to array to pointer conversion
		std::cout << std::endl;
		for (auto &col : row) {
			//&col will be deduced as int
			std::cout << col << " ";
		}
	}

	std::cout << "\nPrinting 2D array using pointers and auto type";
	for (auto p = ia; p != ia + ROW_NUM; ++p) {
		//auto will deduce p to be *p[] pointer to tne int[]
		std::cout << std::endl;
		for (auto q = *p; q != *p + COL_NUM; ++q) {
			//due to dereferencing auto q = *p auto will deduce q to be int* pointer to int
			std::cout << *q << " ";
		}
	}

}
void chapter_3::arrays2d::printArrayWithAliases() {

	std::cout << "\n---" << __FUNCTION__ << "---\n" << std::endl;

	// code to read into the array
	int ROW_NUM = 0;
	int COL_NUM = 0;

	std::cout << "Number of rows: " << std::endl;
	std::cin >> ROW_NUM;
	std::cout << "Number of columns: " << std::endl;
	std::cin >> COL_NUM;

	int ia[ROW_NUM][COL_NUM];
	ia[ROW_NUM][COL_NUM] = {0};

	for (int i = 0; i != ROW_NUM; ++i) {
		std::cout << "Reading the row: " << i << std::endl;
		for (int j = 0; j != COL_NUM; ++j) {
			std::cin >> ia[i][j];
		}
	}

	std::cin.clear();
	std::cin.ignore(999, '\n');

	std::cout << "\nPrinting 2D array using subscription";
	for (int i = 0; i != ROW_NUM; ++i) {
		std::cout << std::endl;
		for (int j = 0; j != COL_NUM; ++j) {
			std::cout << ia[i][j] << " ";
		}
	}

	std::cout << "\nPrinting 2D array using range for loop and type aliases";
	using int_array1 = int[COL_NUM];
	//defining new type int_array is equivalent of int[COL_NUM] - new style
	for (int_array1 &row : ia) {
		std::cout << std::endl;
		for (int &col : row) {
			std::cout << col << " ";
		}
	}
	std::cout << "\nPrinting 2D array using pointers and type aliases";
	// defining new type alias int_array_pointer is equivalent of (*int)[COL_NUM] - old tyle
	typedef int (*int_array_pointer)[COL_NUM];
	for (int_array_pointer p = ia; p != ia + ROW_NUM; ++p) {
		std::cout << std::endl;
		for (int* q = *p; q != *p + COL_NUM; ++q) {
			std::cout << *q << " ";
		}
	}
}
void chapter_3::strings::readWords() {

	std::cout << "\n---" << __FUNCTION__ << "---\n" << std::endl;
	std::string word;

	std::cout << "Reading words (type 'stop' to stop reading)" << std::endl;
	do {
		std::cin >> word;

		std::cout << word << std::endl;

	} while (word != "stop");

}
void chapter_3::strings::readLines(){

	std::cout << "\n---" << __FUNCTION__ << "---\n" << std::endl;
	std::string line;
	std::cout << "Reading whole lines (type 'stop' to stop)" << std::endl;
	do {
		std::getline(std::cin, line);

		std::cout << line << std::endl;

	} while (line != "stop");
}
void chapter_3::strings::areEqual(){

	std::cout << "\n---" << __FUNCTION__ << "---\n" << std::endl;
	std::string str1, str2;
	std::cout << "Checking if strings are equal" << std::endl;
	std::cin >> str1 >> str2;

	if (str1 == str2) {
		std::cout << "Strings are equal!" << std::endl;
	} else {
		std::cout << "Strings are not equal!" << std::endl;
	}

}
void chapter_3::strings::areLength(){

	std::cout << "\n---" << __FUNCTION__ << "---\n" << std::endl;
	std::string str1, str2;
	std::cout << "Checking if strings have the same length"
			<< std::endl;

	std::cin >> str1 >> str2;

	if (str1.size() == str2.size()) {
		std::cout << "Strings have the same length!" << std::endl;
	} else {
		std::cout << "Strings doesn't have the same length!" << std::endl;
	}

}
void chapter_3::strings::concatenate(){

	std::cout << "\n---" << __FUNCTION__ << "---\n" << std::endl;

	std::string word;

	std::cout << "Type number of strings to concatenate and then type the strings"
			<< std::endl;

	int num = 0;
	int cnt = 0;
	std::string result;
	std::cout << "Number of strings to concatenate: " << std::endl;
	std::cin >> num;
	do {
		std::cin >> word;
		result += word;
		cnt++;
	} while (cnt < num);
	std::cout << result << std::endl;

}
void chapter_3::strings::capitalize() {

	std::cout << "\n---" << __FUNCTION__ << "---\n" << std::endl;
	int tmp = 0;
	std::string line;



	std::cout << "\nChoose option: " << std::endl;
	std::cout << "\n1 - first character \n2 - first word \n3 - whole string" << std::endl;
	std::cin >> tmp;
	std::cin.ignore();	//used to flush \n char from the buffer

	std::cout << "Input string" << std::endl;;
	std::getline(std::cin, line);

	switch(tmp) {
	case 1 :
		if(!line.empty()){
			line[0] = toupper(line[0]);
		}
		break;
	case 2 :
		for(decltype(line.size()) i = 0; i !=line.size() && !isspace(line[i]); i++) {
			//executing loop until it finds first space
			line[i] = toupper(line[i]);
		}
		break;
	case 3 :
		for(auto &c : line) {
		// C++11 range loop: for each character in string...
		// using &c reference to directly access string's character not its copy
			c = toupper(c);
		}
		break;
	}
	std::cout << line << std::endl;

}
void chapter_3::strings::removePuncation(){

	std::cout << "\n---" << __FUNCTION__ << "---\n" << std::endl;


	std::string line, result = "";
	//cin.ignore();	//used to flush \n char from the buffer
	std::cout << "Input string" << std::endl;;
	std::getline(std::cin, line);

	for (auto &c : line) {
		if(!ispunct(c)) {
			result+=c;
		}
	}
	std::cout << result << std::endl;
}
void chapter_3::vectors::readIntegers(){

	std::cout << "\n---" << __FUNCTION__ << "---\n" << std::endl;
	std::cout << "Reading Integers (type none integer value to stop reading)" << std::endl;
	int number;
	std::vector<int> ivec;
	while(std::cin >> number){
		ivec.push_back(number);
	}
	std::cin.clear();
	std::cin.ignore(999,'\n');

	decltype(ivec.size()) size = ivec.size();
	for(decltype(size) i = 0; i< size; ++i) {
		std::cout << ivec[i] << std::endl;
	}
}
void chapter_3::vectors::readStrings() {

	std::cout << "\n---" << __FUNCTION__ << "---\n" << std::endl;
	std::string line;
	std::vector < std::string > svec;
	std::cout << "Reading strings (type 'stop' to stop)" << std::endl;
	do {
		std::getline(std::cin, line);
		if (line != "stop") {
			svec.push_back(line);
		}
	} while (line != "stop");

	decltype(svec.size()) size = svec.size();
	for (decltype(size) i = 0; i < size; ++i) {
		std::cout << svec[i] << std::endl;
	}
}
void chapter_3::vectors::toUpper(){

	std::cout << "\n---" << __FUNCTION__ << "---\n" << std::endl;
	std::string line;
	std::vector<std::string> svec;
	std::cout << "Reading strings (type 'stop' to stop)" << std::endl;
	do {
		std::getline(std::cin, line);
		if (line != "stop") {
			svec.push_back(line);
		}
	} while(line != "stop");

	 decltype(svec.size()) size = svec.size();

	 for(decltype(size) i = 0; i< size; ++i) {
		 for(auto &c : svec[i]) {
			 c = toupper(c);
		 }
	 }
	 for(decltype(size) i = 0; i< size; ++i) {
		 std::cout << svec[i] << std::endl;
	 }
}
void chapter_3::vectors::sumUp(){

	std::cout << "\n---" << __FUNCTION__ << "---\n" << std::endl;
	int number;
	std::vector<int> ivec;
	std::cout << "Reading Integers (type none integer value to stop reading)" << std::endl;

	while(std::cin >> number){
		ivec.push_back(number);
	}
	std::cin.clear();
	 std::cin.ignore(999,'\n');

	 std::cout << "\n1 - sum adjacent elements\n2 - sum first and last" << std::endl;
	 int choice;
	 std::cin >> choice;
	 std::cin.clear();
	 std::cin.ignore(999,'\n');

	 decltype(ivec.size()) size = ivec.size();


	 switch(choice){
	 case 1:
		 for(decltype(size) i = 1; i< size; ++i) {
			 std::cout << ivec[i-1] + ivec[i] << " ";
		 }
		 break;
	 case 2:
		 for(decltype(size) i = 0; i< size/2; ++i) {
			 std::cout << ivec[i]+ivec[size- 1-i] << " ";
		 }
	 }
}
