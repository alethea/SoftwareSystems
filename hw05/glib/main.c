#include <glib.h>
#include <glib/gprintf.h>
#include "histogram.h"

void histogram_print(gchar * term, guint32 count, gpointer user_data) {
    g_printf("%s %d\n", term, count);
}

int main() {
    Histogram *histogram;

    histogram = histogram_new();
    g_printf("%d\n", histogram_lookup(histogram, "test"));
    histogram_count(histogram, "test");
    histogram_foreach(histogram, histogram_print, NULL);
    g_printf("%d\n", histogram_total(histogram));
    histogram_free(histogram);
    return 0;
}
