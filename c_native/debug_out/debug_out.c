#include <stdio.h>
#include <stdlib.h>
#include "debug_out.h"

#define DEBUG
#define MAX_DIVISOR 1000000000U

/**
 *  @brief  This function takes an unsigned integer as input and outputs a string
 *          containing its ASCII representaion Eg. 7628 = {0x37, 0x36, 0x32, 0x38}
 *  @param[in]  intVal   Integer to be converted
 *  @param[out] charBuf  Buffer holding converted string
 *  @param[out] charBufLen  Length of string in B
 */

void Conv_Int2String(unsigned int intVal, char* charBuf, unsigned char* charBufLen)
{
    int i = 0;
    int testVal = 1;
    int n = 0;
    int tempVal = intVal;
    char* pCharBuf;

    while(intVal > testVal)
    {
        testVal *= 10;
        n++;
    }

    testVal/=10;

    #ifdef DEBUG
    printf("Input Integer = %d; No. of Digits = %d\n\r", intVal, n);
    #endif // DEBUG

    pCharBuf = (char*)malloc((sizeof(char)*n) + 1);

    for(i=(n-1); i>=0; i--)
    {
        pCharBuf[i] = (tempVal%10) | 0x30;
        tempVal /= 10;
        #ifdef DEBUG
        printf("%d Char = %02x; TempVal = %d\n", i, pCharBuf[i], tempVal);
        #endif // DEBUG
    }
    charBuf[n] = '\0';
    *charBufLen = n;
    charBuf = pCharBuf;
}

static void Conv_Hex2String()
{

}

void Debug_Out(void* pBuf, int pBufLen, char dataType);
