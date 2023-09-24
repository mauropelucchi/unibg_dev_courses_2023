/*

Si individui l'errore presente nel seguente programma. 
Si corregga l’errore lasciando invariata l’intestazione del sottoprogramma funz. 
Si indichino i valori stampati dall’istruzione cout << … del programma principale per effetto 
dell’esecuzione del programma corretto, nell’ipotesi che il valore letto dalla cin >> c sia 20, motivando la risposta.

*/

#include <iostream>
#include <cstdlib>
using namespace std;

void funz(int, int&);

int main( ){
    int e, f;
    f = 10;
    
    funz(f, e);
    
    cout << "f = " << f << "   e = " << e;
    
    system("PAUSE");
    return EXIT_SUCCESS;
}

void funz(int a, int b) {
    int c;

    cin >> c;
    b = a+c;
    a = b; 
}

/* Soluzione:
La definizione di funz non è compatibile con la dichiarazione del prototipo. Infatti, 
il sottoprogramma si aspetta di ricevere un parametro per reference come secondo parametro.
Supponendo che il valore letto da tastiera sia 20, i valori stampati nel programma principale 
per le variabili f ed e sono rispettivamente 10 e 30.

*/
