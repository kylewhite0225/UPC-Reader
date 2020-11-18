#include "BST.h"
#include "UPC.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <chrono>
#include <regex>
#include <exception>
using namespace std;
using namespace std::chrono;

//Started code for Assignment5
//You are allowed to add, but not remove statements 

//..

BST<UPC> buildTree(ifstream *file) {
	BST<UPC> tree;
	string line;
	while (getline(*file, line)) {
		// Skip first line
		if (line == "UPC,Description") {
			continue;
		}
		stringstream ss(line);
		string code;
		string description;
		// While loop alternates between increasing and decreasing count
		// in order to switch between grabbing the UPC and the description.
		int count = 0;
		while (ss.good()) {
			string temp;
			if (count == 0) {
				getline(ss, temp, ',');
				code = temp;
				count++;
			} else if (count == 1) {
				getline(ss, temp);
				description = temp;
				count--;
			}
		}
		long long upcCode = stoll(code);
		UPC upc(upcCode, description);
		tree.insert(upc);
	}
	return tree;
}

void performSearchBST(BST<UPC> tree, UPC key) {
	auto start = high_resolution_clock::now();
	UPC found = tree.search(key);
	if (found.getDescription() == "") {
		cout << "Not found." << endl;
	}
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<milliseconds>(stop - start);
	cout << found.getDescription() << endl;
	cout << "Lookup time: " << duration.count() << " milliseconds." << endl;
}

int main() {
    //...
	ifstream *file = new ifstream();
    bool fileValid = false;
	string fileName;
	do {
		try {

			cout << "Enter file name: ";
			cin >> fileName;
			file->open(fileName);
			if (!file->is_open()) { // || !fileName.find(".csv")) {
				throw out_of_range("Invalid file, or file not found.\n");
			} else {
				fileValid = true;
			}
		} catch (exception out_of_range) {
			cout << "Invalid file, or file not found.\n" << endl;
		}
	} while (fileValid == false);
	
	BST<UPC> tree = buildTree(file);  //build binary search tree of UPC objects

	string code;
	bool validUPC = false;
	// Do-while loop uses a regex to verify user input matches the correct format of a 12 digit UPC.
	do {
		cout << "Please enter a UPC code(! to quit): ";
		cin >> code;
		validUPC = (code.length() == 12 && regex_match(code, regex("^[0-9]+$"))) || code == "!";
		if (validUPC == false) {
			cout << "UPC must be a 12 digit number." << endl;
		}
	} while (validUPC == false);
	while (code != "!") {
        long long entry = stoll(code); //convert user inputted string to type long long int
		UPC key(entry);
		performSearchBST(tree, key);	
		// Do-while loop uses a regex to verify user input matches the correct format of a 12 digit UPC.
		do {
			cout << "\nPlease enter a UPC code(! to quit): ";
			cin >> code;
			validUPC = (code.length() == 12 && regex_match(code, regex("^[0-9]+$"))) || code == "!";
			if (validUPC == false) {
				cout << "UPC must be a 12 digit number." << endl;
			}
		} while (validUPC == false);
	}
	return 0;
} 
