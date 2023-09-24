
/*


Si scriva un programma C che legga due serie di dati e li memorizzi in due vettori di strutture. Nel primo vettore M (di dimensione 3) vengono memorizzati dati del tipo: 
<matricola, nome, cognome>. Si noti che la matricola identifica univocamente uno studente e che non ci sono due strutture che contengono lo stesso numero di matricola.

Nel secondo vettore V (di dimensione 7) vengono memorizzati dati del tipo: <matricola, esame, voto>. Possono esserci più record con lo stesso numero di matricola che denotano 
diversi esami fatti dallo stesso studente.

Si scriva un programma che tramite opportune procedure legga i dati in ingresso e li inserisca nei due vettori. Successivamente per ogni studente con matricola 
X contenuto nel vettore M sommi tutti i suoi voti ottenuti negli esami contenuti nel vettore V.

*/

#include <stdio.h>
#include <iostream>

using namespace std;

#define N 3
#define M 7

typedef struct studente
{
    int matricola;
    char Nome[20];
    char Cognome[20];
} Studente;

typedef struct esame
{
    int matricola;
    char esame[20];
    int voto;
} Esame;

void leggi_studente(int n, Studente studenti[]);
void leggi_esami(int n, Esame esami[], Studente studenti[]);
int somma(Studente studente, Esame esami[]);

int main()
{
    int i, S = 0;
    Studente studenti[N];
    Esame esami[M];
    leggi_studente(N, studenti);
    leggi_esami(M, esami, studenti);
    for (i = 0; i < N; i++)
    {
        S = somma(studenti[i], esami);
        cout << "Studente \n" << studenti[i].Cognome << ", " << studenti[i].Nome << endl;
        cout << "Somma voti: \n" << S;
    }
}

void leggi_studente(int n, Studente studenti[])
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        cout << endl << "Inserisci Matricola, Nome, Cognome\n";
        bool check;
        do {
            check = false;
            cin >> studenti[i].matricola;
            for(int j = 0; j < i; j++) {
                if(studenti[i].matricola == studenti[j].matricola) {
                    cout << endl << "Matricola già presente" << endl;
                    check = true;
                }
            }
        } while(check);
        cin.ignore(100, '\n');
        cin.getline(studenti[i].Nome, 100, '\n');
        cin.getline(studenti[i].Cognome, 100, '\n');
    }
}

void leggi_esami(int n, Esame esami[], Studente studenti[])
{
    int i;
    for (i = 0; i < n; i++)
    {
        cout << endl << "Inserisci Matricola, Esame, Voto\n";
        bool check;
        do {
            check = false;
            cin >> esami[i].matricola;
            for(int j = 0; j < N; j++) {
                if(esami[i].matricola == studenti[j].matricola) {
                    check = true;
                }
            }
            if(!check) {
                cout << endl << "Matricola non presente" << endl;
            }
        } while(!check);
        cin.ignore(100, '\n');
        cin.getline(esami[i].esame, 100, '\n');
        cin >> esami[i].voto;
    }
}

int somma(Studente studente, Esame esami[])
{
    int i;
    int S = 0;
    for (i = 0; i < M; i++)
        if (esami[i].matricola == studente.matricola)
            S = S + esami[i].voto;
    return S;
}