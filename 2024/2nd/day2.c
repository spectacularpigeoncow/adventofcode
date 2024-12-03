#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[])
{
  int counter = 0;
  FILE* file = fopen("day2_input", "r");
  char line[256];
  int safe = 0;
  while(fgets(line, sizeof(line), file)){
    printf("%s", line);
    int len = 0;
    while(line[len] != '\0')len ++;
    int spaces = 0;
    if(len > 0){
      for(int i = 0; i < len - 1; i++){
        if(line[i] == ' '){
          spaces++;
        }
      }
      int* arr = malloc((spaces + 1) *sizeof(int));
      char *p = strtok(line, " ");
      int i =0;
      while(p != NULL){
        arr[i++] = atoi(p);
        p = strtok(NULL, " ");
      }
    int inc_dec = 0; // 0 = minskning 1 = ökning
    for(int i = 0; i < spaces + 1; i++){
      if(i + 1 < spaces + 1){
        int tempy = arr[i] - arr[i+1];
        if(i == 0){
          if(tempy < 0){
            inc_dec = 1;
          }
        }
      }
    }
    free(arr);
    }

  }
  return 0;
}
