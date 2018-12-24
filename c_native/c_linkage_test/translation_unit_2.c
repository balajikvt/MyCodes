#include "translation_unit_2.h"

static const int tl2ConstVar = 256;

int tl2PublicVar = 0;

extern int tl1PublicVar;

int TL2_PublicFunc_1(void)  // By default 'extern'; visible in main
{
    tl1PublicVar++;
    return tl1PublicVar;
}
