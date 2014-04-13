#include <glib.h>
#include <glib/gprintf.h>
#include "histogram.h"
#include "parser.h"

void histogram_print(gchar *term, gint32 count, gpointer user_data) {
    g_printf("%s %d\n", term, count);
}

int main() {
    Parser *parser;
    Histogram *histogram;
    GError *error;
    gchar *word;

    error = NULL;
    parser = parser_new(WORDFREQ_EBOOK, &error);
    if (error != NULL) {
        g_critical("%s: %s", error->message, WORDFREQ_EBOOK);
        g_error_free(error);
        return -1;
    }
    histogram = histogram_new();

    while (TRUE) {
        word = parser_read_word(parser, &error);
        if (word == NULL || error != NULL) {
            break;
        }
        histogram_count(histogram, word);
    }
    if (error != NULL) {
        g_critical("%s: %s", error->message, WORDFREQ_EBOOK);
        g_error_free(error);
    } else {
        histogram_sort(histogram);
        histogram_foreach(histogram, histogram_print, NULL);
    }

    parser_free(parser);
    histogram_free(histogram);
    return 0;
}
