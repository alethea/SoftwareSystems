#include <glib.h>
#include "freqtable.h"

FreqTable *freq_table_new() {
    FreqTable *freq_table;
    
    freq_table = g_new(FreqTable, 1);
    freq_table->hash_table = g_hash_table_new(g_str_hash, g_str_equal);
    freq_table->string_chunk = g_string_chunk_new(0);
    return freq_table;
}

void freq_table_count(FreqTable *freq_table, gchar* term) {
    gint32 count;
    
    count = freq_table_lookup(freq_table, term);
    if (!count) {
        term = g_string_chunk_insert(freq_table->string_chunk, term);
    }
    count++;
    g_hash_table_insert(freq_table->hash_table, term, GINT_TO_POINTER(count));
}

gint32 freq_table_lookup(FreqTable *freq_table, gchar *term) {
    gpointer count_ptr;

    count_ptr = g_hash_table_lookup(freq_table->hash_table, term);
    return GPOINTER_TO_INT(count_ptr);
}

void freq_table_free(FreqTable* freq_table) {
    g_hash_table_destroy(freq_table->hash_table);
    g_free(freq_table->hash_table);
    g_string_chunk_free(freq_table->string_chunk);
    g_free(freq_table);
}
