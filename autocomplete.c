#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "autocomplete.h"


void read_in_terms(term **terms, int *pnterms, char *filename);

int lowest_match(term *terms, int nterms, char *substr);

int highest_match(term *terms, int nterms, char *substr);

void autocomplete(term **answer, int *n_answer, term *terms, int nterms, char *substr);
