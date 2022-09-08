#ifndef FREQUENCY_H
#define FREQUENCY_H

// clase Frecuencia
class Frequency {
    private:
        char character; // caracter
        int frequency; // frecuencia

    public:
        // constructor sin parametros
        Frequency();

        // constructor con parametros
        Frequency(char, int = 0);

        // establecer caracter
        void setCharacter(char);

        // obtener caracter
        char getCharacter() const;

        // establecer frecuencia
        void setFrequency(int);

        // incrementar frecuencia
        void incrementFrequency();

        // obtener frecuencia
        int getFrequency() const;
};

#endif // FREQUENCY_H
