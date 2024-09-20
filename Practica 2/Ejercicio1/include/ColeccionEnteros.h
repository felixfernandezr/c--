#ifndef COLECCIONENTEROS_H
#define COLECCIONENTEROS_H


class ColeccionEnteros
{
    private:
        unsigned int reservado;
        unsigned int utilizado;
        const unsigned int tamanioReserva = 5;
        const unsigned int maximoDesperdicio = 8;
        int * valores;

    public:
        ColeccionEnteros();
        ~ColeccionEnteros();

        unsigned int getReservado() { return this -> reservado ;}
        unsigned int getUtilizado() { return this -> utilizado ;}
        unsigned int getTamanioReserva() { return this -> tamanioReserva ;}
        unsigned int getMaximoDesperdicio() { return this -> maximoDesperdicio ;}

        bool agregarInicio(int);
        bool agregarFinal(int);
        bool eliminarPrimero(int);
        bool eliminarUltimo(int);
        unsigned int eliminarTodos(int);
        unsigned int cantidadvalores(int);
        int operator [] (unsigned int);

    private:
        void redimensionar();
};

#endif // COLECCIONENTEROS_H
