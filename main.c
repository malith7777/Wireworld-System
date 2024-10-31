#include <stdio.h>
#include <stdlib.h>
#include "map.h"

int main(int argc, char* argv[])
{
char* file;
char** map1;
float slp;
int steps;
int a, b, c;
int Rows, Cols;
FILE* F;
    
    if (argc != 4) 
    {
        printf("User Entered Invalid number of arguments\n");
    } else 
    {
        file = argv[1];
        steps = atoi(argv[2]);
        slp = atof(argv[3]);

        F = fopen(file, "r");
        if (F == NULL) 
        {
            perror("Error Can't open the Text file");
        } else 
        {
            fscanf(F, "%d %d", &Rows, &Cols);

            map1 = (char**)malloc(Rows * sizeof(char*)); 

            for (a = 0; a < Rows; a++) 
            {
                map1[a] = (char*)malloc(Cols * sizeof(char));
            }

            for (b = 0; b < Rows; b++) 
            {
            for (c = 0; c < Cols; c++) 
                {
                    fscanf(F, " %c", &map1[b][c]);
                }
            }

            fclose(F); 
            system("clear");
            printmap(map1, Rows, Cols);
            Cellmap(map1, slp, steps, Rows, Cols);
            for (a = 0; a < Rows; a++) 
            {
                free(map1[a]);
            }
            free(map1);
        }
    }

    return 0;
}  
      
         
 
