#include <glib.h>
#include "histogram.h"

Histogram *histogram_new() {
    Histogram *histogram;
    
    histogram = g_new(Histogram, 1);
    histogram->hash_table = g_hash_table_new(g_str_hash, g_str_equal);
    histogram->string_chunk = g_string_chunk_new(0);
    return histogram;
}

void histogram_count(Histogram *histogram, gchar* term) {
    gint32 count;
    
    count = histogram_lookup(histogram, term);
    if (!count) {
        term = g_string_chunk_insert(histogram->string_chunk, term);
    }
    count++;
    g_hash_table_insert(histogram->hash_table, term, GINT_TO_POINTER(count));
}

gint32 histogram_lookup(Histogram *histogram, gchar *term) {
    gpointer count_ptr;

    count_ptr = g_hash_table_lookup(histogram->hash_table, term);
    return GPOINTER_TO_INT(count_ptr);
}

void histogram_free(Histogram *histogram) {
    g_hash_table_destroy(histogram->hash_table);
    g_free(histogram->hash_table);
    g_string_chunk_free(histogram->string_chunk);
    g_free(histogram);
}
