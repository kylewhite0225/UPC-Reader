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

/*
Name: app.cpp
Author: Kyle White
Date: 11/20/2020
Description: The provided and modified main function which tests the 
BST and UPC classes, as well as the buildTree and performSearchBST functions
defined in this file.
*/

// The buildTree functiona accepts a pointer to an ifstream object which is 
// initiated in the main function, and returns a BST<UPC>. It uses the getline method to 
// capture each line of the CSV file using a stringstream object and while loops.

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
		// in order to switch between grabbing the UPC (first column of CSV) 
		// and the description (second column of CSV).
		int count = 0;
		while (ss.good()) {
			string temp;
			if (count == 0) {
				// Comma delimited to grab just the first column
				getline(ss, temp, ',');
				code = temp;
				count++;
			} else if (count == 1) {
				// \n character delimited to grab just the second column.
				// Cannot use comma delimiting because of commas present in product descriptions.
				getline(ss, temp);
				description = temp;
				count--;
			}
		}
		// Convert upcCode into a long long data type and store the code and description
		// in a UPC object, then use the BST class's insert method to add it to the tree.
		long long upcCode = stoll(code);
		UPC upc(upcCode, description);
		tree.insert(upc);
	}
	return tree;
}

// The performSearchBST method accepts a BST<UPC> object and UPC object,
// and uses methods from the chrono library to time the search. It prints
// the results to the console.

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
    // Create new ifstream object in heap.
	ifstream *file = new ifstream();
    // Boolean value to run do-while loop for opening the file.
	bool fileValid = false;
	string fileName;
	do {
		try {
			cout << "Enter file name: ";
			cin >> fileName;
			file->open(fileName);
			// If the file is not open OR the file name does not include .csv.
			// string.find() method returns the index of the located substring
			// or string::npos if not found.
			if (!file->is_open() || fileName.find(".csv") == string::npos) {
				throw out_of_range("Invalid file, or file not found.\n");
			} else {
				fileValid = true;
			}
		} catch (exception out_of_range) {
			cout << "Invalid file, or file not found.\n" << endl;
		}
	} while (fileValid == false);
	
	// Build binary search tree of UPC objects
	BST<UPC> tree = buildTree(file);  
	string code;
	bool validUPC = false;
	// Do-while loop uses a regex to verify user input matches the correct format of a 12 digit UPC.
	do {
		cout << "Please enter a UPC code(! to quit): ";
		cin >> code;
		// Set boolean validUPC to the result of expression to check code length
		// and each character matches integers 0-9.
		validUPC = (code.length() == 12 && regex_match(code, regex("^[0-9]+$"))) || code == "!";
		if (validUPC == false) {
			cout << "UPC must be a 12 digit number." << endl;
		}
	} while (validUPC == false);
	while (code != "!") {
		// Convert user input string to type long long int
        long long entry = stoll(code); 
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
