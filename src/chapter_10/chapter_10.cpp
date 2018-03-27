/*
 * chapter_10.cpp
 *
 *  Created on: Mar 27, 2018
 *      Author: piotrra
 */


#include "chapter_10.h"

void chapter_10::generic_algorithms::countIntegers(const std::vector<int>& ivec){
	std::vector<int> tmp;
	for(auto item : ivec) {
		if(std::find(tmp.cbegin(), tmp.cend(), item) == tmp.cend()){
			std::cout << item << " count: " << std::count(ivec.cbegin(), ivec.cend(), item) << std::endl;
			tmp.push_back(item);
		}
	}
}

void chapter_10::generic_algorithms::countStrings(const std::list<std::string>& slist) {
	std::vector<std::string> tmp;
	for(auto item : slist) {
		if(std::find(tmp.cbegin(), tmp.cend(), item) == tmp.cend()){
			std::cout << item << " count: " << std::count(slist.cbegin(), slist.cend(), item) << std::endl;
			tmp.push_back(item);
		}
	}
}
void chapter_10::generic_algorithms::overview() {

	std::cout << "\n---" << __FUNCTION__ << "---\n" << std::endl;

	std::cout << "Type integers to be pushed into the vector. Non int value to stop" << std::endl;
	std::vector<int> ivec;
	int tmpi;
	while(std::cin >> tmpi) {
		ivec.push_back(tmpi);
	}
	std::cin.clear();
	std::cin.ignore(999, '\n');
	countIntegers(ivec);


	std::cout << "Type strings to be pushed into the list,type 'end' to stop" << std::endl;
	std::list<std::string> slist;
	std::string tmps;
	while(tmps != "end") {
		std::getline(std::cin, tmps);
		slist.push_back(tmps);
	}
	std::cin.clear();
	std::cin.ignore(999, '\n');
	countStrings(slist);

}
void chapter_10::generic_algorithms::customOperations() {

	std::cout << "\n---" << __FUNCTION__ << "---\n" << std::endl;


}
void chapter_10::generic_algorithms::iterators() {

	std::cout << "\n---" << __FUNCTION__ << "---\n" << std::endl;


}
void chapter_10::generic_algorithms::genericALgorithms() {

	std::cout << "\n---" << __FUNCTION__ << "---\n" << std::endl;


}
void chapter_10::generic_algorithms::containerSpecAlgorithms() {}

