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


/////////////////////////////////////////////////
int lowest_match(struct term *terms, int nterms, char *substr)
{
    int sub_len = strlen(substr);
    int low = 0;
    int high = nterms -1;
    while (low <= high){
        int mid = (low + (high -low)) / 2;
        char *snippet = (char *)malloc(200 *sizeof(char));
        memmove(snippet, &(terms)[mid].term, sub_len); 
        int comp = strcmp(snippet, substr);

        if (comp  < 0){
            low = mid + 1;
            free(snippet);  
        }
        else if (comp > 0){
            high = mid -1;
            free(snippet);
        }
       
          return low; 

        }
    }







int highest_match(term *terms, int nterms, char *substr)
{
    int sub_len = strlen(substr);
    int low = 0;
    int high = nterms -1;
    while (low <= high){
        int mid = (low + (high -low)) / 2;
        char *snippet = (char *)malloc(200 *sizeof(char));
        memmove(snippet, &(terms)[mid].term, sub_len); 
        int comp = strcmp(snippet, substr);

        if (comp  > 0){
            right  = mid - 1;
            free(snippet);  
        }
        else {
            left = mid + 1;
            free(snippet);
        }
        
           

        }
    return right;
}





void autocomplete(term **answer, int *n_answer, term *terms, int nterms, char *substr);
