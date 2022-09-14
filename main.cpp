#include <iostream>
#include "Huffman.h"
using namespace std;

int main() {
    cout << "----- Codigo Huffman -----\n" << endl;

	Huffman huffman("a fast runner need never be afraid of the dark");

	huffman.displayFrequencies();
	cout << endl;

	huffman.displayTree();
	cout << endl;

    huffman.displayCodes();
    cout << endl;

    cout << huffman.encode() << "\n" << endl;
    cout << huffman.decode() << endl;

	return 0;
}
