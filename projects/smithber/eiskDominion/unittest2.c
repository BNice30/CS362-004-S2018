/* -----------------------------------------------------------------------
 * Demonstration of how to write unit tests for dominion-base
 * Include the following lines in your makefile:
 *
 * testUpdateCoins: testWhoseTurn.c dominion.o rngs.o
 *      gcc -o testUpdateCoins -g  testWhoseTurn.c dominion.o rngs.o $(CFLAGS)
 * -----------------------------------------------------------------------
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 0

int main() {
    int i;
    int seed = 1000;
    int numPlayer = 2;
    int maxBonus = 10;
    int p, r, handCount;
    int bonus;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
   struct gameState G;

#if (NOISY_TEST == 1)
                printf("Test player %d with %d treasure card(s) and %d bonus.\n", p, handCount, bonus);
#endif
    G.whoseTurn=0;
//cost of copper
int turn =whoseTurn(&G);
    #if (NOISY_TEST == 1)
                printf("player 2 turn, turn==0\n");
#endif
if(turn!=0){
    printf("Incorrect turn!\n");
};
    
    G.whoseTurn=1;
     turn= whoseTurn(&G);
#if (NOISY_TEST == 1)
                printf("player 1 turn, turn==1\n");
#endif
    if(turn!=1){
        printf("Incorrect turn!\n");
    };
                       
printf("All tests passed!\n");
return 0;
  }
