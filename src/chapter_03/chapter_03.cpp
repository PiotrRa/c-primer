/*
 * chapter_03.cpp
 *
 *  Created on: Mar 27, 2018
 *      Author: piotrra
 */

#include "chapter_03.h"

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
	for (auto it = ivec.begin(); it != ivec.end(); ++it) {

		*pcurr = *it;
		++pcurr;
	}

	std::cout << "\nVector: " << std::endl;
	for (auto it = ivec.begin(); it != ivec.end(); ++it) {
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
		for(auto it=ivec.begin(); it!=ivec.end(); ++it) {
			//c++11 begin(); end() return const iterator read-only access to objects
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
		for (auto it = ivec.begin(); it != ivec.end(); ++it) {
			auto first = it;
			auto last = ++first;
			if (last != ivec.end()) {
				std::cout << *first + *last << " ";
			}
		}
		break;
	case 2:
		for (auto it = ivec.begin();
				it != ivec.begin() + ((ivec.end() - ivec.begin()) / 2);
				++it) {
			auto first = it;
			auto last = ivec.end() - (it - ivec.begin() + 1);
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

	 for(auto it = input.begin(); it != input.end(); ++it) {
		 if (*it <= 100) {
			 auto score = scores.begin() + (*it/10);
			 ++(*score);
		 }
	 }
	 std::cout << "Clustered scores: " << std::endl;
	 for (auto it = scores.begin(); it != scores.end(); ++it) {
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



