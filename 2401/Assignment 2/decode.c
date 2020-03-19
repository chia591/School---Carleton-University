#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define DATA_BITS    8
#define PARITY_BITS  4
#define CHAR_LIMIT   100





// Given a bitSequence[] of chars that represent bits of a 12-bit (i.e., DATA_BITS + PARITY_BITS) 
// hamming code sequence, determine the byte/character represented by the data bits of the 12-bit
// sequence and return this character.  If, for example, the incoming bitSequence is the string
// "100010010001", then the letter 'A' should be returned.
char decode(char bitSequence[]) {
  // ...
  // ...
  // Replace the code here with your own code
  int output = 0;
  char temp[8];
  temp [0] = bitSequence[2];
  temp [1] = bitSequence[4];
  temp [2] = bitSequence[5];
  temp [3] = bitSequence[6];
  temp [4] = bitSequence[8];
  temp [5] = bitSequence[9];
  temp [6] = bitSequence[10];
  temp [7] = bitSequence[11];

  int powaah;
  for (int i = 0; i < 8; i++){
    powaah = pow(2, 7 - i);
    if(temp[i] == '1'){
      output += powaah;
    }else{}
  }
  //printf("%d", output);
  return (char)output;   // replace the '?' with the correct code
}






// This program gets a bit sequence in the form of an array of '1' amd '0' characters that
// represent a string that has been encoded using a 12-bit hamming code scheme.   The incoming
// string must be a multiple of 12 bytes/characters in size, as each 12-byte sequence will
// represent a single encoded character from the original user string.  The output is displayed
// as the decoded string, which should match the original string that had been encoded.
int main() {
  unsigned char   recvString[12*CHAR_LIMIT+1];
  unsigned char   decodedCharacters[CHAR_LIMIT];
  int             charCount;

  // Get the string to decode
  char formatString[10];
  sprintf(formatString, "%%%ds", 12*CHAR_LIMIT);
  scanf(formatString, (char *)recvString);
  charCount = strlen(recvString);

  // Make sure that the string size is a multiple of 12 characters, otherwise something is wrong
  if (charCount%12 != 0) {
    printf("The entered bit sequence must have a multiple of 12 bits.\nThis sequence has %d bits left over.\n", charCount%12);
    exit(-1);
    }

  // Decode the bit sequence using a 12-bit hamming code and display the characters
  for (int i=0; i<charCount/12; i++) {
    decodedCharacters[i] = decode(&recvString[i*12]);
    printf("%c",decodedCharacters[i]);
  }
  printf("\n");  
}
