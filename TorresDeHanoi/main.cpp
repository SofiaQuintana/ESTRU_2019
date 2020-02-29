/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: zofia
 *
 * Created on February 16, 2020, 11:22 PM
 */
#include <time.h>
#include <cstdlib>
#include <iostream>
#include <unistd.h>

using namespace std;

/*
 * 
 */
    int start[16];
    int medium[16];
    int finalSpace[16];
    int movements =0;

    int startUsing=0;
    int mediumUsing=0;
    int endUsing=0;

    //Metodo encargado de 'dibujar' c/u de los discos ingresados por el usuario.
    void paintDisc(int tower[], int limit){
        for (int i = (limit-1); i > -1; --i){
            if (tower[i]!= 0){
                int size = tower[i];	
                for (int j = 0; j < size; ++j){
                    cout<<"|";
                }
                    cout<<"D  ";
            }
        }
    }

    /*Metodo encargado de 'dibujar' los discos en sus respectivas torres segun corresponda
     * con cierto delay para poder visualizar cada uno de los 'repaints' realizados,
     * recordando que solo son 3 torres sin importar el numero de discos.*/
    void paintTowersAndDiscs(int limit){
        cout<<" First Tower --------> ";
        paintDisc(start, limit);
        cout<<"\n Second Tower -------> ";
        paintDisc(medium, limit);
        cout<<"\n Third Tower --------> ";
        paintDisc(finalSpace, limit);
        cout<<"\n-------------------------------------------------------end of line-------------------------------------------------------\n"<< endl;
        usleep(500000);
    }

    //Funcion encargada de realizar el intercambios de los discos.
    void swapElements(int send[], int get[], int limit){
        int auxiliar=0;
        bool found = false;
        for (int j = 0; j < limit; ++j){
            if ((send[j] != 0) && (found == false)){
                cout << send[j];
                auxiliar = send[j];
                send[j] = 0;
                get[j] = auxiliar;
                auxiliar=0;
                found = true;
                }
        }
    } 

    /*Funcion encargada de enviarle el movimientos correspondiente de los discos como
     * mensaje en consola al usuario, tambien se encarga de llamar al resto de funciones 
     * encargadas de realizar los 'repaints' para cada movimiento realizado y asi mismo lleva
     * el conteo de movimientos.*/
    void moveTowers(int N, int origin[], int medium[], int destination[], int limit, int uno, int dos, int tres){ 
        if (N > 0 || N < 16){
            if ( 1 == N ){
                cout << " Disk Movement: ";
                swapElements(origin, destination, limit);
                cout << " - from tower "<< uno << " to " << tres << endl;
                paintTowersAndDiscs(limit);

            } else { 
                moveTowers( N - 1, origin, destination, medium, limit, uno, tres, dos);
                cout << " Disk Movement: ";
                swapElements(origin, destination, limit);
                cout << " - from tower "<< uno << " to " << tres << endl;
                paintTowersAndDiscs(limit);
                moveTowers( N - 1, medium, origin, destination, limit, dos, uno, tres);
            } 
        } else {
            cout << "\n number of disks out of range!!!!!! :s "<< endl;
        }
        movements++;
    }

    int main(){ 
        int discs;
        cout << "\tTorres de Hanoi" << endl;
        cout << "Enter number of discs: "<< endl;
        cin >> discs;

        for (int i = 0; i < discs; ++i){
                start[i] = (i+1);
        }

        int limit = (sizeof(start)/sizeof(start[0]));

        movements = 0;
        cout<<"\n\tStart Torre de Hanoi"<<endl;
        paintTowersAndDiscs(limit);
        moveTowers(discs, start, medium, finalSpace, limit, 1, 2, 3);
        cout << "\n\tThe amount of movements made is: "<<movements<<endl;
        cout << endl << endl;

        return 0;
    }

