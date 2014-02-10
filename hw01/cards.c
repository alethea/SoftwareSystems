#include <stdio.h>
#include <stdlib.h>

/* Prompts for card name and stores the response in the given buffer
 * 
 *  prompt: string prompt to show
 *  card_name: buffer to store result in (max 2 characters)
 */
void get_card_name(char *prompt, char *card_name);

int main()
{
    char card_name[3];
    int count = 0;
    while (card_name[0] != 'X') {
        int val = 0;
        get_card_name("Enter the card_name: ", card_name);
        switch(card_name[0]) {
        case 'K':
        case 'Q':
        case 'J':
            val = 10;
            break;
        case 'A':
            val = 11;
            break;
        case 'X':
            continue;
        default:
            val = atoi(card_name);
            if ((val < 1) || (val > 10)) {
                puts("I don't understand that value!");
                continue;
            }
        }
        if ((val > 2) && (val < 7)) {
            count++;
        } else if (val == 10) {
            count--;
        }
        printf("Current count: %i\n", count);
    }
    return 0;
}

void get_card_name(char *prompt, char *card_name) {
    puts(prompt);
    fgets(card_name, 3, stdin);
}
