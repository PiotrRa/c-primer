/*
 * chapter_08.cpp
 *
 *  Created on: Mar 27, 2018
 *      Author: piotrra
 */

#include "chapter_08.h"

std::istream& chapter_8::io_classes::print(std::istream& is) {
	std::string input;
	while(!is.eof()) {
		is >> input;
	}
	std::cout << input;

	is.clear();
	return is;
}
void chapter_8::io_classes::io_classes() {
	std::cout << "\n---" << __FUNCTION__ << "---\n" << std::endl;

	//	print(cin);

	//untie cin from cout, now cin will not cout buffer
	std::cin.tie(nullptr);

	std::string command;
	std::cout <<'$';
	std::cin >> command;
}

chapter_8::io_files::Sales_data::Sales_data(const std::string& str, const unsigned& u, const double& p): bookNo(str), units_sold(u), revenue(u*p){
}
//delegating constructor: delegates object initialization to (string, unsigned, double) constructor
chapter_8::io_files::Sales_data::Sales_data():Sales_data("", 0, 0) {
}
//delegating constructor: delegates object initialization to (string, unsigned, double) constructor
chapter_8::io_files::Sales_data::Sales_data(const std::string& str): Sales_data(str, 0, 0){
}
//after delegating to other constructor, constructor body can be executed
chapter_8::io_files::Sales_data::Sales_data(std::istream& is, std::ostream& os): Sales_data("",0,0){
	chapter_8::io_files::read(is,os,*this);
}

chapter_8::io_files::Sales_data& chapter_8::io_files::Sales_data::combine(const chapter_8::io_files::Sales_data& other) {
	this->units_sold += other.units_sold;
	this->revenue += other.revenue;

	return *this;
}
std::string chapter_8::io_files::Sales_data::isbn () const {
	return this->bookNo;
}
double chapter_8::io_files::Sales_data::avg_price() const {

	return units_sold ? revenue/units_sold : 0.0;
}
bool chapter_8::io_files::read (std::istream& is,std::ostream& os, chapter_8::io_files::Sales_data& item) {
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
bool chapter_8::io_files::read(const std::string& fileName,
		std::vector<chapter_8::io_files::Sales_data>& vector) {

	std::ifstream file(fileName);
	if (file.good()) {
		std::string line;
		chapter_8::io_files::Sales_data item;

		while (std::getline(file, line)) {
			std::stringstream ss(line);
			std::string word;
			std::vector<std::string> words;
			while (ss >> word) {
				words.push_back(word);
			}
			item.bookNo = words[0];
			item.units_sold = std::stoi(words[1]);

			item.revenue = std::stod(words[2]);

			vector.push_back(item);
		}

		file.close();
		return true;
	}
	else {
		return false;
	}
}

std::ostream& chapter_8::io_files::print (std::ostream& os, const chapter_8::io_files::Sales_data& item) {

	os << "ISBN: " << item.isbn() << "\tunits sold: " << item.units_sold << "\trevenue: " << item.revenue << "\tavg price: " << item.avg_price() <<std::endl;
	return os;

}
void chapter_8::io_files::save(const std::string& fileName, const std::vector<Sales_data>& vector, const char& flag) {

	std::ofstream file;
	switch (flag) {
	case 'a':
		file.open(fileName.c_str(), std::ofstream::app);
		break;
	default:
		file.open(fileName.c_str());
		break;
	}

	for (auto item : vector) {
		std::stringstream ss;
		ss << item.bookNo << ' ' << item.units_sold << ' ' << item.revenue << std::endl;
		file << ss.str();
	}
	file.close();
}
void chapter_8::io_files::readLines(std::ifstream& file, std::vector<std::string>& vec) {
	std::string line;
	while (std::getline(file, line)) {
		vec.push_back(line);
	}
}
void chapter_8::io_files::readWords(std::ifstream& file, std::vector<std::string>& vec) {
	std::string word;
	while (file >> word) {
		vec.push_back(word);
	}
}
void chapter_8::io_files::io_files() {
	std::cout << "\n---" << __FUNCTION__ << "---\n" << std::endl;
	//	std::vector<std::string> linesVec;
	//	std::vector<std::string> wordsVec;
	//	std::ifstream file("file.txt");
	//
	//	if (file) {
	//		chapter_8::io_files::readLines(file, linesVec);
	//
	//	} else {
	//		cerr << "couldn't open file.txt" << endl;
	//	}
	//	file.close();
	//	for (auto line : linesVec) {
	//		cout << line << endl;
	//	}
	//
	//	file.open("file.txt");
	//
	//	if(file) {
	//		chapter_8::io_files::readWords(file, wordsVec);
	//	} else {
	//		cerr << "couldn't open file.txt" << endl;
	//	}
	//	for (auto word : wordsVec) {
	//		cout << word << endl;
	//	}


	//	chapter_8::io_files::Sales_data total;
	//
	//	if (chapter_8::io_files::read(cin,cout, total)) {
	//		chapter_8::io_files::Sales_data trans;
	//		while (chapter_8::io_files::read(cin, cout, trans)) {
	//			if (total.isbn() == trans.isbn()) {
	//				total.combine(trans);
	//			} else {
	//				chapter_8::io_files::print(cout, trans);
	//				total = trans;
	//			}
	//		}
	//	}
	//	chapter_8::io_files::print(cout, total);

	std::string fname = "bookstore.txt";
	std::vector<chapter_8::io_files::Sales_data> vec;

	chapter_8::io_files::read(fname, vec);
	std::cout << "Bookstore" << std::endl;
	for (auto item : vec) {
		chapter_8::io_files::print(std::cout, item);
	}
	chapter_8::io_files::Sales_data tmp("c:01:02", 11, 3.25);
	vec.push_back(tmp);
	save(fname, vec);

	vec.clear();
	chapter_8::io_files::	read(fname, vec);
	std::cout << "Bookstore" <<std::endl;
	for (auto item : vec) {
		chapter_8::io_files::print(std::cout, item);
	}

	vec.pop_back();
	save(fname, vec);

	vec.clear();
	chapter_8::io_files::read(fname, vec);
	std::cout << "Bookstore" << std::endl;
	for (auto item : vec) {
		chapter_8::io_files::print(std::cout, item);
	}
}



