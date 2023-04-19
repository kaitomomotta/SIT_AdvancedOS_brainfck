#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//BUFFER CEST MA STRING
//TAB CEST MA MEMOIRE
//RES CEST MON RESULTAT

int tab[30000];
int head=0;
int unmatched=0;

void preparray(int tab[])
{
   for (size_t i = 0; i < 30000; i++)
   {
      tab[i]=0;
   }
}

void process(char* buffer)
{
   int len = strlen(buffer);
   for (int i = 0; i < len; i++)
   {
      if (buffer[i]=='+')
      {
         tab[head]++;
         //continue;
      }
      if (buffer[i]=='-')
      {
         tab[head]--;
         //continue;
      }
      if (buffer[i]=='>')
      {
         head++;
         //continue;
      }
      if (buffer[i]=='<')
      {
         head--;
         //continue;
      }
      if (buffer[i]=='.')
      {
         printf("%c",(char)tab[head]);
         //continue;
      }
      if (buffer[i]==',')
      {
         
         tab[head]=getchar();
         //continue;
      }
      if (buffer[i]=='[')
      {
         if (tab[head]==0)
         {
            /* code */
                     
            unmatched++;
            while (buffer[i]!=']'||unmatched!=0)
            {
               i++;
               if (buffer[i]=='[')
               {
                  unmatched++;
               }
               else if (buffer[i]==']')
               {
                  unmatched--;
               }
               
            }
         }

      }
      if (buffer[i]==']')
      {
         if (tab[head]!=0)
         {
            /* code */
            unmatched++;
            while (buffer[i]!='[' || unmatched!=0)
            {
               i--;
               if (buffer[i]==']')
               {
                  /* code */
                  unmatched++;
               }
               else if (buffer[i]=='[')
               {
                  /* code */
                  unmatched--;
               }
               
               
            }
            
         }
         
      }
      
      
   }
   
   return;
}

int main(int argc, char *argv[]) {
   char * buffer = 0;
   long length;
   FILE * f = fopen (argv[1], "rb");

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
   
   if (buffer)
   {
      // start to process your data / extract strings here...
      //preparray(tab);
       //ICI CEST IMPORTANT
      //printf("%s",buffer);
      
      process(buffer);
      //printf("\n");
      //printf("%c",(char)tab[head]);
   }
   return 0;
}

