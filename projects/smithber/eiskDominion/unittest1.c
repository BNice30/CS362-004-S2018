#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 0

int main(){
    int i;
    int seed = 1000;
    int numPlayer = 2;
    int maxBonus = 10;
    int p, r, handCount;
    int bonus;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};

//define state; make supplyCount 0; make 3 random supply piles empty
    struct gameState G;
    
    #if (NOISY_TEST == 1)
                printf("Test isGameOver. \n", p, handCount, bonus);
#endif

    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    r = initializeGame(numPlayer, k, seed, &G); //intialize game
    
    G.supplyCount[province]=0;
        
    int result=isGameOver(&G);
    
#if (NOISY_TEST == 1)
                printf("G.supplyCount[province] = 0, Result = 1\n");
#endif
                if(result != 1 ){
                printf("Error- Game is not over\n");} // check if GameOver 
    
  r = initializeGame(numPlayer, k, seed, &G); //intialize game
    G.supplyCount[5]=0;
    G.supplyCount[2]=0;
    G.supplyCount[8]=0;
    result=isGameOver(&G);
   // printf("Test 2\n");
#if (NOISY_TEST == 1)
                printf("G.supplyCount[5] = 0, G.supplyCount[2] = 0,G.supplyCount[8] = 0,Result = 0\n");
#endif
                if(result != 1){
                    printf("Error- Game is not over\n");
                } // check if GameOver 
    

//if stakeholder cards is empty, the game ends

//if three supply piles are at 0
    
    r = initializeGame(numPlayer, k, seed,&G); //re-intialize game
    G.supplyCount[6]=0;
    G.supplyCount[11]=0;
    result=isGameOver(&G);
   // printf("Test 3\n");
    
    #if (NOISY_TEST == 1)
                printf("G.supplyCount[6] = 0,G.supplyCount[11] = 0, Result = 0\n");
    #endif
    if(result != 0 ){
        printf("Error- Game is not over\n");
    }; // check if GameOver 

     r = initializeGame(numPlayer, k, seed, &G); //re-intialize game
    
    #if (NOISY_TEST == 1)
                printf("G.supplyCount[province] = 0, Result = 0");
    #endif
    if(result != 0 ){
        printf("Error- Game is not over\n");
    }; // check if GameOver 
    
        printf("All tests passed!\n");
return 0;

}