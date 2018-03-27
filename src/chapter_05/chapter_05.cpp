/*
 * chapter_05.cpp
 *
 *  Created on: Mar 27, 2018
 *      Author: piotrra
 */


#include "chapter_05.h"

void chapter_5::exceptions::exceptions(){

	std::cout << "\n---" << __FUNCTION__ << "---\n" << std::endl;


	try {
		int a, b;
		std::cout << "Type two numbers a/b: (5.23-25)" << std::endl;
		std::cout << "a: ";
		std::cin >> a;
		std::cout << "b: ";
		std::cin >> b;
		if(b==0) {
			throw std::runtime_error("zero division");
		}
		std::cout << "a/b= " << a/b << std::endl;

	} catch (std::runtime_error err) {
		std::cout << err.what() << " program closed gracefully...";
	}
}
void chapter_5::statements::gradesIfElse(){

	std::cout << "\n---" << __FUNCTION__ << "---\n" << std::endl;


	std::vector<std::string> grades = {"F", "D", "C", "B", "A", "A++"};

	int score = 0;
	std::cout << "Input the score 0...100: " << std::endl;

	std::cin >> score;
	std::cin.clear();
	std::cin.ignore(999, '\n');

	std::string grade = "";
	if(score < 60) {
		grade = grades[0];

	} else {
		grade = grades[(score - 50)/10];
	}
	if(score != 100) {
		if(score % 10 < 3) {
			grade += "-";
		} else if (score % 10 > 7) {
			grade +="+";
		}
	}

	std::cout << "The grade for the score: " << score << " is: " << grade << std::endl;

}
void chapter_5::statements::gradesOperator(){

	std::cout << "\n---" << __FUNCTION__ << "---\n" << std::endl;

	std::vector<std::string> grades = {"F", "D", "C", "B", "A", "A++"};

	int score = 0;
	std::cout << "Input the score 0...100: " << std::endl;

	std::cin >> score;
	std::cin.clear();
	std::cin.ignore(999, '\n');

	std::string grade = "";

	score < 60 ? grade = grades[0] : grade = grades[(score - 50)/10];

	const char * p;

	score == 100 ? p = nullptr : score % 10 < 3 ? grade.append("-") : score % 10 > 7 ? grade.append("+") : p = nullptr;

	std::cout << "The grade for the score: " << score << " is: " << grade << std::endl;

}
void chapter_5::statements::vowelCounting(){

	std::cout << "\n---" << __FUNCTION__ << "---\n" << std::endl;

	std::string str;

	std::cout << "Input the string: " << std::endl;

	std::getline (std::cin, str);

	int aCnt = 0;
	int eCnt = 0;
	int iCnt = 0;
	int oCnt = 0;
	int uCnt = 0;

	int ffCnt = 0;
	int flCnt = 0;
	int fiCnt = 0;

	int xCnt = 0;


	for (auto it = str.begin(); it != str.end(); ++it) {
		switch(*it)
		{
		case 'a' : case 'A' :
			++aCnt;
			break;
		case 'e' : case 'E' :
			++eCnt;
			break;
		case 'i' : case 'I' :
			++iCnt;
			break;
		case 'o' : case 'O' :
			++oCnt;
			break;
		case 'u' : case 'U' :
			++uCnt;
			break;
		case 'f':
			switch (*(++it)) {
			case 'f':
				++ffCnt;
				break;
			case 'l':
				++flCnt;
				break;
			case 'i':
				++fiCnt;
				break;
			default:
				break;
			}
			break;
		default:
			if(isblank(*it)){
				++xCnt;
			}
			break;
		}

	}

	std::cout<< "Number of vowel a: " << aCnt << std::endl;
	std::cout<< "Number of vowel e: " << eCnt << std::endl;
	std::cout<< "Number of vowel i: " << iCnt << std::endl;
	std::cout<< "Number of vowel o: " << oCnt << std::endl;
	std::cout<< "Number of vowel u: " << uCnt << std::endl;

	std::cout<< "Number of ff sequence: " << ffCnt << std::endl;
	std::cout<< "Number of fl sequence: " << flCnt << std::endl;
	std::cout<< "Number of fi sequence: " << fiCnt << std::endl;

	std::cout<< "Number of blank characters: " << xCnt << std::endl;


}
void chapter_5::statements::countRepeated() {

	std::cout << "\n---" << __FUNCTION__ << "---\n" << std::endl;

	std::string str;
	std::string word = "";

	std::cout << "Input string line: " << std::endl;
	std::vector < std::string > words;
	std::getline(std::cin, str);

	auto str_it = str.begin();
	while (str_it != str.end()) {

		if (!isblank(*str_it)) {
			word += *str_it;
		} else {
			words.push_back(word);
			word = "";
		}
		++str_it;
	}
	words.push_back(word);

	int cnt = 1;
	int max = 1;
	std::string winner = "";
	auto vec_it = words.begin() + 1;

	while (vec_it != words.end()) {
		if (*vec_it == *(vec_it - 1)) {
			++cnt;
			if (cnt > max) {
				max = cnt;
				winner = *vec_it;
			}
		} else {
			cnt = 1;
		}
		++vec_it;
	}

	cnt > 1 ?
			std::cout << "Word: " << winner << " repeated " << max
					<< " times in a row" << std::endl :
					std::cout << "No repeated words" << std::endl;


}
void chapter_5::statements::findPrefix(){

	std::cout << "\n---" << __FUNCTION__ << "---\n" << std::endl;

	std::vector<int> lvec;
	std::cout << "Input long vector: " << std::endl;
	int tmp;
	while(std::cin >> tmp) {
		lvec.push_back(tmp);
	}
	std::cin.clear();
	std::cin.ignore(999, '\n');

	std::vector<int> svec;
	std::cout << "Input short vector: " << std::endl;
	while(std::cin >> tmp) {
		svec.push_back(tmp);
	}
	std::cin.clear();
	std::cin.ignore(999, '\n');

	bool match = false;
	for(unsigned int i = 0; i != lvec.size(); ++i) {
		match = true;
		for(unsigned int j =0; j != svec.size(); ++j) {
			if(lvec[i+j] == svec[j]) {
				match = false;
			}
		}
		if(match) {
			break;
		}
	}
	match ? std::cout << "prefix found" << std::endl : std::cout << "prefix not found" << std::endl;

}
