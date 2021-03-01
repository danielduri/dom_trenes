//
// Created by Daniel Durán on 1/3/21.
//

#ifndef DOM_TRENES_PELICULA_H
#define DOM_TRENES_PELICULA_H


#include <string>
#include <ostream>
#include "Hora.h"

class Pelicula {
private:
    std::string titulo;
    Hora finaliza;
public:

    bool operator<(const Pelicula &rhs) const;

    bool operator>(const Pelicula &rhs) const;

    bool operator<=(const Pelicula &rhs) const;

    bool operator>=(const Pelicula &rhs) const;

    friend std::ostream &operator<<(std::ostream &os, const Pelicula &pelicula);

    Pelicula(Hora const & inicio, Hora const & duracion, std::string const & titulodado);

    Pelicula();
};


#endif //DOM_TRENES_PELICULA_H
