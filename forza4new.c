#include "forza4new.h"
// forza 4 (connect 4) with anti-easywin functions
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <time.h>
#define dimf 7
const char gamer = 'X';
const char compiuter = 'O';
int turno_f = 0;

void forza4(tabellaf tabella2) {
    char winner = ' ';
    char risposta;
    turno_f = 0;
    int aii;
    int modalita;
    do {
    turno_f = 0;
    winner = ' ';
    risposta = ' ';
    valoriiniziali_f(&tabella2);
    printf("\033[36mWelcum to conect 4!! swag \n");
    disegno_f(tabella2);
    printf("\n \n \033[36mNow lets get started, type 0 if u against PC, 1 if u against a real player: ");
    scanf("%d", &modalita);
    getchar();
    switch (modalita)   {
        case 0:
        modalita = 0; // against pc
        break;
        case 1:
        modalita = 1; // against player
        break;
        default: 
        printf("\n \033[36mdude tf u typing?? type either 0 or 1 cuh");
        continue;   }
    printf("\n");
    printf("\n \033[0m");

    while (winner == ' ' && checkspazi_f(tabella2) != 0) {
        turno_f++;
        disegno_f(tabella2);
        turnomio_f(&tabella2);
        winner = checkwinner_f(tabella2);
        if (winner != ' ' || checkspazi_f(tabella2) == 0) {
            break;          }
        if (modalita == 0) {
            turnocompiuter_f(&tabella2);
            winner = checkwinner_f(tabella2);
            if (winner != ' ' || checkspazi_f(tabella2) == 0) {
                break;          }       }
        else if (modalita == 1) {
            turnomio2_f(&tabella2);
            winner = checkwinner_f(tabella2);
            if (winner != ' ' || checkspazi_f(tabella2) == 0) {
                break;          }       }
    }
    disegno_f(tabella2);
    vincitore_f(winner);
    printf("\n\033[36maaa match finished\n");
    reset_f(&tabella2);
    printf("\n wanna play again? click (S/N) and enter, if u click sometjing else u ded: ");
    scanf("%c", &risposta);
    getchar();
    risposta = toupper(risposta);
    } while (risposta == 'S');
    printf("\n k now frick off\n");
    system("pause");
}

void clrscr_f() {
    system("@cls||clear");  }

void reset_f(tabellaf *tabella2) {
    for (int i=0; i<=7; i++) {
        for (int j=0; j<=7; j++) {
            tabella2->valori[i][j] = ' ';
        }
    }                       }

int disegno_f(tabellaf tabella2) {
    int i=0;
    int j=0;
    clrscr_f();
    printf("\n");//0   1   2   3   4   5   6
    printf("\n \033[31m   CONNECT 4  \033[33m Turn %d - Player: %c \033[0m \n", turno_f, player_f);
    printf("     _____________________________  \n");
    printf("    //_A_|_B_|_C_|_D_|_E_|_F_|_G_\\\\ \n");
    printf("  6 || %c | %c | %c | %c | %c | %c | %c || \n", tabella2.valori[6][0], tabella2.valori[6][1], tabella2.valori[6][2], tabella2.valori[6][3], tabella2.valori[6][4], tabella2.valori[6][5], tabella2.valori[6][6]);
    printf("  5 || %c | %c | %c | %c | %c | %c | %c || \n", tabella2.valori[5][0], tabella2.valori[5][1], tabella2.valori[5][2], tabella2.valori[5][3], tabella2.valori[5][4], tabella2.valori[5][5], tabella2.valori[5][6]);
    printf("  4 || %c | %c | %c | %c | %c | %c | %c || \n", tabella2.valori[4][0], tabella2.valori[4][1], tabella2.valori[4][2], tabella2.valori[4][3], tabella2.valori[4][4], tabella2.valori[4][5], tabella2.valori[4][6]);
    printf("  3 || %c | %c | %c | %c | %c | %c | %c || \n", tabella2.valori[3][0], tabella2.valori[3][1], tabella2.valori[3][2], tabella2.valori[3][3], tabella2.valori[3][4], tabella2.valori[3][5], tabella2.valori[3][6]);
    printf("  2 || %c | %c | %c | %c | %c | %c | %c || \n", tabella2.valori[2][0], tabella2.valori[2][1], tabella2.valori[2][2], tabella2.valori[2][3], tabella2.valori[2][4], tabella2.valori[2][5], tabella2.valori[2][6]);
    printf("  1 || %c | %c | %c | %c | %c | %c | %c || \n", tabella2.valori[1][0], tabella2.valori[1][1], tabella2.valori[1][2], tabella2.valori[1][3], tabella2.valori[1][4], tabella2.valori[1][5], tabella2.valori[1][6]);
    printf("  0 ||_%c_|_%c_|_%c_|_%c_|_%c_|_%c_|_%c_|| \n", tabella2.valori[0][0], tabella2.valori[0][1], tabella2.valori[0][2], tabella2.valori[0][3], tabella2.valori[0][4], tabella2.valori[0][5], tabella2.valori[0][6]);
    printf("    || A | B | C | D | E | F | G || \n");
    printf("    \\\\___________________________// \n");
    return 0;                 }

int valoriiniziali_f(tabellaf *tabella2) {   // uguale a reset si sn stupid
    int i=0;
    int j=0;
    while (i<7) {
        j=0;
        while (j<7) {
            tabella2->valori[i][j] = ' ';
            j++;
        }
        i++;    }
    return 0;             }

int checkspazi_f(tabellaf tabella2) {
    int spazi = 49;
    int i = 0;
    int j = 0;
    for(int i = 0; i < 7; i++)  {
      for(int j = 0; j < 7; j++)  {
         if(tabella2.valori[i][j] != ' ')  {
            spazi--;
         }
       }
    }
    return spazi;            }

char checkwinner_f(tabellaf tabella2) {
    int i=0;
    int j=0;
    char winner;
    if (checkorizz_f(tabella2) != ' ')   {
        return checkorizz_f(tabella2);  }
    if (checkvertic_f(tabella2) != ' ')  {
        return checkvertic_f(tabella2); }
    if (checkdiagonale_f(tabella2) != ' ') {
        return checkdiagonale_f(tabella2);}
    return ' ';              }

char checkvertic_f(tabellaf tabella2) {
    int i=0;
    int j=0;
    char winner = ' ';
    int puntiPL = 4; // roba inutile
    int puntiPC = 4; // roba inutile
    while (j<7) {
        i=0;
        while (i<7) {
            if (tabella2.valori[i][j] == gamer && tabella2.valori[i+1][j] == gamer && tabella2.valori[i+2][j] == gamer && tabella2.valori[i+3][j] == gamer) {
                puntiPL = 0;
                winner = gamer;
                break;  }
            if (tabella2.valori[i][j] == compiuter && tabella2.valori[i+1][j] == compiuter && tabella2.valori[i+2][j] == compiuter && tabella2.valori[i+3][j] == compiuter) {
                puntiPC = 0;
                winner = compiuter;
                break;  }
            i++;  }
        j++;  }
    return winner;          }

char checkorizz_f(tabellaf tabella2) {
    int i=0;
    int j=0;
    char winner = ' ';
    int puntiPL = 4; // roba inutile
    int puntiPC = 4; // roba inutile
    while (i<7) {
        j=0;
        while (j<7) {
            if (tabella2.valori[i][j] == gamer && tabella2.valori[i][j+1] == gamer && tabella2.valori[i][j+2] == gamer && tabella2.valori[i][j+3] == gamer) {
                puntiPL = 0;
                winner = gamer;
                break;  }
            if (tabella2.valori[i][j] == compiuter && tabella2.valori[i][j+1] == compiuter && tabella2.valori[i][j+2] == compiuter && tabella2.valori[i][j+3] == compiuter) {
                puntiPC = 0;
                winner = compiuter;
                break;  }
            j++;  }
        i++;  }
    return winner;         }

char checkdiagonale_f(tabellaf tabella2) {
    int i=0;
    int j=0;
    int x=0;
    int y=0;
    int c=7;  // counter, aiuta a far shiftare la diagionale
    char winner = ' ';
    while (x<7 && c>=0) { // cambia diagonale da controllare da A a B e cosi via... |  /////    |
        i=0;                                                    //                  | ///// --> |
        j=0;
        j=(7-c);  // avanza a destra, quindi di colonne
        while (i<7 && j<7) { // partendo dal basso, va più a fondo in alto a destra nella diagonale fino a toccare l'altra estremità della tabella
            if (tabella2.valori[i][j] == gamer && tabella2.valori[i+1][j+1] == gamer && tabella2.valori[i+2][j+2] == gamer && tabella2.valori[i+3][j+3] == gamer) {
                winner = gamer;
                return winner; }
            if (tabella2.valori[i][j] == compiuter && tabella2.valori[i+1][j+1] == compiuter && tabella2.valori[i+2][j+2] == compiuter && tabella2.valori[i+3][j+3] == compiuter) {
                winner = compiuter;
                return winner; }
            i++;
            j++;
        }
        x++;   
        c--;    }
    i=0;
    j=0;
    x=0;
    c=7;
    while (x<7 && c>=0) { 
        i=0;
        j=0;                                    //                          | //    |      /'\ 
        i=(7-c); // avanza in alto, non a destra, quindi di righe           |//     |       |
        while (i<7 && j<7) { 
            if (tabella2.valori[i][j] == gamer && tabella2.valori[i+1][j+1] == gamer && tabella2.valori[i+2][j+2] == gamer && tabella2.valori[i+3][j+3] == gamer) {
                winner = gamer;
                return winner;  }
            if (tabella2.valori[i][j] == compiuter && tabella2.valori[i+1][j+1] == compiuter && tabella2.valori[i+2][j+2] == compiuter && tabella2.valori[i+3][j+3] == compiuter) {
                winner = compiuter;
                return winner;  }
            i++;
            j++;
        }
        x++;
        c--;    }
    i=0;
    j=0;
    x=0;
    c=7;
    while (x<7 && c>=0) { // stessa cosa ma diagonali da alto-sinistra a basso-destra
        i=6;
        j=0;
        j=(7-c);
        while (i>=3 && j<=5) { 
            if (tabella2.valori[i][j] == gamer && tabella2.valori[i-1][j+1] == gamer && tabella2.valori[i-2][j-2] == gamer && tabella2.valori[i-3][j-3] == gamer) {
                winner = gamer;
                return winner;  }
            if (tabella2.valori[i][j] == compiuter && tabella2.valori[i-1][j-1] == compiuter && tabella2.valori[i-2][j-2] == compiuter && tabella2.valori[i-3][j-3] == compiuter) {
                winner = compiuter;
                return winner;  }
            i--;
            j++;
        }
        x++;
        c--;    }
    i=0;
    j=0;
    c=7;
    x=0;
    while (x<7 && c>=0) { 
        i=6;
        j=0;
        i=(7-c); // avanza in alto, non a destra, quindi di righe
        while (i>=3 && j<=5) { 
            if (tabella2.valori[i][j] == gamer && tabella2.valori[i-1][j+1] == gamer && tabella2.valori[i-2][j+2] == gamer && tabella2.valori[i-3][j+3] == gamer) {
                winner = gamer;
                return winner;  }
            if (tabella2.valori[i][j] == compiuter && tabella2.valori[i-1][j+1] == compiuter && tabella2.valori[i-2][j+2] == compiuter && tabella2.valori[i-3][j+3] == compiuter) {
                winner = compiuter;
                return winner;  }
            i--;
            j++;
        }
        x++;
        c--;    }
    return winner;
                  }

void vincitore_f(char winner) {
    if (winner == gamer) {
        printf("\n \033[36m BRAVO AI VINTP");
    }
    else if (winner == compiuter) {
        printf("\n \033[36m COIONE AI PERSP");
    }
    else {
        printf("\n \033[36m nesuno a vintp...");   }     }

void turnomio_f(tabellaf *tabella2) {
    char char_colonna;
    int colonna;
    player_f = gamer;
    disegno_f(*tabella2);
   do {
    printf("\n \033[36mChoose the column u wanna put X in: A-B-C-D-E-F-G, (not caps lock if u prefer) and press send\n");
    scanf("%c", &char_colonna);
    getchar();
    switch (char_colonna) {
        case 'A':
        colonna=0;
        break;
        case 'B':
        colonna=1;
        break;
        case 'C':
        colonna=2;
        break;
        case 'D':
        colonna=3;
        break;
        case 'E':
        colonna=4;
        break;
        case 'F':
        colonna=5;
        break;
        case 'G':
        colonna=6;
        break;
        case 'a':
        colonna=0;
        break;
        case 'b':
        colonna=1;
        break;
        case 'c':
        colonna=2;
        break;
        case 'd':
        colonna=3;
        break;
        case 'e':
        colonna=4;
        break;
        case 'f':
        colonna=5;
        break;
        case 'g':
        colonna=6;
        break;
        case '1':
        colonna=0;
        break;
        case '2':
        colonna=1;
        break;
        case '3':
        colonna=2;
        break;
        case '4':
        colonna=3;
        break;
        case '5':
        colonna=4;
        break;
        case '6':
        colonna=5;
        break;
        case '7':
        colonna=6;
        break;
        default:
        printf("\n \033[36mdude tf u typin??, type \"A\" or \"a\" or B/b or C/c or 1/2/3... \n");
        continue;  }
    if (tabella2->valori[6][colonna] != ' ') {
        printf("\n \033[36mdude that spot is already occupied, or it dont even exist cuh\n");  }
    else {
        posiziona_f(tabella2, colonna, gamer);
        break;
    }
   } while (1); /* (tabella2->valori[riga][colonna] != ' '); */        }

void turnomio2_f(tabellaf *tabella2) {
    char char_colonna;
    int colonna;
    player_f = compiuter;
    disegno_f(*tabella2);
   do {
    printf("\n \033[36mChoose the column u wanna put X in: A-B-C-D-E-F-G, (not caps lock if u prefer) and press send\n");
    scanf("%c", &char_colonna);
    getchar();
    switch (char_colonna) {
        case 'A':
        colonna=0;
        break;
        case 'B':
        colonna=1;
        break;
        case 'C':
        colonna=2;
        break;
        case 'D':
        colonna=3;
        break;
        case 'E':
        colonna=4;
        break;
        case 'F':
        colonna=5;
        break;
        case 'G':
        colonna=6;
        break;
        case 'a':
        colonna=0;
        break;
        case 'b':
        colonna=1;
        break;
        case 'c':
        colonna=2;
        break;
        case 'd':
        colonna=3;
        break;
        case 'e':
        colonna=4;
        break;
        case 'f':
        colonna=5;
        break;
        case 'g':
        colonna=6;
        break;
        case '1':
        colonna=0;
        break;
        case '2':
        colonna=1;
        break;
        case '3':
        colonna=2;
        break;
        case '4':
        colonna=3;
        break;
        case '5':
        colonna=4;
        break;
        case '6':
        colonna=5;
        break;
        case '7':
        colonna=6;
        break;
        default:
        printf("\n \033[36mdude tf u typin??, type \"A\" or \"a\" or B/b or C/c or 1/2/3... \n");
        continue;  }
    if (tabella2->valori[6][colonna] != ' ') {
        printf("\n \033[36mdude that spot is already occupied, or it dont even exist cuh\n");  }
    else {
        posiziona_f(tabella2, colonna, compiuter);
        break;
    }
   } while (1); /* (tabella2->valori[riga][colonna] != ' '); */        }

void posiziona_f(tabellaf *tabella2, int colonnaa, char user) {
    int i=0;
    int j=0;
    while (i<8) {
        if (tabella2->valori[i][colonnaa] != ' ') {
            i++;    }
        else {
            tabella2->valori[i][colonnaa] = user;
            break;   }
        }       }

void turnocompiuter_f(tabellaf *tabella2) {
    int ai;
    srand(time(0));
    int colonne;
    if (checkspazi_f(*tabella2) > 0) {
        ai=checkwinner2_f(*tabella2); // controlla se stai per vincere
        if (ai != 10) {
            posiziona_f(tabella2, ai, compiuter); // ti impedisce di vincere
            return; }
        do {
            colonne = rand() % 6;
        } while (tabella2->valori[6][colonne] != ' ');
        posiziona_f(tabella2, colonne, compiuter); 
    }
    else {
        vincitore_f(' ');    }        }

int checkwinner2_f(tabellaf tabella2) {  // controllo anti vincita easy
    int i=0;
    int j=0;
    if (checkorizz2_f(tabella2) != 10)   {
        return checkorizz2_f(tabella2);  }
    if (checkvertic2_f(tabella2) != 10)  {
        return checkvertic2_f(tabella2); }
    return 10;              }
int checkvertic2_f(tabellaf tabella2) {
    int i=0;
    int j=0;
    int x=10;
    int y=10;
    while (j<7) {
        i=0;
        while (i<7) {
            if (tabella2.valori[i][j] == gamer && tabella2.valori[i+1][j] == gamer && tabella2.valori[i+2][j] == gamer && tabella2.valori[i+3][j] == ' ') {
                y=j;
                return y;  }
            i++;  }
        j++;  }
    return 10;          }
int checkorizz2_f(tabellaf tabella2) {
    int i=0;
    int j=0;
    int x=10;
    int y=10;
    while (i<7) {
        j=0;
        while (j<7) {
            if (tabella2.valori[i][j] == gamer && tabella2.valori[i][j+1] == gamer && tabella2.valori[i][j+2] == gamer && tabella2.valori[i][j+3] == ' ') {
                y=j+3;
                return y;  }
            j++;  }
        i++;  }
    return 10;         }
