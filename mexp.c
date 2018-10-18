#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int** compute(int** MAT,int** result, int rowcol, int exponent);

int main(int argc, char **argv) {
    FILE *filePointer;
    filePointer = fopen(argv[1],"r");

    if (filePointer == NULL) {
        return EXIT_SUCCESS;
    }

    int i, j,m, entry, exponent, rowcol;
    fscanf(filePointer, "%d\n", &rowcol);

    /* Allocate space for MAT rows and gather respective data */

   int** MAT = (int**)malloc(rowcol * sizeof(int*));
   int** result = (int**)malloc(rowcol * sizeof(int*));

   for (m = 0; m < rowcol; m = m + 1) {
        MAT[m] = (int*)malloc(rowcol * sizeof(int*));
    }
 
   for (i = 0; i < rowcol; i = i + 1) {
        for (j = 0; j < rowcol; j = j + 1) {
            fscanf(filePointer,"%d", &entry);
            MAT[i][j] = entry;
        }
        fscanf(filePointer,"\n");
    }
	for (i = 0; i < rowcol; i = i + 1) {
result[i] = (int*)malloc(rowcol * sizeof(int*));
}
    for (i = 0; i < rowcol; i = i + 1) {
	for (j = 0; j < rowcol; j = j + 1) {
		result[i][j] = MAT[i][j];
}
}
    fscanf(filePointer, "%d", &exponent);
/*  
  for (i = 0; i < rowcol; i = i + 1) {
    result[i] = (int*)malloc(rowcol * sizeof(int*));
    } 
*/
    for (i = 1; i < exponent; i = i + 1) {
    result = compute(MAT, result, rowcol, exponent);
    }
if (exponent == 0) {
result = compute(MAT, result, rowcol, exponent);
}
    for (i = 0; i < rowcol; i = i + 1) {
        for (j = 0; j < rowcol; j = j + 1) {
        if (j != rowcol - 1) {   
	 printf("%d ", result[i][j]);
        } else {
printf("%d", result[i][j]);
}
}
        printf("\n");
    }

return 0;
}


int** compute(int** MAT,int** result, int rowcol, int exponent) {

int i, j, k;

int** multiple;
multiple = (int**)malloc(rowcol * sizeof(int*));

if (exponent == 0) {
for (i = 0; i < rowcol; i = i + 1) {
multiple[i] = (int*)malloc(rowcol * sizeof(int*));
}
for (i = 0; i < rowcol; i = i + 1) {
for (j = 0; j < rowcol; j = j + 1) {
if ( i==j ) {
multiple[i][j] = 1;
} else {
multiple[i][j] = 0;
}
}
} 
} else {
for (i = 0; i < rowcol; i = i + 1) {
    multiple[i] = (int*)malloc(rowcol * sizeof(int*));
}


/* Compute mutliplication on itself once */

for (i = 0; i < rowcol; i = i + 1) {
    for (j = 0; j < rowcol; j = j + 1) {
        for (k= 0; k < rowcol; k = k + 1) {
            multiple[i][j] += MAT[i][k] * result[k][j];
        }
    }
}
return multiple;
}
return multiple;
}






































