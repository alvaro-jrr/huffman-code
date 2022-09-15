#include <iostream>
#include <string>
#include "Huffman.h"
using namespace std;

int main() {
    cout << "----- Codigo Huffman -----\n" << endl;

    cout << "Texto a Comprimir: ";
    string text;
    getline(cin, text);

    // construir arbol de huffman
    Huffman huffman(text);

    cout << "# Tabla de Frecuencias\n" << endl;
    huffman.displayFrequencies();
    cout << endl;

    cout << "# Arbol de Huffman\n" << endl;
    huffman.displayTree();
    cout << endl;

    cout << "# Tabla de Codigos\n" << endl;
    huffman.displayCodes();
    cout << endl;

	return 0;
}
