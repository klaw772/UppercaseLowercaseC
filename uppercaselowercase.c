//Kathleen Law and James Blash
//CS373 - Operating Systems
//Uppercase and Lowercase Converter and Vowel splitWord Counter

//importing necessary libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int main(){
  char c;
  FILE *inputptr = fopen("AssignmentThree-O-S-Fall2018.txt", "r"); //opens input file
  FILE *outputptr = fopen("Assignment-3-Data.txt", "w"); //creates output file
  char str[10000] = ""; //empty string array to hold input file contents
  int count = 0;
  while ((c=fgetc(inputptr))!=EOF) { //traverses and places input into array
    str[count] = c; // this needs to be replaced with function to read from file
    count++;
  }
  printf("%s\n", str);
  char *splitWord = strtok(str, " "); //creates substring of str from a character to a space


    while(splitWord != NULL) {
      if (strlen(splitWord) > 1) //if length of word is greater than 1
        {
          for (int i = 0; i < strlen(splitWord); i++) //traverses across word
          {
            if (i == 0 || i == strlen(splitWord) - 1) //only changes first and last char
            {
              if (splitWord[i] >= 'a' && splitWord[i] <= 'z') //if lowercase
              {
                splitWord[i] = splitWord[i] - 32; //make it uppercase using ASCII
              }
              else if (splitWord[i] >= 'A' && splitWord[i] <= 'Z') //if uppercase
              {
                splitWord[i] = splitWord[i] + 32; //make it lowercase using ASCII
              }
              printf("%c", splitWord[i]); //print the new modified character
            }
            else //if not first or last character
            {
              printf("%c", splitWord[i]); //print the unchanged character
            }
          }
      }
      else { //if length equals 1
        printf("%c", splitWord[0]); //print the single character
      }
      if (splitWord[0] == 'a' || splitWord[0] == 'A' || //if vowel
      splitWord[0] == 'e' || splitWord[0] == 'E' ||
      splitWord[0] == 'i' || splitWord[0] == 'I' ||
      splitWord[0] == 'o' || splitWord[0] == 'O' ||
      splitWord[0] == 'u' || splitWord[0] =='U')
      {
        fprintf (outputptr, "%s\n", splitWord); //print token to output file
      }
      printf(" ");
      splitWord = strtok(NULL, " "); //traverse to the next token
    }

  fclose(inputptr); //close input file
  fclose(outputptr); //close output file
  return 0;
}
