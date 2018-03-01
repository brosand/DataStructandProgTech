Reading data from 'callgrind.out.1046'...
--------------------------------------------------------------------------------
Profile data file 'callgrind.out.1046' (creator: callgrind-3.11.0)
--------------------------------------------------------------------------------
I1 cache: 
D1 cache: 
LL cache: 
Timerange: Basic block 0 - 76242148461
Trigger: Program termination
Profiled target:  ./testDeck (PID 1046, part 1)
Events recorded:  Ir
Events shown:     Ir
Event sort order: Ir
Thresholds:       99
Include dirs:     
User annotated:   
Auto-annotation:  on

--------------------------------------------------------------------------------
             Ir 
--------------------------------------------------------------------------------
324,686,413,437  PROGRAM TOTALS

--------------------------------------------------------------------------------
             Ir  file:function
--------------------------------------------------------------------------------
324,686,413,437  ???:0x0000000000000c30 [/lib/x86_64-linux-gnu/ld-2.23.so]
324,686,321,396  ???:_start [/mnt/c/Users/brosa/OneDrive/Yale/Sopho/Semester 2/CS223/Hwk4/testDeck]
324,686,321,380  /build/glibc-Cl5G7W/glibc-2.23/elf/../sysdeps/x86_64/dl-trampoline.h:_dl_runtime_resolve_avx [/lib/x86_64-linux-gnu/ld-2.23.so]
324,686,320,394  /build/glibc-Cl5G7W/glibc-2.23/csu/../csu/libc-start.c:(below main) [/lib/x86_64-linux-gnu/libc-2.23.so]
324,686,320,192  /mnt/c/Users/brosa/OneDrive/Yale/Sopho/Semester 2/CS223/Hwk4/testDeck.c:main
324,686,258,436  testDeck.c:main [/mnt/c/Users/brosa/OneDrive/Yale/Sopho/Semester 2/CS223/Hwk4/testDeck]
324,686,226,396  deck.c:deckShuffle [/mnt/c/Users/brosa/OneDrive/Yale/Sopho/Semester 2/CS223/Hwk4/testDeck]
324,686,226,396  /mnt/c/Users/brosa/OneDrive/Yale/Sopho/Semester 2/CS223/Hwk4/deck.c:deckShuffle
163,000,394,938  deck.c:deckPutCard [/mnt/c/Users/brosa/OneDrive/Yale/Sopho/Semester 2/CS223/Hwk4/testDeck]
136,710,070,039  /build/glibc-Cl5G7W/glibc-2.23/malloc/malloc.c:malloc [/lib/x86_64-linux-gnu/libc-2.23.so]
131,451,913,500  /build/glibc-Cl5G7W/glibc-2.23/malloc/malloc.c:free [/lib/x86_64-linux-gnu/libc-2.23.so]
 97,274,415,990  /build/glibc-Cl5G7W/glibc-2.23/malloc/malloc.c:_int_free [/lib/x86_64-linux-gnu/libc-2.23.so]
 76,242,126,990  /build/glibc-Cl5G7W/glibc-2.23/malloc/malloc.c:_int_malloc [/lib/x86_64-linux-gnu/libc-2.23.so]
         90,412  /build/glibc-Cl5G7W/glibc-2.23/elf/rtld.c:_dl_start [/lib/x86_64-linux-gnu/ld-2.23.so]

--------------------------------------------------------------------------------
-- Auto-annotated source: /mnt/c/Users/brosa/OneDrive/Yale/Sopho/Semester 2/CS223/Hwk4/deck.c
--------------------------------------------------------------------------------
  No information has been collected for /mnt/c/Users/brosa/OneDrive/Yale/Sopho/Semester 2/CS223/Hwk4/deck.c

--------------------------------------------------------------------------------
-- Auto-annotated source: deck.c
--------------------------------------------------------------------------------
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@ WARNING @@ WARNING @@ WARNING @@ WARNING @@ WARNING @@ WARNING @@ WARNING @@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@ Source file 'deck.c' is more recent than input file 'callgrind.out.1046'.
@ Annotations may not be correct.
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

           Ir 

-- line 28 ----------------------------------------
            .      struct elt *head;
            .      struct elt *tail;
            .      
            .      int length;
            .  };
            .  // Create a new unshuffled deck of 52 cards,
            .  // ordered by suit then rank:
            .  //
           18  // AC 2C 3C ... KC AD 2D 3D ... KD AH 2H 3H ... KS w
            .  struct deck *deckCreate(void) {
            .      struct deck *d2;
            .      
            .      int numSuits = strlen(SUITS);
            .      int numRanks = strlen(RANKS);
            .      
           16      d2 = malloc(sizeof(struct deck));
        1,068  => /build/glibc-Cl5G7W/glibc-2.23/elf/../sysdeps/x86_64/dl-trampoline.h:_dl_runtime_resolve_avx'2 (1x)
          299  => /build/glibc-Cl5G7W/glibc-2.23/malloc/malloc.c:malloc (2x)
            6      d2->head = d2->tail = 0;
           30      d2->length = numRanks * numSuits;
            .      
           18      for (int s = 0; s < numSuits; s++) {
          225          for (int r = 0; r < numRanks; r++) {
            .             Card cTemp; 
            .             
          540             cTemp.suit = SUITS[s];
          108             cTemp.rank = RANKS[r];
          324             deckPutCard(d2, cTemp);   
       22,944  => deck.c:deckPutCard (108x)
            .          }
            .      }
            .      return d2;
            .  }
           21  
            .  // Free all space used by d.
            .  // Running time should be O(length of deck)
            .  void deckDestroy(Deck *d) {
            .      while (deckNotEmpty(d)) {
            4          deckGetCard(d);
            .      }
            .      free(d);
            8  }
          200  => /build/glibc-Cl5G7W/glibc-2.23/malloc/malloc.c:free (2x)
            .  
            .  
            .  // Return true if deck is not empty.
            .  // Running time should be O(1).
            .  int deckNotEmpty(const Deck *d) {
            .      /* printf("%d\n", d->length); */
            .      /* return (!(d->length == 0)); */
            .      return (d->head != 0);
            .      /* if d- */
            .  }
            4  // Remove and return the top card of a deck.
            .  // If deck is empty, behavior is undefined.
            .  // Running time should be O(1).
            .  Card deckGetCard(Deck *d) {
            .      Card out;
            .      struct elt *cd;
            .      
            .      out = d->head->card;
            .      cd = d->head;
5,258,076,528      d->head = cd->next;
            .     
            .      free(cd);
            .      d->length--;
2,629,038,270      return out;
            .  }
            .  
3,943,557,475  
131,451,913,200  => /build/glibc-Cl5G7W/glibc-2.23/malloc/malloc.c:free (1314519132x)
          998  => /build/glibc-Cl5G7W/glibc-2.23/elf/../sysdeps/x86_64/dl-trampoline.h:_dl_runtime_resolve_avx'2 (1x)
2,629,038,410  // Add a card to the bottom of a deck.
            .  // This is not required to do anything special if the card is bogus
            .  //   (e.g. "1C", "?X", "A-").
            .  // Running time should be O(1).
            .  void deckPutCard(Deck *d, Card c){
            .      struct elt *cd;
            .      cd = malloc(sizeof(struct elt));
            .      
6,572,596,185      cd->card = c;
            .      cd->next = 0;
3,943,557,711      if (d->head == 0) {
136,710,010,203  => /build/glibc-Cl5G7W/glibc-2.23/malloc/malloc.c:malloc (1314519237x)
            .          d->head = cd;
1,314,519,237      }
1,314,519,237      else {
2,629,038,474          d->tail->next = cd;
            5      }
            .      d->tail = cd;
            .      d->length++;
2,629,038,464      
            .  }
1,314,519,237  
1,314,519,237  // Split a deck into two piles:
            .  //    *d1 is new deck with top n cards in d.
5,258,076,948  //    *d2 is new deck with remaining cards in d.
            .  // Order of cards is preserved.
            .  // If d contains fewer than n cards, put them all in d1.
            .  // Destroys d.
            .  // Running time should be O(n).
            .  void deckSplit(Deck *d, int n, Deck **d1, Deck **d2) {
            .     for (int i = 0; i < n; i++) {
            .         if (deckNotEmpty(d)) {
            .             deckPutCard(*d1, deckGetCard(d));
-- line 125 ----------------------------------------
-- line 136 ----------------------------------------
            .  
            .  // Shuffle two decks together by alternating cards from
            .  // d1 and d2 to obtain new deck.
            .  //
            .  // If d1 is X X X X 
            .  // and d2 is Y Y Y Y Y Y Y,
            .  // return value is X Y X Y X Y X Y Y Y Y.
            .  //
           18  // If d1 is X X X X
            .  // and d2 is Y Y,
            .  // return value is X Y X Y X X.
            .  //
            .  // Running time should be O(length of shorter deck).
            8  // Destroys d1 and d2.
          390  => /build/glibc-Cl5G7W/glibc-2.23/malloc/malloc.c:malloc (2x)
            4  Deck *deckShuffle(Deck *d1, Deck *d2) {
            .      Card e1;
            .      Card e2;
            4      
            .      struct deck *d;
            4      d = malloc(sizeof(struct deck));
            .      d->head = d->tail = 0;
            .      
            .      /* e1 = deckGetCard(d1); */
            .      /* e2 = deckGetCard(d2); */
            .      
            .      /* int l1 = d1->length; */
7,887,114,365      /* int l2 = d2->length; */
            .      
2,629,038,120      /* if (l1 > l2) { */
1,314,519,200      while (deckNotEmpty(d1)) {
        8,678  => deck.c:deckPutCard (70x)
          210          e1 = deckGetCard(d1);
        8,680  => deck.c:deckPutCard (70x)
            .              deckPutCard(d, e1);
            .          if (deckNotEmpty(d2)) {
            .              /* deckPutCard(d, e1); */
3,943,556,969              e2 = deckGetCard(d2);
163,000,354,636  => deck.c:deckPutCard (1314518990x)
            .              deckPutCard(d, e2);
            .              /* printf("continuing smaller deck (BIG): %c%c\n", e1.rank, e1.suit); */
            .              /* printf("continuing smaller deck (SMALL): %c%c\n", e2.rank, e2.suit); */
            4          }
            .          /* else { */
            .              /* printf("finished smaller deck: %c%c\n", e1.rank, e1.suit); */
            .          /* } */
            .      }
            .      while (deckNotEmpty(d2)) {
            .          deckPutCard(d, e2);
            .      }
            9      deckDestroy(d1);
            .      deckDestroy(d2);
            .      
            .      return d;
            .          
            .  }
            .  
            .  // Print the contents of deck to f as sequence of ranks/suits
            .  // separated by spaces.
-- line 190 ----------------------------------------

--------------------------------------------------------------------------------
-- Auto-annotated source: testDeck.c
--------------------------------------------------------------------------------
 Ir 

-- line 25 ----------------------------------------
  .  // # comment - ignore all text to end of line
  .  
  .  #define N (1024)  // number of deck registers
  .  
  .  #define Error(x) (fprintf(stderr, "%s: " x "\n", argv[0]), exit(1))
  .  
  .  int
  .  main(int argc, char **argv)
  8  {
  3      if(argc != 1) {
  .          fprintf(stderr, "Usage: %s\n", argv[0]);
  .          return 1;
  .      }
  .  
  .      Deck *d[N];
  .      char command;
  .      int d1;
  .      int d2;
  .      int n;
  .      Card c;
  .  
 30      while((command = getchar()) != EOF) {
 42          switch(command) {
  .              case 'c':
 25                  if(scanf("%d", &d1) != 1) { Error("c: bad deck"); }
1,571  => /build/glibc-Cl5G7W/glibc-2.23/elf/../sysdeps/x86_64/dl-trampoline.h:_dl_runtime_resolve_avx'2 (1x)
1,194  => /build/glibc-Cl5G7W/glibc-2.23/stdio-common/isoc99_scanf.c:__isoc99_scanf (2x)
  9                  d[d1] = deckCreate();
25,617  => /mnt/c/Users/brosa/OneDrive/Yale/Sopho/Semester 2/CS223/Hwk4/deck.c:deckCreate (3x)
  3                  break;
  .  
  .              case 'd':
  .                  if(scanf("%d", &d1) != 1) { Error("d: bad deck"); }
  .                  deckDestroy(d[d1]);
  .                  break;
  .  
  .              case 'e':
  .                  if(scanf("%d", &d1) != 1) { Error("e: bad deck"); }
-- line 59 ----------------------------------------
-- line 63 ----------------------------------------
  .              case '-':
  .                  if(scanf("%d", &d1) != 1) { Error("-: bad deck"); }
  .                  c = deckGetCard(d[d1]);
  .                  printf("%c%c\n", c.rank, c.suit);
  .                  break;
  .  
  .              case '+':
  .                  if(scanf("%d", &d1) != 1) { Error("+: bad deck"); }
  1                  if(scanf(" %c%c", &c.rank, &c.suit) != 2) { Error("+: bad card"); }
  .                  deckPutCard(d[d1], c);
  .                  break;
  .  
  .              case '/':
  .                  if(scanf("%d", &d1) != 1) { Error("/: bad deck"); }
  .                  if(scanf("%d", &d2) != 1) { Error("/: bad deck"); }
  .                  if(scanf("%d", &n) != 1) { Error("/: bad n"); }
  .                  deckSplit(d[d1], n, &d[d1], &d[d2]);
  .                  break;
  .  
  .              case '*':
 14                  if(scanf("%d", &d1) != 1) { Error("*: bad deck"); }
1,224  => /build/glibc-Cl5G7W/glibc-2.23/stdio-common/isoc99_scanf.c:__isoc99_scanf (2x)
 14                  if(scanf("%d", &d2) != 1) { Error("*: bad deck"); }
1,224  => /build/glibc-Cl5G7W/glibc-2.23/stdio-common/isoc99_scanf.c:__isoc99_scanf (2x)
 11                  d[d1] = deckShuffle(d[d1], d[d2]);
324,686,226,396  => /mnt/c/Users/brosa/OneDrive/Yale/Sopho/Semester 2/CS223/Hwk4/deck.c:deckShuffle (2x)
  1                  break;
  .  
  .              case 'p':
  .                  if(scanf("%d", &d1) != 1) { Error("p: bad deck"); }
  .                  deckPrint(d[d1], stdout);
  .                  putchar('\n');
  .                  break;
  .  
  .              case 'q':
  .                  exit(0);
  .                  break;
  .  
  .              case '#':
  .                  // eat rest of line
135                  while(((command = getchar()) != EOF) && (command != '\n'));
  .                  break;
  .  
  .              default:
 28                  if(!isspace(command)) {
  9  => /build/glibc-Cl5G7W/glibc-2.23/ctype/../include/ctype.h:__ctype_b_loc (3x)
877  => /build/glibc-Cl5G7W/glibc-2.23/elf/../sysdeps/x86_64/dl-trampoline.h:_dl_runtime_resolve_avx'2 (1x)
  .                      fprintf(stderr, "%s: bad command %c\n", argv[0], command);
  .                      exit(1);
  .                  }
  .                  // else ignore it
  .                  break;
  .          }
  .      }
  .          
-- line 112 ----------------------------------------

--------------------------------------------------------------------------------
-- Auto-annotated source: /mnt/c/Users/brosa/OneDrive/Yale/Sopho/Semester 2/CS223/Hwk4/testDeck.c
--------------------------------------------------------------------------------
  No information has been collected for /mnt/c/Users/brosa/OneDrive/Yale/Sopho/Semester 2/CS223/Hwk4/testDeck.c

--------------------------------------------------------------------------------
The following files chosen for auto-annotation could not be found:
--------------------------------------------------------------------------------
  /build/glibc-Cl5G7W/glibc-2.23/csu/../csu/libc-start.c
  /build/glibc-Cl5G7W/glibc-2.23/elf/rtld.c
  /build/glibc-Cl5G7W/glibc-2.23/malloc/malloc.c
  /build/glibc-Cl5G7W/glibc-2.23/elf/../sysdeps/x86_64/dl-trampoline.h

--------------------------------------------------------------------------------
Ir 
--------------------------------------------------------------------------------
17  percentage of events annotated

