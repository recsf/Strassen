#include<iostream>
#include "Matriz.h"
#include<random>
#include<math.h>

using namespace std;

random_device(rd);
mt19937 mt(rd());
void Matriz:: llenar(int s){
    uniform_int_distribution<int> dist(0, s);
    for(int i=0; i<filas;i++){
        for(int j=0;j<columnas;j++){
            *(*(m+i)+j)=dist(mt);
        }
    }
}

void Matriz:: print(){
    for(int i=0;i<filas;i++){
        for(int j=0; j<columnas;j++){
            cout<<getValue(i, j)<<"    ";
        }
        cout<<endl;
    }
}
int Matriz:: getValue(int i, int j){
    return *(*(m+i)+j);
}

void Matriz:: setValue(int fila, int columna, int n){

    *(*(m+fila)+columna)=n;
}


int Matriz::getFilas() {
    return filas;
}

int Matriz::getColumnas(){
    return columnas;
}

Matriz Matriz:: suma(Matriz m1, Matriz m2){
    Matriz mSuma(m1.getFilas(), m1.getColumnas(), 0);

    if(m1.getFilas()==m2.getFilas() && m1.getColumnas()==m2.getColumnas()){

        for(int i=0; i<m1.getFilas();i++){
            for(int j=0;j<m1.getColumnas();j++){
                mSuma.setValue(i, j, m1.getValue(i, j) + m2.getValue(i, j));
            }
        }
    }else{
        cout<<"No son cuadradas\n";
    }
    return mSuma;
}

Matriz Matriz:: resta(Matriz m1, Matriz m2){
    Matriz mResta(m1.getFilas(), m1.getColumnas(), 0);
    if(m1.getFilas()==m2.getFilas() && m1.getColumnas()==m2.getColumnas()){
        for(int i=0; i<m1.getFilas();i++){
            for(int j=0;j<m1.getColumnas();j++){
                mResta.setValue(i, j, m1.getValue(i, j) - m2.getValue(i, j));
            }
        }
    }else{
        cout<<"No son cuadradas\n";
    }
    return mResta;
}

Matriz Matriz::multi(Matriz m1, Matriz m2){
    Matriz mMulti(m1.getFilas(), m2.getColumnas(), 0);
    if(m1.getColumnas()==m2.getFilas()){
        for(int i=0; i<mMulti.getFilas();i++){
            for(int j=0;j<mMulti.getColumnas();j++){
                mMulti.setValue(i, j, 0);
                for(int k=0;k<m2.getFilas();k++){
                    mMulti.setValue(i, j, mMulti.getValue(i, j)+m1.getValue(i,k)*m2.getValue(k,j));
                }
            }
        }
    }else{
        cout<<"No es posible hacer esta multiplicacion";
    }
    return mMulti;

}

int Matriz:: max(int a, int b, int c){
    if(a>=b && a>=c){
        return a;
    }
    else if(b>=c){
        return b;
    }else{
        return c;
    }
}
int Matriz:: logaritmo(int m){
    float n;
    n = log(m)/log(2);
    n = ceil(n);
    return n;
}

Matriz Matriz:: redimensionar(Matriz m1, int n){
    Matriz c(pow(2, n), pow(2, n), 0);
    for(int i=0; i<c.getFilas();i++){
        for(int j=0;j<c.getColumnas();j++){
            c.setValue(i, j, 0);
        }
    }
    for(int i=0; i<m1.getFilas();i++){
        for(int j=0;j<m1.getColumnas();j++){
            c.setValue(i, j, m1.getValue(i, j));
        }
    }
    m1 = c;
    return m1;
}

Matriz Matriz:: dividir(Matriz m1, int x, int y){
    if(x==0 && y==0){
        Matriz A11(m1, x, y);
        for(int i=0;i<m1.getFilas()/2;i++){
            for(int j=0;j<m1.getColumnas()/2;j++){
                A11.setValue(i, j, m1.getValue(i, j));
            }
        }
        return A11;
    }else if(x==0 && y==1){
        int t = 0;
        Matriz A12(m1, x, y);
        for(int i=0;i<m1.getFilas()/2;i++){
            for(int j=m1.getColumnas()/2;j<m1.getColumnas();j++){
                A12.setValue(i, t, m1.getValue(i, j));
                t+=1;
                if (t>=A12.getColumnas()){
                    t=0;
                }
            }
        }
        return A12;

    }else if(x==1 && y==0){
        int t = 0;
        Matriz A21(m1, x, y);
        for(int i=m1.getFilas()/2;i<m1.getFilas();i++){
            for(int j=0;j<m1.getColumnas()/2;j++){
                A21.setValue(t, j, m1.getValue(i, j));
            }
            t+=1;
        }
        return A21;
    }else{
        int t = 0, p = 0;
        Matriz A22(m1, x, y);
        for(int i=m1.getFilas()/2;i<m1.getFilas();i++){
            for(int j=m1.getColumnas()/2;j<m1.getColumnas();j++){
                A22.setValue(p, t, m1.getValue(i, j));
                t++;
                if(t>=A22.getColumnas()){
                    t=0;
                }
            }
            p++;
        }
        return A22;
    }
}

Matriz Matriz:: strassen(Matriz m1, Matriz m2){
    int longitud= m1.getFilas();
    if(longitud<=2){

        return Matriz::multi(m1, m2);
    }
    else{
        Matriz a = Matriz::dividir(m1, 0, 0);
        Matriz b = Matriz::dividir(m1, 0, 1);
        Matriz c = Matriz::dividir(m1, 1, 0);
        Matriz d = Matriz::dividir(m1, 1, 1);

        Matriz e = Matriz::dividir(m2, 0, 0);
        Matriz f = Matriz::dividir(m2, 0, 1);
        Matriz g = Matriz::dividir(m2, 1, 0);
        Matriz h = Matriz::dividir(m2, 1, 1);

        Matriz M1 = M1.strassen(Matriz::suma(a,d), Matriz::suma(e,h));
        Matriz M2 = M2.strassen(d, Matriz::resta(g,e));
        Matriz M3 = M3.strassen(Matriz::suma(a,b), h);
        Matriz M4 = M4.strassen(Matriz::resta(b,d), Matriz::suma(g, h));
        Matriz M5 = M5.strassen(a, Matriz::resta(f,h));
        Matriz M6 = M6.strassen(Matriz::suma(c, d), e);
        Matriz M7 = M7.strassen(Matriz::resta(a,c), Matriz::suma(e, f));
        Matriz C11 = suma(M1, M2);
        C11 = resta(C11, M3);
        C11 = suma(C11, M4);

        Matriz C12 = C12.suma(M3, M5);

        Matriz C21=C21.suma(M6, M2);

        Matriz C22= suma(M5, M1);
        C22 = resta(C22, M6);
        C22 = resta(C22, M7);


        Matriz C(C11.getFilas()+C12.getFilas(), C21.getColumnas()+C22.getColumnas(), 0);
        int t=0;

        for(int i=0; i<C11.getFilas();i++){
            int p=0;
            for(int j=0; j<C11.getColumnas();j++){
                C.setValue(i, j, C11.getValue(t, p));

                p++;
            }
            t++;
        }
        t=0;
        for(int i=0;i<C12.getFilas();i++){
            int p=0;
            for(int j=C12.getColumnas();j<C12.getColumnas()*2;j++){
                C.setValue(i, j, C12.getValue(t,p));
                p++;
            }
            t++;
        }
        t=0;
        for(int i=C21.getFilas();i<C21.getFilas()*2;i++){
            int p=0;
            for(int j=0;j<C21.getColumnas();j++){
                C.setValue(i, j, C21.getValue(t,p));
                p++;
            }
            t++;
        }
        t=0;
        for(int i=C22.getFilas();i<C22.getFilas()*2;i++){
            int p=0;
            for(int j=C22.getColumnas();j<C22.getColumnas()*2;j++){
                C.setValue(i, j, C22.getValue(t,p));
                p++;
            }
            t++;
        }

        return C;
    }


}