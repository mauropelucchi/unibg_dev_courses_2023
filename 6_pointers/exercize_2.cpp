/*

Dichiarare un tipo per rappresentare i punti in un Piano Cartesiano.

(a)	Realizzare un sottoprogramma per l’acquisizione da stdin di un punto del Piano Cartesiano, esibendo due versioni del sottoprogramma: procedurale e funzionale:

void procedureGetPoint(Point *p)
Point functionGetPoint(void)

(b)	Realizzare un sotto-programma 

Point meanPoint(Point p1, Point p2)

      che dati due punti restituisce il punto medio del segmento che li congiunge.

(c)	Realizzare un sotto-programma 

double distance(Point p1, Point p2)

      che dati due punti restituisce la distanza tra i due.  Un triangolo può essere rappresentato con
      un vettore di tre punti:

typedef Point Triangle[3]

(d)	Realizzare un sotto-programma per l’acquisizione delle coordinate dei vertici di un triangolo nelle due versioni:

void GetTriangleWithFunction(Triangle t)
void GetTriangleWithProcedure(Point *t)

(e)	Scrivere un sotto-programma che verifichi se due triangoli sono uguali.

int testTriangles(Triangle t1, Triangle t2)


*/

#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

typedef struct punto
{
  double x;
  double y;
} Point;

typedef Point Triangle[3];

Point meanPoint(Point p1, Point p2);
double distance(Point p1, Point p2);
void procedureGetPoint(Point *p);
Point functionGetPoint(void);
void GetTriangleWithFunction(Triangle t);
void GetTriangleWithProcedure(Triangle *t);
int testTriangles(Triangle t1, Triangle t2);

int main()
{

  Point a, b, c;
  a = functionGetPoint();
  procedureGetPoint(&b);

  //b = functionGetPoint();
  cout << "\n dist = " << distance(a, b);
  c = meanPoint(a, b);
  cout << "\n mean = (" << c.x << ", " << c.y << ")";

  Triangle Fig1, Fig2;
  cout << "\n-- Triangle 1 -- \n";
  GetTriangleWithFunction(Fig1);
  cout << "\n-- Triangle 2 -- \n";
  GetTriangleWithProcedure(&Fig2);
  cout << "\n Test Result = " << testTriangles(Fig1, Fig2);

  // wait for user to hit enter or another key
  std::cin.sync();
  std::cout << "press enter to exit...";
  std::cin.ignore();
  //
  // for Windows Users use
  //
  // system("pause");
  return 0;
} // end main

Point meanPoint(Point p1, Point p2)
{
  Point mean;
  mean.x = (p1.x + p2.x) / 2;
  mean.y = (p1.y + p2.y) / 2;
  return mean;
} // end meanPoint

double distance(Point p1, Point p2)
{
  double d, xdiff, ydiff;
  xdiff = p1.x - p2.x;
  ydiff = p1.y - p2.y;
  d = sqrt(xdiff * xdiff + ydiff * ydiff);
  return d;
} // end distance

void procedureGetPoint(Point *p)
{
    cout << "\n Point coordinates: ";
    cout << "\n x = ";
    cin >> (p->x); // cin >> ((*p).x))
    cout << "\n y = ";
    cin >> (p->y);
} // end procedureGetPoint

Point functionGetPoint(void)
{
  Point p;
  cout << "\n Point coordinates: ";
    cout << "\n x = ";
    cin >> p.x;
    cout << "\n y = ";
    cin >> p.y;
    return p;
} // end functionGetPoint

void GetTriangleWithFunction(Triangle t)
{
  int i;
  for (i = 1; i <= 3; i++)
  {
    cout << "\n Vertex : " << i;
    t[i] = functionGetPoint();
  }
  return;
} // end GetTriangleWithFunction

void GetTriangleWithProcedure(Triangle *t)
{
  int i;
  for (i = 1; i <= 3; i++)
  {
    cout << "\n Vertex : " << i;
    procedureGetPoint(&(*(t[i])));
  }
  return;
} // end GetTriangleWithProcedure

void swapDoubles(double *one, double *two)
{
  double t = *one;
  *one = *two;
  *two = t;
} // end swapPoints

int testTriangles(Triangle t1, Triangle t2)
{

  double edgesT1[3], edgesT2[3];
  int i, count;

  for (i = 0; i < 3; i++)
  {
    edgesT1[i] = distance(t1[i], t1[(i + 1) % 3]);
    edgesT2[i] = distance(t2[i], t2[(i + 1) % 3]);
  }

  if (edgesT1[0] < edgesT1[1])
    swapDoubles(&edgesT1[0], &edgesT1[1]);
  if (edgesT1[0] < edgesT1[2])
    swapDoubles(&edgesT1[0], &edgesT1[2]);
  if (edgesT1[1] < edgesT1[2])
    swapDoubles(&edgesT1[1], &edgesT1[2]);

  if (edgesT2[0] < edgesT2[1])
    swapDoubles(&edgesT2[0], &edgesT2[1]);
  if (edgesT2[0] < edgesT2[2])
    swapDoubles(&edgesT2[0], &edgesT2[2]);
  if (edgesT2[1] < edgesT2[2])
    swapDoubles(&edgesT2[1], &edgesT2[2]);

  for (i = 0; (i < 3) && (edgesT1[i] == edgesT2[i]); i++)
    ;

  return (!(i == 3));
} // end testTriangles
