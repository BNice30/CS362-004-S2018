#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <math.h>
#include <stdlib.h>

int checkCouncil_room(struct gameState *post, int handPos,int p)
{
  struct gameState pre;
  memcpy (&pre, post, sizeof(struct gameState));

  int r;
    
 councilRoomEffect(post, handPos, p);
  int i;
 // int currentPlayer = whoseTurn(post);
  int nextPlayer = p + 1;
	//cECouncil_room(post, currentPlayer);

  if (nextPlayer > (post->numPlayers - 1)){
    nextPlayer = 0;
  }
pre.handCount[p]=pre.handCount[p]+3;
    
    printf("expected: %d , returned: %d\n", pre.handCount[p], post->handCount[p]);
  
    if(pre.handCount[p]!= post->handCount[p])
	{
		printf("Error- handCount incorrect\n");
	}

  //  assert(pre.handCount[currentPlayer]+4== post.handCount[currentPlayer]);
    pre.numBuys++;
printf("expected: %d , returned: %d\n", pre.numBuys, post->numBuys);
	if(pre.numBuys!=post->numBuys)
	{
	printf("Error- numBuys incorrect\n");
	}
  
 //   assert(pre.numBuys==post.numBuys);
/*    pre.discardCount[currentPlayer]--;
printf("expected: %d , returned: %d\n", pre.discardCount[currentPlayer], post->discardCount[currentPlayer]);
    
	if(pre.discardCount[currentPlayer]!=post->discardCount[currentPlayer])
		{
		printf("Error- incorrect discard Count\n");

		}
  //  assert(pre.discardCount[p]==post.discardCount[p]);*/
    
   // for (i = 0; i < post->numPlayers; i++)
     //            {
       //             if ( i != currentPlayer)
        ///           {
                    pre.handCount[nextPlayer]++;  
    printf("expected: %d , returned: %d\n", pre.handCount[nextPlayer], post->handCount[nextPlayer]);

		if(pre.handCount[nextPlayer]!=post->handCount[nextPlayer])
			{
				printf("Error- incorrect handcount\n");
			}  
                    //assert(pre.handCount[nextPlayer]==post.handCount[nextPlayer]);
                 //  }
                // } 
    return 0;
    
}

int main () {

  int i, n, r, p, deckCount, discardCount, handCount;
  int pos; 
  int k[10] = {adventurer, council_room, feast, gardens, mine,
	       remodel, smithy, village, baron, great_hall};

  struct gameState G;

  printf ("Testing Council Room.\n");

  printf ("RANDOM TESTS.\n");
for(i=0;i<5;i++){
    
  SelectStream(2);
  PutSeed(3);

 // for (n = 0; n < 2000; n++) {
   // for (i = 0; i < sizeof(struct gameState); i++) {
     // ((char*)&G)[i] = floor(Random() * 256);
   // }
  //  p = floor(Random() * 2);
  
	memset(&G, 23, sizeof(struct gameState));
          r = initializeGame(2, k, 1, &G);
	p = floor(Random() * 2);
   G.deckCount[p]= floor(rand() % MAX_DECK);
  G.discardCount[p]=floor(rand() % MAX_DECK);
  G.handCount[p]= floor(rand() % MAX_HAND);
    pos= floor(rand() % G.handCount[p]);
    checkCouncil_room(&G,pos,p);
  
}
  printf ("ALL RANDOM TEST COMPLETED\n");

exit(0) ; 

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
	  checkCouncil_room(&G,pos,p);
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

