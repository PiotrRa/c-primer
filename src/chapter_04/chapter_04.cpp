/*
 * chapter_04.cpp
 *
 *  Created on: Mar 27, 2018
 *      Author: piotrra
 */

#include "chapter_04.h"

int* chapter_4::expresions::getPtr(){

	int i = 1234;
	int* ptr = &i;
	//int *ptr = nullptr;
	return ptr;
}
void chapter_4::expresions::expresions(){
	std::cout << "\n---" << __FUNCTION__ << "---\n" << std::endl;

	//Arithmetic operators
	std::cout << "-30 * 3 + 21 / 5 = " << -30 * 3 + 21 / 5 << "\t-> ( ( ( -30 ) * 3 ) + ( 21 / 5 ) ) " << std::endl;
	std::cout << "-30 + 3 * 21 / 5 = " << -30 + 3 * 21 / 5 <<"\t->  ( ( -30 )  + ( ( 3  * 21 )  / 5 ) ) " << std::endl;
	std::cout << "30 / 3 * 21 % 5 = " << 30 / 3 * 21 % 5 << "\t-> ( ( ( 30 / 3 ) * 21 ) % 5 )" << std::endl;
	std::cout << "-30 * 3 * 21 / 4 = " << -30 * 3 * 21 % 4 <<"\t-> ( ( ( ( -30 ) * 3 ) * 21 ) % 4 )" << std::endl;


	// c++11 - list initialisation
	int arr[5] = {0, 1, 2, 3, 4};
//Arithmetic expressions in logical statement

	std::cout << std::endl;

	for(const auto &i : arr) {
		if(i%2 == 0) {
			std::cout << i << " is even!" << std::endl;
		}
		else {
			std::cout << i << " is odd!" << std::endl;
		}
	}

	std::cout << "Reading integer input until 42 is typed: " << std::endl;
	int input;
	do {
		std::cin >> input;
	} while (input != 42);


//Combound assignment operators
	int *p = nullptr;
//(p==getPtr()) ensure the getPtr() call *p assigment happens before && operator call
	if((p=expresions::getPtr()) && p != nullptr) {
		std::cout<< "Statement int* p = getPtr() != 0 is true, pointer p is: "<< p <<" pointed value is: " << *p<< std::endl;
	} else {
		std::cout<< "Statement int* p = getPtr() != 0 is false, pointer p is: "<< p <<" pointed value is: " << *p<< std::endl;

	}
	std::cout << "Double the odd vector items: (4.23)" << std::endl;
	std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	for (auto it = vec.begin(); it != vec.end(); ++it){
		!(*it % 2) ? : *it = *it * 2;
		std::cout << *it << " ";
	}

	std::cout << "\nType grade 0...100" << std::endl;
	int grade = 0;
	std::cin >> grade;

	std::cout << (grade < 60 ? "fail\n" : (grade <=75) ? "low pass\n" : (grade < 100) ? "high pass\n" : "input to high");

	if (grade<60) {
		std::cout << "fail\n";
	} if(grade <= 75) {
		std::cout << "low pass\n";
	} else {
		std::cout << "high pass\n";
	}
}

