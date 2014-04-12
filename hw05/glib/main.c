#include <glib.h>
#include <glib/gprintf.h>
#include "histogram.h"
#include "parser.h"

int main() {
    Parser *parser;
    GError *error;

    error = NULL;
    parser = parser_new("main.c", &error);
    parser_free(parser);
    return 0;
}
