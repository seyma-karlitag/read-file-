#include <stdio.h>
#define Max 250

void tree(FILE*fptr, char *s, int c0, int c1)
 {
 int total, k;
   if (*s == '\0') return;
    else if(*s==',') tree(fptr, s+1, c0, c1); //if you see a comma, call the increase index function again
    else if(*s=='(') tree(fptr, s+1, c0+1, c1); //when you see the brackets, the index is increased and the function is called again
    else if(*s==')') tree(fptr, s+1, c0, c1+1); //when you see the brackets, the index is increased and the function is called again
    
    
    else
    {
    total = c0 - c1; //the opening and closing brackets indicate the difference
         for(k=0;k<total;k++)
         {
           fprintf(fptr,"-");  //it makes the writing process as different as the opening and closing brackets
         }
         fprintf(fptr,"%c\n" ,*s);
         tree(fptr, s+1, c0, c1);
    }
 }


int main(){


  FILE *fptr;               

  char index[Max];
  int i=0,j=0,k=0,count_0=0,count_1=0;
  int total=0;
  fptr = fopen ("input.txt", "r+"); //file opening
  if(fptr==NULL)
  {
     return 0;
  }

 while(!feof(fptr))
  {
     fscanf(fptr,"%c ",&index[i]); //read strings and throw them into directories until the end of the file
     i++;
  }
  index[i] = '\0';
  
 fclose(fptr); //close the file
 
 fptr = fopen ("output.txt", "w"); //opening the output file
  if(fptr==NULL)
  {
     return 0;
  }
tree(fptr, index, count_0, count_1); //calling the recursive function

 
 fclose(fptr); //close the file

 return 0;


}
