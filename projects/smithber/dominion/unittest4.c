/* -----------------------------------------------------------------------
 * Demonstration of how to write unit tests for dominion-base
 * Include the following lines in your makefile:
 *
 * testSupplyCount: testSupplyCount.c dominion.o rngs.o
 *      gcc -o testSupplyCount -g  testSupplyCount.c dominion.o rngs.o $(CFLAGS)
 * -----------------------------------------------------------------------
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 1

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
              //  printf("Test player %d with %d treasure card(s) and %d bonus.\n", p, handCount, bonus);
#endif
//test when there are cards in game
int supplyC= supplyCount(province,&G);
printf("supplyC = %d\n",supplyC);

if(supplyC!=8)
{
printf("Test Failed\n");
return 0;
}

#if (NOISY_TEST == 1)
                printf("Test supplyCount\n", p, handCount, bonus);
#endif
//test when no supply of card in game
    G.supplyCount[estate] = 0;
supplyC= supplyCount(estate,&G);
if(supplyC!=0)
{
printf("Test Failed\n");
return 0;
}

    
    
    printf("All tests passed!\n");
    
return 0; 
}
