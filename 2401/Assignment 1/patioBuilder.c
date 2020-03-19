#include <stdio.h>
#include <math.h>

int main(){
    float paverWidth = 7.75;
    float paverLength = 7.75;
    float curbWide = 4.3;
    float curbLong = 11.8;
    float paverCost = 3.9;
    float curbCost = 2.48;

    float patioWidth = 0.0;
    float patioLength = 0.0;
    
    
    printf("Please enter the desired patio width (in feet):\n");
    scanf("%f", &patioWidth);
    if (patioWidth < 24.0){
        printf("The patio dimension is not enough");
        return(0);
    }

    printf("Please enter the desired patio Length (in feet):\n");
    scanf("%f", &patioLength);
    if (patioLength < 24.0){
        printf("The patio dimension is not enough");
        return(0);
    }

    patioWidth = patioWidth * 12;
    patioLength = patioLength * 12;

    //calculating ammout of curb
    int curbCount = (2 * (ceil(patioWidth / curbLong)));
    curbCount += (2 * (ceil((patioLength - (curbWide * 2)) / curbLong)));
 
    //calculating the ammount of paver
    int paverCount = ((ceil(((patioWidth - (curbWide * 2))) / paverWidth)) * (ceil((patioLength - (curbWide * 2)) / paverLength)));

    //calculating the price
    float curbTotal = ((float)curbCount * curbCost);
    float paverTotal = ((float)paverCount * paverCost);

    float subTotal = curbTotal + paverTotal;

    float HST = subTotal * 0.13;

    float Total = subTotal + HST;

    //receipt printed to user
    printf("\nCurb ---- %d * %.2f = %.2f\nPaver --- %d * %.2f = %.2f\nSubTotal -------- %.2f\nHST ------------- %.2f\nTotal ----------- %.2f\n", curbCount, curbCost, curbTotal, paverCount, paverCost, paverTotal, subTotal, HST, Total);
    return(0);
}