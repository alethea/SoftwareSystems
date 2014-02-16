/* Example code for Software Systems at Olin College.

Copyright 2014 Allen Downey
License: Creative Commons Attribution-ShareAlike 3.0

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <regex.h>

#define NUM_TRACKS 5

char tracks[][80] = {
    "So What",
    "Freddie Freeloader",
    "Blue in Green",
    "All Blues",
    "Flamenco Sketches"
};


// Finds all tracks that contain the given string.
//
// Prints track number and title.
void find_track(char search_for[])
{
    int i;
    for (i=0; i<NUM_TRACKS; i++) {
	if (strstr(tracks[i], search_for)) {
	    printf("Track %i: '%s'\n", i, tracks[i]);
	}
    }
}

// Print a error code from regcomp or regexec
void print_regex_error(int errcode, const regex_t* preg) {
    size_t errbuf_size;
    char *errbuf;

    errbuf_size = regerror(errcode, preg, 0, 0);
    errbuf = malloc(errbuf_size * sizeof (char));
    regerror(errcode, preg, errbuf, errbuf_size);
    puts(errbuf);
    free(errbuf);
}

// Finds all tracks that match the given pattern.
//
// Prints track number and title.
void find_track_regex(char pattern[])
{
    int i;
    int err;
    regex_t regex;

    err = regcomp(&regex, pattern, REG_NOSUB);
    if (err) {
        print_regex_error(err, &regex);
        return;
    }
    for (i = 0; i < NUM_TRACKS; i++) {
        if (!regexec(&regex, tracks[i], 0, 0, 0)) {
            printf("Track %i: '%s'\n", i, tracks[i]);
        }
    }
    regfree(&regex);
}

// Truncates the string at the first newline, if there is one.
void rstrip(char s[])
{
    char *ptr = strchr(s, '\n');
    if (ptr) {
	*ptr = '\0';
    }
}

int main (int argc, char *argv[])
{
    char search_for[80];

    /* take input from the user and search */
    printf("Search for: ");
    fgets(search_for, 80, stdin);
    rstrip(search_for);

    //find_track(search_for);
    find_track_regex(search_for);

    return 0;
}
