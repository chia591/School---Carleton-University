#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CATCHED_FISHES 10
#define POND_FISHES 15

typedef struct Fish{
    unsigned char size;
    char *species;
}Fish;

typedef struct Fisher{
    char *name;
    unsigned char keepSize;
    Fish bucket[CATCHED_FISHES];
    unsigned char numFish;
}Fisher;

typedef struct Pond{
    Fish fish[POND_FISHES];
    unsigned char numFish;
}Pond;

int addFish(Pond *p, unsigned char size, char *species){
    if (p->numFish == POND_FISHES){
        return 0;
    }else{
        Fish newFish;
        newFish.size = size;
        newFish.species = species;
        p->fish[p->numFish] = newFish;
        p->numFish++;
        return 1;
    }
}

void listFish(Fish *arrayOfFish, int n){
    for(int i = 0; i < n; i++, arrayOfFish++){
        Fish current = *arrayOfFish;
        printf("A %d cm %s\n", current.size, current.species);
    }
}

char likes(Fisher *fisher, Fish *f){
    if(fisher->keepSize <= f->size && f->species != "Sunfish"){
        return 1;
    }else{
        return 0;
    }
}

int keep(Fisher *fisher, Fish *f){
    if(fisher->numFish == CATCHED_FISHES){
        return 0;
    }else{
        fisher->bucket[fisher->numFish] = *f;
        fisher->numFish++;
        return 1;
    }
}

int castLine(Fisher *fisher, Pond *p){
    int num;
    if(p->numFish == 0){
        return 0;
    }else{
        num = rand() % p->numFish;
        //printf("%d\n", num);
        if(likes(fisher, &p->fish[num]) == 1){
            Fish caught = p->fish[num];
            if(keep(fisher, &p->fish[num]) == 1){
                for(int i = num; i < p->numFish; i++){
                    p->fish[i] = p->fish[i + 1];
                }
                p->numFish--;
                return 1;
            }
        }
    }
    return 0;
}

void giveAwayFish(Fisher *fisher1, Fisher *fisher2, Pond *p){
    for(int i = 0; i < fisher1->numFish; i++){
        if(fisher2->numFish != CATCHED_FISHES && likes(fisher2, &fisher2->bucket[i]) == 1){
            fisher2->bucket[fisher2->numFish] = fisher1->bucket[i];
            fisher2->numFish++;
        }else{
            p->fish[p->numFish] = fisher1->bucket[i];
            p->numFish++;
        }
    }
    fisher1->numFish = 0;
}

int main(){
    srand(time(0));

    Fisher f1;
    f1.name = "Fred";
    f1.numFish = 0;
    f1.keepSize = 15;

    Fisher f2;
    f2.name = "Suzy";
    f2.numFish = 0;
    f2.keepSize = 10;

    Pond LakeVerity;
    LakeVerity.numFish = 0;
    addFish(&LakeVerity, 4, "Sunfish");
    addFish(&LakeVerity, 25, "Pike");
    addFish(&LakeVerity, 20, "Bass");
    addFish(&LakeVerity, 30, "Perch");
    addFish(&LakeVerity, 14, "Sunfish");
    addFish(&LakeVerity, 15, "Pike");
    addFish(&LakeVerity, 9, "Pike");
    addFish(&LakeVerity, 12, "Bass");
    addFish(&LakeVerity, 5, "Sunfish");
    addFish(&LakeVerity, 12, "Sunfish");
    addFish(&LakeVerity, 10, "Bass");
    addFish(&LakeVerity, 2, "Bass");
    addFish(&LakeVerity, 16, "Perch");
    addFish(&LakeVerity, 30, "Sunfish");
    addFish(&LakeVerity, 7, "Perch");

    printf("All the fishes in the lake\n");
    listFish(LakeVerity.fish, 15);

    printf("\nFred is feeling himself and he is going to try to catch all the fishes...\n");
    for(int i = 0; i < 10; i++){
        if(castLine(&f1, &LakeVerity) == 1){
            //printf("caught\n");
        }else{
            //printf("Released\n");
        }
    }
    //listFish(LakeVerity.fish, LakeVerity.numFish);
    printf("Fred's fishes:\n");
    listFish(f1.bucket, f1.numFish);

    printf("\nSuzy is disapointed in fred and decides to prepare him a gift...\n");
    for(int i = 0; i < 10; i++){
        if(castLine(&f2, &LakeVerity) == 1){
            //printf("caught\n");
        }else{
            //printf("Released\n");
        }
    }
    //listFish(LakeVerity.fish, LakeVerity.numFish);
    printf("Suzy's fishes:\n");
    listFish(f2.bucket, f2.numFish);

    printf("\nAfter the rampage of these two animals the lake contains:\n");
    listFish(LakeVerity.fish, LakeVerity.numFish);

    printf("\nSuzy is as nice as a goddess and hands over her goods to her dear Fred\n");
    giveAwayFish(&f2, &f1, &LakeVerity);


    printf("Fred's fishes:\n");
    listFish(f1.bucket, f1.numFish);

    printf("Suzy's fishes:\n");
    listFish(f2.bucket, f2.numFish);

    printf("\nThe spoil of war:\n");
    listFish(LakeVerity.fish, LakeVerity.numFish);
}