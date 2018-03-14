//============================================================================
// Name        : c++Primer.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include "chapters.h"

using namespace std;
using namespace chapter_1;
using namespace chapter_2;
using namespace chapter_3;
using namespace chapter_4;
using namespace chapter_5;

int main() {

cout << "testing 2";
	bool loop = true;

	while (loop) {
		cout << "Chapter 1 - Getting started" << endl;
		cout << "Chapter 2 - Basics" << endl;
		cout << "Chapter 3 - Strings, Vectors, Arrays" << endl;
		cout << "Chapter 4 - Expressions" << endl;
		cout << "Chapter 5 - Statements" << endl;
		cout << "Chapter 6 - Functions" << endl;
		cout << "Chapter 7 - Classes" << endl;
		cout << "Chapter 8 - IO Library" << endl;
		cout << "Chapter 9 - Sequential Containers" << endl;
		cout << "Choose: " << endl;

		int choice;
		cin >> choice;
		cin.clear();
		cin.ignore(999, '\n');
		switch (choice) {
		case 1:
			bookstore();
			break;
		case 2:
			built_in_types::autoExamples();
			built_in_types::decltypeExamples();
			built_in_types::initialization();
			built_in_types::unsignedTypes();

			literals::escapeCharacters();
			literals::values();

			pointers::compoundDeclarations();
			pointers::doublePointers();
			pointers::references();

			break;

		case 3:
			arrays::allZeros();
			arrays::equalityTest();
			arrays::copyArrtoVec();
			arrays::copyVecToArr();

			iterators::printVectors();
			iterators::doubleVector();
			iterators::sumUp();
			iterators::clusterGrades();

			arrays2d::printArray();
			arrays2d::printArrayWithAuto();
			arrays2d::printArrayWithAliases();

			strings::readWords();
			strings::readLines();
			strings::areEqual();
			strings::areLength();
			strings::concatenate();
			strings::capitalize();
			strings::removePuncation();

			vectors::readIntegers();
			vectors::readStrings();
			vectors::toUpper();
			vectors::sumUp();

			break;

		case 4:
			expresions::expresions();
			break;

		case 5:
			exceptions::exceptions();

			statements::gradesIfElse();
			statements::gradesOperator();
			statements::vowelCounting();
			statements::countRepeated();
			statements::findPrefix();

			break;
		}
		cout << "\nDo you want to continue? yes/no" << endl;
		string answer;
		getline(cin, answer);
		if (answer == "no") {
			loop = false;
		}
	}
	return 0;
}
