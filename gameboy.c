// gaym boy, includes tic tac toe, connect 4 and battleship (uncompleted), sorry if some functions or variables are in italian
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <time.h>
#include "trisnew.h"
#include "forza4new.h"

char winner = ' ';
int  turnot = 0;
int  turnof = 0;
int  correct = 1;
char risposta;
int  esci = 0;
int start();
void battaglianavale();

int main() {
    int ore = 0;
    esci = 0;
    while (esci == 0 && ore<3) {
        ore++;
        winner = ' ';
        turnot = 0;
        turnof = 0;
        correct = 1;
        esci = 0;
        start();     }
    if (ore>4) {
        printf("\n\033[36mok now u played too much cuh\n");
        system("pause");    }
    return 0;   }

int start(void) {
system("@cls||clear");
printf("\n");
printf("        \033[31m                  WELCUM TO GAYM VOIP BOY \n");
printf("\033[35m                         __________________________ \n");
printf("                   \033[35m     |                          |\n");
printf("              \033[35m          | .----------------------. |\n");
printf(" \033[35m                       | |  .----------------.  | |\n");
printf("         \033[35m               | |  | \033[31mChoose da game \033[35m|  | |\n");
printf("                 \033[35m       | |  | \033[31m 1) TicTacToe \033[35m |  | |\n");
printf("\033[35m                        | |  | \033[31m 2) Connect4 \033[35m  |  | |\n");
printf("        \033[35m                | |  | \033[31m 3) Battle \033[35m    |  | |\n");
printf("                \033[35m        | |  | \033[31m    ship   \033[35m    |  | |\n");
printf("\033[35m                        | |  | \033[31m 0) quit : ( \033[35m  |  | |\n");
printf("        \033[35m                | |  |  _             |  | |\n");
printf("                \033[35m        | |  '----------------'  | |\n");
printf("\033[35m                        | |_____[\033[31m VOIP  BOY \033[35m]____| |\n");
printf("        \033[35m                |          ________        |\n");
printf("                \033[35m        |    _    (\033[31mNiggTendo\033[35m)      |\n");
printf("                        \033[35m|  _| |_   \"\"\"\"\"\"\"\"   .-.  |\n");
printf("\033[35m                        |-[_   _]-       .-. (   ) |\n");
printf("        \033[35m                |   |_|         (   ) '-'  |\n");
printf("                \033[35m        |    '           '-'   A   |\n");
printf("\033[35m                        |                 B        |\n");
printf("        \033[35m                |          ___   ___       |\n");
printf("                \033[35m        |         (___) (___)  ,.  |\n");
printf("\033[35m                        |        \033[31mselect start\033[35m ;:;  |\n");
printf("        \033[35m                |                    ,;:  .'\n");
printf("                \033[35m        |________________________' \n");
    tabellat tabella1;
    tabellaf tabella2;
    int start_answer = 10;
  do {
    printf("                            \033[31m    --> ");
    scanf(" %d", &start_answer);
    getchar();
    switch (start_answer) {
        case 1:
        tris(tabella1);
        start_answer = 0;
        break;
        case 2:
        forza4(tabella2);
        start_answer = 0;
        break;
        case 3:
        battaglianavale();
        start_answer = 0;
        break;
        case 0:
        printf("\033[36frick off then cuh");
        start_answer = 0;
        esci = 1;
        break;
        break;
        default:
        printf("\n \033[36mu stupid tf u typin?? type 1, 2, 3 or 0 \n");
        continue;
    }
  } while (start_answer != 0);
    printf("\n");
    system("pause");
    return 0;
}

void battaglianavale() {
    printf("\033[36mNot yet cuh");
}
