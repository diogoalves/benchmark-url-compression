#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <ctype.h>

char * trim2(char *d, const char *s)
{
    if (s == NULL  ||  d == NULL)
        return NULL;

    unsigned const char * p = (unsigned const char *)s;
    while (isspace(*p))
        p++;

    unsigned char * dst = (unsigned char *)d;   
    unsigned char * end = dst;
    while (*p != '\0')
    {
        if (!isspace(*dst++ = *p++))
            end = dst;
    }

    *end = '\0';
    return d;
}

char * trim(char *s)
{
    return trim2(s, s);
}

int main ( void ) {
  char out[4096];
  int comprlen;
  static const char filename[] = "../input.txt";
  FILE *file = fopen ( filename, "r" );
  if ( file != NULL ) {
    char line [ 256 ]; /* or other suitable maximum line size */
    while ( fgets ( line, sizeof line, file ) != NULL ) {
      int comprlevel;
      trim(line);
      comprlen = smaz_compress(line,strlen(line),out,sizeof(out));
      comprlevel = 100-((100*comprlen)/strlen(line));
      if (comprlevel < 0) {
          printf("'%s' enlarged by %d%%\n",line,-comprlevel);
      } else {
          printf("'%s' compressed by %d%%\n",line,comprlevel);
      }
    }
   
    fclose ( file );
  } else {
    perror ( filename ); /* why didn't the file open? */
  }
  return 0;
}

