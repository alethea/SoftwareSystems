#include <glib.h>
#include "parser.h"

Parser *parser_new(gchar *filename, GError **error) {
    Parser *parser;
    GIOChannel *channel;
    
    channel = g_io_channel_new_file(filename, "r", error);
    if (channel == NULL) {
        return NULL;
    }
    parser = g_slice_new(Parser);
    parser->channel = channel;
    parser->buf = g_string_new("");
    return parser;
}

void parser_free(Parser *parser) {
    g_io_channel_unref(parser->channel);
    g_string_free(parser->buf, TRUE);
    g_slice_free(Parser, parser);
}
