#include <glib-2.0/glib.h>
#include <stdio.h>
#include <sys/timeb.h>
#include "intlist.h"

int main(void)
{
    GHashTable *intcounts = NULL;
    gpointer elem = NULL;
    struct timeb end;
    struct timeb start;
    int cur = 0;
    int i = 0;

    intcounts = g_hash_table_new(g_int_hash, g_int_equal);
    if ( !intcounts ) {
	fprintf(stderr, "No memory\n");
	return 1;
    }

    ftime(&start);
    for (i = 0; i < INTLISTSIZE ; i++ ) {
	cur = intlist[i];
	elem = g_hash_table_lookup(intcounts, &cur);
	if ( ! elem ) {
	    g_hash_table_insert(intcounts, &cur, (void *)1);
	} else {
	    g_hash_table_insert(intcounts, &cur, elem + 1);
	}
    }
    ftime(&end);
    printf("Over %d elements : %d milliseconds\n",
	   INTLISTSIZE,
	   (int)(((end.time * 1000) + end.millitm) - ((start.time * 1000) + start.millitm)));

    g_hash_table_destroy(intcounts);
}
