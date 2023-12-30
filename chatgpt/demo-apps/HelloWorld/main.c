#include <stdio.h>
#include <stdlib.h>

int main(){
  FILE *fptr;

  // Open a file in read mode
  fptr = fopen("helloworld.txt", "r");

  // Store the content of the file
  char myString[100000];

  // Read the content and store it inside myString
  fgets(myString, 10000, fptr);

  // Print file content
  printf("%s\n", myString);  

  // Close the file
  fclose(fptr);
};