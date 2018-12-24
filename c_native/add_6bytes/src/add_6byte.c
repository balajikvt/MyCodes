/**
 *  @file       add_6byte.c
 *  @brief      This source file implements a 6 byte addition
 *
 *  Mathematical operations on numbers larger than those supported by the 
 *  processor ALU must be carried out by dividing the operands into smaller
 *  chunks such as bytes or words. In this particular case, adding two 6 byte
 *  numbers can be accomplished by casting them as long long integers (8 byte)
 *
 *  @date       2018/07/03
 *  @version    1.0
 *  @author     kbalaji/balajikvt
 */

/* STD C LIB INCLUDES */
#include <stdio.h>

/* MACROS */
#define LEN6    6

/* USER DATA TYPES */
/** @defgroup Byte-6_datatype 6 Byte datatype
 * @{
 */

/**
 *  @brief  Represents a 6 byte integer; declared as long long for simpler math
 *          operations
 */
typedef union _var_6_byte_t_ {
    long long int ll_val;           /**< 64 bit integer representation */
    unsigned char byte_arr[LEN6];   /**< 6 byte array to hold value */
} var_6_byte_t;

/**
 * @}
 */

/* GLOBAL VARIABLE */
var_6_byte_t var1;      /**< 6 byte operand 1 */
var_6_byte_t var2;      /**< 6 byte operand 2 */
var_6_byte_t var1_le;   /**< 6 byte operand 1: Little Endian version */
var_6_byte_t var2_le;   /**< 6 byte operand 2: Little Endian version */

/* MAIN APPLICATION ROUTINE */
/**
 * @brief   The main application routine
 * @param   argc Number of command line arguments
 *          argv Array of string arguments
 * @return  0 on success
 */
int main(int argc, char* argv[]) {

    int i;
    /// Initialize test variable 1
    for(i=0; i<LEN6; i++) {
        var1.byte_arr[i] = ( (0x11 + (0x11*i)) & 0xFF );
        printf("ARR[%d] = %02x\n", i, var1.byte_arr[i]);
    }
    printf("LL VAL = %llx\n", var1.ll_val);

    /// Initialize test variable 2
    for(i=0; i<LEN6; i++) {
        var2.byte_arr[i] = 0xCC;
        printf("ARR[%d] = %02x\n", i, var2.byte_arr[i]);
    }
    printf("LL VAL = %llx\n", var2.ll_val);

    // Wrong way to add! Does not work as intended in little endian systems
/*    
    var1.ll_val += var2.ll_val;
    for(i=0; i<LEN6; i++) {
        printf("ARR[%d] = %02x\n", i, var1.byte_arr[i]);
    }
    printf("LL VAL = %llx\n", var1.ll_val);
*/
    // One right way to do the addition in a little endian system
    /// Arrays store multibyte values in big endian format (MSB first)

    /// In little endian systems, reverse the byte ordering of test variables
    for(i=0; i<LEN6; i++) {
        var1_le.byte_arr[i] = var1.byte_arr[LEN6-1-i];
    }
    printf("VAR1 = 0x%llx\n", var1_le.ll_val);

    for(i=0; i<LEN6; i++) {
        var2_le.byte_arr[i] = var2.byte_arr[LEN6-1-i];
    }
    printf("VAR2 = 0x%llx\n", var2_le.ll_val);

    /// Add the two 6 byte numbers now as long long ints
    var1_le.ll_val += var2_le.ll_val;
    for(i=0; i<LEN6; i++) {
        printf("ADD[%d] = %02x\n", i, var1_le.byte_arr[i]);
    }
    printf("VAR1+VAR2 = 0x%llx\n", var1_le.ll_val);

    return 0;
}
