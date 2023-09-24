/*
Acquire from the keyboard the coordinates of three points in the Cartesian plane,
recognise if they can represent the vertices of a triangle that is not degenerate and, if so, 
show its perimeter on the screen, even if the triangle is: equilateral, isosceles, scalene or rectangle.                               

*/

#include <iostream>
#include <cmath>    // to import sqrt(...), abs(...)
#include <iomanip>

using namespace std;
int main() {
    
   float ax,ay;
   float bx,by;
   float cx,cy;
   
   float lab, lac, lbc;
   float perimeter;
   
   cout << "\n Digit ax: "; cin >> ax;
   cout << "\n Digit ay: "; cin >> ay;
   
   cout << "\n Digit bx: "; cin >> bx;
   cout << "\n Digit by: "; cin >> by;

   cout << "\n Digit cx: "; cin >> cx;
   cout << "\n Digit cy: "; cin >> cy;

   lab = sqrt(((ax-bx)*(ax-bx)+(ay-by)*(ay-by))); 
   lac = sqrt(((ax-cx)*(ax-cx)+(ay-cy)*(ay-cy)));
   lbc = sqrt(((bx-cx)*(bx-cx)+(by-cy)*(by-cy)));
   
   if ( !(lab < lac+lbc && lac < lab+lbc && lbc < lab+lac) ) {
      cout << "\n Degenerate triangle !!! ";
   } else {
      if (lab == lac && lac == lbc) {
         cout << "\n Equilateral !!! ";   
      } else if ((lab == lac) || (lab == lbc) || (lac == lbc)) {
         cout << "\n Isosceles !!! ";   
      } else {
         cout << "\n Scalene !!! ";   
      }
      if (((lab*lab)-(lac*lac+lbc*lbc) < 1e-12) ||
         ((lac*lac)-(lab*lab+lbc*lbc) < 1e-12) ||
         ((lbc*lbc)-(lab*lab+lac*lac) < 1e-12)) {
            cout << "\n Rectangle !!! ";   
         }
   }
   
   perimeter = lab + lac + lbc;
   cout << endl << endl;
   cout << "Perimeter " << endl << endl;
   cout << setfill('.') << setw(5) <<  setprecision(4) << perimeter;
   cout << endl << endl;

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
