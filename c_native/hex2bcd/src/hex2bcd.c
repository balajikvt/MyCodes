#include <stdio.h>

unsigned char hexIn = 0x12;
unsigned char bcdOut;

int main(int argc, char* argv[]) {

//    printf("Enter HEX byte: ");
//    scanf("%02x",&hexIn);

    char bcdOut_l, bcdOut_u;

    bcdOut_l = (hexIn % 10) & 0x0F;
    printf("%02x\n",bcdOut_l);

    bcdOut_u = ((hexIn / 10) << 4) & 0xF0;
    printf("%02x\n",bcdOut_u);

    bcdOut = bcdOut_u | bcdOut_l;
    printf("%02x\n",bcdOut);
    return 0;

}
