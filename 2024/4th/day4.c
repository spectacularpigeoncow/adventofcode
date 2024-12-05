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
    for(int i = 0; i < len-1; i++){
      matrix[row][i] = temp[i];
    }
    row++;
  }
  int count = 0;
  for(int i = 0; i < lines; i++){
    for(int j = 0; j < len - 1; j++){
      if(matrix[i][j] == 'X'){
        //Up
        if(i > 2){
          if(matrix[i-1][j] == 'M' && matrix[i-2][j] == 'A' && matrix[i-3][j] =='S')count++;
        }

        //Down
        if(i < lines - 3){
          if(matrix[i+1][j] == 'M' && matrix[i+2][j] == 'A' && matrix[i+3][j] =='S')count++;
        }

        //Right
        if(j < len - 2){
          if(matrix[i][j+1] == 'M' && matrix[i][j+2] == 'A' && matrix[i][j+3] =='S')count++;
        }

        //Left
        if(j > 2){
          if(matrix[i][j-1] == 'M' && matrix[i][j-2] == 'A' && matrix[i][j-3] =='S')count++;
        }

        //Up-right
        if(i > 2 && j < len - 2){
          if(matrix[i-1][j+1] == 'M' && matrix[i-2][j+2] == 'A' && matrix[i-3][j+3] =='S')count++;
        }
        //Up-left
        if(i > 2 && j > 2){
          if(matrix[i-1][j-1] == 'M' && matrix[i-2][j-2] == 'A' && matrix[i-3][j-3] =='S')count++;
        }
        //Down-right
        if(i < lines - 3 && j < len - 2){
          if(matrix[i+1][j+1] == 'M' && matrix[i+2][j+2] == 'A' && matrix[i+3][j+3] =='S')count++;
        }
        //Down-left
        if(i < lines - 3 && j > 2){
          if(matrix[i+1][j-1] == 'M' && matrix[i+2][j-2] == 'A' && matrix[i+3][j-3] =='S')count++;
        }
        
      }
    }
  }
  printf("%i",count);
  return EXIT_SUCCESS;
}
