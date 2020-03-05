#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>
#include <string.h>
#include "Card.cpp"
#include "DoubleLinkedList.cpp"
#include "Stack.cpp"
#include "Queue.cpp"
#include "Node.cpp"
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_RESET   "\x1b[0m"

using namespace std;

Stack<Card*> *storage = new Stack<Card*>; 
Queue<Card*> *queue = new Queue<Card*>;
DoubleLinkedList<Card*> *list = new DoubleLinkedList<Card*>;
DoubleLinkedList<Card*> *auxList = new DoubleLinkedList<Card*>;

/*Instanciamos 52 cartas con valores predeterminados y
 *las guardamos en el stack encargado de almacenarlas. */
void instanceCards() {
    Card *card;
    for (int i = 0; i < 53; i++) {
        card = new Card;
        storage->push(card); //pushing card :)
    }
}

//Asigna el valor de la carta, correspondientemente.
void setValue(int index, Card *temporal) {
    switch (index) {
    case 1:
        temporal -> setValue("A");
    break;
    case 11:
        temporal -> setValue("J");
    break;
    case 12:
        temporal -> setValue("Q");
    break;
    case 13:
        temporal -> setValue("K");
    break;
    default:
        temporal -> setValue(to_string(index));
    break;
    }
}

void setAttributes(string type, int color, int index, Card *temporal) {
    temporal -> setType(type); //Palo
    temporal -> setColor(color); //Color
    setValue(index, temporal); //Asignacion de valor A, 1-10, J, Q, K.       
    list -> insertAtFront(temporal); //push en el stack correspondiente.
}

void assignCardValues() {
    Stack<Card*> *aux = storage;
    Card *temporal;
    int a, b, c;
	a = b = c = 1;
	for(int i = 0; i < 52; i++) {
        temporal = aux -> pop();
		if(i <= 12 ) {
            setAttributes("<>", 1, i+1, temporal);
		}
		if(i > 12 && i <= 25) {
            setAttributes("<3", 1, a++, temporal);
		}
		if(i > 25 && i <= 38) {
            setAttributes("E3", 0, b++, temporal);
		}
		if(i > 38) {
            setAttributes("!!", 0, c++, temporal);
		}
	}
    storage-> ~Stack();
}



void exchange(int position, int random) {
    Card *aux = list -> get(position);
    list -> remove(position);
    auxList -> insert(random, aux);
}

void shuffleCards() {
    auxList = list;
    srand((unsigned)time(NULL));
    int randomPosition = 0;
    int size = list->size();
    for (int i = 0; i < size; i++) {
        randomPosition = rand()%51+0;
        exchange(i, randomPosition);
    }
    list = auxList;
}


void dealCards() {
    instanceCards(); //Inicializacion de las 56 cartas
    assignCardValues(); //Asignacion de c/u de los valores a las cartas
    shuffleCards(); //Baraja las cartas.

}

void startGame() {
    dealCards();
}

void menu() {
	int option = 1;
	int value;
	while(option != 0) {
		printf("\t\tSolitario\n\n");
		printf("1. Rules\n");
		printf("2. Game Instructions\n");
		printf("3. Play New Game\n");
		printf("4. Exit\n");
		
		printf("Insert option:\n");

        cin >> option;
		switch(option) {

			case 1:	
                // reglasDelJuego();
            break;

			case 2:	
                // comandosDelJuego();
            break;
			case 3: 
                startGame();	
            break;
			case 4:	
                option = 0;
            break;
			default: 
                cout << "Insert Valid Option [1-4]!!!\n";
            break;
		}
	}		
}

int main() {
	menu();

}