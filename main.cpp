// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include "Hora.h"

bool resolver(std::vector<Hora> & horario, Hora & actual, int c, int f, Hora & solucion) {
    if (c==f-1)
    {
        if (actual <= horario[c]) {
            solucion = horario[c];
            return true;
        }
        else {
            return false;
        }
    }
    int m = (c + f) / 2;
    if (actual <= horario[m]) {
        if (actual <= horario[m-1]) {
            return resolver(horario, actual, c, m, solucion);
        }
        else {
            solucion = horario[m];
            return true;
        }
    }
    else {
        return resolver(horario, actual, m, f, solucion);
    }
}



// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int n, check;
    std::cin >> n >> check;
    std::vector<Hora> horario(n);

    // leer los datos de la entrada

    if (n == 0)
        return false;

    for (int i = 0; i < n; i++) {
        std::string hora_raw;
        std::cin >> hora_raw;
        horario[i]=Hora(hora_raw);
    }

    for (int i = 0; i < check; i++) {
        std::string hora_raw;
        std::cin >> hora_raw;
        try
        {
            Hora actual = Hora(hora_raw), solucion;

            bool encontrado = resolver(horario, actual, 0, horario.size(), solucion);

            if (encontrado) {
                solucion.print();
            }
            else {
                std::cout << "NO" << std::endl;
            }
        }
        catch (...)
        {
            std::cout << "ERROR" << std::endl;
        }
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
