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
            Node *left; // subarbol a la izquierda
            Node *right; // subarbol a la derecha

            // constructor por defecto
            Node() : left(nullptr), right(nullptr) { }

            // constructor con parametros
            Node(char item) : data(item), left(nullptr), right(nullptr) { }
        };

        Node *root; // raiz del arbol
        std::vector<Frequency> frequencies; // frecuencias

        // generar vector de frecuencias
        std::vector<Frequency> generateFrequencyTable(std::string);

        // ordenamiento de shell para frecuencias
        void shellSort(std::vector<Frequency> &);

    public:
        // constructor
        Huffman(std::string);

        // establecer frecuencias
        void setFrequencies(std::vector<Frequency>);

        // obtener frecuencias
        std::vector<Frequency> getFrequencies() const;

        // mostrar tabla de frecuencias
        void displayFrequencies() const;
};

#endif // HUFFMAN_H
