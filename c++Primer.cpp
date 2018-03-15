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
using namespace chapter_6;
using namespace chapter_7;


int main() {

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
			chapter_1::bookstore();
			break;
		case 2:
			chapter_2::built_in_types::autoExamples();
			chapter_2::built_in_types::decltypeExamples();
			chapter_2::built_in_types::initialization();
			chapter_2::built_in_types::unsignedTypes();

			chapter_2::literals::escapeCharacters();
			chapter_2::literals::values();

			chapter_2::pointers::compoundDeclarations();
			chapter_2::pointers::doublePointers();
			chapter_2::pointers::references();

			break;

		case 3:
			chapter_3::arrays::allZeros();
			chapter_3::arrays::equalityTest();
			chapter_3::arrays::copyArrtoVec();
			chapter_3::arrays::copyVecToArr();

			chapter_3::iterators::printVectors();
			chapter_3::iterators::doubleVector();
			chapter_3::iterators::sumUp();
			chapter_3::iterators::clusterGrades();

			chapter_3::arrays2d::printArray();
			chapter_3::arrays2d::printArrayWithAuto();
			chapter_3::arrays2d::printArrayWithAliases();

			chapter_3::strings::readWords();
			chapter_3::strings::readLines();
			chapter_3::strings::areEqual();
			chapter_3::strings::areLength();
			chapter_3::strings::concatenate();
			chapter_3::strings::capitalize();
			strings::removePuncation();

			chapter_3::vectors::readIntegers();
			chapter_3::vectors::readStrings();
			chapter_3::vectors::toUpper();
			chapter_3::vectors::sumUp();

			break;

		case 4:
			chapter_4::expresions::expresions();
			break;

		case 5:

			chapter_5::exceptions::exceptions();

			chapter_5::statements::gradesIfElse();
			chapter_5::statements::gradesOperator();
			chapter_5::statements::vowelCounting();
			chapter_5::statements::countRepeated();
			chapter_5::statements::findPrefix();

			break;

		case 6:

			chapter_6::functions::matching();
			chapter_6::functions::passing_args();
			//chapter_6::functions::return_val(); --broken
			chapter_6::functions::pointers();
			chapter_6::functions::special_features();
			break;

		case 7:
			chapter_7::classes::classes();
			chapter_7::constructors::constructors();
			chapter_7::special_features::special_features();

			break;
		case 8:
			chapter_8::io_classes::io_classes();
			chapter_8::io_files::io_files();
			break;
		}

		cout << "\nDo you want to continue? yes/no" << endl;

		string answer;
		cin.clear();
		cin.ignore(999, '\n');
		getline(cin, answer);
		if (answer == "no") {
			loop = false;
		}
	}
	return 0;
}
