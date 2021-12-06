/*
Nombre: Erick Rafael Garcia Gutierrez
Practica: Strassen 
Fecha: 19/11/2021
*/

#include <iostream>
#include "Matriz.h"

using namespace std;


int main(int argc, char** argv) {
	int a, b, c, s;
	cout<<"Ingrese valor de a: ";cin>>a;
	cout<<"Ingrese valor de b: ";cin>>b;
	cout<<"Ingrese valor de c: ";cin>>c;
	s=a*c;
	
	Matriz A(a, b, s);
	cout<<"\nMatriz A:\n";
	A.llenar(s);
	A.print();
	
	Matriz B(b, c, s);
	cout<<"\nMatriz B:\n";
	B.llenar(s);
	B.print();

	cout<<"\nRedimension A:\n";
	A = Matriz::redimensionar(A, A.logaritmo(A.max(a, b, c)));
	A.print();
	
	cout<<"\nRedimension B:\n";
	B = B.redimensionar(B, B.logaritmo(B.max(a, b, c)));
	B.print();

    cout<<"\nMulti:\n";
    Matriz::multi(A, B).print();

	cout<<"\nProducto:\n";
    Matriz::strassen(A, B).print();

	return 0;
}