#include "Frequency.h"

// constructor
Frequency::Frequency(char character, int frequency) {
    setCharacter(character);
    setFrequency(frequency);
}

// establecer caracter
void Frequency::setCharacter(char character) {
    this->character = character;
}

// obtener caracter
char Frequency::getCharacter() const {
    return character;
}

// establecer frecuencia
void Frequency::setFrequency(int frequency) {
    if (frequency >= 0) {
        this->frequency = frequency;
    }
}

// obtener frecuencia
int Frequency::getFrequency() const {
    return frequency;
}
