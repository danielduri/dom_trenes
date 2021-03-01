// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

#include "Hora.h"
#include "Pelicula.h"

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int n;
    std::cin >> n;
    std::vector<Pelicula> cartelera;

    // leer los datos de la entrada

    if (n == 0)
        return false;

    for (int i = 0; i < n; i++) {
        std::string hora_ini, dur, titulo;
        std::cin >> hora_ini >> dur;
        std::cin.ignore();
        std::getline(std::cin, titulo);
        try {
            Hora inicio = Hora(hora_ini);
            Hora duracion = Hora(dur);
            cartelera.push_back(Pelicula(inicio, duracion, titulo));
        } catch (...) {
            //std::cout << "ERROR" << std::endl;
        }

    }

    std::sort(cartelera.begin(), cartelera.end());

    for (int i = 0; i < cartelera.size(); i++) {
        std::cout << cartelera[i];
    }

    std::cout << "---" << std::endl;

    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
        std::ifstream in("datos.txt");
        auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
    #endif


    while (resuelveCaso())
        ;


    // Para restablecer entrada. Comentar para acepta el reto
    #ifndef DOMJUDGE // para dejar todo como estaba al principio
        std::cin.rdbuf(cinbuf);
        system("PAUSE");
    #endif

    return 0;
}
