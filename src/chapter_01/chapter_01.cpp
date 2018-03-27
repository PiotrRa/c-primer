/*
 * chapter_01.cpp
 *
 *  Created on: Mar 27, 2018
 *      Author: piotrra
 */

#include "chapter_01.h"
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



