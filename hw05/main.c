#include <glib.h>
#include <glib/gprintf.h>
#include "freqtable.h"

int main() {
    FreqTable *freq_table;

    freq_table = freq_table_new();
    g_printf("%d\n", freq_table_lookup(freq_table, "test"));
    freq_table_count(freq_table, "test");
    g_printf("%d\n", freq_table_lookup(freq_table, "test"));
    freq_table_free(freq_table);
    return 0;
}
