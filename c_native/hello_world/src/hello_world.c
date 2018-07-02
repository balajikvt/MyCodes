/**
 *  @file       hello_world.c
 *  @note       A simple hello world program to get things started. 
 *              Usage: ./hello_world [name]
 *  @author     kbalaji/balajikvt
 *  @date       30/06/2018
 *  @version    1.0
 */

/* STANDARD C LIBRARY INCLUDES */
#include <stdio.h>

/* MAIN FUNCTION */

/**
 *  @brief  The main application routine
 *  @param [in] argc - The number of command line arguments the user has passed
 *  @param [in] argv - The list of all command line arguments as strings. The 
 *              fist argument is the command name
 *  @return 0
 */
int main(int argc, char* argv[])
{       
    printf("This is the %s program!\n",argv[0]);
    printf("Usage: %s [name]\n",argv[0]);
    if(argc == 2)
    {
        printf("Hello %s! Welcome!!\n", argv[1]);
    }
    else if(argc > 2)
    {
        printf("Hello! I kinda see too many arguments ...\n");    
    }
    else
    {
        printf("You didn't introduce yourself human ...\n");
    }
    return 0;
}
