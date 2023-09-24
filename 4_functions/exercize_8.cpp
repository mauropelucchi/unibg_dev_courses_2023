/*

Data una sequenza di numeri interi, positivi e negativi, in valore assoluto minori di MAX_NUM,
si vuole sapere qual è la porzione di sequenza (fatta di elementi consecutivi) che rende massima la somma dei suoi elementi.

Scrivere un sotto-programma che restituisca le posizioni d'inizio e di fine della porzione di sequenza
individuata e restituisca anche il valore della somma degli interi nella sottosequenza.


*/

#include <cstdlib>
#include <iostream>

using namespace std;
#define MAX_NUM 35535

int sottoseq(int v[], int len, int &sx, int &dx);

int main(int argc, char *argv[])
{

    //int v[]= {8,-1,-1,-1,-1,-1,-1,-1,8,8};//sx = 1a,dx = 10a,max = 17;
    //int v[]= {7,-1,-1,-1,-1,-1,-1,-1,8,8};//sx = 1a,dx = 10a,max = 16;
    //int v[]= {6,-1,-1,-1,-1,-1,-1,-1,8,8};//sx = 9a,dx = 10a,max = 16;
    //int v[]= {6,-1,-1,-1,-1,-1,-1,-1,-1,-1};//sx = 1a,dx = 1a,max = 6;
    //int v[]= {-1,-1,-1,-1,-1,-1,-1,-1,-1,0};//sx = 10a,dx = 10a,max = 0;
    //int v[]= {-2,-1,-2,-1,-1,0,-1,-1,-1,-2};//sx = 6a,dx = 6a,max = 0;

    int v[] = {10, -21, 17, 16, 2, -37, -4, 17, -10, 12};
    int len = 10;
    int maxSum, isx, idx;

    maxSum = sottoseq(v, len, isx, idx);

    cout << "\n isx = " << isx + 1;
    cout << "\n idx = " << idx + 1;
    cout << "\n La somma e': " << maxSum;

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

int sottoseq(int v[], int len, int &sx, int &dx)
{

    int i, j, sum, maxSum, ind_sx, ind_dx;
    maxSum = -(MAX_NUM + 1);
    ind_sx = 0;
    ind_dx = 0;

    for (i = 0; i < len; i++)
    {
        sum = v[i];
        for (j = i + 1; j < len; j++)
        {
            sum = sum + v[j];
            if (sum > maxSum)
            {
                maxSum = sum;
                ind_sx = i;
                ind_dx = j;
            }
        }
    }

    sx = ind_sx;
    dx = ind_dx;

    return maxSum;
}
