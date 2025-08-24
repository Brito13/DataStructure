#include <iostream>

#include <fstream>
#include <string>
#pragma once

using namespace std;

class TAD {
public:
    int* datos;
    int cantidadElementos;
    int capacidadArreglo;
    string nombreArchivo = "Datos";

    void cambioTam() {
        capacidadArreglo *= 2;
        int* nuevoTam = new int[capacidadArreglo];
        for (int i = 0; i < cantidadElementos; ++i) {
            nuevoTam[i] = datos[i];
        }
        delete[] datos;
        datos = nuevoTam;
    }

public:
    // Constructor
    TAD() {
        cantidadElementos = 0;
        capacidadArreglo = 2;
        datos = new int[capacidadArreglo];
        cargarDesdeArchivo();
    }

    TAD(const TAD& otro) {
        cantidadElementos = otro.cantidadElementos;
        capacidadArreglo = otro.capacidadArreglo;
        datos = new int[capacidadArreglo];
        for (int i = 0; i < cantidadElementos; i++)
            datos[i] = otro.datos[i];
    }

    // Operador de asignación
    TAD& operator=(const TAD& otro) {
        if (this != &otro) {
            delete[] datos;
            capacidadArreglo = otro.capacidadArreglo;
            cantidadElementos = otro.cantidadElementos;
            datos = new int[capacidadArreglo];
            for (int i = 0; i < cantidadElementos; i++)
                datos[i] = otro.datos[i];
        }
        return *this;
    }



    // Destructor
    ~TAD() {
        delete[] datos;
    }

    void Alta(int valor) {
        if (cantidadElementos == capacidadArreglo) {
            cambioTam();
        }
        datos[cantidadElementos++] = valor;
    }

    void mostrar() const {
        for (int i = 0; i < cantidadElementos; i++) {
            cout << datos[i] << " ";
        }
        cout << endl;
    }

    void buscar(int valor) const {
        for (int i = 0; i < cantidadElementos; i++) {
            if (datos[i] == valor) {
                cout << "Elemento encontrado => " << datos[i] << endl;
                return;
            }
        }
        cout << "Elemento no encontrado" << endl;
    }

    void eliminar(int posicion) {
        if (posicion < 1 || posicion > cantidadElementos) {
            cout << "Posicion invalida" << endl;
            return;
        }
        for (int i = posicion - 1; i < cantidadElementos - 1; i++) {
            datos[i] = datos[i + 1];
        }
        cantidadElementos--;
        cout << "Elemento eliminado:"<<endl;
    }

    void guardarDatos() {
        ofstream archivo(nombreArchivo, ios::trunc); // Sobrescribe el archivo
        if (!archivo) {
            cout << "No se pudo abrir el archivo para guardar." << endl;
            return;
        }
        for (int i = 0; i < cantidadElementos; i++) {
            archivo << datos[i] << " ";
        }
        cout << "Datos guardados correctamente" << endl;
        archivo.close();
    }


    void cargarDesdeArchivo() {
        ifstream archivo(nombreArchivo);
        if (!archivo) return; // Si no existe el archivo, no hacer nada

        int valor;
        while (archivo >> valor) {
            Alta(valor); // Usa tu método Alta para añadir al arreglo dinámico
        }
        archivo.close();
    }


    TAD Union(TAD elemento) {
        TAD resultado;
        for (int i = 0; i < cantidadElementos; i++)
        {
            resultado.Alta(datos[i]);
        }


        for (int i = 0; i < elemento.cantidadElementos; i++)
        {
            resultado.Alta(elemento.datos[i]);
        } 
        return resultado;
    }

    TAD unionDistinct(TAD elemento) {
        TAD resultado;
        for (int i = 0; i < cantidadElementos; i++)
        {
            resultado.Alta(datos[i]);
        }
        for (int i = 0; i < elemento.cantidadElementos; i++)
        {
            bool existe = false;
            for (int j = 0; j < resultado.cantidadElementos; j++)
            {
                if (resultado.datos[j] == elemento.datos[i]) {
                    existe = true;
                    break;
                }
            }
            if (!existe)
            {
                resultado.Alta(elemento.datos[i]);
            }
        }
        return resultado;
    }

    TAD interseccion(TAD elemento) {
        TAD resulatado;
        for (int i = 0; i < cantidadElementos; i++)
        {
            for (int j = 0; j <elemento.cantidadElementos; j++)
            {
                if (datos[i] == elemento.datos[j])
                {
                    bool existe = false;
                    for (int t = 0; t <resulatado.cantidadElementos; t++)
                    {
                        if (resulatado.datos[t] == datos[i]) {
                            existe = true;
                            break;
                        }
                    }
                    if (!existe)
                    {
                        resulatado.Alta(datos[i]);
                    }
                }
            }
        }
        return resulatado;
    }

    TAD Diferencia(TAD elemento) {
        TAD resultado;
        for (int i = 0; i < cantidadElementos; i++)
        {
            bool existe = false;
            for (int j = 0; j < elemento.cantidadElementos; j++) {
                
                if (datos[i] == elemento.datos[j]) {
                    existe = true;
                    break;
                }
            }
            if (!existe) {
                resultado.Alta(datos[i]);
            }
        }
        return resultado;
    }



};

