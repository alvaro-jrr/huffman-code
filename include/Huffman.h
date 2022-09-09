#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <vector>
#include "Frequency.h"
#include "Code.h"

// clase Huffman
class Huffman {
    private:
        // estructura Nodo
        struct Node {
            char data; // dato a almacenar
            int key; // clave
            Node *left; // subarbol a la izquierda
            Node *right; // subarbol a la derecha

            // constructor por defecto
            Node() : left(nullptr), right(nullptr) { }

            // constructor con parametros
            Node(char data, int key) {
                this->data = data;
                this->key = key;
                left = right = nullptr;
            }

            // constructor a partir de otro nodo
            Node(const Node &node) {
                this->data = node.data;
                this->key = node.key;
                left = node.left;
                right = node.right;
            }
        };

        // Estructuras
        Node *root; // raiz del arbol
        std::vector<Frequency> frequencies; // frecuencias
        std::vector<Code> codes; // codigos

        // Constantes
        static const int COLUMN_INDENT = 10; // sangria de columnas
        static const char FATHER_ID = '*'; // identificador de nodo padre

        // generar vector de frecuencias
        std::vector<Frequency> generateFrequencyTable(std::string);

        // ordenamiento de shell para frecuencias
        void shellSort(std::vector<Frequency> &);

        // ordenamiento de shell para nodos
        void shellSort(std::vector<Node> &);

        // construir arbol
        void buildTree();

        // construir codigos
        void buildCodes();

        // construir codigos
        void buildCodes(Node *, std::string);

        // mostrar arbol
        void displayTree(Node *, int) const;

    public:
        // constructor
        Huffman(std::string);

        // constructor
        Huffman(std::vector<Frequency>);

        // establecer frecuencias
        void setFrequencies(std::vector<Frequency>);

        // obtener frecuencias
        std::vector<Frequency> getFrequencies() const;

        // mostrar tabla de frecuencias
        void displayFrequencyTable() const;

        // mostrar tabla de codigos
        void displayCodeTable() const;

        // mostrar arbol
        void displayTree() const;
};

#endif // HUFFMAN_H