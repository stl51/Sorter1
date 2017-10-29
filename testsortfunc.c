#include <stdio.h>
#include <string.h>
#include "Sorter.h"

int main() {
	char * filename = "short_movie.csv"; //add filename here
	FILE* fp = fopen(filename, "r");
	FILE* fpo = sort_csv(fp, 4);
	return 0;
}