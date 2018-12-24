#include <stdio.h>
#include "debug_out.h"


int main(void)
{
    int intVal = 87332;
    char* pCharBuf;
    unsigned char charBufLen;
    int i;

    Conv_Int2String(intVal, (char*)pCharBuf, &charBufLen);

    for(i=charBufLen; i>0; i--)
    {
        printf(pCharBuf[i]);
    }
    printf("\n");

    return 0;
}
