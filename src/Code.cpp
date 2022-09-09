#include <string>
#include "Code.h"
using namespace std;

// constructor
Code::Code(char character, string code) {
    setCharacter(character);
    setCode(code);
}

// establecer caracter
void Code::setCharacter(char character) {
    this->character = character;
}

// obtener caracter
char Code::getCharacter() const {
    return character;
}

// establecer codigo
void Code::setCode(string code) {
    this->code = code;
}

// obtener codigo
string Code::getCode() const {
    return code;
}
