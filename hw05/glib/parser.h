#ifndef _WORDFREQ_PARSER_H_
#define _WORDFREQ_PARSER_H_

#include <glib.h>

typedef struct {
    GIOChannel *channel;
    GString *buf;
} Parser;

Parser *parser_new(gchar *filename, GError **error);

gchar *parser_read_word(Parser *parser, GError **error);

void parser_free(Parser *parser);

#endif
