/*

Realizzare un programma che legga tre valori interi (n1, n2, n3) compresi tra 1 e 100, estremi inclusi, e poi presenti a video il seguente menù di operazioni possibili:
A - somma tra n1, n2 e n3

B - prodotto tra n1 e n2
C - sottrazione tra n3 e n1
D - divisione tra n1 e n2 (risultato double). X - uscita dal programma

Legge poi un carattere da tastiera: se il carattere è tra quelli indicati nel menù, si deve eseguire l’operazione richiesta, stampare i numeri utilizzati 
nell’operazione e il risultato e poi ripresentare il menù altrimenti il carattere deve essere ignorato e si deve ripresentare solo il menù.

Nel caso il carattere sia X, il programma termina.
Nota: nel caso D è necessaria la conversione di almeno uno dei due operandi.

*/

#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
    int n1, n2, n3, somma, differenza, prodotto;
    double quoziente;
    char scelta;
    bool quit = false;
    cout << " Inserisci tre numeri interi compresi (1 <= n <= 100): ";
    do
    {

        cout << "\nNumero 1: ";
        cin >> n1;
        cout << "\nNumero 2: ";
        cin >> n2;
        cout << "\nNumero 3: ";
        cin >> n3;

    } while (n1 < 1 || n1 > 100 || n2 < 1 || n2 > 100 || n3 < 1 || n3 > 100);

    while (!quit)
    {

        cout << "\n Scegli tra le seguenti operazioni: ";
        cout << "\n A: Somma tra n1, n2 e n3.";
        cout << "\n B: Prodotto tra n1 e n2.";
        cout << "\n C: Sottrazione tra n3 e n1.";
        cout << "\n D: Divisione tra n1 e n2.";
        cout << "\n X: Esci dal programma.";
        cout << "\n \nScelta: ";
        cin >> scelta;

        if (scelta == 'A' || scelta == 'a')
        {
            somma = n1 + n2 + n3;
            cout << "\nSomma = " << n1 << " + " << n2 << " + " << n3 << " = " << somma << endl;
        }
        else if (scelta == 'B' || scelta == 'b')
        {
            prodotto = n1 * n2;
            cout << "\nProdotto = " << n1 << " * " << n2 << " = " << prodotto << endl;
        }
        else if (scelta == 'C' || scelta == 'c')
        {
            differenza = n3 - n1;
            cout << "\nSottrazione = " << n3 << " - " << n1 << " = " << differenza << endl;
        }
        else if (scelta == 'D' || scelta == 'd')
        {
            quoziente = (double)n1 / n2;
            cout << "\nDivisione = " << n1 << " / " << n2 << " = " << quoziente << endl;
        }
        else if (scelta == 'X' || scelta == 'x')
        {
            quit = true;
            cout << "\nProgramma interrotto con successo." << endl;
        }
        else
        {
            cout << "\nScelta non valida. " << endl;
        }
    }

    return 0;
}