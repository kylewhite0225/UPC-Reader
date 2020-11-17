#include "BST.h"
#include "UPC.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <time.h>
#include <chrono>
using namespace std;
using namespace std::chrono;

//Started code for Assignment5
//You are allowed to add, but not remove statements 

//..

BST<UPC> buildTree(ifstream *file) {
	BST<UPC> tree;
	string line;
	while (getline(*file, line)) {
		if (line == "UPC,Description") {
			continue;
		}
		stringstream ss(line);
		string code;
		string description;
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
	clock_t t;
	t = clock();
	auto start = high_resolution_clock::now();
	UPC found = tree.search(key);
	if (found.getDescription() == "") {
		cout << "Not found." << endl;
	}
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<nanoseconds>(stop - start);
	t = clock() - t;
	cout << found.getDescription() << endl;
	cout << "Lookup time: " << duration.count() << " milliseconds." << endl;
}

int main() {
    //...
	ifstream *file = new ifstream();
    file->open("grocery_upc_database.csv");
	BST<UPC> tree = buildTree(file);  //build binary search tree of UPC objects

	string code;
	cout << "Please enter a UPC code(! to quit): ";
	cin >> code;
	while (code != "!") {
		
        long long entry = stoll(code); //convert user inputted string to type long long int
		UPC key(entry);
		performSearchBST(tree, key);	
		
		cout << "\nPlease enter a UPC code(! to quit): ";
		cin >> code;
	}

	return 0;
} 
