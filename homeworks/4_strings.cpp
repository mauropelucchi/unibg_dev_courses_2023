
/*
****** Stringhe *****

Scrivere un programma che acquisita una frase permetta a scelta dell'utente di (attraverso un menu):
1. Stamparla
2. Stamparla invertita
3. Stampare la stringa in maiuscolo
4. Stamparla eliminando gli spazi
5. Contare il numero di parole presenti
6. Permetta di sostituire un carattere con un altro
7. Calcoli la ricorrenza di una determinata lettera dell'alfabeto sia essa minuscola o maiuscola
8. Uscire dal programma

*/

#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

int menu();
void clear_screen();
void lettura(char *);
void stampa(char *);
void inverti(char *, char *);
void maiuscolo(char *, char *);
void nospazi(char *, char *);
int numparole(char *);
void cambiacar(char *, char, char);
int ricorrenza(char *, char);

int main()
{
    int scelta;
    char frase[100];
    char frase1[100];
    char vecchio, nuovo;
    lettura(frase);
    do
    {
        scelta = menu();
        switch (scelta)
        {
        case 1:
            stampa(frase);
            break;
        case 2:
            inverti(frase, frase1);
            stampa(frase1);
            break;
        case 3:
            maiuscolo(frase, frase1);
            stampa(frase1);
            break;
        case 4:
            nospazi(frase, frase1);
            stampa(frase1);
            break;
        case 5:
            cout << "Numero di parole: " << numparole(frase) << endl;
            break;
        case 6:
            cout << "Carattere da sostituire : ";
            cin >> vecchio;
            cout << "Nuovo carattere : ";
            cin >> nuovo;
            cambiacar(frase, vecchio, nuovo);
            break;
        case 7:
            cout << "Carattere da esaminare : ";
            cin >> vecchio;
            cout << "Il carattere compare " << ricorrenza(frase, vecchio) << " volte " << endl ;
            break;
        }
    } while (scelta != 8);
    return 0;
}

int menu()
{
    int s;
    do
    {
        clear_screen();
        cout << " - 1 - Stampa" << endl;
        cout << " - 2 - Inverti" << endl;
        cout << " - 3 - Maiuscolo" << endl;
        cout << " - 4 - Senza Spazi" << endl;
        cout << " - 5 - Numero Parole" << endl;
        cout << " - 6 - Cambia carattere" << endl;
        cout << " - 7 - Ricorrenza di una lettera" << endl;
        cout << " - 8 - Esci" << endl;
        cout << "Inserire la scelta ";
        cin >> s;
    } while (s < 1 || s > 8);
    return (s);
}

void lettura(char *f)
{
    cout << "Inserire la frase : ";
    cin.getline(f, 100);
}

void stampa(char *f)
{
    cout << f;
}

void inverti(char *f, char *f1)
{
    int j;
    int len;
    len = strlen(f);
    f1 += len - 1;
    for (j = len - 1; j >= 0; j--)
    {
        *f1 = *f;
        f1--;
        f++;
    }
    *f1 = '\0';
}

void maiuscolo(char *f, char *f1)
{
    int len;
    int j;
    len = strlen(f);
    for (j = 0; j < len; j++)
    {
        if (*f >= 'a' && *f <= 'z')
            *f1 = *f - 32;
        else
            *f1 = *f;
        f++;
        f1++;
    }
    *f1 = '\0';
}

void nospazi(char *f, char *f1)
{
    int len;
    int j;
    len = strlen(f);
    for (j = 0; j < len; j++)
    {
        if (*f != ' ')
        {
            *f1 = *f;
            f1++;
        }
        f++;
    }
    *f1 = '\0';
}
int numparole(char *f)
{
    int nump = 0;
    int len;
    len = strlen(f);
    while (*f != '\0')
    {
        while (*f != ' ' && *f != '\0')
            f++;
        nump++;
        while (*f == ' ')
            f++;
    }
    return (nump);
}

void cambiacar(char *f, char v, char n)
{
    while (*f != '\0')
    {
        if (*f == v)
            *f = n;
        f++;
    }
}

int ricorrenza(char *f, char c)
{
    int conta = 0;
    while (*f != '\0')
    {
        if (*f == c)
            conta++;
        f++;
    }
    return (conta);
}


#include <cstdlib>

void clear_screen()
{
#ifdef WINDOWS
    std::system("cls");
#else
    // Assume POSIX
    std::system ("clear");
#endif
}