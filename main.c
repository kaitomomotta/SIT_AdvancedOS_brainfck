#include <stdio.h>
#include <stdlib.h>
int main() {


   char * buffer = 0;
   long length;
   FILE * f = fopen ("test.bf", "rb");

   if (f)
   {
      fseek (f, 0, SEEK_END);
      length = ftell (f);
      fseek (f, 0, SEEK_SET);
      buffer = malloc (length);
      if (buffer)
      {
         fread (buffer, 1, length, f);
      }
      fclose (f);
   }
   //BUFFER CEST MA STRING ALLO
   if (buffer)
   {
      // start to process your data / extract strings here...
      printf(buffer);
   }
   return 0;
}