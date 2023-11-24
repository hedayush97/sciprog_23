#include <stdio.h>
#include <math.h>

int main(void) {

/* Declare variables */
   int i,inum,tmp,numdigits;
   float fnum;
   char binnum[60];

/* Intialise 4-byte integer */
   inum = 33554431;
/* Convert to 4-byte float */
   fnum = (float) inum;


/* Convert to binary number (string)*/
   i = 0; tmp = inum;

/* Create a while loop for running all the numbers*/
   while (tmp > 0) {
     sprintf(&binnum[i],"%1d",tmp%2);
     tmp = tmp/2;
     i++;
   }

/* Terminate the string */
   binnum[i] = '\0';
       

/* Complete the expression */
   numdigits = ceil(logf(inum)/logf(2));
   printf("The number of digits is %d\n",numdigits);

/* Print the numbers*/
   printf("inum=%d,  fnum=%f, inum in binary=%s\n",
      inum,fnum,binnum);
   return 0;
}
