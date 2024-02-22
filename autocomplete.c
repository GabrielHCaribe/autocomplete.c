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

    *terms = (term *)malloc((*pnterms)*sizeof(term));//---> already allocated memory for all the terms
    if (*terms == NULL) {
        fprintf(stderr, "Memory allocation error\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < *pnterms; i++)
    {
     if (fscanf(file, "%lf  %199s",&(*terms)[i].weight,(*terms)[i].term) != 2)//----> gives the number of stuff read.
     {
        fprintf(stderr,"File could not be read %s\n",filename);//---> maybe don't have to print stuff.
        exit(1);
     }
    }

    fclose(file);


}







int lowest_match(term *terms, int nterms, char *substr);

int highest_match(term *terms, int nterms, char *substr);

void autocomplete(term **answer, int *n_answer, term *terms, int nterms, char *substr);
