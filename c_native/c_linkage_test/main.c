#include <stdio.h>
#include <stdlib.h>
#include "translation_unit_1.h"     // Required only to bring protected variable in scope
//#include "translation_unit_2.h"

/** Public functions and variables (NOT 'static') can be accessed from anywhere in the program */
// Variable declaration
extern int tl1PublicVar;            // Required to establish linkage with public variable in TL1
extern int TL1_PublicFunc_1(void);  // Not required to access; but removes warning
int TL1_PublicFunc_2(void);         // extern is implied in function declarations

extern int tl2PublicVar;
//extern int tl2ConstVar;           // Constant declared static; not visible here
extern int TL2_PublicFunc_1(void);

int Main_PublicFunc_1(void);

int main()
{
    printf("Hello world!\n");
//    printf("TL1: Private Variable   = %d/n", tl1PrivateVar);  // ERROR!: Private variable hidden within TL1;
                                                                // not directly accessible
    printf("TL1: Private Variable    = %d\n", TL1_PublicFunc_1());
    printf("TL1: Protected Variable  = %d\n", tl1ProtectedVar+2);
    printf("TL1: Public Variable     = %d\n", tl1PublicVar+3);
    printf("TL2: Public Variable     = %d\n", tl2PublicVar+4);
    printf("TL2: Public Variable TL1 = %d\n", TL2_PublicFunc_1());
//    printf("TL2: Constant Variable  = %d\n", tl2ConstVar);    // Private constant; not visible here
    printf("TL1: Protected Var. Mod. = %d\n", TL1_PublicFunc_2());  // Output = 10
    printf("MAI: Protected Var. Mod. = %d\n", Main_PublicFunc_1()); // Output = 100
                                                                // This implies a static variable defined in
                                                                // the header file is a separate variable in
                                                                // each source file it is included in
    return 0;
}

int Main_PublicFunc_1(void)
{
    tl1ProtectedVar+=100;
    return tl1ProtectedVar;
}
