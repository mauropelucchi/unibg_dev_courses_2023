/*

Tratto dalla Prima Prova in itinere a. a. 2011-2012

Si codifichi un programma C++ che legge da tastiera (lo standard input) una sequenza (di lunghezza arbitraria) 
di interi positivi nell’intervallo [1, M] (M arbitrariamente scelto dal programmatore); 
la lettura della sequenza termina inserendo il valore 0 e, al termine della sequenza, visualizza sullo schermo 
(lo standard output) un messaggio che riporta la Moda della sequenza inserita. 

La Moda è il valore della sequenza con la frequenza più alta (in caso di più di un valore con la frequenza più alta,
si scelga il valore più piccolo).

1. Scrivere una funzione  … Moda( … ), che riceve un vettore di interi di lunghezza M+1 contenente le frequenze
di ciascun valore intero, la quale restituisce il valore della Moda.

2. Scrivere il programma principale per rispondere alla specifica precedentemente descritta usando la funzione Moda.


*/

#include <iostream>
using namespace std;

#define M 7

int moda(float freq[], int len);

int main()
{

    float freq[M + 1] = {0.0};
    int i, val, num = 0, res;

    do
    {
        do
        {
            cout << endl
                 << "num = ";
            cin >> val;
        } while (val < 0 || val > M);
        freq[val] += 1.0;
        num++;
    } while (val != 0);
    num = num - 1; // scarto lo 0 dal conteggio
    if (num > 0)
    {
        for (i = 0; i <= M; ++i)
            freq[i] = freq[i] / num;
    }
    res = moda(freq, M + 1);
    cout << endl
         << "moda = " << res;

    // wait for user to hit enter or another key
    std::cin.sync();
    std::cout << "press enter to exit...";
    std::cin.ignore();
    //
    // for Windows Users use
    //
    // system("pause");
    return EXIT_SUCCESS;
} // end main

int moda(float freq[], int len)
{

    int i, res;
    float m = freq[1]; // per il calcolo del Massimo in freq[]

    res = 1;
    for (i = 2; i < len; i++)
    {
        if (freq[i] > m)
        {
            m = freq[i];
            res = i;
        } // end if
    }     // end for, i

    return res;
} // end modeAndMedian
