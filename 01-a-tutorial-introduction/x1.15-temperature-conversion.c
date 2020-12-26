
#include <stdio.h>

float fahr(float celsius);

/* print Fahrenheit-Celsius table
 * for fahr = 0, 20, ..., 300 */
int main()
{
    float celsius;
    float lower, upper, step;

    lower = -20;      /* lower limit of temperature table */
    upper = 150;    /* upper limit */
    step = 20;      /* step size */

    celsius = lower;
    puts("  fahr | celsius");
    puts("====== | =======");
    while (celsius <= upper) {
        printf("%6.1f | %7.0f\n",  celsius, fahr(celsius));
        celsius = celsius + step;
    }

    return 0;
}

float
fahr(float celsius)
{
    return (celsius / (5.0/9.0)) + 32.0;
}

