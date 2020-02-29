#include <cstdlib>
#include <iostream>
#include <string.h>
using namespace std;


void bubbleSortSwap(int *firstNumber, int *secondNumber) {
    int temporal = *firstNumber;
    *firstNumber = *secondNumber;
    *secondNumber = temporal;
}

void bubbleSort(int numbers[], int size) {
    bool isSorted = false;
    int lastUnsorted = size-1;
    int position;
    while(!isSorted) {
        isSorted = true;
        for(int i = 0; i < lastUnsorted; i++) {
            if(numbers[i] > numbers[i+1]) {
                position = i + 1;
                bubbleSortSwap(&numbers[i], &numbers[position]);
                isSorted = false;
            }
        }
    }
    lastUnsorted--;
}

void insertionSortSwap(int numbers[], int temporal, int actualNumber) {
    while(temporal >= 0 && numbers[temporal] > actualNumber) {
        numbers[temporal + 1] = numbers[temporal];
        numbers[temporal] = actualNumber;
        temporal--;
    }
}

void insertionSort(int numbers[], int size) {
    int actualNumber;
    int temporal;
    for(int i = 1; i < size; i++) {
        actualNumber = numbers[i];
        temporal = i - 1;
        insertionSortSwap(numbers, temporal, actualNumber);
        temporal++;
    }
}

int arraySize() {
    int size;
    cout<< "Cantidad de numeros a ingresar: ";
    cin >> size;
    return size;
}

int insertNumbers() {
    int number;
    cout<< "Ingrese numero: ";
    cin>> number;
    return number;
}

void fillArray(int numbers[], int size) {
    for(int i = 0; i < size; i++) {
        numbers[i] = insertNumbers();
    }
}

void printSortedArray(int numbers[], int size) {
    int temporal = 0;
    string array = "";
    while(temporal < size) {
        array += "[" + to_string(numbers[temporal]) + "]";
        temporal++;
    }
    cout<< "Su lista ordenada es " << array;
}

int selection() {
    int selection;
    cout<< "Seleccione tipo de ordenacion: [1] Bubble Sort, [2] Insertion Sort \n";
    cin >> selection;
    return selection;
}

int main(int argc, char** argv) {
    int size = arraySize();
    int numbers[size];
    fillArray(numbers, size);
    int sort = selection();
    if (sort == 1) {
        bubbleSort(numbers, size);
    } else if(sort == 2) {
        insertionSort(numbers, size);
    }
    printSortedArray(numbers, size);
    return 0;
}
