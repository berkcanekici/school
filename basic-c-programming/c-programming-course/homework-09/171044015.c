/*----------------------------------------------------------------------------
                                BERKCAN EKICI                               
                                  171044015                                 
                                                                            
 Description                                                                
    This homework consists of three parts. In the 1st part, recursive 
    calculations are made. A small game is requested in the 2nd part.     
    In the third party, card game is made.  
                                                                            
 Notes                                                                      
    I couldn't do the 2nd part.                                                           
                                                                            
----------------------------------------------------------------------------*/
/*­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­
                                Includes
            ­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­                                                                */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­
                                Structures
            ­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­                                                                */
struct card {
    const char *face;
    const char *suit;
};
/*­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­                                                                          
                         Function Prototypes                              
­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­                                                                            */
void randomize(); // for srand function
void struct_swap(struct card *, struct card *); // for structures swap
void print_cards(void); // for third part
int numPathsHome(int, int); // for first part

int main() 
{
    int street, avenue;

    randomize();

    printf("Enter the street number:\n");
    scanf("%d", &street);
    printf("Enter the avenue number:\n");
    scanf("%d", &avenue);
    printf("Number of optimal paths to take back home: %d\n\n", numPathsHome(street, avenue));
    
    print_cards();
}

void randomize() 
{
    srand((unsigned)time(NULL));
}

int numPathsHome(int street, int avenue) 
{
    if (street < 1 || avenue < 1)
        return -1;
    
    if (street == 1 || avenue == 1)
        return 1;

    return (numPathsHome(street-1, avenue) + numPathsHome(street, avenue-1));
}

void print_cards(void) 
{
    
    struct card Deck[52];

    const char *faces[] = {"Ace", "Deuce", "Three", "Four", "Five",
                           "Six", "Seven", "Eight", "Nine", "Ten",
                           "Jack", "Queen", "King"};
    const char *suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};

    for (int i = 0; i < 4; ++i) {
        for (int k = 0; k < 13; ++k) {
            if (0 == i) {
                Deck[k].suit = suits[i];
                Deck[k].face = faces[k];
            }
            else if (1 == i) {
                Deck[k + 13].suit = suits[i];
                Deck[k + 13].face = faces[k];
            }
			else if (2 == i) {
                Deck[k + 26].suit = suits[i];
                Deck[k + 26].face = faces[k];
            }
            else if (3 == i) {
                Deck[k + 39].suit = suits[i];
                Deck[k + 39].face = faces[k];
            }
        }
    }

    for (int i = 0; i < 52; ++i)
        struct_swap(&Deck[i], &Deck[rand() % 52]);

    for (int i = 0; i < 52; ++i)
        printf(" %5s of %-8s%c", Deck[i].face, Deck[i].suit, (i + 1) % 2 ? '\t' : '\n');
}
void struct_swap(struct card *source, struct card *destination)
{
    struct card temp = *destination;
    *destination = *source;
    *source = temp;
}
