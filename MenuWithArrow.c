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
#define RIGHT_KEY 77
#define ESC 27
/* Function to add two values */
int Add(int x, int y){
    int result = x + y;
    return result;
}
/* Function to subtract two values */
int Sub(int x, int y){
    int result = x - y;
    return result;
}
/* Function to Multiply two values */
int Mul(int x, int y){
    int result = x * y;
    return result;
}
/* Function to print the menu and 'x' is the cursor to the current menu item */
void menu(int x){
    switch(x){
        case 0: printf("....Menu....\n");
                printf("Add <-\n");
                printf("Sub\n");
                printf("Mul\n");
                printf("Press Esc Key For Exit\n\n");
                printf("Use UP and DOWN arrow key to navigate and RIGHT arrow key to perform operation!! ");
                break;

        case 1: printf("....Menu....\n");
                printf("Add\n");
                printf("Sub <-\n");
                printf("Mul\n");
                printf("Press Esc Key For Exit\n\n");
                printf("Use UP and DOWN arrow key to navigate and RIGHT arrow key to perform operation!! ");
                break;

        case 2: printf("....Menu....\n");
                printf("Add\n");
                printf("Sub\n");
                printf("Mul <-\n");
                printf("Press Esc Key For Exit\n\n");
                printf("Use UP and DOWN arrow key to navigate and RIGHT arrow key to perform operation!! ");
                break;
    }
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

                case RIGHT_KEY: if(cursor == 0){
                                    printf("\nEnter two elements to add: \n");
                                    int x, y;
                                    scanf("%d %d", &x, &y);
                                    printf("Result: %d\n", Add(x, y));
                                    fflush(stdin);
                                    printf("Do you want to go back to the main menu?? (Y/N)\n");
                                    scanf("%c", &ch3);
                                    if(ch3 == 'Y' || ch3 == 'y'){
                                        break;
                                    }
                                    else{
                                        exit(0);
                                    }
                                }
                                else if(cursor == 1){
                                    printf("\nEnter two elements to subtract: \n");
                                    int x, y;
                                    scanf("%d %d", &x, &y);
                                    printf("Result: %d\n", Sub(x, y));
                                    fflush(stdin);
                                    printf("Do you want to go back to the main menu?? (Y/N)\n");
                                    scanf("%c", &ch3);
                                    if(ch3 == 'Y' || ch3 == 'y'){
                                        break;
                                    }
                                    else{
                                        exit(0);
                                    }
                                }
                                else if(cursor == 2){
                                    printf("\nEnter two elements to muliply: \n");
                                    int x, y;
                                    scanf("%d %d", &x, &y);
                                    printf("Result: %d\n", Mul(x, y));
                                    fflush(stdin);
                                    printf("Do you want to go back to the main menu?? (Y/N)\n");
                                    scanf("%c", &ch3);
                                    if(ch3 == 'Y' || ch3 == 'y'){
                                        break;
                                    }
                                    else{
                                        exit(0);
                                    }
                                }

                case ESC: break;
            }
        }
    }while(ch1 != ESC);
}
