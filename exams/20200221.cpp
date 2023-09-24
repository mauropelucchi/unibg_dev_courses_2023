/*

INFORMATICA 12 CFU – Modulo di Programmazione (ING. INFORMATICA)
Prof. G. PSAILA
APPELLO DEL 21/02/2020


Si consideri un programma per gestire la raccolta delle informazioni relative agli abbonamenti ad un parcheggio. Un abbonamento è descritto da un tipo strutturato denominato 
ABBONAMENTO, i cui campi sono un codice di 10 caratteri (che identifica univocamente l’abbonamento), la data di emissione (stringa nel formato internazionale aaaa-mm-gg ), 
la data di scadenza, il numero di targa (stringa di 10 caratteri), l’importo residuo (numero in virgola mobile), il valore dell’ultimo addebito e la data dell’ultimo addebito..
Si definisca quindi la struttura dati per una lista dinamica dove il campo informativo del nodo è a sua volta basato sul tipo ABBONAMENTO.
Si scriva la funzione denominata SpostaAbbonamenti che riceve come parametri due liste di abbonamenti, denominate rispettivamente lista1 e lista2, un vettore di stringhe 
(vettore di puntatori a carattere) denominato elencoCodici, ed un parametro size (numero intero) che indica quanti sono gli elementi nel vettore elencoCodici. Per ogni 
codice presente nel vettore elencoCodici, la funzione verifica se il codice è presente in lista1: se un abbonamento con il codice cercato non è presente in lista1, 
lo cerca in lista2 e, se lo trova, copia l’abbonamento in questione in lista1.
La funzione restituisce il numero di abbonamenti copiati da lista2 a lista1; in caso di errore, la funzione restituisce -1.


*/

#include <cstring>

struct ABBONAMENTO
{
    char codice[11];
    char data_emissione[11];
    char data_scadenza[11];
    char targa[11];
    float importo_residuo;
    float ultimo_addebito;
    char data_ultimo_addebito[11];
};

struct NODO
{
    ABBONAMENTO info;
    NODO *next;
};

NODO *cerca(NODO *head, char codiceCercato[])
{
    NODO *p;
    for (p = head; p != NULL; p = p->next)
    {
        if (strcmp(p->info.codice, codiceCercato) == 0)
            return p;
    }
    return NULL;
}

int ins_testa(NODO *&head, NODO *pAbbonamento)
{
    NODO *t;
    t = new NODO;
    if (t == NULL)
        return 1;
    t->info = pAbbonamento->info;
    t->next = head;
    head = t;
    return 0;
}
int SpostaAbbonamenti(NODO *&lista1, NODO *lista2, char *elencoCodici[], int size)
{
    NODO *ricerca1;
    NODO *ricerca2;
    int i;
    int contatore = 0;
    for (i = 0; i < size; i++)
    {
        ricerca1 = cerca(lista1, elencoCodici[i]);
        if (ricerca1 == NULL)
        {
            ricerca2 = cerca(lista2, elencoCodici[i]);
            if (ricerca2 != NULL)
            {
                if (ins_testa(lista1, ricerca2) != 0)
                    return -1;
                contatore++;
            }
        }
    }
    return contatore;
}