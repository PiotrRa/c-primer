/*
 * chapter_09.cpp
 *
 *  Created on: Mar 27, 2018
 *      Author: piotrra
 */


#include "chapter_09.h"
bool chapter_9::seq_containers::findNumberInVector1 (std::vector<int>& vec, const int& number) {

	bool match = false;
	for(auto it = vec.begin(); it!=vec.end(); ++it) {
		if (*it == number)
			match = true;
		}
	return match;
}
chapter_9::seq_containers::intVecIterator_t chapter_9::seq_containers::findNumberInVector2 (std::vector<int>& vec, const int& number){

	chapter_9::seq_containers::intVecIterator_t match = vec.end();

	for(auto it = vec.begin(); it!=vec.end(); ++it) {
		if (*it == number)
			match = it;
		}
	return match;
}
void chapter_9::seq_containers::overview(){

//iterators

	std::cout << "\n---" << __FUNCTION__ << "---\n" << std::endl;

	std::cout << " (9.3) Reading Integers (type none integer value to stop reading)" << std::endl;
	int number;
	std::vector<int> ivec;
	while(std::cin >> number){
		ivec.push_back(number);
	}
	std::cin.clear();
	std::cin.ignore(999, '\n');
	std::cout << "Type number to be found in vector" << std::endl;
	std::cin >> number;
	std::cin.clear();
	std::cin.ignore(999, '\n');

	bool result1 = chapter_9::seq_containers::findNumberInVector1(ivec, number);
	result1 ? std::cout << "Number found!" << std::endl : std::cout << "Number not found!" << std::endl ;

	ivec.clear();
	number = 0;
	std::cout << " (9.4) Reading Integers (type none integer value to stop reading)" << std::endl;
	while(std::cin >> number){
			ivec.push_back(number);
		}
		std::cin.clear();
		std::cin.ignore(999, '\n');
		std::cout << "Type number to be found in vector" << std::endl;
		std::cin >> number;
		std::cin.clear();
		std::cin.ignore(999, '\n');

		chapter_9::seq_containers::intVecIterator_t result2 = chapter_9::seq_containers::findNumberInVector2(ivec, number);
		result2 == ivec.end() ? std::cout << "Number not found!" << std::endl : std::cout << "Number found!" << std::endl ;

//sequential containers initialization

		std::vector<int> 		vec1;									//default constructor
		std::vector<int> 		vec2(vec1);								//copy of another vector, vec1 and vec2 must be the same containers of the same types
		std::vector<int> 		vec3 = {1, 2, 3};						//list initialized; type of list elements must be compatible with type of vector
		std::vector<int> 		vec4(vec3.begin(), vec3.end());			//range initialized, types of the vec3 elements must be compatible with vec4 type
		std::vector<int> 		vec5(10, 1);							//size initialized, creates vector of 10 ints of value 1;


		std::list<int> 			l1 = {1, 2, 3};

		//std::vector<double> 	d1(l1);									//error, containers types incompatible
		std::vector<double> 	d1(l1.begin(), l1.end());				// ok, l1 elements are convertible to double

//swap() and assign()

		std::cout << "\n\nassign() function\n" <<std::endl;
		std::list<char*> list1 = {"this", "is", "a", "list", "of", "char* pointers", "to", "C-style", "character", "strings"};
		for (auto item : list1) std::cout << item << " ";
		std::cout << std::endl;

		std::vector<std::string> vector1;
		vector1.assign(list1.begin(), list1.end());					//assign is guaranteed to run at constant time, not like copy constructor or assignment operator
		for (auto item : vector1) std::cout << item << " ";
		std::cout << std::endl;

		std::cout << "\n\nswap() function\n" <<std::endl;

		std::vector<std::string> vector2 = {"this", "is", "another", "vector"};

		for (auto item : vector1) std::cout << item << " ";
		std::cout << std::endl;
		for (auto item : vector2) std::cout << item << " ";
		std::cout<< "\nswapping vectors..." << std::endl;

		vector1.swap(vector2);										//swap is guaranteed to run at constant time. swap does not invalidate pointers and iterators...

		for (auto item : vector1) std::cout << item << " ";
		std::cout << std::endl;
		for (auto item : vector2) std::cout << item << " ";
		std::cout<< "\nswapping vectors..." << std::endl;

		std::swap(vector1, vector2);								//non-member version of swap - C++11

		for (auto item : vector1) std::cout << item << " ";
		std::cout << std::endl;
		for (auto item : vector2) std::cout << item << " ";
		std::cout << std::endl;

//relational operators

		std::vector<int>	vector3 = {1, 2, 3, 4};
		std::vector<int>	vector4 = {4, 5, 6};

		std::cout << "\nvector 1: " << std::flush;
		for(auto item : vector3) std::cout << " " << item;
		std::cout  << "\nvector 2: " << std::flush;
		for(auto item : vector4) std::cout << " " << item;

		vector3 == vector4 ? std::cout <<"\nvectors are equal!" << std::endl : std::cout << "\nvectors are not equal!" << std::endl;
		vector3 > vector4 ? std::cout <<"\nvector 1 is bigger!" << std::endl : std::cout << "\nvector 2 is bigger" << std::endl;


}
void chapter_9::seq_containers::insertString(std::forward_list<std::string>& flist, const std::string& key, const std::string& item){

	std::cout << "forward list: "<<std::endl;
	for (auto item : flist) {
		std::cout << item << " ";
	}

	std::cout << std::endl;
	std::forward_list<std::string>::iterator prev = flist.before_begin();
	std::forward_list<std::string>::iterator curr = flist.before_begin();

	bool flag = false;
	while (curr != flist.end()) {
		if(*curr == key) {
			curr = flist.insert_after(curr, item);
			flag = true;
			break;
		}
		++curr;
	}
	if(flag) {
		std::cout << "\nkey string " << key << " found! " << "item string " << item << "inserted after key:" << std::endl;
		std::cout << "forward list: "<<std::endl;
		for (auto item : flist) {
			std::cout << item << " ";
		}
	} else {
		std::cout << "\nkey string " << key << " not found! " << "item string " << item << " inserted at the list end:" << std::endl;
		prev = flist.before_begin();
		curr = flist.before_begin();
		while(curr != flist.end()) {				//forward_list has no iterato decrement menber
			prev = curr;							//to get one-before-the-end element need to loop from before-beginning
			++curr;
		}
		flist.insert_after(prev, item);
		for (auto item : flist) {
			std::cout << item << " ";
		}
	}
}
void chapter_9::seq_containers::operation(){

	std::cout << "\n---" << __FUNCTION__ << "---\n" << std::endl;

//inserting elements: push_back
	std::string					tmp;
	std::deque<std::string>		deque1;
	std::cout << "\nType strings to be inserted into deque, type 'end' to break:" <<std::endl;
	while (tmp != "end") {
		std::getline(std::cin, tmp);
		deque1.push_back(tmp);
	}
	std::cout << "\n\ndeque: " << std::endl;
	for(std::deque<std::string>::const_iterator it = deque1.cbegin(); it != deque1.cend(); ++it) {
		std::cout << *it <<std::endl;
	}
//inserting elements: emplace_back
	tmp = "";
	std::list<std::string>		list1;
	std::cout << "\nType strings to be inserted into list, type 'end' to break:" <<std::endl;
	while (tmp != "end") {
		std::getline(std::cin, tmp);
		list1.emplace_back(tmp);																		//C++11 - emplace_back(front); this run a constructor to create object directly
																										//within container structure, no copy or temp object create lik in push_back - more efficient
	}
	std::cout << "\n\nlist: " << std::endl;
	for(std::list<std::string>::const_iterator it = list1.cbegin(); it != list1.cend(); ++it) {
		std::cout << *it <<std::endl;
	}
//inserting elements: insert
	std::list<int>		list2 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	std::deque<int>		deque3;
	std::deque<int>		deque4;

	for(auto item : list2) {
		std::deque<int>::iterator it1 = deque3.end();
		std::deque<int>::iterator it2 = deque4.end();

		if (item % 2 == 0) {
			deque3.insert(it1, item);												//insert used to push elements and the end, need to reinitialize iterator after each insert() to point at
																					//the new deque's end
			it1 = deque3.end();
		}
		else {
			it2 = deque4.insert(it2, item);											//C++11 - insert return iterator of to the inserted element
		}
	}

	std::cout << "\nlist of ints: " << std::endl;
	for (auto item : list2) std::cout << item << " ";
	std::cout << std::endl << "\neven values: " << std::endl;
	for (auto item : deque3) std::cout << item << " ";
	std::cout << std::endl << "\nodd values: " << std::endl;
	for (auto item : deque4) std::cout << item << " ";
	std::cout << std::endl;

//accessing elements:
std::cout << "\nAccessing vector elements..." << std::endl;
	std::vector<int>	vector1 = {1, 2};


	auto a = vector1[0];								//subscript, if try access out_of_range element program crash
	auto b = vector1.begin();							//returns iterator, need to be dereferenced to access object
	auto c = vector1.front();							//return copy of the first object
	auto d = vector1.at(0);								//similar to subscript, check if index is in range - exception otherwise

	std::cout <<"\na = " << a << "\nb = " << *b << "\nc = " << c << "\nd = " << d << std::endl;

//erasing elements:

	std::cout << "\nErasing container elements... " << std::endl;

	int ia[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	std::vector<int> even;
	std::list<int> odd;

	for(int i = 0; i != sizeof(ia)/sizeof(*ia); ++i) {
		even.push_back(ia[i]);
		odd.push_back(ia[i]);
	}
	for (std::vector<int>::iterator it = even.begin(); it != even.end(); ++it) {
		if (*it % 2 != 0) {
			it = even.erase(it);							//erase invalidate iterator, but returns new iterator, need to assign it to the loop control iterator
		}
	}

	for (std::list<int>::iterator it = odd.begin(); it != odd.end(); ++it) {
		std::cout << *it << std::endl;
		if (*it % 2 == 0) {
			it = odd.erase(it);							//erase invalidate iterator, but returns new iterator, need to assign it to the loop control iterator
		}
	}

	std::cout << "\nArray: " << std::endl;
	for(int i = 0; i != sizeof(ia)/sizeof(*ia); ++i) {
		std::cout << ia[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "\nEven: " << std::endl;
	for (auto item : even) {
		std::cout << item << " ";
	}
	std::cout << std::endl;
	std::cout << "\nOdd " << std::endl;
	for (auto item : odd) {
		std::cout << item << " ";
	}
	std::cout << std::endl;
// forward_list specialized operation
	std::cout << "\nforward_list specialized operation" << std::endl;

	std::cout << "\ninserting elements to forward_list: " << std::endl;
	std::forward_list<int> flist;
	std::forward_list<int>::iterator last = flist.before_begin();
	for(int i = 0; i != sizeof(ia)/sizeof(*ia); ++i) {
		last =flist.insert_after(last, ia[i]);								//forward_list is a single linked list, to insert/erase element need the on-before element denoted
	}																		//to establish link to the new  next-to element

	for (auto item : flist) {
		std::cout << item << " ";
	}
	std::cout << std::endl;
	std::cout << "\nerasing odd elements from forward_list: " << std::endl;

	std::forward_list<int>::iterator prev = flist.before_begin();
	std::forward_list<int>::iterator curr = flist.before_begin();

	while(curr != flist.end()) {
		if(*curr % 2 != 0) {
			curr = flist.erase_after(prev);
		} else {
			prev = curr;
			++curr;
		}
	}
	for (auto item : flist) {
		std::cout << item << " ";
	}
	std::cout << std::endl;

	std::string temp;
	std::string key;
	std::string item;

	std::forward_list<std::string> flist1;
	std::forward_list<std::string>::iterator iter = flist1.before_begin();
	std::cout << "\nType strings to be inserted into forward_list, type 'end' to break:" <<std::endl;
	while (temp != "end") {
		std::getline(std::cin, temp);
		iter = flist1.insert_after(iter, temp);
	}
	std::cout << "\nType key string:" <<std::endl;
	std::getline(std::cin, key);
	std::cout << "\nType item string:" <<std::endl;
	std::getline(std::cin, item);

	chapter_9::seq_containers::insertString(flist1, key, item);
	std::cout << std::endl;

//capacity and size:

	std::vector<int> ivec = {1, 2, 3, 4, 5, 6};
	std::cout << "\nsize = " << ivec.size() << " capacity = " << ivec.capacity() << std::endl;

	ivec.reserve(50);
	std::cout << "\nsize = " << ivec.size() << " capacity = " << ivec.capacity() << std::endl;

	while(ivec.size() != ivec.capacity()) {
		ivec.push_back(0);
	}
	std::cout << "\nsize = " << ivec.size() << " capacity = " << ivec.capacity() << std::endl;

	ivec.push_back(0);
	std::cout << "\nsize = " << ivec.size() << " capacity = " << ivec.capacity() << std::endl;

	ivec.shrink_to_fit(); 			//C++11
	std::cout << "\nsize = " << ivec.size() << " capacity = " << ivec.capacity() << std::endl;
}
void chapter_9::seq_containers::stringReplace1(std::string& s, const std::string& oldVal, const std::string& newVal){

	size_t pos = 0;
	while(pos != std::string::npos) {

		pos=s.find(oldVal, pos);
		if(pos != std::string::npos) {
			s.erase(pos, oldVal.size());
			s.insert(pos, newVal);
		}
	}
}
void chapter_9::seq_containers::stringReplace2(std::string& s, const std::string& oldVal, const std::string& newVal){

	size_t pos = 0;
	while(pos != std::string::npos) {

		pos=s.find(oldVal, pos);
		if(pos != std::string::npos) {
			s.replace(pos, oldVal.size(), newVal);
		}
	}
}
void chapter_9::seq_containers::stringAppend1(std::string& name, const std::string& prefix, const std::string& suffix) {

	size_t pos = 0;

	name.insert(pos, " ");
	name.insert(pos, prefix);
	name.append(" ");
	name.append(suffix);


}
void chapter_9::seq_containers::stringFindNumber1(const std::string& s){

	std::string numbers = "0123456789";
	std::string::size_type pos = 0;
	std::cout << "\nString: " << s << std::endl;
	while((pos = s.find_first_of(numbers, pos)) != std::string::npos) {;
		std::cout << "Number at position: " << pos << std::endl;
		++pos;
	}
}
void chapter_9::seq_containers::stringFindCharacter1(const std::string& s){

	std::string characters = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";
	std::string::size_type pos = 0;
	std::cout << "\nString: " << s << std::endl;

	while((pos = s.find_first_of(characters, pos)) != std::string::npos) {;
		std::cout << "Character at position: " << pos << std::endl;
		++pos;
	}
}
void chapter_9::seq_containers::stringFindNumber2(const std::string& s){

	std::string characters = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";
	std::string::size_type pos = 0;
	std::cout << "\nString: " << s << std::endl;
	while((pos = s.find_first_not_of(characters, pos)) != std::string::npos) {;
		std::cout << "Number at position: " << pos << std::endl;
		++pos;
	}
}
void chapter_9::seq_containers::stringFindCharacter2(const std::string& s){

	std::string numbers = "0123456789";
	std::string::size_type pos = 0;
	std::cout << "\nString: " << s << std::endl;

	while((pos = s.find_first_not_of(numbers, pos)) != std::string::npos) {;
		std::cout << "Character at position: " << pos << std::endl;
		++pos;
	}
}

chapter_9::seq_containers::date::date(const std::string& s):day(0), month(0), year(0) {

	unsigned temp = 0;
	std::vector<std::string> fullMonth = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
	std::vector<std::string> shortMonth = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
	std::string digits = "0123456789";
	std::string::size_type slashPos = 0;
	std::string::size_type curr = 0;

	if (s.find_first_of("/") != std::string::npos) {
		curr = slashPos;
		slashPos = s.find_first_of("/", slashPos);
		this->day = stoul(s.substr(curr,  slashPos - curr));
		curr = ++slashPos;
		slashPos = s.find_first_of("/", slashPos);
		this->month = stoul(s.substr(curr,  slashPos - curr));
		curr = ++slashPos;
		slashPos = s.find_first_of("/", slashPos);
		this->year = stoul(s.substr(curr,  slashPos - curr));
	}
	for (auto item : fullMonth) {
		++temp;
		if (s.find(item) != std::string::npos) {
			this->day = stoul(s.substr(s.find_first_of(digits), s.find_first_of(",") - s.find_first_of(digits)));
			this->month = temp;
			this->year = stoul(s.substr(s.find_first_of(",") + 1));
		}
	}
	temp = 0;
	for (auto item : shortMonth) {
		++temp;
		if (s.find(item) != std::string::npos) {
			this->day = stoul(s.substr(s.find_first_of(digits), s.find_first_of(",") - s.find_first_of(digits)));
			this->month = temp;
			this->year = stoul(s.substr(s.find_first_of(",") + 1));
		}
	}
}
void chapter_9::seq_containers::date::print() {
	std::cout << day << " " << month << " " << year << std::endl;
}

void chapter_9::seq_containers::stringOperation(){

	std::cout << "\n---" << __FUNCTION__ << "---\n" << std::endl;

	std::vector<char> cvec = {'a', 'b', 'c', 'd'};
	std::string s1(cvec.begin(), cvec.end());				//initializing string with other containers iterators
	std::cout << "\n" << s1 <<std::endl;

	std::string s, oldVal, newVal;
	std::cout << "\nType the string to be searched and replaced: " << std::endl;
	std::getline(std::cin, s);
	std::cout << "\nType the string to be searched for: " << std::endl;
	std::getline(std::cin, oldVal);
	std::cout << "\nType the string to be replaced with: " << std::endl;
	std::getline(std::cin, newVal);

	std::cout << "\nOld string: \n" << s << std::endl;
	chapter_9::seq_containers::stringReplace1(s, oldVal, newVal);
	std::cout << "\nNew string: \n" << s << std::endl;


	//

	s.clear(); oldVal.clear(); newVal.clear();
	std::cout << "\nType the string to be searched and replaced: " << std::endl;
	std::getline(std::cin, s);
	std::cout << "\nType the string to be searched for: " << std::endl;
	std::getline(std::cin, oldVal);
	std::cout << "\nType the string to be replaced with: " << std::endl;
	std::getline(std::cin, newVal);

	std::cout << "\nOld string: \n" << s << std::endl;
	chapter_9::seq_containers::stringReplace2(s, oldVal, newVal);
	std::cout << "\nNew string: \n" << s << std::endl;


	std::string name, prefix, suffix;
	std::cout << "\nType name: " << std::endl;
	std::getline(std::cin, name);
	std::cout << "\nType prefix: " << std::endl;
	std::getline(std::cin, prefix);
	std::cout << "\nType suffix: " << std::endl;
	std::getline(std::cin, suffix);

	std::cout << "\nOld name: \n" << name << std::endl;
	chapter_9::seq_containers::stringAppend1(name, prefix, suffix);
	std::cout << "\nNew name: \n" << name << std::endl;

	s.clear();
	s = "ab2c3d7R4E6";

	chapter_9::seq_containers::stringFindNumber1(s);
	chapter_9::seq_containers::stringFindNumber2(s);
	chapter_9::seq_containers::stringFindCharacter1(s);
	chapter_9::seq_containers::stringFindCharacter2(s);

	chapter_9::seq_containers::date d1("11/05/1990");
	d1.print();
	chapter_9::seq_containers::date d2("April 23, 2000");
	d2.print();
	chapter_9::seq_containers::date d3("Dec 23, 2049");
	d3.print();
}


