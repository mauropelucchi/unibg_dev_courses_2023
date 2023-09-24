#include <iostream>
#include <cmath>
#include <time.h>
using namespace std;

//Il programma si ferma dopo aver calcolato fino ai numeri di questa lunghezza
long long digits = 10;

long long unitPowers[] = {0, 1, 8, 27, 64, 125, 216, 343, 512, 729};
long long tot = 9;
long long globalSum = 1;

void raiseExponent();
void findNumbers(long long);
void testNumber(long long*, long long);
long long arToNumber(long long*, long long);
void otherFindNumbers(long long);
void othertestNumber(long long);

void raiseExponent(){
    for (long long i=2; i<10; i++){
        unitPowers[i] *= i;
    }
}

void findNumbers(long long lenght){
    long long i = pow(10, lenght - 1) + 1;
    long long end = i*10;
    long long digits[lenght];
    digits[0] = 1;
    for (long long k=1; k<lenght; k++){
        digits[k] = 0;
    }

    long long kMax = lenght-1;

    for(; i < end; i++){
        for (long long k = kMax; k >= 0; k--){
            if (digits[k] < 9){
                digits[k]++;
                globalSum = globalSum + unitPowers[digits[k]] - unitPowers[digits[k]-1];
                break;
            }else{
                digits[k] = 0;
                globalSum = globalSum - unitPowers[9];
                //cout << globalSum << "sum\n";
            }
        }
        if (globalSum == i){
            cout << i<< "\n";
            tot++;
        }
        //testNumber(digits, lenght);
    }
    globalSum = 1;
}

/*void otherFindNumbers(long long lenght){
    long long i = pow(10, lenght - 1);
    long long end = i*10;
     for(; i < end-1; i++){
        othertestNumber(i);
    }
}*/

/*void otherTestNumber(long long n, long long lenght){
    int digits[lenght];
    for (int i=0; i<lenght; i++){
        digits[i] = n*pow(length*0.1)
    }
}*/

/*void testNumber(long long* n, long long lenght){
    //long long sum = 0;
    long long num = arToNumber(n, lenght);
    /*for (long long i=0; i<lenght; i++){
        sum += unitPowers[n[i]];
    }
    if (sum == num) 
    {
        cout << num << "\n";
        tot++;
    }
    if (globalSum == num){
        cout << num << "\n";
        tot++;
    }
}*/

/*long long arToNumber(long long*n, long long lenght){
    long long num = n[lenght-1];
    long long position = 10;
    for (long long k=lenght-2; k>=0; k--){
        num += n[k]*position;
        position *= 10;
    }
    return num;
}*/

int main(){
    cout << "1\n2\n3\n4\n5\n6\n7\n8\n9\n";
    time_t start = time(NULL);
    for (long long i=3; i<digits+1; i++){
        findNumbers(i);
        raiseExponent();
    }
    cout << "complete, " << tot << " numbers found\n";
    cout << "time: " << time(NULL) - start << " seconds";
    return 0;
}

