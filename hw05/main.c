#include <glib.h>
#include <glib/gprintf.h>
#include "freqtable.h"

int main() {
    FreqTable *freq_table;

    freq_table = freq_table_new();
    freq_table_free(freq_table);
    return 0;
}
