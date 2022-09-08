#include <iostream>
#include <iomanip>
#include <vector>
#include "Frequency.h"
#include "Huffman.h"
using namespace std;

// constructor
Huffman::Huffman(string str) {
	// establecer frecuencias
	setFrequencies(generateFrequencyTable(str));

	// construir arbol
	buildTree();
}

// constructor
Huffman::Huffman(vector<Frequency> frequencies) {
    // establecer frecuencias
    setFrequencies(frequencies);

    // construir arbol
    buildTree();
}

// generar vector de frecuencias
vector<Frequency> Huffman::generateFrequencyTable(string str) {
	vector<Frequency> frequencies;

	// recorrer cada caracter de la cadena
	for (char currentChar : str) {
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

// ordenamiento de shell para nodos
void Huffman::shellSort(vector<Node> &nodes) {
    int size = nodes.size();

	// ordenar frecuencias
	for (int gap = size / 2; gap > 0; gap /= 2) {
		// dividir en grupos
		for (int i = gap; i < size; i++) {
			// ordenar grupos
			for (
			    int j = i - gap;
			    j >= 0 && nodes[j + gap].key < nodes[j].key;
			    j -= gap
			) {
				// intercambiar posiciones
				Node temp = nodes[j];
				nodes[j] = nodes[j + gap];
				nodes[j + gap] = temp;
			}
		}
	}
}

// construir arbol
void Huffman::buildTree() {
	vector<Node> nodes;

    // crear vector de nodos para cada frecuencia
	for (Frequency frequency : frequencies) {
        // insertar nodo creado a partir de la frecuencia
		nodes.push_back(Node(
			frequency.getCharacter(),
            frequency.getFrequency()
		));
	}

	// crear arbol
	while(nodes.size() > 1) {
        Node subtree;
        Node *leftSubtree;
        Node *rightSubtree;

        // obtener minimos (subarbol izquierdo y derecho)
        leftSubtree = new Node(nodes.front());
        nodes.erase(nodes.begin());

        rightSubtree = new Node(nodes.front());
        nodes.erase(nodes.begin());

        // crear subarbol a partir de subarbol izq. y der.
        subtree.data = '*';
        subtree.key = leftSubtree->key + rightSubtree->key;
        subtree.left = leftSubtree;
        subtree.right = rightSubtree;

        // insertar a vector y reordenar
        nodes.push_back(subtree);
        shellSort(nodes);
	}

    // asignar a raiz del arbol
    root = new Node(nodes.front());
}

// mostrar tabla de codigos
void Huffman::displayCodeTableAux(Node *root, string str) const {
    // si esta vacio
    if (!root) return;

    // si no es raiz
    if (root->data != '*') {
        cout << setw(COLUMN_INDENT) << root->data << str << endl;
    }

    displayCodeTableAux(root->left, str + "0");
    displayCodeTableAux(root->right, str + "1");
}

// mostrar arbol
void Huffman::displayTreeAux(Node *root, int indent) const {
    if (root) {
        // graficar siguiente nivel derecho
        displayTreeAux(root->right, indent + 8);

        // mostrar elemento
        cout << setw(indent) << " " << root->key << " [" << root->data << "]" << endl;

        // graficar siguiente nivel izquierdo
        displayTreeAux(root->left, indent + 8);
    }
}

// establecer frecuencias
void Huffman::setFrequencies(vector<Frequency> frequencies) {
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
void Huffman::displayFrequencyTable() const {
	// mostrar cabecera
	cout << left << setw(COLUMN_INDENT) << "Caracter" << "Frecuencia" << endl;

	// mostrar cada frecuencia
	for (Frequency frequency : frequencies) {
		cout << setw(COLUMN_INDENT) << frequency.getCharacter()
		     << frequency.getFrequency() << endl;
	}
}

// mostrar codigos
void Huffman::displayCodeTable() const {
    // mostrar cabecera
	cout << left << setw(COLUMN_INDENT) << "Caracter" << "Codigo" << endl;

    displayCodeTableAux(root, "");
}

// mostrar arbol
void Huffman::displayTree() const {
    displayTreeAux(root, 0);
}
