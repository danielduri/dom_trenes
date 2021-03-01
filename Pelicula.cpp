//
// Created by Daniel Durán on 1/3/21.
//

#include "Pelicula.h"
#include "Error.h"

Pelicula::Pelicula(const Hora &inicio, const Hora &duracion, const std::string &titulodado) {
    try {
        finaliza = inicio + duracion;
    } catch (Error e) {
        throw Error("ERROR");
    }
    titulo=titulodado;
}

std::ostream &operator<<(std::ostream &os, const Pelicula &pelicula) {
    os << pelicula.finaliza << " " << pelicula.titulo << std::endl;
    return os;
}

bool Pelicula::operator<(const Pelicula &rhs) const {
    if (finaliza < rhs.finaliza)
        return true;
    if (rhs.finaliza < finaliza)
        return false;
    return titulo < rhs.titulo;
}

bool Pelicula::operator>(const Pelicula &rhs) const {
    return rhs < *this;
}

bool Pelicula::operator<=(const Pelicula &rhs) const {
    return !(rhs < *this);
}

bool Pelicula::operator>=(const Pelicula &rhs) const {
    return !(*this < rhs);
}

Pelicula::Pelicula() = default;
