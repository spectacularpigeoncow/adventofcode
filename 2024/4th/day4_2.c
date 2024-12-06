#include <stdio.h>
#include <stdlib.h>



int main(int argc, char *argv[])
{
  char* filename = "input";
  if(argc > 1){
    filename = argv[1];
  }

  FILE* file = fopen(filename, "r");
  char temp[2000];
  int lines = 0;
  while(fgets(temp, sizeof(temp), file))lines++;
  int len =0;
  while(temp[len] != '\0')len++;
  char **matrix = malloc(lines * sizeof(char*));
  for(int i = 0; i < lines; i++){
    matrix[i] = malloc(len-1 * sizeof(char));
  }
  int row = 0;
  file = fopen(filename, "r");
  while(fgets(temp,sizeof(temp),file)){
    for(int i = 0; i < len; i++){
      matrix[row][i] = temp[i];
    }
    row++;
  }
  int count = 0;
  for(int i = 0; i < lines; i++){
    for(int j = 0; j < len - 1; j++){
      if(matrix[i][j] == 'A'){

        char top_left[] = {'a', 'A', 'a'};
        char top_right[] = {'a', 'A', 'a'};
        if(i > 0 && j < len ){
          if(matrix[i-1][j+1] == 'M' || matrix[i-1][j+1] == 'S'){
            int l = 0;
            if(matrix[i-1][j+1] == 'M')l = 0;
            else l=2;
            top_right[l] = matrix[i-1][j+1];

            if(i > 0 && j > 0){
              if(matrix[i-1][j-1] == 'M' || matrix[i-1][j-1] == 'S'){
                if(matrix[i-1][j-1] == 'M')l = 0;
                else l=2;
                top_left[l] = matrix[i-1][j-1];

                if(i < lines - 1 && j < len ){
                  if(matrix[i+1][j+1] == 'M' || matrix[i+1][j+1] == 'S'){
                    if(matrix[i+1][j+1] == 'M')l = 0;
                    else l=2;
                    top_left[l] = matrix[i+1][j+1];

                    if(i < lines  && j > 0){
                      if(matrix[i+1][j-1] == 'M' || matrix[i+1][j-1] == 'S'){
                        if(matrix[i+1][j-1] == 'M')l = 0;
                        else l=2;
                        top_right[l] = matrix[i+1][j-1];


                      }
                    }
                  }
                }
              }
            }
          }
        }
        if(top_left[0] == 'M' && top_right[0] == 'M' && top_left[2] == 'S' && top_right[2] == 'S'){
          count++;
        }  
      }
        



    }
  }
  printf("%i",count);
  return EXIT_SUCCESS;
}
