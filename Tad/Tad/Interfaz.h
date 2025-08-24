#pragma once
#include <iostream>
#include "TAD.h"
class Interfaz
{
    public: void menu() {
        TAD tadA;
        TAD tadB;
        int valor1;
        short opcion = 0;

        do {
            system("cls");
            valor1 = 0;
            cout << "1)Alta" << endl;
            cout << "2)Baja" << endl;
            cout << "3)Buscar Elemento del conjunto a" << endl;
            cout << "4)Guardar Elementos del conjunto a" << endl;
            cout << "5)Mostrar Elementos conjunto A" << endl;
            cout << "6)Mostrar Elementos conjunto B" << endl;
            cout << "7)Alta conunto B" << endl;
            cout << "8)Operaciones de conjuntos entre a y B" << endl;
            cout << "0)Sair" << endl;
            cout << "Seleccione una opcion:";
            cin >> opcion;

            switch (opcion) {
            case 1:
                cout << "Introduzca el valor:";
                cin >> valor1;
                tadA.Alta(valor1);
                system("pause");
                break;

            case 2:
                cout << "Introduzca la posicion";
                cin >> valor1;
                tadA.eliminar(valor1);
                system("pause");
                break;

            case 3:
                cout << "Introduzca el valor a buscar:";
                cin >> valor1;
                tadA.buscar(valor1);
                system("pause");
                break;
            case 4:
                tadA.guardarDatos();
                break;
            case 5:
                tadA.mostrar();
                system("pause");
                break;
            case 6:
                cout << "Conjunto B ";
                tadB.mostrar();
                system("Pause");
                break;
            case 7:
                cout << "Introduzca el valor (conjuntoB)";
                cin >> valor1;
                tadB.Alta(valor1);
                system("Pause");
                break;
            case 8:
                cout << endl;
                cout << "----------------Operaciones de conjuntos----------" << endl;

                cout << "Union (Inluye elementos duplicados)";
                tadA.Union(tadB).mostrar();

                cout << "Union Distinct: ";
                tadA.unionDistinct(tadB).mostrar();

                cout << "Interseccion: ";
                tadA.interseccion(tadB).mostrar();

                cout << "Diferencia conju(A) y conjun(B): ";
                tadA.Diferencia(tadB).mostrar();
                system("pause");
                system("cls");
                break;
            }

        } while (opcion != 0);
	}
};

