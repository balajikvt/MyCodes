/**
 * @file    fahr2celcius.c
 * @brief   This is a reproduction of an example from K&R's The C Programming
 *          Language. Introduces floating point numbers. 
 *          
 * @date    2018/07/05
 * @version 1.0
 * @author  kbalaji/balajikvt
 */

#include <stdio.h>

/** print Fahrenheit-Celsius table
 *        for fahr = 0, 20, ..., 300 
 */
int main()
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;      /* lower limit of temperature scale */
    upper = 300;    /* upper limit */
    step = 20;      /* step size */
    fahr = lower;
    
    /** No truncation as (5.0/9.0) is a floating point operation;
     * printf indicates C as 5 digits before and 1 digit after the decimal point.
     * This right aligns the values (But why 5? 4.1 fails to achieve the result)
     * The integer '32' in (fahr-32) is automatically typecast to a float before 
     * the subtraction is done, but writing it as 32.0 will indicate the float
     * nature of fahr to the human readers. The int->float conversion also 
     * happens in lines fahr = lower & while(fahr <= upper)
     */
    while (fahr <= upper) {
//      celsius = (5/9) * (fahr-32);
        celsius = (5.0/9.0) * (fahr-32);
        printf("%3.0f\t%5.1f\n", fahr, celsius);
        fahr = fahr + step;
    }

    return 0;
}
