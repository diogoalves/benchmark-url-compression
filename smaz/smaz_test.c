#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "smaz.h"

int main(void) {
    char out[4096];
    int comprlen;
    int j;
    char *strings[] = {
        "http://www.paulgraham.com/mit.html",
        "http://www.foundersatwork.com/stevewozniak.html",
        "http://avc.blogs.com/a_vc/2006/10/the_nyc_develop.html",
        NULL
    };

    j=0;
    while(strings[j]) {
        int comprlevel;

        comprlen = smaz_compress(strings[j],strlen(strings[j]),out,sizeof(out));
        comprlevel = 100-((100*comprlen)/strlen(strings[j]));
        if (comprlevel < 0) {
            printf("'%s' enlarged by %d%%\n",strings[j],-comprlevel);
        } else {
            printf("'%s' compressed by %d%%\n",strings[j],comprlevel);
        }
        j++;
    }
   
    return 0;
}