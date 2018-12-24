/**
 * @file    fahr2celcius.c
 * @brief   This is a reproduction of an example from K&R's The C Programming
 *          Language. The important take-away in this example is that integer
 *          division truncates
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
    int fahr, celsius;

    int lower;  // lower limit of temperature scale
    int upper;  // upper limit
    int step;   // step size

    lower = 0;      
    upper = 300;    
    step = 20;      
    fahr = lower;
    
    /** The formula is not written as (5/9)*(F-32) as integer division truncates 
     * leading to (5/9) being evaluated as 0. 
     * %3d used in printf makes the value right-aligned; %03d would fill the 
     * blank spaces with '0's
     */
    while (fahr <= upper) {
        celsius = 5 * (fahr-32) / 9;
        printf("%3d\t%3d\n", fahr, celsius);
        fahr = fahr + step;
    }

    return 0;
}
