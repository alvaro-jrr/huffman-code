#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <vector>
#include "Frequency.h"

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

        Node *root; // raiz del arbol
        std::vector<Frequency> frequencies; // frecuencias
        static const int COLUMN_INDENT = 10; // sangria de tabla

        // generar vector de frecuencias
        std::vector<Frequency> generateFrequencyTable(std::string);

        // ordenamiento de shell para frecuencias
        void shellSort(std::vector<Frequency> &);

        // ordenamiento de shell para nodos
        void shellSort(std::vector<Node> &);

        // construir arbol
        void buildTree();

        // mostrar tabla de codigos
        void displayCodeTableAux(Node *, std::string) const;

        // mostrar arbol
        void displayTreeAux(Node *, int) const;

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
