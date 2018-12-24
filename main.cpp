#include <iostream>
#include "LinearHash.h"
#include "DoubleHash.h"
#include "UniversalHash.h"
#include <fstream>
#include <map>
using namespace std;

int main(int argc, char *argv[]) {
	map<string, int> wordList;
	string word;
	int counter = 0;
	int keyToSearch;
	Node input;
	LinearHash linearHash1(17863);
	LinearHash linearHash2(21929);
	DoubleHash doubleHash1(17863, 17851);
	DoubleHash doubleHash2(21929, 21911);
	UniversalHash universalHash1(17863);
	UniversalHash universalHash2(21929);
	ifstream inputFile(argv[1]);

	if (inputFile.good()) {

		while (getline(inputFile, word)) {
			input.key = counter;
			input.value = word;

			linearHash1.insert(input);
			linearHash2.insert(input);
			doubleHash1.insert(input);
			doubleHash2.insert(input);
			universalHash1.insert(input);
			universalHash2.insert(input);

			wordList[word] = counter;
			counter++;
		}
	}
	else {
		cout << "FILE ERROR!" << endl;
		inputFile.close();
		return 1;
	}

	inputFile.close();
	inputFile.open(argv[2]);
	if (inputFile.good()) {
		while (getline(inputFile, word)) {
			keyToSearch = wordList.find(word)->second;
			linearHash1.search(keyToSearch);
			linearHash2.search(keyToSearch);
			doubleHash1.search(keyToSearch);
			doubleHash2.search(keyToSearch);
			universalHash1.search(keyToSearch);
			universalHash2.search(keyToSearch);	
		}
	}
	else {
		cout << "FILE ERROR!" << endl;
		inputFile.close();
		return 1;
	}

	cout << "---------------" << endl;
	cout << "For m = 17863: |" << endl;
	cout << "---------------" << endl << endl;
	cout << "Linear Insertion Collisions: " << linearHash1.insertCollisionCounter << endl;
	cout << "Linear Search Collisions: " << linearHash1.searchCollisionCounter << endl;
	cout << "Double Insertion Collisions: " << doubleHash1.insertCollisionCounter << endl;
	cout << "Double Search Collisions: " << doubleHash1.searchCollisionCounter << endl;
	cout << "Universal Insertion Collisions: " << universalHash1.insertCollisionCounter << endl;
	cout << "Universal Search Collisions: " << universalHash1.searchCollisionCounter << endl << endl;

	cout << "---------------" << endl;
	cout << "For m = 21929: |" << endl;
	cout << "---------------" << endl << endl;
	cout << "Linear Insertion Collisions: " << linearHash2.insertCollisionCounter << endl;
	cout << "Linear Search Collisions: " << linearHash2.searchCollisionCounter << endl;
	cout << "Double Insertion Collisions: " << doubleHash2.insertCollisionCounter << endl;
	cout << "Double Search Collisions: " << doubleHash2.searchCollisionCounter << endl;
	cout << "Universal Insertion Collisions: " << universalHash2.insertCollisionCounter << endl;
	cout << "Universal Search Collisions: " << universalHash2.searchCollisionCounter << endl << endl;


	inputFile.close();
	return 0;
}