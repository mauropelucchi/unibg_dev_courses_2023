
/*
Scrivere un programma (con funzioni!) per gestire un array di numeri interi.

In particolare il problema si occupa di generare un array di 50 numeri casuali compresi fra 1 e 100 e offrire a menu le seguenti scelte:
1. Calcolare la media
2. Visualizzare il massimo
3. Visualizzare il minimo
4. Rigenerare l’array
5. Visualizzare i valori che deltaano meno di 4 dalla media
6. Calcolare la moda
7. Uscire dal programma

nb. per generare numeri casuali usare vedere http://www.cplusplus.com/reference/cstdlib/srand/

*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
#define N 50

void genera(int a[N]);
float media(int a[N]);
int max(int a[N]);
int min(int a[N]);
void delta(int a[N]);
int moda(int a[N]);

int menu(void)
{
    int selezione = 0;
    do
    {
        cout << endl
             << "1 - Calcolare la media" << endl;
        cout << "2 - Massimo" << endl;
        cout << "3 - Minimo" << endl;
        cout << "4 - Rigenera array" << endl;
        cout << "5 - Visualizzare i valori che deltaano meno di 4 dalla media" << endl;
        cout << "6 - Calcolare la moda" << endl;
        cout << "7 - Esci" << endl;
        cout << "Effettua una scelta:" << endl;
        cin >> selezione;
    } while (selezione < 1 || selezione > 7);
    return selezione;
}

int main(void)
{
    int scelta;
    int massimo, minimo;
    float med;
    int m;
    int v[N];
    genera(v);

    while ((scelta = menu()) != 7)
    {
        switch (scelta)
        {
        case 1:
            med = media(v);
            cout << "Media: " << med << endl;
            break;
        case 2:
            massimo = max(v);
            cout << "Massimo: " << massimo << endl;
            break;
        case 3:
            minimo = min(v);
            cout << "Minimo: " << minimo << endl;
            break;
        case 4:
            genera(v);
            break;
        case 5:
            delta(v);
            break;
        case 6:
            m = moda(v);
            cout << "Moda: " << m << endl;
            break;
        }
    }
    return 0;
}

void genera(int a[N])
{
    int i;

    srand(time(NULL));
    for (i = 0; i < N; i++)
        a[i] = rand() % 100 + 1;

    cout << "Array generato " << endl;
    for (i = 0; i < N; i++)
        cout << a[i] << "\t";
}

float media(int a[N])
{
    int m = 0;
    int i;

    for (i = 0; i < N; i++)
    {
        m += a[i];
    }
    m = m / N;

    return m;
}

int max(int a[N])
{
    int massimo = a[0];
    int i;

    for (i = 0; i < N; i++)
        if (a[i] > massimo)
            massimo = a[i];

    return massimo;
}

int min(int a[N])
{
    int minimo = a[0];
    int i;

    for (i = 0; i < N; i++)
        if (a[i] < minimo)
            minimo = a[i];

    return minimo;
}

void delta(int a[N])
{
    float med = media(a);
    int i, delta1, delta2, trovato = 0;

    delta1 = med + 4;
    delta2 = med - 4;

    cout << "I valori sono che distano meno di 4 dalla media sono: " << endl;
    for (i = 0; i < N; i++)
    {
        if (a[i] > delta2 && a[i] < delta1)
        {
            cout << a[i] << " in posizione " << i << "\t";
            trovato = 1;
        }
    }

    if (trovato != 1)
        cout << " nessun elemento " << endl;
}

int moda(int a[N])
{
    int cont = 0, i, pos, moda, max = 1;

    for (int i = 0; i < N; i++)
    {
        cont = 0;
        for (int j = i + 1; j < N; j++)
        {
            if (a[i] == a[j])
            {
                cont++;
                pos = i;
            }
            if (cont > max)
            {
                max = cont;
                moda = pos;
            }
        }
    }
    return a[moda];
}