#include <iostream>
#include <math.h>
#define LENGTH 10
using namespace std;

void matching (int armstrong, int number)
{
	if (armstrong==number)
	{
		cout << number << "\n";
	}
	return;
}

void digits_to_power (int v_input[], int v_output[], int exp, int loopsize, long int *armstrong_check)
{
	for (int i=0; i<=loopsize; i++)
	{
		*armstrong_check -= v_output[i];
		v_output[i] = pow(v_input[i], exp);
		*armstrong_check += v_output[i];
	}
	return;
}

int carry (int v[], int i)
 {
 	int loopsize;
	if (v[i]!=9)
	{
		v[i]++;
		loopsize = i+1;
	}
	else
	{
		v[i]=0;
		loopsize = carry (v, i+1);
	}
	return loopsize;
}

int main()
{
	int armstrong_candidate = 0;
	int digits_array[LENGTH] = {0};
	int power_array[LENGTH] = {0};
	int exponent = 0;
	int loopsize;
	long int armstrong_check = 0;

	while (digits_array[LENGTH-1] != 1)
	{
		armstrong_candidate++;
		loopsize = carry (digits_array, 0);
		if (loopsize>exponent)
		{
			exponent = loopsize;
		}
		digits_to_power (digits_array, power_array, exponent, loopsize, &armstrong_check);
		matching (armstrong_check, armstrong_candidate);
	}
	return 0;
}