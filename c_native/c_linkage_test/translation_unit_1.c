#include "translation_unit_1.h"

static int tl1PrivateVar = 0;

int tl1PublicVar = 0;       // By default not 'extern'; not visible in main

int TL1_PublicFunc_1(void)  // By default 'extern'; visible in main
{
    tl1PrivateVar++;
    return tl1PrivateVar;
}

int TL1_PublicFunc_2(void)
{
    tl1ProtectedVar+=10;
    return tl1ProtectedVar;
}
