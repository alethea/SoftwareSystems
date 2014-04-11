#include <glib.h>
#include "histogram.h"

void histogram_node_free(gpointer node) {
    g_slice_free(HistogramNode, node);
}

Histogram *histogram_new() {
    Histogram *histogram;
    
    histogram = g_slice_new(Histogram);
    histogram->table = g_hash_table_new(g_str_hash, g_str_equal);
    histogram->terms = g_string_chunk_new(1024);
    histogram->nodes = g_ptr_array_new_with_free_func(histogram_node_free);
    
    return histogram;
}

void histogram_count(Histogram *histogram, gchar* term) {
    HistogramNode *node;
    
    node = g_hash_table_lookup(histogram->table, term);
    if (node == NULL) {
        node = g_slice_new(HistogramNode);
        node->term = g_string_chunk_insert(histogram->terms, term);
        node->count = 1;
        g_ptr_array_add(histogram->nodes, node);
        g_hash_table_insert(histogram->table, term, node);
    } else {
        node->count++;
    }
}

typedef struct {
    HistogramFunc func;
    gpointer user_data;
} HistogramForEachWrapper;

void histogram_foreach_wrapper(gpointer data, gpointer user_data) {
    HistogramNode *node;
    HistogramForEachWrapper *wrapped_data;
    
    node = data;
    wrapped_data = user_data;
    wrapped_data->func(node->term, node->count, wrapped_data->user_data);
}

void histogram_foreach(Histogram *histogram,
                       HistogramFunc func,
                       gpointer user_data) {
    HistogramForEachWrapper data;

    data.func = func;
    data.user_data = user_data;
    g_ptr_array_foreach(histogram->nodes, histogram_foreach_wrapper, &data);
}

guint32 histogram_lookup(Histogram *histogram, gchar *term) {
    HistogramNode *node;

    node = g_hash_table_lookup(histogram->table, term);
    if (node != NULL) {
        return node->count;
    } else {
        return 0;
    }
}

void histogram_free(Histogram *histogram) {
    g_hash_table_destroy(histogram->table);
    g_string_chunk_free(histogram->terms);
    g_ptr_array_free(histogram->nodes, TRUE);
    g_slice_free(Histogram, histogram);
}
