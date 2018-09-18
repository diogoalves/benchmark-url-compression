#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <ctype.h>

/*
 from: https://stackoverflow.com/questions/122616/how-do-i-trim-leading-trailing-whitespace-in-a-standard-way
 */
char *trim2(char *d, const char *s) {
  if (s == NULL || d == NULL) return NULL;
  unsigned const char *p = (unsigned const char *)s;
  while (isspace(*p)) p++;
  unsigned char *dst = (unsigned char *)d;
  unsigned char *end = dst;
  while (*p != '\0') {
    if (!isspace(*dst++ = *p++)) end = dst;
  }
  *end = '\0';
  return d;
}

char *trim(char *s)  {
  return trim2(s, s);
}

int main(void) {
  char outSmaz[4096];
  char outShoco[4096];
  char outShocoUrlmodel[4096];
  int comprlenSmaz, comprlenShoco, comprlenShocoUrlmodel;
  static const char filename[] = "./urls.txt"; /* download used file in https://mega.nz/#!4hlTlaQK!qFsukhsNdWUdxHk655JWnUua6qQU--dHWiyqsMExRqc */
  FILE *file = fopen(filename, "r");
  if (file != NULL) {
    char line[512];
    double sumCompressionsSmaz, sumCompressionsShoco, sumCompressionsShocoUrlmodel;
    int countCompressions = 0;
    while (fgets(line, sizeof line, file) != NULL)     {
      double compressionSmaz, compressionShoco, compressionShocoUrlmodel;
      trim(line);
      comprlenSmaz = smaz_compress(line,strlen(line),outSmaz,sizeof(outSmaz));
      comprlenShoco = shoco_compress(line, strlen(line), outShoco, sizeof(outShoco));
      comprlenShocoUrlmodel = shoco_compress_urlmodel(line, strlen(line), outShocoUrlmodel, sizeof(outShocoUrlmodel));
      compressionSmaz = 1.0 - (double)comprlenSmaz / strlen(line);
      compressionShoco = 1.0 - (double)comprlenShoco / strlen(line);
      compressionShocoUrlmodel = 1.0 - (double)comprlenShocoUrlmodel / strlen(line);
      sumCompressionsSmaz += compressionSmaz;
      sumCompressionsShoco += compressionShoco;
      sumCompressionsShocoUrlmodel += compressionShocoUrlmodel;
      countCompressions++;
      /* printf("'%s'compressed by %f %f %f\n", line, compressionSmaz, compressionShoco, compressionShocoUrlmodel); */
    }
    printf("Overall compression of smaz:%f shoco:%f shoco_urlmodel:%f\n", sumCompressionsSmaz / countCompressions, sumCompressionsShoco / countCompressions, sumCompressionsShocoUrlmodel / countCompressions);
    fclose(file);
  }
  else
  {
    perror(filename); /* why didn't the file open? */
  }
  return 0;
}
