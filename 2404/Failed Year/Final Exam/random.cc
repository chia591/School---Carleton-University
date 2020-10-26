#include <iostream>

/*
  You must seed the random number generator with the current
  time in main(), before any calls to random(); use the 
  following call:  srand( (unsigned)time( NULL ) );
  You may need to include <cstdlib> and <time.h> libraries
*/

#include "random.h"

int random(int max)
{
	double r = ( (double)rand() / ((double)(RAND_MAX)+(double)(1)) ); 
	return (int)(r * max);
}
