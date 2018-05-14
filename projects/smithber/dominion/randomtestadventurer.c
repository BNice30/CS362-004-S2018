#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

#define DEBUG 0
#define NOISY_TEST 1

int checkAdventurer(int p, struct gameState *post){
    
    struct gameState pre;
    memcpy(&pre, post, sizeof(struct gameState))
        
    int r;
    
    r= cEAdventurer(post);
    
    pre.handCount=pre.handCount+2;
    
    assert(pre.handCount==post.handCount);
    
    int cardDrawn[2];
    cardDrawn[0] = post.hand[currentPlayer][post.handCount-1];
    cardDrawn[1] = post.hand[currentPlayer][post.handCount-2];
    
    for(i=0;i<2;i++)
    {
       if (cardDrawn[i] != copper || cardDrawn[i] != silver || cardDrawn[i] != gold){
           assert(1);
       } 
    }
            
    assert(r==0);
            
}


int main (){
    
    int i, n, r, p, deckCount, discardCount, handCount;
    
   int k[10] = {adventurer, council_room, feast, gardens, mine,
	       remodel, smithy, village, baron, great_hall};

  struct gameState G;

  printf ("Testing drawCard.\n");

  printf ("RANDOM TESTS.\n");
    
  SelectStream(2); 
  putSeed(3);
    
    
  p= floor(Random()*2);
  G.deckCount[p]= floor(Random() * MAX_DECK);
  G.discardCount[p]=floor(Random() * MAX_DECK);
  G.handCount[p]= floor(Random()* MAX_HAND);
  checkDrawCard(p, &G);
    
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


//void cEAdventurer(struct gameState *state){

  int currentPlayer = whoseTurn(state);
  int nextPlayer = currentPlayer + 1;
  int temphand[MAX_HAND];// moved above the if statement
  int drawntreasure=0;
  int cardDrawn;
  int z = 0;// this is the counter for the temp hand
  if (nextPlayer > (state->numPlayers - 1)){
    nextPlayer = 0;

  }

while(drawntreasure<2){

        if (state->deckCount[currentPlayer] <1){//if the deck is empty we need to shuffle discard and add to deck
          shuffle(currentPlayer, state);
        }

        drawCard(currentPlayer, state);
        cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]-1];//top card of hand is most recently drawn card.

        if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)

          drawntreasure=drawntreasure+2;                  //Bug 3- drawn extra treasure card
        else{

          temphand[z]=cardDrawn;
          state->handCount[currentPlayer]--; //this should just remove the top card (the most recently drawn one).
          z++;
        }
      }
      while(z-1>=0){

        state->discard[currentPlayer][state->discardCount[currentPlayer]++]=temphand[z-1]; // discard all cards in play that have been drawn

        z=z-1;

      }

      

}