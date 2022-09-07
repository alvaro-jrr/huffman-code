#include <iostream>
#include <iomanip>
#include <vector>
#include "Frequency.h"
#include "Huffman.h"
using namespace std;

// constructor
Huffman::Huffman(string target) {
    // crear y establecer tabla de frecuencias
    vector<Frequency> frequencies = generateFrequencyTable(target);
    setFrequencies(frequencies);
}

// generar vector de frecuencias
vector<Frequency> Huffman::generateFrequencyTable(string target) {
    vector<Frequency> frequencies;

    // recorrer cada caracter de la cadena
    for (char currentChar : target) {
        int charIndex = 0;
        bool found = false;

        // buscar si se encuentra en el vector
        for (Frequency frequency : frequencies) {
            if (frequency.getCharacter() == currentChar) {
                found = true;
                break;
            }

            charIndex++;
        }

        if (found) {
            // aumentar frecuencia
            int prevFrequency = frequencies.at(charIndex).getFrequency();
            frequencies[charIndex].setFrequency(prevFrequency + 1);
        } else {
            // agregar nueva frecuencia
            Frequency newFrequency(currentChar, 1);
            frequencies.push_back(newFrequency);
        }
    }

    return frequencies;
}

// ordenamiento de shell para frecuencias
void Huffman::shellSort(vector<Frequency> &frequencies) {
	int size = frequencies.size();

	// ordenar frecuencias
	for (int gap = size / 2; gap > 0; gap /= 2) {
		// dividir en grupos
		for (int i = gap; i < size; i++) {
			// ordenar grupos
			for (
			    int j = i - gap;
			    j >= 0 && frequencies[j + gap].getFrequency() < frequencies[j].getFrequency();
			    j -= gap
			) {
				// intercambiar posiciones
				Frequency temp = frequencies[j];
				frequencies[j] = frequencies[j + gap];
				frequencies[j + gap] = temp;
			}
		}
	}
}

// establecer frecuencias
void Huffman::setFrequencies(std::vector<Frequency> frequencies) {
	// ordenar por frecuencia de caracteres
	shellSort(frequencies);

	// establecer frecuencias
	this->frequencies = frequencies;
}

// obtener frecuencias
vector<Frequency> Huffman::getFrequencies() const {
    return frequencies;
}

// mostrar tabla de frecuencias
void Huffman::displayFrequencies() const {
	int indent = 12;

	// mostrar cabecera
	cout << left << setw(indent) << "Caracter" << "Frecuencia" << endl;

	// mostrar cada frecuencia
	for (Frequency frequency : frequencies) {
		cout << setw(indent) << frequency.getCharacter()
		     << frequency.getFrequency() << endl;
	}
}
