//Kathleen Law and James Blash
//CS373 - Operating Systems
//Uppercase and Lowercase Converter and Vowel splitWord Counter

#include <stdio.h> //importing necessary libraries
#include <stdlib.h> // I guess
#include <string.h> //dis 4 dem strangggggs
#include <ctype.h>


int main(){
  char c;
  FILE *inputptr = fopen("AssignmentThree-O-S-Fall2018.txt", "r");
  FILE *outputptr = fopen("Assignment-3-Data.txt", "w");
  char str[10000] = "";
  int count = 0;
  while ((c=fgetc(inputptr))!=EOF) {
    str[count] = c; // this needs to be replaced with function to read from file
    count++;
  }
  printf("%s\n", str);
  char *splitWord = strtok(str, " ");


    while(splitWord != NULL) {
      if (strlen(splitWord) > 1) //if length of word is greater than 1
        {
          for (int i = 0; i < strlen(splitWord); i++)
          {
            if (i == 0 || i == strlen(splitWord) - 1)
            {
              if (splitWord[i] >= 'a' && splitWord[i] <= 'z')
              {
                splitWord[i] = splitWord[i] - 32;
              }
              else if (splitWord[i] >= 'A' && splitWord[i] <= 'Z')
              {
                splitWord[i] = splitWord[i] + 32;
              }
              printf("%c", splitWord[i]);
            }
            else
            {
              printf("%c", splitWord[i]);
            }
          }
      }
      else {
        printf("%c", splitWord[0]);
      }
      if (splitWord[0] == 'a' || splitWord[0] == 'A' ||
      splitWord[0] == 'e' || splitWord[0] == 'E' ||
      splitWord[0] == 'i' || splitWord[0] == 'I' ||
      splitWord[0] == 'o' || splitWord[0] == 'O' ||
      splitWord[0] == 'u' || splitWord[0] =='U')
      {
        fprintf (outputptr, "%s\n", splitWord);
      }
      printf(" ");
      splitWord = strtok(NULL, " ");
    }

  fclose(inputptr);
  fclose(outputptr);
  return 0;
}


//**  **//
//while (word length > 1)
  //while next character in word isn't null
  //if the letter is uppercase, make it lowercase
  //else if the letter is lowercase, make it uppercase
  //else continue
  //if this word starts with a vowel, copy it to another file
//print word to console
