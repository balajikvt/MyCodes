#ifndef TRANSLATION_UNIT_1
#define TRANSLATION_UNIT_1

static int tl1ProtectedVar = 0;

static void TL1_ProtectedFunc_1(int val)
{
    tl1ProtectedVar = val;
}

static int TL1_ProtectedFunc_2(void)
{
    return tl1ProtectedVar;
}

#endif // TRANSLATION_UNIT_1
