/*
 * chapter_06.cpp
 *
 *  Created on: Mar 27, 2018
 *      Author: piotrra
 */

#include "chapter_06.h"


void chapter_6::functions::f() {
	std::cout << "f()" << std::endl;
}
void chapter_6::functions::f(int) {
	std::cout << "f(int)" << std::endl;
}
void chapter_6::functions::f(int, int) {
	std::cout << "f(int, int)" << std::endl;
}
void chapter_6::functions::f(double, double) {
	std::cout << "f(double, double = 3.14)" << std::endl;
}
void chapter_6::functions::matching() {

	std::cout << "\n---" << __FUNCTION__ << "---\n" << std::endl;

	// Ambiguous call f(int, int) and f(double, double=3.14) are both best match
	//cout << "Best match for f(42, 2.56) is: "
	//f(42, 2.56);
	std::cout << "Best match for f(42) is: ";
	f(42);
	std::cout << "Best match for f(42, 0) is: ";
	f(42,0);
	std::cout << "Best match for f(2.56, 3.14) is: ";
	f(2.56, 3.14);
	// Ambiguous call f(int, int) and f(double, double=3.14) are both best match
	//cout << "Best match for f(1, 2.56) is: " << f(1, 2.56) << endl;
}
bool chapter_6::functions::str_subrange(const std::string& str1, const std::string& str2){

	if(str1.size() == str2.size())
		return str1 == str2;
	auto size = (str1.size() < str2.size()) ? str1.size() : str2.size();

	bool r = true;
	for(decltype(size) i = 0; i != size; ++i) {

		if(str1[i] != str2[i])
			r = false;
	}
	return r;
}
//recursive function call
void chapter_6::functions::printVecRecursive(std::vector<std::string> vec){


	if (vec.begin() != vec.end() -1) {
		std::cout << *vec.begin() <<std::endl;
		std::vector<std::string> newVec(vec.begin()+1, vec.end());
		printVecRecursive(newVec);
	}
}
//return array
//#1 return explicitly defined pointer to array of 10 ints: int(*)[10]
int (*chapter_6::functions::multiply1(int (*arr)[10], int val))[10] {

	for (int i = 0; i != 10; ++i) {
		*arr[i] = 2 * val;
	}
//return resulst - return int* - pointer ot the first arr elelemnt
//return &result - return (*)[10] - pointer to arr of 10 int
	return arr;
}
//#2 return arrPtr using type alias
//deosnt work, makes progrma exot cod -1
chapter_6::functions::arr* chapter_6::functions::multiply2(int (*arr)[10], int val){
	for (int i = 0; i != 10; ++i) {
		*arr[i] = 2 * val;
	}
	return arr;
}
//#3 return arrPtr using auto and type trailing - c++11

auto chapter_6::functions::multiply3(int (*arr)[10], int val) -> int(*)[10] {
	for (int i = 0; i != 10; ++i) {
		*arr[i] = 2 * val;
	}
	return arr;
}

//#4 return arrPtr using decltype
//decltype deduce int[10] type, need to explicitly invoke * befor name function to return int(*)[10]
void chapter_6::functions::return_val(){

	std::cout << "\n---" << __FUNCTION__ << "---\n" << std::endl;

	std::string str1, str2;
	std::cout << "(6.30)Type two strings: \n";
	std::cout << "string#1: ";
	std::cin >> str1;
	std::cout << "string#2: ";
	std::cin >> str2;
	std::cin.clear();
	std::cin.ignore(999, '\n');

	str_subrange(str1, str2) ? std::cout << "subrange found!\n" : std::cout << "subrange not found!\n";

//
	std::cout << "(6.33)Type strings to be pushed to vector, type 'end' to print vector" << std::endl;
	std::vector<std::string> vec;
	std::string str = "";
	do{
		std::cin >> str;
		vec.push_back(str);
	}
	while(str != "end");

	printVecRecursive(vec);

//
	std::cout << "(6.36-37) Type integer: \n";
	std::cout << "value#1: ";
	int val = 0;
	std::cin >> val;
	std::cin.clear();
	std::cin.ignore(999, '\n');

	int arr1[10] = {0};
	int arr2[10] = {0};
	int arr3[10] = {0};
	int (*arrPtr1)[10] = nullptr;
	int (*arrPtr2)[10]= nullptr;
	int (*arrPtr3)[10]= nullptr;

//
	arrPtr1 = multiply1(&arr1, val);
//	arrPtr2 = multiply2(&arr2, val);
//	arrPtr3 = multiply3(&arr3, val);
////
//	std::cout << "\nArray of ten ints = 2*value#1 returned as explicitly defined pointer to array: \n";
//	for(int i = 0; i != 10; ++i) {
//		std::cout << arrPtr1[i] << " ";
//	}
//	std::cout << "\nArray of ten ints = 2*value#1 returned as pointer to array using type alias: \n";
//	for(int i = 0; i != 10; ++i) {
//		std::cout << arrPtr2[i] << " ";
//	}
//	std::cout << "\nArray of ten ints = 2*value#1 returned as pointer to array using auto and type trailing - c++11: \n";
//	for(int i = 0; i != 10; ++i) {
//		std::cout << *arrPtr3[i] << " ";
//	}
}
int chapter_6::functions::factorial(int val) {

	int ret = 1;
	while (val > 0) {
		ret *= val--;
	}
	return ret;
}
void chapter_6::functions::swap(int* p1, int* p2) {

	int tmp = 0;
	tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
void chapter_6::functions::reset(int& val) {
	val = 0;
}
bool chapter_6::functions::isCapital(const std::string& s) {
	// passing a const reference - function does not write into the object!
	bool ret = false;
	for (auto c : s) {
		isupper(c) ? ret = true : ret = false;
	}
	return ret;
}
void chapter_6::functions::lowerCase(std::string& s) {
//passing non-const string reference - function can write into the object!
	for (auto &c : s) {
		c = tolower(c);
	}
}
int chapter_6::functions::compare(const int val1, const int* val2) {

	int ret = 0;
	val1 >= *val2 ? ret = val1 : ret = *val2;
	return ret;
}
void chapter_6::functions::swapPointers(int*& p1, int*& p2) {
//int*& - reference to pointer to int
	int* tmp = nullptr;
	tmp = p1;
	p1 = p2;
	p2 = tmp;
}
/*int chapter_6::functions::sum(std::initializer_list<int> ints) {
	int sum = 0;
	for (auto &i : ints) {
		sum += i;
	}
	return sum;
}
*/
void chapter_6::functions::passing_args() {

	std::cout << "\n---" << __FUNCTION__ << "---\n" << std::endl;

	//passing by value
	int val;
	std::cout << "(6.5)Value: " << std::endl;
	std::cin >> val;
	std::cout << val << "! = " << factorial(val) << std::endl;
	//passing pointers
	int val1, val2;
	std::cout << "(6.10) type two values to be swapped: " << std::endl;
	std::cout << "value#1 : ";
	std::cin >> val1;
	std::cout << "value#2 : ";
	std::cin >> val2;

	swap(&val1, &val2);
	std::cout << "value#1 : " << val1 << std::endl;
	std::cout << "value#2 : " << val2 << std::endl;


	//passing by reference
	int val3 = 0;
	std::cout << "6.11 Type a value to be reset: " << std::endl;
	std::cout << "value: ";
	std::cin >> val3;
	reset(val3);
	std::cout << "value: " << val3 << std::endl;

	std::cout
			<< "(6.17) Type string to check if contains capital letter"
			<< std::endl;
	std::string s1;
	std::cout << "string: ";
	std::cin >> s1;
	bool r = isCapital(s1);
	r ? std::cout << "capital letter found\n" : std::cout
			<< "capital letter not found\n";
	std::cout << "(6.17) Type string to lowercase" << std::endl;
	std::string s2;
	std::cout << "string: ";
	std::cin >> s2;
	lowerCase(s2);
	std::cout << s2 << std::endl;

	int v5, v6;

	std::cout << "(6.21)Type two values: \n";
	std::cout << "value#1: ";
	std::cin >> v5;
	std::cout << "value#2: ";
	std::cin >> v6;

	std::cout << compare(v5, &v6) << " is bigger!" << std::endl;

	int v7, v8;
	std::cout << "(6.22)Type two values: \n";
	std::cout << "value#1: ";
	std::cin >> v7;
	std::cout << "value#2: ";
	std::cin >> v8;
	int* p1 = &v7;
	int* p2 = &v8;
	std::cout << "pointer#1 points to: " << *p1 << std::endl;
	std::cout << "pointer#2 points to: " << *p2 << std::endl;
	std::cout << "swapping pointers...\n";
	swapPointers(p1, p2);
	std::cout << "pointer#1 points to: " << *p1 << std::endl;
	std::cout << "pointer#2 points to: " << *p2 << std::endl;

	//passing varying number of arguments
	//C++11 initializer list

	//std::cout << "(6.27) 1 + 2 + 3 + 4 + 5 = "
		//	<< sum( { 1, 2, 3, 4, 5 }) << std::endl;
	//std::cout << "(6.27) 1 + 2 = " << sum( { 1, 2 }) << std::endl;
}
int chapter_6::functions::add(const int& v1, const int& v2) {
	return v1 + v2;
}
int chapter_6::functions::subtruct(const int& v1, const int& v2) {
	return v1 - v2;
}
int chapter_6::functions::multiply(const int& v1, const int& v2) {
	return v1 * v2;
}
int chapter_6::functions::divide(const int& v1, const int& v2) {
	return v1 / v2;
}
//function that return function pointer
auto chapter_6::functions::getFunc(const char& c) -> int(*)(const int&, const int&) {			// pointer (*) to the function (const int&, const int&) of return type int

	int (*func_ptr)(const int&, const int&) = nullptr;
	switch (c) {
	case '+':
		func_ptr = &add;
		break;
	case '-':
		func_ptr = &subtruct;
		break;
	case '*':
		func_ptr = &multiply;
		break;
	case '/':
		func_ptr = &divide;
		break;
	}
	return func_ptr;
}
void chapter_6::functions::pointers(){

	std::cout << "\n---" << __FUNCTION__ << "---\n" << std::endl;

	int (*add_ptr)(const int&, const int&) = &add;			//explicit function pointer type definition

															//definition using type alias
	typedef decltype(add) *sub;								//typedef and decltype to define pointer to function type
	sub sub_ptr = &subtruct;


	using func = int(const int&, const int&);				//using keyword to define function type,
	func* mul_ptr = &multiply;
	func* div_ptr = &divide;

	std::vector<decltype(add_ptr)> vec;							//vector of pointer-to-function type
	vec.push_back(add_ptr);
	vec.push_back(sub_ptr);
	vec.push_back(mul_ptr);
	vec.push_back(div_ptr);

	for (auto func : vec) {									//calling functions from vector
		std::cout << func(10, 5) << std::endl;
	}

	func* fptr1 = getFunc('+');								// initialize funct pointer with function return value
	func* fptr2 = getFunc('-');
	func* fptr3 = getFunc('*');
	func* fptr4 = getFunc('/');

	std::cout << "--------------" << std::endl;

	std::cout << fptr1(10, 5) << std::endl;							// function pointers don't need dereference to be called
	std::cout << fptr2(10, 5) << std::endl;
	std::cout << fptr3(10, 5) << std::endl;
	std::cout << fptr4(10, 5) << std::endl;

}
std::string& chapter_6::functions::make_plural(std::string& str, std::string postfix) {
#ifndef NDEBUG
	//__func__ is static local preprocessor var which stores function name
	std::cout << std::endl<<__func__ << " "<< __FILE__ << " " << __LINE__ << " "<< __TIME__ << " " << __DATE__ << std::endl;
#endif
// assert() terminate the program and write err message if condition is true, works only with NDEBUG not defined
	std::cout <<str << " " << postfix << std::endl;
	assert(str != postfix);

	str = str.append(postfix);
	return str;
}

inline bool chapter_6::functions::isShorter(const std::string& str1, const std::string& str2) {
//inline requests the compiler to replace function calls with a function body in the code, optimisation
	return str1.size() < str2.size();
}
void chapter_6::functions::special_features() {

	std::cout << "\n---" << __FUNCTION__ << "---\n" << std::endl;

	std::string str1 = "failure";
	std::string str2 = "success";

//call make_plural() with default value of postfix
	std::cout <<  "Plural form of 'failure' is: " << make_plural(str1) <<std::endl;

//call make_plural() and override default value of postfix
	std::cout <<  "Plural form of 'success' is: " << make_plural(str2, "es") << std::endl;
	//
	std::cout << "Is " << make_plural(str1) << " shorter than " << make_plural(str2, "es") << "? ";
	isShorter(make_plural(str1),  make_plural(str2, "es")) ?  std::cout << "Yes\n" : std::cout << "No\n";

}
