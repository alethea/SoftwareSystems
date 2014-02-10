#include <stdio.h>
#include <stdlib.h>

/* Prompts for card name and stores the response in the given buffer
 * 
 *  prompt: string prompt to show
 *  card_name: buffer to store result in (max 2 characters)
 */
void get_card_name(char* prompt, char* card_name);

/* Takes a card name and returns a value
 * Returns 0 on unrecognized input, -1 on 'X' and 1-11 otherwise
 *
 * card_name: buffer containing user-inputed card name
 */
int name_to_value(char* card_name);

/* Takes a card value and increments the count as needed
 *
 * val: card value to use
 * count: pointer to the count to increment
 */
void increment_count(int val, int* count);

int main()
{
    char card_name[3];
    int count = 0;
    int val;

    while (1) {
        get_card_name("Enter the card_name: ", card_name);
        val = name_to_value(card_name);
        if (val < 0) {
            break;
        } else if (val == 0) {
            puts("I don't understand that value!");
        } else {
            increment_count(val, &count);
            printf("Current count: %i\n", count);
        }
    }
    return 0;
}

void get_card_name(char* prompt, char* card_name) {
    puts(prompt);
    fgets(card_name, 3, stdin);
}

int name_to_value(char* card_name) {
    int val;

    switch(card_name[0]) {
    case 'K':
    case 'Q':
    case 'J':
        return 10;
    case 'A':
        return 11;
    case 'X':
        return -1;
    default:
        val = atoi(card_name);
        if ((val > 1) && (val < 10)) {
            return val;
        }
    }
    return 0;
}

void increment_count(int val, int* count) {
    if ((val > 2) && (val < 7)) {
        (*count)++;
    } else if (val == 10) {
        (*count)--;
    }
}

