/*

Si consideri un array v[...] di n interi.
Si vuole scrivere un sottoprogramma per "esplorare" il vettore, iniziando dal primo elemento v[0]
e muovendosi con la regola descritta in seguito. 
Il sottoprogramma restituisce 0 e modifica il vettore inserendo in ogni cella il valore 0 se
l'esplorazione porta ad un percorso "infinito”, perché il vettore è ciclico, altrimenti restituisce 1 e
non modifica il vettore se a un certo punto termina.

*/

#include <iostream>
using namespace std;

int esplora(int v[], int n);

int main()
{

    int vett[8] = {3, 13, 5, 6, 2, 4, 2, -4};

    int res;

    res = esplora(vett, 8);

    if (res == 0)
        cout << "\n Vettore Ciclico!" << endl;
    else
        cout << "\n Vettore NON Ciclico!" << endl;


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

int esplora(int v[], int n)
{

    int pos, val, count = 0;

    pos = 0;
    while (pos >= 0 && pos < n && count < n)
    {
        val = v[pos];
        count++;
        pos = val;
    } // end while

    if (pos < 0 || pos > n)
        return 1;

    for (pos = 0; pos < n; pos++)
        v[pos] = 0;
    return 0;

} // end esplora
