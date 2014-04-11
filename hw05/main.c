#include <glib.h>
#include <glib/gprintf.h>
#include "histogram.h"

int main() {
    Histogram *histogram;

    histogram = histogram_new();
    g_printf("%d\n", histogram_lookup(histogram, "test"));
    histogram_count(histogram, "test");
    g_printf("%d\n", histogram_lookup(histogram, "test"));
    histogram_free(histogram);
    return 0;
}
