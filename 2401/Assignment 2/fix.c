#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define DATA_BITS    8
#define PARITY_BITS  4
#define CHAR_LIMIT   100




// Given a brokenSequence of bits representing a corrupted 12-bit (i.e., DATA_BITS + PARITY_BITS)
// hamming code sequence, determine which bit had been flipped and then flip it back and store
// the repaired sequence in fixedSequence.    Note that both bit sequences may be very large,
// but this function should only examine the first 12 bits of the sequence (i.e., the first
// 12 characters in the incoming and outgoing char array).
void fix(char brokenSequence[], char fixedSequence[]) {
  // ...
  // Replace the code below with your own code
  // ...
  /*
  for(int i = 0; i < 12; i++){
    printf("%c", brokenSequence[i]);
  }
  printf("\n");
  */
  int y[12];
  for(int i = 0; i < 12; i++){
    if(brokenSequence[i] == '1'){
      y[i] = 1;
    }else{
      y[i] = 0;
    }
  }

  char p1 = y[0];
  char p2 = y[1];
  char p4 = y[3];
  char p8 = y[7];

  char t1 = (y[2] + y[4] + y[6] + y[8] + y[10]) % 2;
  char t2 = (y[2] + y[5] + y[6] + y[9] + y[10]) % 2;
  char t4 = (y[4] + y[5] + y[6] + y[11]) % 2;
  char t8 = (y[8] + y[9] + y[10] + y[11]) % 2;

  int x[12];
  for(int i = 0; i < 12; i++){
    x[i] = 0;
  }
  // 2 0/1, 4 0/2, 3 1/1, 5 1/2 (5 being the number it holds, initial/strikes)
  if(p1 != t1){
    x[2]++; x[4]++; x[6]++; x[8]++; x[10]++;
  }
  if(p2 != t2){
    x[2]++; x[5]++; x[6]++; x[9]++; x[10]++;
  }
  if(p4 != t4){
    x[4]++; x[5]++; x[6]++; x[11]++;
  }
  if(p8 != t8){
    x[8]++; x[9]++; x[10]++; x[11]++;
  }
  /*
  printf("%d / %d \n", p1, t1);
  for(int i = 0; i < 12; i++){
    printf("%d ", x[i]);
  }
  printf("\n");
  */
  if(x[6] == 3){
    //printf("\n fix");
    if(brokenSequence[6] == '0'){
      brokenSequence[6] = '1';
    }else{
      brokenSequence[6] = '0';
    }
  }else if(x[10] == 3){
    //printf("\n fix");
    if(brokenSequence[10] == '0'){
      brokenSequence[10] = '1';
    }else{
      brokenSequence[10] = '0';
    }
  }else if(x[2] == 2){
    //printf("\n fix");
    if(brokenSequence[2] == '0'){
      brokenSequence[2] = '1';
    }else{
      brokenSequence[2] = '0';
    }
  }else if(x[4] == 2){
    //printf("\n fix");
    if(brokenSequence[4] == '0'){
      brokenSequence[4] = '1';
    }else{
      brokenSequence[4] = '0';
    }
  }else if(x[5] == 2){
    //printf("\n fix");
    if(brokenSequence[5] == '0'){
      brokenSequence[5] = '1';
    }else{
      brokenSequence[5] = '0';
    }
  }else if(x[8] == 2){
    //printf("\n fix");
    if(brokenSequence[8] == '0'){
      brokenSequence[8] = '1';
    }else{
      brokenSequence[8] = '0';
    }
  }else if(x[9] == 2){
    //printf("\n fix");
    if(brokenSequence[9] == '0'){
      brokenSequence[9] = '1';
    }else{
      brokenSequence[9] = '0';
    }
  }else if(x[11] == 2){
    //printf("\n fix");
    if(brokenSequence[11] == '0'){
      brokenSequence[11] = '1';
    }else{
      brokenSequence[11] = '0';
    }
  }else if(x[2] == 1 & x[4] == 1 & x[6] == 1 & x[8] == 1 & x[10] == 1){
    //printf("\n fix");
    if(brokenSequence[0] == '0'){
      brokenSequence[0] = '1';
    }else{
      brokenSequence[0] = '0';
    }
  }else if(x[2] == 1 & x[5] == 1 & x[6] == 1 & x[9] == 1 & x[10] == 1){
    //printf("\n fix");
    if(brokenSequence[1] == '0'){
      brokenSequence[1] = '1';
    }else{
      brokenSequence[1] = '0';
    }
  }else if(x[4] == 1 & x[5] == 1 & x[6] == 1 & x[11] == 1){
    //printf("\n fix");
    if(brokenSequence[3] == '0'){
      brokenSequence[3] = '1';
    }else{
      brokenSequence[3] = '0';
    }
  }else if(x[8] == 1 & x[9] == 1 & x[10] == 1 & x[11] == 1){
    //printf("\n fix");
    if(brokenSequence[7] == '0'){
      brokenSequence[7] = '1';
    }else{
      brokenSequence[7] = '0';
    }
  }else{
    //printf("\n Something is very wronmg \n");
  }
  /*
  printf("\n");
  for(int i = 0; i < 12; i++){
    printf("%c", brokenSequence[i]);
  }
  printf("\n");
  */
  for (int i=0; i<DATA_BITS+PARITY_BITS; i++) 
    fixedSequence[i] = brokenSequence[i];
}




// This program takes in a corrupted 12-bit hamming code sequence from the user and then
// attempts to correct the corrupted bits.   It is assumed that exactly one bit in each
// of the 12-bit sequences has been flipped.   The input is a large array of characters
// which are all 1's or 0's.   The incoming sequence MUST be a multiple of 12 characters.
// For example, if a data string was entered originally as "ABCD" ... then each character
// in the string would be encoded as 12-bits.  So we would need 48 bits to represent the
// input string.   These 48 bits would be coded as 48 characters consisiting of 1's or
// 0's.   So, the expected input to this program would be a large 48 character string of
// '1' and '0' chars.
int main() {
  unsigned char   brokenString[12*CHAR_LIMIT+1];
  unsigned char   fixedString[12*CHAR_LIMIT+1];
  int             charCount;

  // Get the string to decode
  char formatString[10];
  sprintf(formatString, "%%%ds", 12*CHAR_LIMIT);
  scanf(formatString, (char *)brokenString);
  charCount = strlen(brokenString);

  // Make sure that the string size is a multiple of 12 characters, otherwise something is wrong
  if (charCount%12 != 0) {
    printf("The entered bit sequence must have a multiple of 12 bits.\nThis sequence has %d bits left over.\n", charCount%12);
    exit(-1);
  }

  // Fix the bits in the brokenString by identifying the single flipped bit in each of
  // the sequential sets of 12 bits
  for (int i=0; i<charCount/12; i++)
    fix(&brokenString[i*12], &fixedString[i*12]);
  fixedString[12*(charCount/12)] = '\0';
  printf("%s\n", fixedString);  
}
