#include "Controler.h"
#include <cstdlib>
#include <time.h>

int main()
{
    srand( (unsigned)time( NULL ) );
    Controler c;
    c.turn();
    return 0;
}