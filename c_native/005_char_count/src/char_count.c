/******************************************************************************
 * @file    char_count.c
 * @brief   This program explores getchar putchar further along with for() loop
 *          example having the condition not dependent on the index.
 *          The execution of the program indicates that the even though we send 
 *          a character using putchar to the stdout, it is  displayed only on 
 *          the reception of a newline character. (Hypothesis)
 * @date    2018/07/05
 * @version 1.0
 * @author  kbalaji/balajikvt
 *****************************************************************************/

#include <stdio.h>

#define OUT     0
#define IN      1

int main() {

    double n_c, n_l, n_t, n_b;  /**< Counters for escape sequences*/
    double n_w;                 /**< Counter for number of words */
    int c;          /**< Variable to hold character input from stdin */
    int state;      /**< Variable stores if currently a word is being typed*/

    state = OUT;
    /** 
     * This line is equivalent to
     * n_c = (n_l = (n_t = (n_b = (n_w = 0))));
     */
    n_c = n_l = n_t = n_b = n_w = 0;

    /**
     * The if..else if...else is frequently used as a way to express a multi-way
     * decision. The conditions are evaluated from the top until some condition 
     * is satisfied, at which point the corresponding statement part is executed
     * and the enitre construct is finished
     */
    for(n_c=0; (c=getchar()) != EOF; n_c++) {
        if(c == '\n') {
            ++n_l;
            putchar('\\');
            putchar('n');
            state = OUT;
        } else if(c == '\t') {
            ++n_t;
            putchar('\\');
            putchar('t');
            state = OUT;
        } else if(c == '\b') {
            ++n_b;
            putchar('\\');
            putchar('b');
        } else if(c == '\\') {
            putchar('\\');
            putchar('\\');
        } else if(c == ' ') {
            putchar('_');
            state = OUT;
        } else {
            if(state == OUT) {
                putchar('\n'); 
                ++n_w;
                state = IN;
            }
            putchar(c);
        }
    } // END of for()

    printf("\n");
    printf("EOF [%d] received\n",EOF);
    printf("No of characters: %.0f\n",n_c);
    printf("No of words     : %.0f\n",n_w);
    printf("No of new lines : %.0f\n",n_l);
    printf("No of tab spaces: %.0f\n",n_t);
    printf("No of backspaces: %.0f\n",n_b);

    return 0;
}
