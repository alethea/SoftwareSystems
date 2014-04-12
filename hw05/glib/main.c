#include <glib.h>
#include <glib/gprintf.h>
#include "histogram.h"
#include "parser.h"

int main() {
    Parser *parser;
    GError *error;
    gchar *word;

    error = NULL;
    parser = parser_new("test.txt", &error);
    while (TRUE) {
        word = parser_read_word(parser, &error);
        if (word == NULL) {
            break;
        }
        puts(word);
    }
    parser_free(parser);
    return 0;
}
