#include <stdio.h>

/* print Fahrenheit-Celsius table
 * for fahr = 0, 20, ..., 300 */
int main()
{
    float fahr, celsius;
    float lower, upper, step;

    lower = -20;      /* lower limit of temperature table */
    upper = 150;    /* upper limit */
    step = 20;      /* step size */

    celsius = lower;
    puts("fahr celsius");
    puts("==== =======");
    while (celsius <= upper) {
        /*celsius = (5.0/9.0) * (fahr-32.0);*/
        fahr = (celsius / (5.0/9.0)) + 32.0;
        /*printf("%3.0f %6.1f\n", fahr, celsius);*/
        printf("%6.1f %3.0f\n",  celsius, fahr);
        celsius = celsius + step;
    }

    return 0;
}

