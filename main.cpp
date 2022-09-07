#include <iostream>
#include <vector>
#include "Huffman.h"
#include "Frequency.h"
using namespace std;

int main() {
	string compressTarget = "a fast runner need never be afraid of the dark";

	Huffman huffman(compressTarget);
	huffman.displayFrequencies();

	return 0;
}
