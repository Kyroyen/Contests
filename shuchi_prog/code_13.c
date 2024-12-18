#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    FILE *file_ptr;

    file_ptr = fopen("test.txt", "r");

    if (NULL == file_ptr){
        printf("File can't be opened \n");
        return 0;
    }

    char ch;
    int inWord, count;
    inWord = count = 0;

    //Read the chracters one by one in file, until the end of file is reached.
    //Every chracter is put into ch, then checked if it's a EOF or not
    while ((ch = fgetc(file_ptr)) != EOF){
        if (isspace(ch) || ispunct(ch)){ //Check if it's either a space or not
            inWord = 0;
        }
        else if (!inWord)
        {
            // If we are not in a word and encounter a non-space character, it's the start of a new word
            inWord = 1;
            count++;
        }
    }
    fclose(file_ptr); //close the file

    file_ptr = fopen("output.txt", "w"); //open file on write mode

    if (NULL == file_ptr){
        printf("File can't be opened \n");
        return 0;
    }

    fprintf(file_ptr, "Number of words in the file: %d\n", count); //Just print into the output file
    fclose(file_ptr);

    return 0;
}