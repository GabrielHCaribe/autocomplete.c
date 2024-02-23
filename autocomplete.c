#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "autocomplete.h"


int compare_terms(const void *a, const void *b) {
    return strcmp(((term *)a)->term, ((term *)b)->term);

void read_in_terms(term **terms, int *pnterms, char *filename)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL){
        fprintf(stderr,"memory allocation error!");
        exit(1);
    }

    char *line  = (char *)malloc(sizeof(char) * 200);
    fgets(number, 200, file);
    *pnterms = atoi(number);

    (*terms) = (term *)malloc(sizeof(term)*(*pnterms));
    
    for(int i = 0; i < (*pnterms); i++)
    {
        fgets(line, 200, file);
        
        double temp;
        sscanf(line, "%lf", &temp);
        (*terms)[i].weight = temp;
        
        memmove(&((*terms + i)->term), &(line[14]), 200);

    }

    fclose(file);
    qsort(*terms, *pnterms, sizeof(term), compare_terms);


}
//////////////////////////////


int compare_terms(const void *a, const void *b) {
    return strcmp(((term *)a)->term, ((term *)b)->term);
}

void read_in_terms(term **terms, int *pnterms, char *filename)
{
    //This first code opens the file
    FILE *file = fopen(filename, "r");
    if (file == NULL){
        exit(1);
    }

    //Ths part of the code reads the the number saying how many terms are. Storing it in a pointer
    char *line  = (char *)malloc(sizeof(char) * 200);
    fgets(number, 200, file);
    *pnterms = atoi(number);
     //This mallocs an array of terms which we can now manipulate
    (*terms) = (term *)malloc(sizeof(term)*(*pnterms));
     
    char buffer[300];
    int i = 0;

    while (i <= (*pnterms) && fgets(buffer,sizeof(buffer),file ))
    {
        //remove the trailing space
        size_t newlineIndex = strcspn(buffer, "\n");//---> basically calculate how many characters before the line change 
        if (newlineIndex < sizeof(buffer)) {
            buffer[newlineIndex] = '\0';
        }
        // If the next character is a space keep skipping space.
        char *space = strchr(buffer,' ');
        while (*(space + 1) == ' '){
            space++;
        }

        *space = '\0';
        (*terms)[i] -> weight = atof(buffer);

        // now we copy the rest of the characters, we define where we start copying,aka right after the space index 
        strncpy((*terms)[i] -> term, space + 1, sizeof((*terms)[i] -> term)- 1);// the minus one is reserved for the null character
        (*terms)[i] -> term[sizeof((*terms)[i] -> term)-1] = '\0';
        i++;


    }

    fclose(file);
    qsort(*terms, *pnterms,sizeof(term),compare_terms);
    

}
//////////////////////////////////////////////////
//String Sorting Function
    char s1[] = "Zhis is the way";
    char s2[] = "This is the way";
    if (strcmp(s1,s2) == 0){
        printf("string is equal. \n");
    }
    else if (strcmp(s1,s2) < 0){ //less than 0 means that s1 has lower ascci value
        printf("s1 < s2\n");
    }
     else if (strcmp(s1,s2) > 0){
        printf("s1 > s2\n"); // greater than 0  means that s1 has higher ascci value
    }

    //what if the string is not equal?
    //< 0 if the 1st non matching char has a lower ascci value in s1 than s2
    //> 0 if the first non matching char has a higher ascii value in s1 than s2
    






int lowest_match(term *terms, int nterms, char *substr);

int highest_match(term *terms, int nterms, char *substr);

void autocomplete(term **answer, int *n_answer, term *terms, int nterms, char *substr);
