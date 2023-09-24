/*
 *
 * Print Celsius to Fahrenheit table
 *
 */
#include <iostream>
using namespace std;

#define LOWER_LIMIT 0
#define HIGHER_LIMIT 50000

int main(int argc, char *argv[]) {
    double fahr, cel;
    int limit_low = -1;
    int limit_high = -1;
    int step = -1;
    int max_step_size = 0;
    
    /* Read in lower, higher limit and step */
    while(limit_low < (int) LOWER_LIMIT) {
        cout << "Please give in a lower limit, limit >= " << LOWER_LIMIT;
        cin >> limit_low;
    }
    while((limit_high <= limit_low) || (limit_high > (int) HIGHER_LIMIT)) {
        cout << "Please give in a higher limit " << limit_low << " < limit <= " << (int) HIGHER_LIMIT;
        cin >> limit_high;
    }
    max_step_size = limit_high - limit_low;
    while((step <= 0) || (step > max_step_size)) {
        cout << "Please give in a step, 0 < step <= " << max_step_size;
        cin >> step;
    }
    
    /* Initialise Celsius-Variable */
    cel = limit_low;
    
    /* Print the Table */
    printf("\nCelsius\t\tFahrenheit");
    printf("\n-------\t\t----------\n");
    while(cel <= limit_high) {
        fahr = (9.0 * cel) / 5.0 + 32.0;
        printf("%f\t%f\n", cel, fahr);
        cel += step;
    }
    printf("\n");
    
    return 0;
}

