#include <cstdlib>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

void mainMenu() {
    int option = 1;
    int selectedOption;

    while(option != 0) {
        printf("----Guatemala's DB----\n");
        printf("  [1] Insert Query \n");
        printf("  [2] Reports \n");
        printf("  [3] DB Graphics \n");
        printf("  [4] Exit \n\n");
        printf("Insert Option: ");

        cin >> selectedOption;

        switch (selectedOption) {
            case 1:
                //Query insertion, go to lexer and parser.
            break;
            case 2:
                //Reports menu
            break;
            case 3:
                //DB graphics menu
            break;
            case 4:
                //Defines ending.
                option = 0; 
            break;
            default:
                cout << "\nInsert a valid option [1 - 4]\n";
            break;
        }
    }
}

int main() {
    mainMenu();
}