#include <iostream>
#include <string>
#include "utils.h"
#include "Huffman.h"
using namespace std;

int main() {
	// opciones del programa
	string options[] = {
		"Comprimir Archivo",
		"Salir"
	};

	int optionsLength = 2;

	// control del programa
	bool shouldContinue = true;

	do {
		cout << "----- Codigo Huffman -----\n" << endl;

		// mostrar opciones
		displayOptions(options, optionsLength);
		cout << endl;

		// pedir y leer opcion
		int option = getOption("Opcion: ", 1, optionsLength);
		cout << endl;

		switch(option) {
            case 1: {
                cin.ignore();

                // pedir y leer nombre de archivo
                cout << "Nombre de Archivo: ";
                string fileName;
                getline(cin, fileName);
                cout << endl;

                // obtener contenido
                string content = readFile(fileName);

                // construir arbol de huffman
                Huffman huffman(content);

                cout << "# Tabla de Frecuencias\n" << endl;
                huffman.displayFrequencies();
                cout << endl;

                cout << "# Arbol de Huffman\n" << endl;
                huffman.displayTree();
                cout << endl;

                cout << "# Tabla de Codigos\n" << endl;
                huffman.displayCodes();
                cout << endl;
                break;
            }

            case 2:
                shouldContinue = false;
                break;

            default:
                cout << "Opcion invalida" << endl;
		}

		cout << endl;
	} while(shouldContinue);

	return 0;
}
