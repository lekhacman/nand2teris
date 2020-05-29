#ifndef C_HEX_H
#define C_HEX_H

char hexToDecimal(char hex);
void decimalToBinary(char out[], char decimal);
void hexToBinary(char out[][4], const char hex[], const char len);
void showBinaryArr(char arr[][4], char len);

#endif //C_HEX_H
