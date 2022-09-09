#ifndef CODE_H
#define CODE_H

#include <string>

// clase Codigo
class Code {
	private:
        char character; // caracter
        std::string code; // codigo

	public:
        // constructor
		Code(char, std::string);

        // establecer caracter
        void setCharacter(char);

        // obtener caracter
        char getCharacter() const;

        // establecer codigo
        void setCode(std::string);

        // obtener codigo
        std::string getCode() const;
};

#endif // CODE_H
