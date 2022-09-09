#include <iostream>
#include "Huffman.h"
using namespace std;

int main() {
	Huffman huffman("a fast runner need never be afraid of the dark");

    cout << "----- Codigo Huffman -----\n" << endl;

	huffman.displayFrequencyTable();
	cout << endl;

	huffman.displayTree();
	cout << endl;

    huffman.displayCodeTable();
    cout << endl;

	return 0;
}
