#ifndef _HISTOGRAM_H_
#define _HISTOGRAM_H_

typedef struct {
    GHashTable *hash_table;
    GStringChunk *string_chunk;
} Histogram;

Histogram *histogram_new();
void histogram_count(Histogram *histogram, gchar* term);
gint32 histogram_lookup(Histogram *histogram, gchar* term);
void histogram_free(Histogram *histogram);

#endif
