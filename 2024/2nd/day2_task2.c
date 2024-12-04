#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check_rules(int* arr, int spaces){
int inc_dec = 0; // > 0 = minskning < 0 = ökning
    int safe_temp = 0;
    for(int i = 0; i < spaces; i++){
      int tempy = arr[i] - arr[i+1];

      if(i == 0) inc_dec = tempy;
      if((inc_dec > 0) && (tempy < 0)) {
          safe_temp = 0;
          break;
        }
      if((inc_dec < 0) && (tempy > 0 )){
          safe_temp = 0;
          break;
        }
      if(tempy == 0){
          safe_temp = 0;
          break;
        }
      if(tempy > 3){
          safe_temp = 0;
          break;
        }
      if(tempy < -3){
          safe_temp = 0;
          break;
        }
      safe_temp++;
    }
  return safe_temp;
}

int main(int argc, char *argv[])
{
  int counter = 0;
  FILE* file = fopen("day2_input", "r");
  char line[256];
  int safe = 0;
  while(fgets(line, sizeof(line), file)){
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
    
    int safe_temp = check_rules(arr,spaces);
    
    if(safe_temp == spaces){
      safe++;
    }
    else{
      int* arr_less = malloc(spaces*sizeof(int));
      int removed = 0;
      while(removed < spaces + 1){
          int index_new = 0;
          for(int i =0; i < spaces + 1; i++){
            if(i == removed){
              continue;
            }
            arr_less[index_new] = arr[i];
            index_new++;
          }
          int safe_temp2 = check_rules(arr_less, spaces - 1);
          if(safe_temp2 == (spaces -1)){
            safe++;
            removed = spaces;
          }
          removed++;
      }


      free(arr_less);
      }

    free(arr);
    }

  }
  printf("Safe = %i", safe);
  return 0;
}
