/**
 * @file    clk_test.c
 * @brief   A program to test out C library functions
 * @date    2018/07/16
 * @version 1.0
 * @author  kbalaji/balajikvt
 */

#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <unistd.h>

int main() 
{

    int retVal;
    double timeTaken;
    struct timeval tv1, tv2; 

    timeTaken = (double) clock();
    gettimeofday(&tv1, NULL);
    printf("Going to sleep ...\n");
    retVal = sleep(5);
    if(retVal == 0) {
        printf("Waking up ...\n");
    } else {
        printf("Interrupted at %u seconds", retVal);
    }
    gettimeofday(&tv2, NULL);
    timeTaken = ( (double) clock() - timeTaken ) / CLOCKS_PER_SEC;
    printf("CPU time taken = %f\n", timeTaken);
    timeTaken = (double)(tv2.tv_usec - tv1.tv_usec) / 1000000 + (double)(tv2.tv_sec - tv1.tv_sec);
    printf("Total time taken = %f\n", timeTaken);

    return 0;

}
