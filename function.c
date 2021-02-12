
#include "header.h"

#define MAX_ROWS 100
#define MAX_COLS 80

char store_data_in_2Dmatrix(void)
{
   FILE *fp = fopen("input.txt", "r");
   char array[100][80]={0};
   int i = 0;
   int j = 0;
   int k;
   int row = 100;
   int col = 80;

   if ( fp )
   {
      for ( ;; )
      {
         int c = getc(fp);
         if ( c == EOF )
         {
            break;
         }
         if ( c != '\n' && c != '\r' )
         {
            array[i][j] = c;
            if ( ++j >= col )
            {
               j = 0;
               if ( ++i >= row )
               {
                  break;
               }
            }
         }
      }
      fclose(fp);
   }

   for ( i = 0; i < row; i++ )
   {
      for ( j = 0; j < col; j++ )
      {
          putchar(array[i][j]);
      }
      putchar('\n\n');
   }
   return array;
}
