//
// Created by RECIE on 20/11/2021.
//

#ifndef STRASSN_MATRIZ_H
#define STRASSN_MATRIZ_H


#include<iostream>
#include<vector>
using namespace std;
class Matriz{

private:
    int filas, columnas,**m, s;

public:
    Matriz (int _filas, int _columnas, int _s){ //constructor 1

        filas = _filas;
        columnas = _columnas;
        s = _s;

        m = new int*[filas];
        for(int i=0; i<filas;i++){
            m[i] = new int[columnas];
        }

    }
    Matriz(Matriz src, int _height, int _side){ //constructor 2

        filas = src.getFilas()/2;
        columnas = src.getColumnas()/2;

        typedef enum{above, down} height;
        typedef enum{left, right} side;

        m = new int*[filas];
        for(int i=0; i<filas;i++){
            m[i] = new int[columnas];
        }
    }


    ~Matriz(){

    }

    void llenar(int s);
    void print();
    void setValue(int fila, int columna, int n);
    int getValue(int i, int j);
    int getFilas();
    int getColumnas();
    static Matriz suma(Matriz m1, Matriz m2);
    static Matriz resta(Matriz m1, Matriz m2);
    int max(int a, int b, int c);
    int logaritmo(int n);
    static Matriz redimensionar(Matriz m1, int n);
    static Matriz multi(Matriz m1, Matriz m2);
    static Matriz dividir(Matriz m1, int x, int y);
    static Matriz strassen(Matriz m1, Matriz m2);
};



#endif //STRASSN_MATRIZ_H
