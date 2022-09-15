#include <iostream>
#include <iomanip>
#include <vector>
#include "Code.h"
#include "Frequency.h"
#include "Huffman.h"
#include "PriorityQueue.h"
using namespace std;

// constructor a partir de una cadena
Huffman::Huffman(string text) {
	// generar y establecer frecuencias
    frequencies = shellSort(generateFrequencies(text));

	// construir arbol
	buildTree();

	// construir codigos
	buildCodes();

	// establecer texto codificado
	encoded = encode(text);
}

// constructor a partir de frecuencias
Huffman::Huffman(vector<Frequency> frequencies) {
	// establecer frecuencias
	this->frequencies = shellSort(frequencies);

	// construir arbol
	buildTree();

	// construir codigos
	buildCodes();

	// establecer cadena vacia como texto codificado (no se tiene texto original)
	encoded = "";
}

// constructor a partir de otro arbol de Huffman
Huffman::Huffman(const Huffman &otherHuffman) {
    // establecer atributos
    frequencies = otherHuffman.getFrequencies();
    codes = otherHuffman.getCodes();
    encoded = otherHuffman.encode();

    // construir arbol
    buildTree();
}

// generar vector de frecuencias
vector<Frequency> Huffman::generateFrequencies(string text) {
	vector<Frequency> frequencies;

	// recorrer cada caracter del texto
	for (char currentChar : text) {
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
			frequencies.at(charIndex).incrementFrequency();
		} else {
			// agregar nueva frecuencia
			frequencies.push_back(Frequency(currentChar, 1));
		}
	}

	return frequencies;
}

// ordenamiento de shell para frecuencias
vector<Frequency> Huffman::shellSort(vector<Frequency> frequencies) {
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

	return frequencies;
}

// construir arbol
void Huffman::buildTree() {
    PriorityQueue<Node> priorityQueue;

	// crear vector de nodos para cada frecuencia
	for (Frequency frequency : frequencies) {
        Node newNode(frequency.getCharacter(), frequency.getFrequency());
        int priority = frequency.getFrequency();

        // insertar en cola de prioridad
        priorityQueue.insert(newNode, priority);
	}

	// crear arbol
	while(priorityQueue.getLength() > 1) {
        // obtener minimos
        Node left = priorityQueue.min();
        priorityQueue.removeMin();

        Node right = priorityQueue.min();
        priorityQueue.removeMin();

        // crear subarbol a partir de minimos
        int subtreeKey = left.key + right.key;

        Node subtree(
            FATHER_ID,
            subtreeKey,
            new Node(left),
            new Node(right)
        );

        // agregar subarbol a cola de prioridad
        priorityQueue.insert(subtree, subtreeKey);
	}

	// asignar a raiz del arbol
	root = new Node(priorityQueue.min());
	priorityQueue.removeMin();
}

// construir codigos
void Huffman::buildCodes() {
	buildCodes(root, "");
}

// construir codigos
void Huffman::buildCodes(Node *root, string code) {
	// si esta vacio
	if (!root) return;

	// si no es padre agregar codigo
	if (root->data != FATHER_ID) codes.push_back(Code(root->data, code));

	buildCodes(root->left, code + "0");
	buildCodes(root->right, code + "1");
}

// obtener codigo de un caracter
string Huffman::codeOf(char character) const {
    // buscar en tabla de codigos
    for (Code code : codes) {
        if (code.getCharacter() == character) {
            return code.getCode();
        }
    }

    return "";
}

// devolver texto codificado
string Huffman::encode(string text) const {
    string encoded = "";

    for (char character : text) {
        encoded.append(codeOf(character));
    }

    return encoded;
}

// mostrar arbol
void Huffman::displayTree(Node *root, int indent) const {
	if (root) {
		// graficar siguiente nivel derecho
		displayTree(root->right, indent + 8);

		// mostrar elemento
		cout << setw(indent) << " " << root->key << " [" << root->data << "]" << endl;

		// graficar siguiente nivel izquierdo
		displayTree(root->left, indent + 8);
	}
}

// obtener texto codificado
string Huffman::encode() const {
	return encoded;
}

// decodificar texto
string Huffman::decode() const {
    string decoded = "";
    Node *currentRoot = root;

    // recorrer cada caracter de cadena codificada
    for (char character : encoded) {
        // determinar subarbol
        if (character == '0') {
            currentRoot = currentRoot->left;
        } else {
            currentRoot = currentRoot->right;
        }

        // agregar caracter si es nodo terminal
        if (!currentRoot->left && !currentRoot->right) {
            decoded += currentRoot->data;
            currentRoot = root;
        }
    }

    return decoded;
}

// obtener frecuencias
vector<Frequency> Huffman::getFrequencies() const {
	return frequencies;
}

// obtener codigos
vector<Code> Huffman::getCodes() const {
	return codes;
}

// mostrar tabla de frecuencias
void Huffman::displayFrequencies() const {
	// mostrar cabecera
	cout << left << setw(COLUMN_INDENT) << "Caracter" << "Frecuencia" << endl;

	// mostrar cada frecuencia
	for (Frequency frequency : frequencies) {
		cout << setw(COLUMN_INDENT) << frequency.getCharacter()
		     << frequency.getFrequency() << endl;
	}
}

// mostrar codigos
void Huffman::displayCodes() const {
	// mostrar cabecera
	cout << left << setw(COLUMN_INDENT) << "Caracter" << "Codigo" << endl;

	// mostrar cada codigo
	for (Code code : codes) {
		cout << setw(COLUMN_INDENT) << code.getCharacter()
		     << code.getCode() << endl;
	}
}

// mostrar arbol
void Huffman::displayTree() const {
	displayTree(root, 0);
}
