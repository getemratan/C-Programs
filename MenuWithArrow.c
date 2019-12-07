/*
Author: Getem Ratan
Date: 06-12-2019
Description: Menu based program with the use of arrow keys
Example: ....Menu....
         Add <-
         Sub
         Mul
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define DOWN_KEY 80
#define UP_KEY 72
#define ESC 27
/* Function to add two values */
void Add(){
    system("cls");
    int x, y;
    printf("Enter two elements to add: \n");
    scanf("%d %d", &x, &y);
    int result = x + y;
    printf("Result: %d\n", result);
}
/* Function to subtract two values */
void Sub(){
    system("cls");
    int x, y;
    printf("Enter two elements to subtract: \n");
    scanf("%d %d", &x, &y);
    int result = x - y;
    printf("Result: %d\n", result);
}
/* Function to Multiply two values */
void Mul(){
    system("cls");
    int x, y;
    printf("Enter two elements to muliply: \n");
    scanf("%d %d", &x, &y);
    int result = x * y;
    printf("Result: %d\n", result);
}
/* Function to print the menu and 'x' is the cursor to the current menu item */
void menu(int x){
    printf("....Menu....\n");
    printf(x == 0 ? "Add <-\n" : "Add\n");
    printf(x == 1 ? "Sub <-\n" : "Sub\n");
    printf(x == 2 ? "Mul <-\n" : "Mul\n");
    printf("Press Esc Key For Exit\n\n");
    printf("Use UP and DOWN arrow key to navigate\n");
    printf("Enter to perform operation...");
}

int main(){
    int ch1, ch2;
    char ch3;
    int cursor = 0;

    do{
        system("cls");
        menu(cursor);

        ch1 = getch();
        /* For function keys and arrow keys getch() needs to be called twice
        first time to check scroll key interrupt */
        if(ch1 == 0xE0){
        /* Reading the arrow key */
            ch2 = getch();
            switch(ch2){
                case DOWN_KEY: system("cls");
                               if(cursor < 2)
                                  cursor++;
                               menu(cursor);
                               break;

                case UP_KEY: system("cls");
                             if(cursor != 0)
                                cursor--;
                             menu(cursor);
                             break;

                case ESC: break;
            }
        }
        /* Update: User can now use 'Enter' key to perform the corresponding operation */
        else if(ch1 == 10 || ch1 == 13){
            switch(cursor){
                case 0: Add();
                        break;
                case 1: Sub();
                        break;
                case 2: Mul();
                        break;
            }
            fflush(stdin);
            printf("Do you want to go back to the main menu?? (Y/N)\n");
            scanf("%c", &ch3);
            if(ch3 == 'Y' || ch3 == 'y'){
                continue;
            }
            else{
                exit(0);
            }
        }
    }while(ch1 != ESC);
}
