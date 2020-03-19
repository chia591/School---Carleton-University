#include <stdio.h>

char isValidRank(char c){
    switch (c){
        case '2': return('1'); break;
        case '3': return('1'); break;
        case '4': return('1'); break;
        case '5': return('1'); break;
        case '6': return('1'); break;
        case '7': return('1'); break;
        case '8': return('1'); break;
        case '9': return('1'); break;
        case 'T': return('1'); break;
        case 'J': return('1'); break;
        case 'Q': return('1'); break;
        case 'K': return('1'); break;
        case 'A': return('1'); break;
        default: return('0');
    }
}

int compareRank(char c1, char c2){
    int i1 = 0;
    int i2 = 0;
    switch (c1){
        case '2': i1 = 2; break;
        case '3': i1 = 3; break;
        case '4': i1 = 4; break;
        case '5': i1 = 5; break;
        case '6': i1 = 6; break;
        case '7': i1 = 7; break;
        case '8': i1 = 8; break;
        case '9': i1 = 9; break;
        case 'T': i1 = 10; break;
        case 'J': i1 = 11; break;
        case 'Q': i1 = 12; break;
        case 'K': i1 = 13; break;
        case 'A': i1 = 14; break;
        default: return(0);
    }
    switch (c2){
        case '2': i2 = 2; break;
        case '3': i2 = 3; break;
        case '4': i2 = 4; break;
        case '5': i2 = 5; break;
        case '6': i2 = 6; break;
        case '7': i2 = 7; break;
        case '8': i2 = 8; break;
        case '9': i2 = 9; break;
        case 'T': i2 = 10; break;
        case 'J': i2 = 11; break;
        case 'Q': i2 = 12; break;
        case 'K': i2 = 13; break;
        case 'A': i2 = 14; break;
        default: return(0);
    }
    if (i1 > i2){return(1);}
    else if (i1 < i2){return(2);}
    else {return(0);}
}

char isValidSuit(char c){
    switch(c){
        case 'H': return('1'); break;
        case 'D': return('1'); break;
        case 'S': return('1'); break;
        case 'C': return('1'); break;
        default: return('0');
    }
}

char getTrump(){
    printf("please enter a trump suit (this can be 'H' 'D' 'S' 'C'):\n");
    char input;
    scanf(" %c", &input);
    if (isValidSuit(input) == '1'){
        return(input);
    }else if(input == '.'){
        return('q');
    }
    else{
        printf("this is not a valid entry\n");
        return(getTrump());
    }
}

int main(){
    char TrumpSuit;
    TrumpSuit = getTrump();
    if (TrumpSuit == 'q'){ return(1);}
    
    char cBreak = 0; //When this turns 1 then break

    char R[4];
    char S[4];
    int temp;

    while(1){
        //Initialisation
        for (int i = 0; i < 4; i++){
            R[i] = '0';
            S[i] = '0';
        }
        temp = 100;

        //Start game
        //main loop
        for (int p = 0; p < 4; p++){
            //Prep Phase
            while(1){
                printf("\nPlayer %d: Enter card rank and suit (Example: 2S, TH, KS, ect...)\n", p + 1);
                scanf(" %c%c", &R[p], &S[p]);
                if (R[p] == '.'){
                    cBreak = 1;
                    break;
                }else if(isValidRank(R[p]) == '1' && isValidSuit(S[p]) == '1'){
                    break;
                }else{
                    R[p] = '0';
                    S[p] = '0';
                    printf("  [error]Invalid card, please re-enter\n");
                }
            }
            if (cBreak == 1){ break;}
        }
        printf("\n%c%c, %c%c, %c%c, %c%c\n", R[0], S[0], R[1], S[1], R[2], S[2], R[3], S[3]);

        //Competing phase
            //Trump
        for (int p = 0; p < 4; p++){
            if (TrumpSuit == S[p]){ //Finds a player with trumpSuit
                if (temp == 100){ //Checks if the trump suit position has been modified (not modified)
                    temp = p;
                }else{ //(been modified)
                    if (compareRank(R[temp], R[p]) == 2){ //compares the rank of the two cards with the trump suit and leaves the winner in the winning position
                        temp = p;
                    }
                }
            }
        }
        if (temp == 100){ //If there has been no modification of the temp (aka no cards with a trump suit)
            temp = 0; //winner position is given to player 1 as their rank is now the suit led
            for (int p = 1; p < 4; p++){
                if (S[temp] == S[p]){ //Checks if there is another card matching the suit led
                    if (compareRank(R[temp], R[p]) == 2){
                        temp = p;
                    }
                }
            }
        }

        //Final screen
        printf("Congragulation Player %d for winning the game\n\n\nThe game will now restart", temp + 1);
        
        if (cBreak == 1){ break;}
    }
}