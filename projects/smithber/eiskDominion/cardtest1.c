/*
 * cardtest4.c
 *
 
 */

/*
 * Include the following lines in your makefile:
 *
 * cardtest4: cardtest4.c dominion.o rngs.o
 *      gcc -o cardtest1 -g  cardtest4.c dominion.o rngs.o $(CFLAGS)
 */


#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "adventurer"

int main() {
    int newCards = 0;
    int discarded = 1;
    int xtraCoins = 0;
    int shuffledCards = 0;
    int xtraActions=0;
    int i, j, m;
    int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    int remove1, remove2;
    int seed = 1000;
    int numPlayers = 2;
    int thisPlayer = 0;
	struct gameState G, testG;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};

	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G);

	printf("----------------- Testing Card: %s ----------------\n", TESTCARD);

	// ----------- TEST 1: choice1 = 1 = +2 cards --------------
	printf("TEST 1:+2 cards; variable discard\n");

	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));
	choice1 = 0;
	cardEffect(adventurer, choice1, choice2, choice3, &testG, handpos, &bonus);

	newCards = 2;
	xtraCoins = 0;
    xtraActions=0;
    discarded=1;
        //testG.discardCount[thisPlayer]-G.discardCount[thisPlayer];
    
    
        printf("discarded = %d\n",discarded);
	printf("hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] + newCards);
	printf("deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - newCards + shuffledCards);
	printf("coins = %d, expected = %d\n", testG.coins, G.coins + xtraCoins);
    printf("actions = %d, expected = %d\n", testG.numActions, G.numActions + xtraActions);
	
   if(testG.handCount[thisPlayer] != G.handCount[thisPlayer] + newCards){
       printf("Error- incorrect handCount\n");
   }
       
	if(testG.deckCount[thisPlayer] != G.deckCount[thisPlayer] - newCards + shuffledCards){
        printf("Error- incorrect deckCount\n");
    }
        
	if(testG.coins != G.coins + xtraCoins){
        printf("Error- incorrect amount of coins\n");
    }
        
    if(testG.numActions==G.numActions + xtraActions){
        printf("Error- incorrect number of actions");
    }
    
    //test new cards in discard pile aren't treasure
   /* int cardDrawn;
    for(i=testG.discardCount[thisPlayer]-1; i>G.discardCount[thisPlayer];i--)
    {
        cardDrawn =testG.discard[thisPlayer][i];
        assert(cardDrawn != copper && cardDrawn != silver && cardDrawn && gold);
    }
*/
	return 0;
    
    printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);
}
