#include <glib-2.0/glib.h>
#include <stdio.h>
#include <sys/timeb.h>
#include <string.h>
#include "stringlist.h"

const char *_findthis = NULL;

gboolean finder(gpointer key, gpointer value)
{
    return strcmp((char *)key, _findthis);
}

int main(void)
{
    GHashTable *stringcounts = NULL;
    gpointer elem = NULL;
    struct timeb end;
    struct timeb start;
    int i = 0;

    stringcounts = g_hash_table_new(g_str_hash, g_str_equal);
    if ( !stringcounts ) {
	fprintf(stderr, "No memory\n");
	return 1;
    }

    ftime(&start);
    for (i = 0; i < STRINGLISTSIZE ; i++ ) {
	_findthis = stringlist[i];
	elem = g_hash_table_find(stringcounts, (GHRFunc)finder, NULL);
	if ( ! elem ) {
	    g_hash_table_insert(stringcounts, (char *)_findthis, (void *)1);
	} else {
	    g_hash_table_insert(stringcounts, (char *)_findthis, elem + 1);
	}
    }
    ftime(&end);
    printf("Over %d elements : %d milliseconds\n",
	   STRINGLISTSIZE,
	   (int)(((end.time * 1000) + end.millitm) - ((start.time * 1000) + start.millitm)));

    g_hash_table_destroy(stringcounts);
}
