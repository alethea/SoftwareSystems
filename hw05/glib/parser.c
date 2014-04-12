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

gboolean parser_skip(gunichar c) {
    return g_unichar_isspace(c) || g_unichar_ispunct(c);
}

gchar *parser_read_word(Parser *parser, GError **error) {
    gunichar c;
    GIOStatus status;

    g_string_truncate(parser->buf, 0);
    do {
        status = g_io_channel_read_unichar(parser->channel, &c, error);
        if (status != G_IO_STATUS_NORMAL) {
            return NULL;
        }
    } while (parser_skip(c));

    while (!parser_skip(c)) {
        switch (status) {
            case G_IO_STATUS_NORMAL:
            case G_IO_STATUS_EOF:
                g_string_append_unichar(parser->buf, g_unichar_tolower(c));
                break;
            default:
                return NULL;
        }
        status = g_io_channel_read_unichar(parser->channel, &c, error);
    }

    return parser->buf->str;
}

void parser_free(Parser *parser) {
    g_io_channel_unref(parser->channel);
    g_string_free(parser->buf, TRUE);
    g_slice_free(Parser, parser);
}
