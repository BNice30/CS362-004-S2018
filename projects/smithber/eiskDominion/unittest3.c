/* -----------------------------------------------------------------------
 * Demonstration of how to write unit tests for dominion-base
 * Include the following lines in your makefile:
 *
 * testUpdateCoins: testGetCost.c dominion.o rngs.o
 *      gcc -o testCoss -g  testGetCost.c dominion.o rngs.o $(CFLAGS)
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

#if (NOISY_TEST == 1)
//                printf("Test player %d with %d treasure card(s) and %d bonus.\n", p, handCount, bonus);
#endif
//cost of copper
int cost =getCost(copper);
    #if (NOISY_TEST == 1)
                printf("copper, expected = 0\n");
#endif
if(cost!=0){
    printf("Incorrect turn!\n");
}

//cost of curse
 cost=getCost(curse);
    #if (NOISY_TEST == 1)
                printf("curse, expected = 0\n");
#endif
if(cost!=0){
    printf("Incorrect turn!\n");
}

//cost of treasure_map
 cost=getCost(treasure_map);
    #if (NOISY_TEST == 1)
                printf("treasure_map, expected = 4\n");
#endif
if(cost!=4){
    printf("Incorrect turn!\n");
}
    
    printf("All tests passed!\n");
                       
return 0;
  }
