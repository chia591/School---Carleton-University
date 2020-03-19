#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define DATA_BITS    8
#define PARITY_BITS  4
#define CHAR_LIMIT   100


// Encode the given character c into a bitSequence of size (DATA_BITS + PARITY_BITS).
// Each character in bitSequence must be a '1' or '0' character corresponding to one of the
// proper hamming code data bits or parity bits.  For example, if c='A', then the
// resulting string "100010010001" should be stored in bitSequence.
void encode(unsigned char c, char bitSequence[]) {
  // Replace the code below with your own code.
  char output[8];
  for(int i = 7; i >= 0; i--){
    if (c & (1 << i)){
      output[7 - i] = '1';
      //printf("%c", '1');
    }else{
      output[7 - i] = '0';
      //printf("%c", '0');
    }
  }
  if ((output[0] + output[1] + output[3] + output[4] + output[6]) % 2 == 1){
    bitSequence[0] = '1';
  }else{ bitSequence[0] = '0'; }
  if ((output[0] + output[2] + output[3] + output[5] + output[6]) % 2 == 1){
    bitSequence[1] = '1';
  }else{ bitSequence[1] = '0'; }
  bitSequence[2] = output[0];
  if ((output[1] + output[2] + output[3] + output[7]) % 2 == 1){
    bitSequence[3] = '1';
  }else{ bitSequence[3] = '0'; }
  bitSequence[4] = output[1];
  bitSequence[5] = output[2];
  bitSequence[6] = output[3];
  if ((output[4] + output[5] + output[6] + output[7]) % 2 == 1){
    bitSequence[7] = '1';
  }else{ bitSequence[7] = '0'; }
  bitSequence[8] = output[4];
  bitSequence[9] = output[5];
  bitSequence[10] = output[6];
  bitSequence[11] = output[7];
  bitSequence[12] = '\0';

  /*
  for (int i=0; i<PARITY_BITS + DATA_BITS; i++)
    bitSequence[i] = '0';
  bitSequence[12] = '\0';
  */
  // ...
  
}


// This program gets a string of ASCII characters from the user and then encodes each character
// using a 12-bit hamming code scheme, which uses 4 parity bits.  The output is displayed as a single
// string that represents a sequence of bits which has length of 12 times the number of characters
// entered.  The resulting string output consists solely of '1' and '0' characters.
int main() {
  unsigned char   transmitString[CHAR_LIMIT+1];
  unsigned char   encodedCharacters[(12+1)*(CHAR_LIMIT+1)];
  int             charCount;

  // Get the string to encode
  char formatString[10];
  sprintf(formatString, "%%%ds", CHAR_LIMIT);
  scanf(formatString, (char *)transmitString);
  charCount = strlen(transmitString);

  // Encode each character in the string by using a 12-bit hamming code
  for (int i=0; i<charCount; i++) {
    encode(transmitString[i], &encodedCharacters[i]);
    printf("%s", &encodedCharacters[i]);
  }
  printf("\n");  
}
