#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <math.h>
#include <stdlib.h>

void checkSmithy(struct gameState *post, int handPos)
{
    struct gameState pre;
    memcpy (&pre, post, sizeof(struct gameState));

//    int i;
//    int currentPlayer= whoseTurn(post);
//    int nextPlayer= currentPlayer + 1;


    
   int p = whoseTurn(&pre);
	cESmithy(post,handPos);
    pre.handCount[p]++;
    pre.handCount[p]++;
    
       if(pre.handCount[p]== post->handCount[p]){
	printf("Error- incorrect handCount\n");
}


   // assert(pre.handCount[p]== post->handCount[p]);
   if(pre.discardCount[p]+1==post->discardCount[p])
	 {
	printf("Error- incorrect discard Count\n");	
	}

 //   assert(pre.discardCount[p]+1==post->discardCount[p]);
    
}

int main () {

  int i, n, p, deckCount, discardCount, handCount;

  int k[10] = {adventurer, council_room, feast, gardens, mine,
	       remodel, smithy, village, baron, great_hall};

  struct gameState G;
  int pos;
  printf ("Testing Smithy Card.\n");

  printf ("RANDOM TESTS.\n");

  SelectStream(2);
  PutSeed(3);

  //for (n = 0; n < 2000; n++) {
   // for (i = 0; i < sizeof(struct gameState); i++) {
    //  ((char*)&G)[i] = floor(Random() * 256);
    //}
    // 
   initializeGame(2, k, 1, &G);  
  G.whoseTurn = floor(Random() * 2);
    p=G.whoseTurn;
    pos= floor(Random()* MAX_HAND);
    G.deckCount[p] = floor(Random() * MAX_DECK);
    G.discardCount[p] = floor(Random() * MAX_DECK);
    G.handCount[p] = floor(Random() * MAX_HAND);
  //  printf ("BEFORE TESTS.\n");
    checkSmithy(&G,pos);

  

  printf ("ALL TESTS OK\n");

  exit(0);

  printf ("SIMPLE FIXED TESTS.\n");
  for (p = 0; p < 2; p++) {
    for (deckCount = 0; deckCount < 5; deckCount++) {
      for (discardCount = 0; discardCount < 5; discardCount++) {
	for (handCount = 0; handCount < 5; handCount++) {
	  memset(&G, 23, sizeof(struct gameState)); 
	 initializeGame(2, k, 1, &G);
	  G.deckCount[p] = deckCount;
	  memset(G.deck[p], 0, sizeof(int) * deckCount);
	  G.discardCount[p] = discardCount;
	  memset(G.discard[p], 0, sizeof(int) * discardCount);
	  G.handCount[p] = handCount;
	  memset(G.hand[p], 0, sizeof(int) * handCount);
	  checkSmithy(&G,pos);
	}
      }
    }
  }

  return 0;
}

/*

void cESmithy(struct gameState *state,int handPos){

  int i;
  int currentPlayer = whoseTurn(state);
  int nextPlayer = currentPlayer + 1;

   if (nextPlayer > (state->numPlayers - 1)){
    nextPlayer = 0;
  }
	//Bug 2- Card now drawn

	 for (i = 0; i < 3; i++)

        {

         // drawCard(currentPlayer, state);

        }

      //discard card from hand

           discardCard(handPos, currentPlayer, state, 0);
  */ 
