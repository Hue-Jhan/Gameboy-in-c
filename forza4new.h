#ifndef FORZA4NEW
#define FORZA4NEW
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <time.h>
#define dimf 7

typedef struct {
    int righe;
    int colonne;
    char valori[dimf][dimf];
} tabellaf;
char risposta_f;
int  modalita_f;
char player_f;

void clrscr_f();
void turnomio_f(tabellaf *tabella2);
void turnomio2_f(tabellaf *tabella2);
void posiziona_f(tabellaf *tabella2, int colonnaa, char user);
void reset_f(tabellaf *tabella2);
void turnocompiuter_f(tabellaf *tabella2);
void vincitore_f(char winner);
char checkwinner_f(tabellaf tabella2);
char checkorizz_f(tabellaf tabella2);
char checkvertic_f(tabellaf tabella2);
char checkdiagonale_f(tabellaf tabella2);
int  checkspazi_f(tabellaf tabella2);
int  checkwinner2_f(tabellaf tabella2);
int  checkorizz2_f(tabellaf tabella2);
int  checkvertic2_f(tabellaf tabella2);
int  disegno_f(tabellaf tabella2);
int  valoriiniziali_f(tabellaf *tabella2);
void forza4(tabellaf tabella2);

#endif
