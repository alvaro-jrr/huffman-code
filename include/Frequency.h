#ifndef FREQUENCY_H
#define FREQUENCY_H

// clase Frecuencia
class Frequency {
    private:
        char character; // caracter
        int frequency; // frecuencia

    public:
        // constructor
        Frequency(char, int);

        // establecer caracter
        void setCharacter(char);

        // obtener caracter
        char getCharacter() const;

        // establecer frecuencia
        void setFrequency(int);

        // obtener frecuencia
        int getFrequency() const;
};

#endif // FREQUENCY_H
