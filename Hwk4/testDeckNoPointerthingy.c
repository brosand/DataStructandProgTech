// Abstract data type for a deck of playing cards

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "deck.h"
// Standard suits and ranks
#define SUITS "CDHS"
#define RANKS "A23456789TJQK"

// A single card
// This is small enough that we usually pass it 
// around by copying instead of using pointers.
/* struct card { */
    /* char rank;   /\* from RANKS *\/ */
    /* char suit;   /\* from SUITS *\/ */
/* } Card; */

// A deck of cards
/* typedef struct deck Deck; */
struct elt {
    elt next;
    Card card;
};

struct deck {
    /* int length; */
    struct elt *head;
    struct elt *tail;
};
// Create a new unshuffled deck of 52 cards,
// ordered by suit then rank:
//
// AC 2C 3C ... KC AD 2D 3D ... KD AH 2H 3H ... KS w
struct deck *deckCreate(void) {
    struct deck *d2;
    /* struct card c1; */
    
    int numSuits = strlen(SUITS);
    int numRanks = strlen(RANKS);
    
    d2 = malloc(sizeof(struct deck));
    d2->head = d2->tail = 0;
    /* d2->length = 0;    */
    for (int s = 1; s < numSuits; s++) {
        for (int r = 1; r < numRanks; r++) {
           Card cTemp; 
           /* cTemp = malloc(sizeof(struct card)); */
           cTemp.suit = SUITS[s];
           cTemp.rank = RANKS[r];
           deckPutCard(d2, cTemp);   
           /* d2->length++; */
        }
    }
    return d2;
}

// Free all space used by d.
// Running time should be O(length of deck)
void deckDestroy(Deck *d) {
    while (deckNotEmpty(d)) {
        deckGetCard;
    }
    free(d);
}

    
    /* free(d->cards); */
    /* free(d); */


// Return true if deck is not empty.
// Running time should be O(1).
int deckNotEmpty(const Deck *d) {
    return (d->head == 0);
}
// Remove and return the top card of a deck.
// If deck is empty, behavior is undefined.
// Running time should be O(1).
Card deckGetCard(Deck *d) {
    Card out;
    struct elt *cd;
    out = (d->head)->card;
    cd = d->head;
    /* printf("%c\n", cd->card.rank); */
    d->head = cd.next;
   
    /* free(cd->card); */
    free(cd);
    return out;
}

// Add a card to the bottom of a deck.
// This is not required to do anything special if the card is bogus
//   (e.g. "1C", "?X", "A-").
// Running time should be O(1).
void deckPutCard(Deck *d, Card c){
    elt cd;
    /* cd = malloc(sizeof(struct elt)); */
    
    cd.card = c;
    cd.next = 0;
    if (d->head == 0) {
        d->head = cd;
    }
    else {
        d->tail.next = cd;
    }
    d->tail = cd;
       
    
}

// Split a deck into two piles:
//    *d1 is new deck with top n cards in d.
//    *d2 is new deck with remaining cards in d.
// Order of cards is preserved.
// If d contains fewer than n cards, put them all in d1.
// Destroys d.
// Running time should be O(n).
void deckSplit(Deck *d, int n, Deck **d1, Deck **d2) {
    
}

// Shuffle two decks together by alternating cards from
// d1 and d2 to obtain new deck.
//
// If d1 is X X X X 
// and d2 is Y Y Y Y Y Y Y,
// return value is X Y X Y X Y X Y Y Y Y.
//
// If d1 is X X X X
// and d2 is Y Y,
// return value is X Y X Y X X.
//
// Running time should be O(length of shorter deck).
// Destroys d1 and d2.
Deck *deckShuffle(Deck *d1, Deck *d2) {
    Card e1;
    Card e2;

    struct deck *d;
    d = malloc(sizeof(struct deck));
    d->head = d->tail = 0;
    /* e1 = malloc(sizeof(struct elt)); */
    /* e2 = malloc(sizeof(struct elt)); */
    /* e1 = deckGetCard(d1); */
    /* e2 = deckGetCard(d2); */

    while (deckNotEmpty(d1)) {
        if (deckNotEmpty(d2)) {
            deckPutCard(d, e1);
            deckPutCard(d, e2);
            e2 = deckGetCard(d2);
        }
        else {
            deckPutCard(d1, e1);
        }
        e1 = deckGetCard(d1);
    }
    while (deckNotEmpty(d2)) {
        deckPutCard(d, e2);
    }
    deckDestroy(d1);
    deckDestroy(d2);
    
    return d;
        
}

// Print the contents of deck to f as sequence of ranks/suits
// separated by spaces.
// Example output: "AS TC 9D 3H 5S" (without quotes)
// Running time should be O(length of deck).
void deckPrint(const Deck *d, FILE *f) {
    struct elt *e;
    e = d->head;
    Card cd;
    
    while(e != 0) {
        cd = e.card;
        fprintf(f, "%c%c", cd.rank, cd.suit);
        
        e = e.next;
        if (e != 0) {
            fputc(' ', f);
        }
    }
}
