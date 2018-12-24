#ifndef DEBUG_OUT_H_
#define DEBUG_OUT_H_

#define DEBUGTYPE_STRING
#define DEBUGTYPE_INT
#define DEBUGTYPE_HEX

void Conv_Int2String(unsigned int intVal, char* charBuf, unsigned char* charBufLen);

void Debug_Out(void* pBuf, int pBufLen, char dataType);

#endif // DEBUG_OUT_H_
