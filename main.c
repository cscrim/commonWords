/* Name: commonWords.c
   Author: Courtney Scrimshaw
   Function: take in 2 strings returning the words in common and the number of words in common
   Compilation: gcc -Wall -std=c99 -o commonWords commonWords.c
   Execution: ./commonWords
   Date: created on Feb. 27, 2024
*/

#include <stdio.h>
#include <string.h>

#define MAX_WORDS 10
#define MAX_WORD_LENGTH 15
#define MAX_SENTENCE_LENGTH 159

// function prototype

void findCommonWords(const char *str1, const char *str2);

int main() {

    // declare arrays for each sentence entered by user

    char sentence1[MAX_SENTENCE_LENGTH];
    char sentence2[MAX_SENTENCE_LENGTH];

    // user inputs two strings
    // fgets to read the input (ensuring no greater than max sentence length)

    printf("Enter the first string: ");
    fgets(sentence1, MAX_SENTENCE_LENGTH, stdin);

    if (strlen(sentence1) > 0 && sentence1[strlen(sentence1) - 1] == '\n')
        sentence1[strlen(sentence1) - 1] = '\0';

    printf("Enter the second string: ");
    fgets(sentence2, MAX_SENTENCE_LENGTH, stdin);

    if (strlen(sentence1) > 0 && sentence1[strlen(sentence1) - 1] == '\n')
        sentence1[strlen(sentence1) - 1] = '\0';

    // call the function to find the common words

    findCommonWords(sentence1, sentence2);

    return 0;
}

// function definition

void findCommonWords(const char *str1, const char *str2) {
    char words1[MAX_WORDS][MAX_WORD_LENGTH];
    char words2[MAX_WORDS][MAX_WORD_LENGTH];
    int count1 = 0, count2 = 0;
    int commonCount = 0;

    // token the strings
    // typecast str from const char* to char*
    // while loop to check if token is not NULL - meaning there are more tokens in the string
    // copy each token into the words array

    char *token = strtok((char *)str1, " ");
    while (token != NULL && count1 < MAX_WORDS) {
        strcpy(words1[count1++], token);
        token = strtok(NULL, " ");
    }

    token = strtok((char *)str2, " ");
    while (token != NULL && count2 < MAX_WORDS) {
        strcpy(words2[count2++], token);
        token = strtok(NULL, " ");
    }

  // compare to find common words

  printf("The word(s) in common are: [");
  for (int i = 0; i < count1; i++) {
      for (int j = 0; j < count2; j++) {
          if (strcmp(words1[i], words2[j]) == 0) {
              printf("%s", words1[i]);
              commonCount++; 

              if (i < count1 - 1 && commonCount > 0)
                  printf(", ");
          }
      }
  }

  printf("]");

  if (commonCount == 0) 
      printf("\nThere are no common words shared between the two sentences");

    else
        printf("\n%d word(s) are the same between the two strings", commonCount);
}