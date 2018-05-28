#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <stdlib.h>
#include "rngs.h"

#define DEBUG 0
#define NOISY_TEST 1

int checkAdventurer(int p, struct gameState *post,int pos, int z, int drawntreasure, int temphand[]){
    
    struct gameState pre;
    memcpy(&pre, post, sizeof(struct gameState));
        
    int i;
   // int currentPlayer= whoseTurn(post);
  
    adventurerEffect(post, pos, p ,z,drawntreasure,temphand);
    
    pre.handCount[p]= pre.handCount[p]+2;
    printf("expected: %d , returned: %d\n", pre.handCount[p], post->handCount[p]);
  if(pre.handCount[p]!= post->handCount[p]){
      
	printf("Error- incorrect handCount\n");
      
}
    
   // assert(pre.handCount==post.handCount);
    
    int cardDrawn[2];
    cardDrawn[0] = post->hand[p][post->handCount[p]-1];
    cardDrawn[1] = post->hand[p][post->handCount[p]-2];
    
    printf("cardDrawn 1: %d, cardDrawn 2:  %d\n",         cardDrawn[0],cardDrawn[1]);
    int drawn=0;
    for(i=0;i<2;i++)
    {
       if (cardDrawn[i] != copper && cardDrawn[i] != silver && cardDrawn[i] != gold){           
           drawn ++;
	 }
        
     } 
    printf("Error- %d treasure cards not drawn\n",drawn);
}
            
   
            



int main (){
    
    int i, n, r, p, deckCount, discardCount, handCount;
    int temphand[MAX_HAND];
    int pos;
    time_t t;
    srand((unsigned)time(&t));
    int drawntreasure=0;
    int z = 0;// this is the counter for the temp hand
    
    
   int k[10] = {adventurer, council_room, feast, gardens, mine,
	       remodel, smithy, village, baron, great_hall};

  struct gameState G;

  printf ("Testing Adventure card.\n");

  printf ("RANDOM TESTS.\n");
 for(i=0;i<5;i++){   
  SelectStream(2);
  PutSeed(3);
    
  initializeGame(2, k, 1, &G); 
  p= floor(Random()*2);
  //int t=whoseTurn(&G);
  G.deckCount[p]= floor(rand() % MAX_DECK);
  G.discardCount[p]=floor(rand() % MAX_DECK);
  G.handCount[p]= floor(rand() % MAX_HAND);
  pos=floor(rand() * G.handCount[p]);
  checkAdventurer(p, &G, pos, z, drawntreasure, temphand);
 }
  printf ("ALL RANDOM TEST COMPLETED\n");

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
	  checkAdventurer(p, &G, pos, z, drawntreasure, temphand);
	}
      }
    }
  }

  return 0;    
    
}
/*

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
*/
      

