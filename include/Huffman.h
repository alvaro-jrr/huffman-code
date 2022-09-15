#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <vector>
#include "Code.h"
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
            Node(
                char data,
                int key,
                Node *left = nullptr,
                Node *right = nullptr
            ) {
                this->data = data;
                this->key = key;
                this->left = left;
                this->right = right;
            }

            // constructor a partir de otro nodo
            Node(const Node &node) {
                this->data = node.data;
                this->key = node.key;
                left = node.left;
                right = node.right;
            }
        };

        // Constantes
        static const int COLUMN_INDENT = 10; // sangria de columnas
        static const char FATHER_ID = '*'; // identificador de nodo padre

        // Atributos
        Node *root; // raiz del arbol
        std::vector<Frequency> frequencies; // frecuencias
        std::vector<Code> codes; // codigos
        std::string encoded; // texto codificado

        // generar vector de frecuencias
        std::vector<Frequency> generateFrequencies(std::string);

        // ordenamiento de shell para frecuencias
        std::vector<Frequency> shellSort(std::vector<Frequency>);

        // construir arbol
        void buildTree();

        // construir codigos
        void buildCodes();

        // construir codigos
        void buildCodes(Node *, std::string);

        // obtener codigo de un caracter
        std::string codeOf(char) const;

        // codificar texto
        std::string encode(std::string) const;

        // mostrar arbol
        void displayTree(Node *, int) const;

    public:
        // constructor a partir de una cadena
        Huffman(std::string);

        // constructor a partir de frecuencias
        Huffman(std::vector<Frequency>);

        // constructor a partir de otro arbol de Huffman
        Huffman(const Huffman &);

        // codificar texto
        std::string encode() const;

        // decodificar texto
        std::string decode() const;

        // obtener frecuencias
        std::vector<Frequency> getFrequencies() const;

        // obtener codigos
        std::vector<Code> getCodes() const;

        // mostrar frecuencias
        void displayFrequencies() const;

        // mostrar codigos
        void displayCodes() const;

        // mostrar arbol
        void displayTree() const;
};

#endif // HUFFMAN_H
