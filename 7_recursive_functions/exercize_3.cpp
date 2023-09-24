/*

Scrivere una funzione ricorsiva void BoomBang(int k) che stampa k volte la 
stringa “Boom” seguita dalla stampa della stringa “Bang” anche’essa k volte.

Esempio:
                 BoomBang(3)
                 output: Boom Boom Boom Bang Bang Bang

*/

void BoomBang(int k)
{
  if (k == 0)
    return;
  cout << "Boom ";
  BoomBang(k - 1);
  cout << "Bang ";
}
