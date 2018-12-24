/**
 * @file    celsius2fahr.c
 * @brief   This program is a solution to Ex 1-3 & 1-4 in K&R's book
 *          This example introduces the for loop which is as generalization of
 *          the while loop.
 *          The choice between while() and for() is arbitrary, based on which 
 *          seems clearer. The for() loop is usually appopriate for loops in 
 *          which the initialization and increment are single statements and
 *          are logically related.
 * @date    2018/07/05
 * @version 1.0
 * @author  kbalaji/balajikvt
 */

#include <stdio.h>

/** It is better to use symbolic contants instead of 'magic' numbers in the 
 * program; this will improve code readability as well as facilitate changes 
 * to the code in a structured way
 */
#define LOWER   -20
#define UPPER   140
#define STEP    10

int main()
{
    float celsius;
    int lower, upper, step;

//  lower = -20;    /* lower limit of temperature scale */
//  upper = 140;    /* upper limit */
//  step = 10;      /* step size */
    
    printf("*************************\n");
    printf("Celsius |\tFarenheit\n");
    printf("*************************\n");
    /** The for loop consists of three parts; the initialization is done once 
     * before the loop is entered; the loop condition/test is then evaluated
     * and if true the body of the loop is executed; then the increment step
     * is evaluated and the condition is evaluated again. The loop executes 
     * till the condition becomes false
     */ 
//  for(celsius=lower; celsius<=upper; celsius+=step) {
//  for(celsius=upper; celsius>=lower; celsius-=step) {
    for(celsius=UPPER; celsius>=LOWER; celsius-=STEP) {
        printf("%3.0f\t|\t%5.1f\n", celsius, ( (9.0/5.0) * celsius ) + 32.0);
    }
    printf("*************************\n");

    return 0;
}
