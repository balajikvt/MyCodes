/******************************************************************************
 * @file    histogram.c
 * @brief   This program addresses Ex. 1-13 & 1-14 from K&R's book; it explores 
 *          arrays
 * @date    2018/07/06
 * @version 1.0
 * @author  kbalaji/balajikvt
 ******************************************************************************/

#include <stdio.h>

/** @defgroup PublicMacros PUBLIC MACROS
 *  @{
 */ 
#define IN  1   /**< Indicates that the character being parsed is part of a word*/
#define OUT 0   /**< Indicates that the character being parsed is a whitespace */
#define H_HISTOGRAM_CHAR '|' /**< Character used to indicate one step in graph */ 
#define V_HISTOGRAM_CHAR '-' /**< Character used to indicate one step in graph */
#define VERTICAL    1   /**< Displays a vertical histogram */
#define HORIZONTAL  0   /**< Displays a horizontal histogram */
#define TRIM    0   /**< Used to suppress zero value entries in histogram data*/
#define NOTRIM  1   /**< Data displayed as is */
/**
 *  @}
 */ 

int wordLength[20]; /**< Array to hold the number of occurances of word lengths */
int charFreq[26];   /**< Array to hold the number of occurances of an alphabet */

static void DrawHorizontalHistogram(int *pData, int dataLen, int trimDisplay);
static void DrawVerticalHistogram(int *pData, int dataLen, int trimDisplay);
static void DrawHistogram(int *pData, int dataLen, int hgrmOrientation, int trimDisplay);

int main() 
{
    int i;
    int state;      /**< Variable to hold current 'word state' */ 
    int c;          /**< Variable to hold the input character stream */
    int wordChar;   /**< Number of characters in a word */

    state = OUT;
    wordChar = 0;

    /// Parse the input stream till EOF is reached
    while( (c=getchar()) != EOF ) {
        /// If whitespace received, change state to OUT
        if( (c=='\n') || (c=='\t') || (c==' ') ) {
            if(state == IN) {
                state = OUT;
                ++wordLength[wordChar];
            }
            wordChar = 0;
        } 
        /// Else, a character is received
        else { 
            /// If first character ...
            if(state == OUT) {
                state = IN;
            }
            if( (c>='A') && (c<='Z') ) {
                ++charFreq[c-'A'];
            }
            if( (c>='a') && (c<='z') ) {
                ++charFreq[c-'a'];
            }
            ++wordChar;
        }
    } // END of while()

    ///EOF received; process last word if any
    if(state == IN) {
        state = OUT;
        ++wordLength[wordChar];
    }
    wordChar = 0;

    printf("\n");
/*  /// DEBUG: The sizeof() function returns the size of the array in bytes
    for(i=0; i<( sizeof(wordLength)/sizeof(int) ); i++) {
        if(wordLength[i]!=0) {
            printf("%d : %d\n", i, wordLength[i]);
        }
    }
    for(i=0; i<( sizeof(charFreq)/sizeof(int) ); i++) {
        if(charFreq[i]!=0) {
            printf("%c : %d\n", 'A'+i, charFreq[i]);
        }
    }
*/
    /// Display the array as a histogram
    /// Horizontal histogram of the word size
//    DrawHorizontalHistogram(wordLength, sizeof(wordLength)/sizeof(int), NOTRIM); 
//    DrawVerticalHistogram(charFreq, sizeof(charFreq)/sizeof(int), NOTRIM); 
    DrawHistogram(wordLength, sizeof(wordLength)/sizeof(int), VERTICAL, TRIM); 
    DrawHistogram(charFreq, sizeof(charFreq)/sizeof(int), HORIZONTAL, TRIM); 

    printf("   ");
    for(i=0; i<( sizeof(charFreq)/sizeof(int) ); i++) {
        printf("%c ",'A' + i);
    }
    printf("\n");

    return 0;
}

static void DrawHorizontalHistogram(int *pData, int dataLen, int trimDisplay) 
{
    int i, j;
    printf("\n");
    for(i=0; i<dataLen; i++) {
        if( (pData[i] != 0) || (trimDisplay == NOTRIM) ) {
            printf("%3d", i);
            for(j=0; j<pData[i]; j++) {
                printf("%c", H_HISTOGRAM_CHAR);
            }
//          printf("(%d)", pData[i]);
            printf("\n");
        }
    }
}

static void DrawVerticalHistogram(int *pData, int dataLen, int trimDisplay)
{
    int i, j, max = 0;
    printf("\n");
    /// Find the maximum histogram 'depth'
    for(i=0; i<dataLen; i++) {
        max = (max < pData[i])? pData[i] : max;
    }
//  printf("%d\n",max); // DEBUG
    /// For each level from max, draw the character if bin value is more than or equal to current depth
    for(i=max; i>0; i--) {
        printf("%3d", i);
        for(j=0; j<dataLen; j++) {
            if( (trimDisplay == NOTRIM) || (pData[j] != 0) ) {
                if(pData[j] >= i) {
                    printf("%c ", V_HISTOGRAM_CHAR);
                } else {
                    printf("  ");
                }
            }
        } // END of for(j)
        printf("\n");
    } // END of for(i)
}

static void DrawHistogram(int *pData, int dataLen, int hgrmOrientation, int trimDisplay)
{
    if(hgrmOrientation == VERTICAL) {
        DrawVerticalHistogram(pData, dataLen, trimDisplay);
    } else {
        DrawHorizontalHistogram(pData, dataLen, trimDisplay);
    }
}
