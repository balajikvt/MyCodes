/******************************************************************************
 * @file    char_io.c
 * @brief   This explores the character input output functions getchar() and 
 *          putchar() which are provided by the standard C library.
 *          getchar() receives a character from the standard input usually the
 *          keyboard, while putchar() sends a character to the standard output
 *          which is usually the display
 * @date    2018/07/05
 * @version 1.0
 * @author  kbalaji/balajikvt
 *****************************************************************************/

#include <stdio.h>

int main() {

    /* c must be large enough to store any character returned by the getchar()
     * routine in addition to the EOF signal (integer macro)
     * Ctrl+D in the command line corresponds to a EOF signal
     */
    int c;
    while( (c=getchar()) != EOF ) {
        putchar(c); 
    }
    printf("\n");
    printf("EOF [%d] received\n",EOF);

    return 0;
}
