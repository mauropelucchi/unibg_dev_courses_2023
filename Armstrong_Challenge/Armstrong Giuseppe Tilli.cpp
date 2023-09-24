#include <iostream>
#include <climits>
#include <chrono>

//#pragma GCC optimize("Ofast")

using namespace std;
unsigned long long powOf(int base, int exp)
{
    if (base <= 0)
    {
        return 0;
    }
    if (exp <= 0)
    {
        return 1;
    }

    unsigned long long result = 1;
    unsigned long long overflowCheck;
    for (int i = 1; i <= exp; i++)
    {
        overflowCheck = result;
        result *= base;

        if (result / base != overflowCheck)
        {
            // come affrontare questa possibilità?
            cout << "Errore: overflow  " << base << " elevato " << exp << endl;
            return -1;
        }
    }
    return result;
}
int getNumDigits(unsigned long long number)
{
    int numDigits = 1;
    while ((number /= 10) > 0)
    {
        numDigits++;
    }
    return numDigits;
}

void updatePowersArray(unsigned long long *powers, int exponent)
{
    for (int i = 0; i < 10; i++)
    {
        powers[i] = powOf(i, exponent);
    }
}
void updateDigitsFrequencyMaxValues(int *digitsFrequencyMaxValues, unsigned long long *powers, int numDigits, unsigned long long upperLengthLimit)
{
    for (int i = 0; i < 10; i++)
    {
        digitsFrequencyMaxValues[i] = (i == 0 ? upperLengthLimit : upperLengthLimit / powers[i]);
        if (digitsFrequencyMaxValues[i] > numDigits)
        {
            digitsFrequencyMaxValues[i] = numDigits;
        }
    }
}
void updateDigitsFrequency(int *digits, int *digitsFrequency, int numDigits)
{

    for (int i = 0; i < 10; i++)
    {
        digitsFrequency[i] = 0;
    }
    for (int i = 0; i < numDigits; i++)
    {
        digitsFrequency[digits[i]]++;
    }
}
bool isUnderFlow(int *digitsFrequency, int *digitsFrequencyMaxValues)
{
    for (int i = 9; i >= 0; i--)
    {
        if (digitsFrequency[i] > digitsFrequencyMaxValues[i])
        {
            return 0;
        }
    }
    return 1;
}
bool isArmstrong(unsigned long long sum, int *digitsFrequency, int numDigits)
{

    int comparedDigits = 0;
    bool enoughDigits;
    do
    {
        int digitToCompare = sum % 10;
        digitsFrequency[digitToCompare]--;
        enoughDigits = digitsFrequency[digitToCompare] >= 0;
        sum /= 10;
        if (enoughDigits)
        {
            comparedDigits++;
        }

    } while (sum != 0 && enoughDigits);

    return (comparedDigits == numDigits);
}

void updateCombination(int *digitsArray, int numDigits)
{
    for (int i = numDigits - 1; i < numDigits; i--)
    {
        if (digitsArray[i] > 0)
        {
            digitsArray[i]--;
            if (digitsArray[i] != 0 && i < numDigits)
            {
                for (int nextDigit = i + 1; nextDigit < numDigits; nextDigit++)
                {
                    digitsArray[nextDigit] = digitsArray[i];
                }
            }
            break;
        }
    }
}
void displayResult(unsigned long long armstrong, int numDigits)
{
    cout << "Numero di Armstrong massimo trovato per " << numDigits << " cifre: " << armstrong << endl;
}
int main()
{
    auto start = chrono::steady_clock::now();

    int digitsFrequency[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    unsigned long long powers[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    // int digitsFrequencyMaxValues[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    unsigned long long systemMax = ULLONG_MAX;

    unsigned long long lowerLengthLimit;
    unsigned long long upperLengthLimit;

    int numDigits = getNumDigits(systemMax);

    while (numDigits > 1)
    {
        int digitsArray[numDigits];
        unsigned long long maxArmstrong = 0;
        for (int i = 0; i < numDigits; i++)
        {
            digitsArray[i] = 9;
        }
        lowerLengthLimit = powOf(10, numDigits - 1);
        upperLengthLimit = (lowerLengthLimit * 10) - 1;
        updatePowersArray(powers, numDigits);
        //  updateDigitsFrequencyMaxValues(digitsFrequencyMaxValues, powers, numDigits, upperLengthLimit);
        int allZeros = 0;
        do
        {

            //  if (isUnderFlow(digitsArray, digitsFrequencyMaxValues))
            // {
            unsigned long long sum = 0;
            for (int i = 0; i < numDigits; i++)
            {
                sum += powers[digitsArray[i]];
                if (sum > upperLengthLimit)
                {
                    goto skipToNextCombination;
                }
            }
            if (sum < lowerLengthLimit)
            {
                goto skipToNextCombination;
            }

            if (isArmstrong(sum, digitsFrequency, numDigits))
            {

                if (sum > maxArmstrong)
                {
                    maxArmstrong = sum;
                }
            }
        // }
        skipToNextCombination:
            updateCombination(digitsArray, numDigits);
            updateDigitsFrequency(digitsArray, digitsFrequency, numDigits);
            allZeros = digitsFrequency[0] == numDigits;

        } while (!allZeros);
        if (maxArmstrong > 0)
        {
            displayResult(maxArmstrong, numDigits);
            break;
        }
        numDigits--;
    }
    auto end = chrono::steady_clock::now();
    chrono::duration<double> elapsed_seconds = end - start;
    cout << "tempo: " << elapsed_seconds.count() << "s\n";
    return 0;
}