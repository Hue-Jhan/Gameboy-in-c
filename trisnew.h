#ifndef TRISNEW
#define TRISNEW
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <time.h>
#define dimt 3

typedef struct {
    int righe;
    int colonne;
    char valori[dimt][dimt];
} tabellat;
char risposta_t;
int  modalita_t;
char player_t;
void clrscr();
void turnomio_t(tabellat *tabella1);
void turnomio2_t(tabellat *tabella1);
void reset_t(tabellat *tabella1);
void turnocompiuter_t(tabellat *tabella1);
void vincitore_t(char winner);
char checkwinner_t(tabellat tabella1);
int  checkspazi_t(tabellat tabella1);
int  disegno_t(tabellat tabella1);
int  valoriiniziali_t(tabellat *tabella1);
int  checkwinnerX_t(tabellat tabella1);
int  checkwinnerY_t(tabellat tabella1);
void tris(tabellat tabella1);
#endif 
