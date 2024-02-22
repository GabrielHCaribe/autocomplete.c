#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "autocomplete.h"


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
    
    char buffer[256]; // Adjust the buffer size as needed

    // New version
    for(int i = 0; i < (*pnterms) + 1; i++)
    {
        fgets(line, sizeof(line), file);
        if (i == 0)
        {
            continue;
        }
        else
        {
            
        }
    }

    

    fclose(file);


}







int lowest_match(term *terms, int nterms, char *substr);

int highest_match(term *terms, int nterms, char *substr);

void autocomplete(term **answer, int *n_answer, term *terms, int nterms, char *substr);
