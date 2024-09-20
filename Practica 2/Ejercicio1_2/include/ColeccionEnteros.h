#ifndef COLECCIONENTEROS_H
#define COLECCIONENTEROS_H


class ColeccionEnteros
{
    private:
        unsigned int reservado;
        unsigned int utilizado;
        const unsigned int tamanoReserva = 5;
        const unsigned int maximoDesperdicio = 6;
        int * valores;
    public:
        ColeccionEnteros();
        ~ColeccionEnteros();

        unsigned int getReservado() { return this->reservado ;}
        unsigned int getUtilizado() { return this->utilizado ;}
        unsigned int getTamanoReserva() { return this->tamanoReserva ;}
        unsigned int getMaximoDesperdicio() { return this->maximoDesperdicio ;}

        bool agregarInicio(int unValor);
        bool agregarFinal(int unValor);
        bool eliminarPrimero(int unValor);
        bool eliminarUltimo(int unValor);
        unsigned int eliminarTodos(int unValor);
        unsigned int cantidadValores();
        int operator[] (unsigned int i);
    private:
        void redimensionar();

};

#endif // COLECCIONENTEROS_H
