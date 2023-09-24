#include <iostream.h>					
#include <cstring.h>					
					
#define MAX 50					
		

struct BIGLIETTO {
	char codice[16];
	char data_emissione[11];
	char data_viaggio[11];
	char numero_treno[11];
	char stazione_partenza[31];
	char stazione_arrivo[31];
	int classe;
	float prezzo;
};


struct NODO {
	BIGLIETTO dato;
	NODO *next;
};
			
NODO* BigliettiTreniSemiVuoti(NODO *listaIn, char data[], char *treni[], int size);					
bool VerificaDataAcquisto(BIGLIETTO b, char data[]);					
bool VerificaTreno(BIGLIETTO b, char * treni[], int size);					
bool VerificaNumeroBiglietti(NODO *listaIn, BIGLIETTO b);					
int  Inserimento_in_testa(NODO *&listaOut, BIGLIETTO b);					
					
					
NODO* BigliettiTreniSemiVuoti(NODO *listaIn, char data[], char *treni[], int size) {					
	NODO *listaOut = null;				
	NODO *p = listaIn;				
	while (p != null) {				
		bool condizione1 = VerificaDataAcquisto(p->dato, data);			
		bool condizione2 = VerificaTreno(p->dato, treni, size);			
		bool condizione3 = VerificaNumeroBiglietti(listaIn, p->dato);			
		if (condizione1 == true && condizione2 == true && condizione3 == true) {			
			int errore = Inserimento_in_testa(listaOut, p->dato);		
			if (errore != 0) {		
				return null;	
			}		
		}			
		p = p -> next;			
	}				
	return listaOut;				
}					
					
int  Inserimento_in_testa(NODO *&listaOut, BIGLIETTO b) {					
	NODO *t;				
	t = new NODO;				
	if (t == NULL) {				
		cout << "Memoria esaurita";			
		return 1;			
	}				
	t->dato = b;				
	t->next = listaOut;				
	listaOut = t;				
					
	return 0				
}					
					
bool VerificaDataAcquisto(BIGLIETTO b, char data[]) {					
	// verifica se il biglietto è stato acquistato in data = data in input				
	if (strcmp(b.data_emissione, data) == 0) {				
		return true;			
	}				
					
	return false;				
}					
					
bool VerificaTreno(BIGLIETTO b, char * treni[], int size) {					
	// controlla se il treno del biglietto b è presente nella lista treni				
	for (int i = 0; i < size; i++) {				
		if (strcmp(b.numero_treno, treni[i]) == 0) {			
			return true;		
		}			
	}				
					
	return false;				
					
}					
					
bool VerificaNumeroBiglietti(NODO *listaIn, BIGLIETTO b) {					
	// verifico che nella listaIn siano presenti <= di MAX biglietti per lo stesso treno e la stessa data				
	int contatore = 0;				
	while (listaIn != null) {				
		if ((strcmp(b.data_emissione, listaIn->dato.data_emissione) == 0) 			
			&& (strcmp(b.numero_treno, listaIn->dato.numero_treno) == 0)) {		
			contatore = contatore + 1;		
		}			
		if (contatore > MAX) {			
			return false;		
		}			
		listaIn = listaIn -> next;			
	}				
					
	return true;				
}					















