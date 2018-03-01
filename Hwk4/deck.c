
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#include "deck.h"
// Standard suits and ranks
#define SUITS "CDHS"
#define RANKS "A23456789TJQK"

struct elt {
    struct elt *next;
    Card card;
};

struct deck {
    struct elt *head;
    struct elt *tail;
    /* int length; */
    
};

// Create a new unshuffled deck of 52 cards,
// ordered by suit then rank:
//
// AC 2C 3C ... KC AD 2D 3D ... KD AH 2H 3H ... KS w
struct deck *deckCreate(void) {
    Deck *d2;
    
    int numSuits = strlen(SUITS);
    int numRanks = strlen(RANKS);

    d2 = malloc(sizeof(Deck));
    d2->head = d2->tail = 0;
    
    for (int s = 0; s < numSuits; s++) {
        for (int r = 0; r < numRanks; r++) {
           Card cTemp; 
           
           cTemp.suit = SUITS[s];
           cTemp.rank = RANKS[r];
           deckPutCard(d2, cTemp);   
        }
    }
    return d2;
}

// Free all space used by d.
// Running time should be O(length of deck)
void deckDestroy(Deck *d) {
    while (deckNotEmpty(d)) {
        deckGetCard(d);
    }
    free(d);
}


// Return true if deck is not empty.
// Running time should be O(1).
int deckNotEmpty(const Deck *d) {
    return (d->head != 0);
}
// Remove and return the top card of a deck.
// If deck is empty, behavior is undefined.
// Running time should be O(1).
Card deckGetCard(Deck *d) {
    Card out;
    struct elt *cd;
    
    out = d->head->card;
    cd = d->head;
    d->head = cd->next;
   
    free(cd);
    return out;
}


// Add a card to the bottom of a deck.
// This is not required to do anything special if the card is bogus
//   (e.g. "1C", "?X", "A-").
// Running time should be O(1).
void deckPutCard(Deck *d, Card c){
    struct elt *cd;
    cd = malloc(sizeof(struct elt));
    
    cd->card = c;
    cd->next = 0;
   
    if (d->head == 0) {
        d->head = cd;
    }
    else {
        d->tail->next = cd;
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
    Deck *d1_;
    Deck *d2_;
    
    d1_ = malloc(sizeof(Deck));
    d1_->head = d1_->tail = 0;
    
    for (int i = 0; i < n; i++) {
       if (deckNotEmpty(d)) {
           deckPutCard(d1_, deckGetCard(d));
       }
       else {
           break;
       }
   } 
    
    d2_ = d;
    *d1 = d1_;
    *d2 = d2_;
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
    
    struct elt *temp;
    struct elt *temp1;
    
    Deck *d;
    
    d = malloc(sizeof(Deck));
    d->head = d->tail = 0;
   
    while (deckNotEmpty(d1) && deckNotEmpty(d2)) {
        e1 = deckGetCard(d1);
        deckPutCard(d, e1);
        e2 = deckGetCard(d2);
        deckPutCard(d, e2);
    }
    
    if (deckNotEmpty(d1)) {
        temp = d1->head;
        temp1 = d1->tail;
    }
    else if (deckNotEmpty(d2)) {
        temp = d2->head;
        temp1 = d2->tail;
    }
    
    if (deckNotEmpty(d1) || deckNotEmpty(d2)) {
        if (!(deckNotEmpty(d))) {
            d->head = temp;
            d->tail = temp1;
        }
        else {
            d->tail->next = temp;
            d->tail = temp1;
        }
    }
    free(d1);
    free(d2);
    return d;
        
}

// Print the contents of deck to f as sequence of ranks/suits
// separated by spaces.
// Example output: "AS TC 9D 3H 5S" (without quotes)
// Running time should be O(length of deck).
void deckPrint(const Deck *d, FILE *f) {
    struct elt *e;
    e = d->head;
    
    while(e != 0) { 
        Card cd = e->card;
        
        fprintf(f, "%c%c", cd.rank, cd.suit);
        
        e = e->next;
        if (e != 0) {
            fputc(' ', f);
        }
    }
}
