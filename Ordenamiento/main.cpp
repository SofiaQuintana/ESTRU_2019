/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: zofia
 *
 * Created on February 26, 2020, 4:22 PM
 */

#include <cstdlib>
#include <iostream>
using namespace std;
/*
 * 
 */

void bubbleSort(int numbers[], int size) {
    bool isSorted = false;
    int lastUnsorted = size-1;
    while(!isSorted) {
        isSorted = true;
        for(int i = 0; i < (size-1); i++) {
            if(numbers[i] > numbers[i + 1]) {
                swap(numbers, i, i+1);
                isSorted = false;
            }
        }
    } 
    lastUnsorted--;
}

void swap(int numbers[], int firstNumber, int secondNumber) {
    int temporal = numbers[firstNumber];
    numbers[firstNumber] = numbers[secondNumber];
    numbers[secondNumber] = temporal;
}

int arraySize() {
    int size;
    cout << "Cantidad de numeros a ingresar: ";
    
}

int main(int argc, char** argv) {

    
    
    return 0;
}

