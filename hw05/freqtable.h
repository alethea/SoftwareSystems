#ifndef _FREQTABLE_H_
#define _FREQTABLE_H_

typedef struct {
    GHashTable *hash_table;
    GStringChunk *string_chunk;
} FreqTable;

FreqTable *freq_table_new();
void freq_table_free(FreqTable *freq_table);

#endif
