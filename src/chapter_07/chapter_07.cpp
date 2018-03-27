/*
 * chapter_07.cpp
 *
 *  Created on: Mar 27, 2018
 *      Author: piotrra
 */

#include "chapter_07.h"

chapter_7::classes::Sales_data::Sales_data(const std::string& str): bookNo(str){}
chapter_7::classes::Sales_data::Sales_data(const std::string& str, const unsigned& u, const double& p): bookNo(str), units_sold(u), revenue(u*p){}
chapter_7::classes::Sales_data::Sales_data(std::istream& is, std::ostream& os){
	read(is,os,*this);
}

chapter_7::classes::Sales_data& chapter_7::classes::Sales_data::combine(const Sales_data& other) {
	this->units_sold += other.units_sold;
	this->revenue += other.revenue;

//return object reference as lvalue - mimic operator+= behaviour fo consistency
	return *this;
}
std::string chapter_7::classes::Sales_data::isbn () const {
	return this->bookNo;
}
double chapter_7::classes::Sales_data::avg_price() const {

	return units_sold ? revenue/units_sold : 0.0;
}
//class interface implementation:
bool chapter_7::classes::read (std::istream& is,std::ostream& os, Sales_data& item) {
	double price = 0.0;
	os <<"ISBN:\t";
	is >> item.bookNo;
	os << "Units sold:\t";
	is >> item.units_sold;
	os << "Price:\t";
	is >> price;
	item.revenue = price * item.units_sold;

	char answer;
	os << "\nAnother transaction?y/n:\t";
	is >> answer;
	return answer == 'y' ? true : false;

}
std::ostream& chapter_7::classes::print (std::ostream& os, const Sales_data& item) {

	os << "ISBN: " << item.isbn() << "\tunits sold: " << item.units_sold << "\trevenue: " << item.revenue << "\tavg price: " << item.avg_price() <<std::endl;
	return os;

}
chapter_7::classes::Sales_data chapter_7::classes::add(const Sales_data& lhs, const Sales_data& rhs) {
	Sales_data sum;

	return sum;
}
void chapter_7::classes::classes(){
	std::cout << "\n---" << __FUNCTION__ << "---\n" << std::endl;


	//	Sales_data total;
	//
	//	if (read(cin,cout, total)) {
	//		Sales_data trans;
	//		while (read(cin, cout, trans)) {
	//			if (total.isbn() == trans.isbn()) {
	//				total.combine(trans);
	//			} else {
	//				print(cout, trans);
	//				total = trans;
	//			}
	//		}
	//	}
	//	print(cout, total);

		Sales_data item1;
		Sales_data item2("book:01:02");
		Sales_data item3("book:03:01", 5, 9.99);
		Sales_data item4(std::cin, std::cout);

		chapter_7::classes::print(std::cout, item1);
		chapter_7::classes::print(std::cout, item2);
		chapter_7::classes::print(std::cout, item3);
		chapter_7::classes::print(std::cout, item4);
}
chapter_7::constructors::Sales_data::Sales_data(const std::string& str, const unsigned& u, const double& p): bookNo(str), units_sold(u), revenue(u*p){
	std::cout << "CALLED: Sales_data(const std::string& str, const unsigned& u, const double& p\n";
}
//delegating constructor: delegates object initialization to (string, unsigned, double) constructor
chapter_7::constructors::Sales_data::Sales_data():Sales_data("", 0, 0) {
	std::cout << "CALLED: Sales_data()\n";
}
//delegating constructor: delegates object initialization to (string, unsigned, double) constructor
chapter_7::constructors::Sales_data::Sales_data(const std::string& str): Sales_data(str, 0, 0){
	std::cout << "CALLED: Sales_data(const std::string& str)\n";
}
//after delegating to other constructor, constructor body can be executed
chapter_7::constructors::Sales_data::Sales_data(std::istream& is, std::ostream& os): Sales_data("",0,0){
	std::cout<<"CALLED: Sales_data(std::istream& is, std::ostream& os)\n";
	chapter_7::constructors::read(is,os,*this);
}

chapter_7::constructors::Sales_data& chapter_7::constructors::Sales_data::combine(const chapter_7::constructors::Sales_data& other) {
	this->units_sold += other.units_sold;
	this->revenue += other.revenue;

	return *this;
}
std::string chapter_7::constructors::Sales_data::isbn () const {
	return this->bookNo;
}
double chapter_7::constructors::Sales_data::avg_price() const {

	return units_sold ? revenue/units_sold : 0.0;
}
bool chapter_7::constructors::read (std::istream& is,std::ostream& os, chapter_7::constructors::Sales_data& item) {
	double price = 0.0;
	os <<"ISBN:\t";
	is >> item.bookNo;
	os << "Units sold:\t";
	is >> item.units_sold;
	os << "Price:\t";
	is >> price;
	item.revenue = price * item.units_sold;

	char answer;
	os << "\nAnother transaction?y/n:\t";
	is >> answer;
	return answer == 'y' ? true : false;

}
std::ostream& chapter_7::constructors::print (std::ostream& os, const chapter_7::constructors::Sales_data& item) {

	os << "ISBN: " << item.isbn() << "\tunits sold: " << item.units_sold << "\trevenue: " << item.revenue << "\tavg price: " << item.avg_price() <<std::endl;
	return os;

}
//Sales_data add(const Sales_data& lhs, const Sales_data& rhs) {
//	Sales_data sum;
//
//	return sum;
//}

//static members declared in class body needs to be defined outside the class body to be used
double chapter_7::constructors::Account::interestRate = 0.0;
//dont repeat static keyword in  member definition
void chapter_7::constructors::Account::rate(double newRate) {
	interestRate = newRate;
}
void chapter_7::constructors::constructors () {

	std::cout << "\n---" << __FUNCTION__ << "---\n" << std::endl;

	std::cout << "\n-- Sales_data obj1" << std::endl;
	chapter_7::constructors::Sales_data obj1;

	std::cout << "\n-- Sales_data obj2(obj2)" << std::endl;
	chapter_7::constructors::Sales_data obj2("obj2");

	std::cout << "\n-- Sales_data obj3(obj3, 1, 2)" << std::endl;
	chapter_7::constructors::Sales_data obj3("obj3", 1, 2);
	std::cout << "\n-- Sales_data obj4(cin, cout)" << std::endl;
	chapter_7::constructors::Sales_data obj4(std::cin, std::cout);
}
chapter_7::special_features::Windowmgr::Windowmgr():screens({chapter_7::special_features::Screen()}) {}
chapter_7::special_features::Windowmgr::Windowmgr(chapter_7::special_features::Screen &s): screens({s}){
}

void chapter_7::special_features::Windowmgr::clear(screenId id) {
	chapter_7::special_features::Screen &s = screens[id];
	std::cout << &s << std::endl;
	s.contents = std::string(s.height * s.width, 'a');
}


chapter_7::special_features::Screen::Screen(pos h, pos w): height(h), width(w) {
}
chapter_7::special_features::Screen::Screen(pos h, pos w, char c): height(h), width(w), contents(w*h, c) {
}
char chapter_7::special_features::Screen::get() const {

	return contents[cursor];
}
char chapter_7::special_features::Screen::get(pos row, pos col) const{

	return contents[row*width+col];
}
chapter_7::special_features::Screen& chapter_7::special_features::Screen::move(pos row, pos col) {
	cursor = row*width+col;
	return *this;
}
void chapter_7::special_features::Screen::do_display(std::ostream& os) const{
	for (pos i =0; i !=height; ++i) {
		for (pos j =0; j !=width; ++j) {
			os << contents[i*width+j];
		}
		os << '\n';
	}
}
void chapter_7::special_features::special_features() {
	std::cout << "\n---" << __FUNCTION__ << "---\n" << std::endl;

	//	cout << "7.23-26" << endl;
	//	chapter_7::special_features::Screen s(10, 10, 'X');
	//	s.display(std::cout);
	//	std::cout << std::endl;
	//
	//	s.set('O');
	//	s.display(std::cout);
	//	std::cout << std::endl;
	//
	//	s.move(5, 5);
	//	s.set('O');
	//	s.display(std::cout);
	//	std::cout << std::endl;
	//
	//	s.set(9, 9, ' A');
	//	s.display(std::cout);
	//	std::cout << std::endl;


	chapter_7::special_features::Screen s(10, 10, 'X');
	chapter_7::special_features::Windowmgr window(s);
	s.display(std::cout);
	std::cout << "-------------"<< std::endl;

	window.clear(0);
	s.display(std::cout);
	std::cout << "-------------"<< std::endl;

	std::cout << &s << std::endl;
}



