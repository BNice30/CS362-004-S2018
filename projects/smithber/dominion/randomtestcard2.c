#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <math.h>
#include <stdlib.h>

int checkCouncil_room(struct gameState post, int handPos)
{
  struct gameState pre;
  memcpy (&pre, post, sizeof(struct gameState));

  int r;
    
 // cECouncil_room(post, p);
  int i;
  int currentPlayer = whoseTurn(state);
  int nextPlayer = currentPlayer + 1;
	cECouncil_room(post, currentPlayer);

  if (nextPlayer > (state->numPlayers - 1)){
    nextPlayer = 0;
  }

   if(pre.handCount[currentPlayer]+4== post.handCount[currentPlayer])
	{
		printf("Error- handCount incorrect");
	}

    assert(pre.handCount[currentPlayer]+4== post.handCount[currentPlayer]);
    pre.numBuys++;

	if(pre.numBuys==post.numBuys)
	{
	printf("Error- numBuys incorrect");
	}
  
    assert(pre.numBuys==post.numBuys);
    pre.discardCount[currentPlayer]--;

	if(pre.discardCount[p]==post.discardCount[p])
		{
		printf("Error- incorrect discard Count");

		}
    assert(pre.discardCount[p]==post.discardCount[p]);
    
   // for (i = 0; i < post->numPlayers; i++)
     //            {
       //             if ( i != currentPlayer)
        ///           {
                    pre.handCount[nextPlayer]++;  

		if(pre.handCount[nextPlayer]==post.handCount[nextPlayer])
			{
				printf("Error- incorrect handcount);
			}  
                    assert(pre.handCount[nextPlayer]==post.handCount[nextPlayer]);
                 //  }
                // } 
    return 0;
    
}

int main () {

  int i, n, r, p, deckCount, discardCount, handCount;

  int k[10] = {adventurer, council_room, feast, gardens, mine,
	       remodel, smithy, village, baron, great_hall};

  struct gameState G;

  printf ("Testing drawCard.\n");

  printf ("RANDOM TESTS.\n");

  SelectStream(2);
  PutSeed(3);

  for (n = 0; n < 2000; n++) {
   // for (i = 0; i < sizeof(struct gameState); i++) {
     // ((char*)&G)[i] = floor(Random() * 256);
   // }
  //  p = floor(Random() * 2);
    pos= floor(Random()* MAX_HAND);
	memset(&G, 23, sizeof(struct gameState));
          r = initializeGame(2, k, 1, &G);
	  G.whoseTurn = floor(Random() * 2);
    p=G.whoseTurn;
    G.deckCount[p] = floor(Random() * MAX_DECK);
    G.discardCount[p] = floor(Random() * MAX_DECK);
    G.handCount[p] = floor(Random() * MAX_HAND);
    checkCouncil_room(G,pos);
  }

  printf ("ALL TESTS OK\n");

  exit(0);

  printf ("SIMPLE FIXED TESTS.\n");
  for (p = 0; p < 2; p++) {
    for (deckCount = 0; deckCount < 5; deckCount++) {
      for (discardCount = 0; discardCount < 5; discardCount++) {
	for (handCount = 0; handCount < 5; handCount++) {
	  memset(&G, 23, sizeof(struct gameState)); 
	  r = initializeGame(2, k, 1, &G);
	  G.deckCount[p] = deckCount;
	  memset(G.deck[p], 0, sizeof(int) * deckCount);
	  G.discardCount[p] = discardCount;
	  memset(G.discard[p], 0, sizeof(int) * discardCount);
	  G.handCount[p] = handCount;
	  memset(G.hand[p], 0, sizeof(int) * handCount);
	  checkDrawCard(p, &G);
	}
      }
    }
  }

  return 0;
}

/*
void cECouncil_room(int p, struct gameState *state, int handPos){

  int i;
  int currentPlayer =i;
  int nextPlayer = currentPlayer + 1;

  if (nextPlayer > (state->numPlayers - 1)){
    nextPlayer = 0;
  }
    assert(pre.handCount[p]+4== post.handCount[p]);
    pre.numBuys++;
    assert(pre.numBuys==post.numBuys);
    pre.discardCount--;
    assert(pre.discardCount==post.discardCount);
    
    for (i = 0; i < state->numPlayers; i++)
                 {
                    if ( i != currentPlayer )
                   {
                    pre.handCount[i]++;    
                    assert(pre.handCount[i]==post.handCount[i]);
                   }
                 }
    
    
    for (i = 0; i < 4; i++)
        {
          drawCard(nextPlayer, state);     //Bug 4- next player draws card rather than current player
        }

      //+1 Buy
            state->numBuys++;
                  //Each other player draws a card
        for (i = 0; i < state->numPlayers; i++)
                 {
                    if ( i != currentPlayer )
                   {
                    drawCard(i, state);
                   }
                 }
        //put played card in played card pile
                discardCard(handPos, currentPlayer, state, 0);*/
}
*/
