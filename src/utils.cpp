#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <cstdlib>
#include "utils.h"
using namespace std;

// desplegar opciones
void displayOptions(string *options, int size) {
    int option;

    // mostrar opcion con su numero correspondiente
    for (option = 0; option < size; option++) {
        cout << option + 1 << ") " << options[option] << endl;
    }
}

// obtener numero
int getNumber(string label) {
    int number;

    do {
        // si fallo entrada
        if (cin.fail()) {
            cin.clear(); // manejar fallo de entrada
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignorar linea
            cout << "Entrada invalida\n" << endl;
        }

        cout << label;
        cin >> number;
    } while(cin.fail());

    return number;
}

// obtener opcion
int getOption(string label, int min, int max) {
    int option;

    do {
        option = getNumber(label);
    } while(option < min || option > max);

    return option;
}

// leer archivo
string readFile(string fileName) {
    // constructor de ifstream abre el archivo
    ifstream file(fileName, ios::in);

    // sale del programa si ifstream no pudo abrir el archivo
    if (file.fail()) {
        cerr << "No se pudo abrir el archivo" << endl;
        exit(EXIT_FAILURE);
    }

    // variables de estructura
    string content = "";
    string currentLine;

    // almacenar cada linea
    while(getline(file, currentLine)) content.append(currentLine);

    return content;
}
