#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

//prototype
int morph(char *number);
int fexist(char *filename);

int pid;

int main(int argc, char *argv[]){
    unsigned int *numbers[10];
    printf("yeet program is running hopefully\n");
    if(argc == 1){
        printf("Usage: multiFactor fileName\n");
        return 0; //placeholder
    }else if(argc >= 2){
        printf("%s\n", argv[1]);
        if(fexist(argv[1]) == 1){
            FILE *fp = NULL;
            fp = fopen(argv[1], "r");
            fread(numbers, sizeof(numbers), 10, fp);
            printf("read filed\n");
            for(int i = 0; i < 10; i++){
                printf("-- %i\n", i);
                //printf("%ls\n", numbers[i]);
            }
            fclose(fp);
        }else{
            printf("file %s does not exist\n", argv[1]);
            return 0; //placeholder
        }
    }

    return 0;
}

int fexist(char *filename){
    FILE *fp;
    if((fp = fopen(filename, "r"))){
        printf("file found\n");
        fclose(fp);
        return 1;
    }
    return 0;
}

int morph(char *number){
    //pid = fork();
    char *args[] = {"./numPrimeFactors", number};
    return execvp(args[0], args);
}
