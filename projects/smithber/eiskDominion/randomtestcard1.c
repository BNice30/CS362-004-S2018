#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <math.h>
#include <stdlib.h>

void checkSmithy(struct gameState *post, int handPos,int p)
{
    struct gameState pre;
    memcpy (&pre, post, sizeof(struct gameState));

//    int i;
//    int currentPlayer= whoseTurn(post);
//    int nextPlayer= currentPlayer + 1;


    
 
   // printf("Turn %d\n", p);
	smithyEffect(post,handPos,p);
    pre.handCount[p]++;
    pre.handCount[p]++;
    
    
    printf("expected: %d , returned: %d\n", pre.handCount[p], post->handCount[p]);

    
       if(pre.handCount[p]!= post->handCount[p]){
	printf("Error- incorrect handCount\n");
}
    
     //   assert(pre.discardCount[p]+1==post->discardCount[p]);
    
}

int main () {

  int i, n, p, deckCount, discardCount, handCount;

  int k[10] = {adventurer, council_room, feast, gardens, mine,
	       remodel, smithy, village, baron, great_hall};
    
    time_t t;
    srand((unsigned)time(&t));

  struct gameState G;
  int pos;
  printf ("Testing Smithy Card.\n");

  printf ("RANDOM TESTS.\n");
for(i=0; i<5; i++){
  SelectStream(2);
  PutSeed(3);

  //for (n = 0; n < 2000; n++) {
   // for (i = 0; i < sizeof(struct gameState); i++) {
    //  ((char*)&G)[i] = floor(Random() * 256);
    //}
    // 
     
    p = floor(Random() * 2);
    initializeGame(2, k, 1, &G);
  // int t=G.whoseTurn;
   
  G.deckCount[p]= floor(rand() % MAX_DECK);
  G.discardCount[p]=floor(rand() % MAX_DECK);
  G.handCount[p]= floor(rand() % MAX_HAND);
  pos= floor(rand()% G.handCount[p]);
  //printf ("BEFORE TESTS.\n");
  checkSmithy(&G,pos,p);

        }

  printf ("ALL RANDOM TEST COMPLETE\n");

  exit(0);

  printf ("SIMPLE FIXED TESTS.\n");
    struct gameState S;
  for (p = 0; p < 2; p++) {
    for (deckCount = 0; deckCount < 5; deckCount++) {
      for (discardCount = 0; discardCount < 5; discardCount++) {
	for (handCount = 0; handCount < 5; handCount++) {
	//  memset(&S, 23, sizeof(struct gameState)); 
	 initializeGame(2, k, 1, &S);
       // t=whoseTurn(&S);
	 S.deckCount[p] = deckCount;
	  memset(S.deck[p], 0, sizeof(int) * deckCount);
	  S.discardCount[p] = discardCount;
	  memset(S.discard[p], 0, sizeof(int) * discardCount);
	  S.handCount[p] = handCount;
	  memset(S.hand[p], 0, sizeof(int) * handCount);
     checkSmithy(&S,pos,p);
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
