#ifndef _HISTOGRAM_H_
#define _HISTOGRAM_H_

typedef struct {
    GHashTable *table;
    GStringChunk *terms;
    GPtrArray *nodes;
} Histogram;

typedef struct {
    guint32 count;
    gchar *term;
} HistogramNode;

typedef void (*HistogramFunc) (gchar* term, guint32 count, gpointer user_data);

Histogram *histogram_new();

void histogram_count(Histogram *histogram, gchar* term);

guint32 histogram_lookup(Histogram *histogram, gchar* term);

void histogram_foreach(Histogram *histogram,
                       HistogramFunc func,
                       gpointer user_data);

void histogram_free(Histogram *histogram);

#endif
