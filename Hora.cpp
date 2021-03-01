//
// Created by Daniel Durán on 24/2/21.
//

#include "Hora.h"
#include "Error.h"

bool Hora::correctHora() const {
    bool correct = false;
    if (hora >= 0 && hora <= 23) {
        if (minuto>=0 && minuto<=59)
        {
            if (segundo >= 0 && segundo <= 59)
            {
                correct = true;
            }
        }
    }
    return correct;
}

Hora::Hora(int h, int m, int s) {
    hora = h;
    minuto=m;
    segundo=s;
    if (!correctHora()){
        throw Error("ERROR");
    }
}

Hora::Hora(const Hora &horacopia) {
    hora=horacopia.hora;
    minuto=horacopia.minuto;
    segundo=horacopia.segundo;
}

bool Hora::operator<(const Hora &hora2) const {
    if(hora<hora2.hora){
        return true;
    }else if(hora==hora2.hora){
        if(minuto<hora2.minuto){
            return true;
        }else if(minuto==hora2.minuto){
            if(segundo<hora2.segundo){
                return true;
            }
        }
    }
    return false;
}

bool Hora::operator<=(const Hora &hora2) const {
    if(hora<hora2.hora){
        return true;
    }else if(hora==hora2.hora){
        if(minuto<hora2.minuto){
            return true;
        }else if(minuto==hora2.minuto){
            if(segundo<=hora2.segundo){
                return true;
            }
        }
    }
    return false;
}

//void Hora::print() const {
//    std::cout << std::setfill('0') << std::setw(2) << hora << ":" << std::setfill('0') << std::setw(2) <<
//    minuto << ":" << std::setfill('0') << std::setw(2) << segundo << std::endl;
//}

Hora::Hora() = default;

Hora::Hora(const std::string& hora_raw){
    try{
        hora = stoi(hora_raw.substr(0, 2));
        minuto = stoi(hora_raw.substr(3, 2));
        segundo = stoi(hora_raw.substr(6, 2));
        if (!correctHora()) {
            throw Error("Invalid hour");
        }
    }catch (...){
        throw Error("Bad format");
    }


}

Hora Hora::operator+(const Hora &rhs) const{
    Hora suma = Hora();
    suma.hora = hora + rhs.hora;
    suma.minuto = minuto + rhs.minuto;
    suma.segundo = segundo + rhs.segundo;
    if(suma.segundo>=60){
        suma.minuto++;
        suma.segundo-=60;
    }
    if (suma.minuto>=60){
        suma.hora++;
        suma.minuto-=60;
    }
    if (suma.hora>23){
        throw Error("ERROR");
    }
    return suma;
}

std::ostream &operator<<(std::ostream &os, const Hora &hora) {
    os << std::setfill('0') << std::setw(2) << hora.hora << ":" << std::setfill('0') << std::setw(2) <<
       hora.minuto << ":" << std::setfill('0') << std::setw(2) << hora.segundo;
    return os;
}



