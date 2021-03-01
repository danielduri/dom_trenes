//
// Created by Daniel Durán on 24/2/21.
//

#ifndef DOM_TRENES_HORA_H
#define DOM_TRENES_HORA_H

#include <string>
#include <iomanip>
#include <iostream>

class Hora{
private:
    int hora{};
    int minuto{};
    int segundo{};
    bool correctHora() const;

public:
    Hora(int h, int m, int s);
    Hora(Hora const &horacopia);
    explicit Hora(const std::string& hora_raw);
    bool operator <(Hora const &hora2) const;
    bool operator <=(Hora const &hora2) const;
    void print() const;

    Hora();

    friend std::ostream &operator<<(std::ostream &os, const Hora &hora);
};

#endif //DOM_TRENES_HORA_H
