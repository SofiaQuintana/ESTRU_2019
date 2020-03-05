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
Stack<Card*> *auxiliarStack = new Stack<Card*>; 
Stack<Card*> *firstStack = new Stack<Card*>; 
Stack<Card*> *secondStack = new Stack<Card*>; 
Stack<Card*> *thirdStack = new Stack<Card*>; 
Stack<Card*> *fourthStack = new Stack<Card*>; 
Stack<Card*> *fifthStack = new Stack<Card*>; 
Stack<Card*> *sixthStack = new Stack<Card*>; 
Stack<Card*> *seventhStack = new Stack<Card*>; 
Stack<Card*> *hearts = new Stack<Card*>; 
Stack<Card*> *swords = new Stack<Card*>; 
Stack<Card*> *clovers = new Stack<Card*>; 
Stack<Card*> *diamonds = new Stack<Card*>; 
Queue<Card*> *reserve = new Queue<Card*>;
Queue<Card*> *discard = new Queue<Card*>;
DoubleLinkedList<Card*> *list = new DoubleLinkedList<Card*>;

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
        temporal -> setValue("A"); //As
    break;
    case 11:
        temporal -> setValue("J"); //Jack
    break;
    case 12:
        temporal -> setValue("Q"); //Queen
    break;
    case 13:
        temporal -> setValue("K"); //King
    break;
    default:
        temporal -> setValue(to_string(index)); //Everything else
    break;
    }
}

void setAttributes(string type, int color, int index, Card *temporal) {
    temporal -> setType(type); //Palo
    temporal -> setColor(color); //Color
    setValue(index, temporal); //Asignacion de valor A, 1-10, J, Q, K.       
    auxiliarStack -> push(temporal); //push en el stack correspondiente.
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
    list -> insert(random, aux);
}

void fillStack() {
    Card *aux;
    for (int i = 0; i < 52; i++) {
        aux = auxiliarStack -> pop();
        storage -> push(aux);
    }
    auxiliarStack -> ~Stack();
}

void shuffleCards() {
    srand((unsigned)time(NULL));
    int randomPosition = 0;
    int size = list->size();
    for (int i = 0; i < size; i++) {
        randomPosition = rand()%51+0;
        exchange(i, randomPosition);
    }
}

//Llena la cola de reserva con 24 cartas
void fillReserve() {
    Card *aux;
    for (int i = 0; i < 24; i++) {
        aux = storage -> pop();
        reserve -> enqueue(aux);
    }
}

//Llena los 7 stacks de juego
void fillGameStacks() {
    Card *aux;
    for (int i = 0; i < 7; i++) {
        assignStackValues(i);
    }
    
}

void fillStacks(int cantidad, Stack<Card*> *aux) {
    Card *card;
    Card *peek;

    for (int i = 0; i < cantidad; i++) {
            card = storage -> pop();
            aux -> push(card);
        }
        peek = aux -> peek();
        peek -> setHidden(false);
}

void assignStackValues(int index) {
    switch (index)
    {
    case 1:
        fillStacks(1, firstStack);
    break;
    case 2:
        fillStacks(2, secondStack);
    break;
    case 3:
        fillStacks(3, thirdStack);
    break;
    case 4:
        fillStacks(4, fourthStack);
    break;
    case 5:
        fillStacks(5, fifthStack);
    break;
    case 6:
        fillStacks(6, sixthStack);
    break;
    case 7:
        fillStacks(7, seventhStack);
    break;
    default:
        printf("invalid");
    break;
    }
}


void dealCards() {
    instanceCards(); //Inicializacion de las 56 cartas
    assignCardValues(); //Asignacion de c/u de los valores a las cartas
    // shuffleCards(); //Baraja las cartas.
    fillStack(); //Vuelve a llenar el storage.
    fillReserve(); 
}

void startGame() {
    dealCards();
    int counter = -1;
    bool flag = false;
    while(!flag) {
        cout<<"\nIngrese jugada\n";
    }
    cout<<"You win!";
}

void rules() {
	cout<<"\n**********************************\n";
    cout<< "REGLAS DEL JUEGO\n" << "Hay 7 stacks de juego, en estas solo se pueden colocar cartas que formen\n";
    cout<< "una secuencia decreciente consecutiva y de colores alternantes.\n";
	cout<< "1 Stack de Reserva, donde las cartas restantes esperan ser descubiertas.\n";
	cout<< "1 Stack de Discard, de la cual podemos tomar una carta por cada vez.\n";
	cout<< "4 Pilas de Salida, en estas stacks se iran apilando cada carta de un mismo palo\n";
	cout<< "Si se logra llenar cada una de las 13 cartas de un mismo palo en cada stack de salida\n";
	cout<< "se gana el juego, y se pierde cuando no se puede hacer ningun movimiento.\n";
}

void instructions() {
    cout<<"\n********************************************************\n";
    cout<<"Movimientos: [Carta] [Stack origen] [Stack destino]\n";
	cout<<"Ejemplo: 2 3, lo cual mueve una carta del stack 2 al 3. \n";
    cout<<"Comandos: D, Barajar carta descarte y colocar otra carta\n";
	cout<<"Comandos: +, Mover mas de una carta\n";
	cout<<"Comandos: N, Nuevo juego\n";
	cout<<"Si la jugada es invalida, se ignora y no se lleva a cabo\n";
}

void menu() {
	int option = 1;
	int value;
	while(option != 0) {
		printf("\n      Solitario\n*********************\n");
		printf("1. Rules\n");
		printf("2. Game Instructions\n");
		printf("3. Play New Game\n");
		printf("4. Exit\n");
		
		printf("Insert option:\n");

        cin >> option;
		switch(option) {

			case 1:	
                rules();
            break;

			case 2:	
                instructions();
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