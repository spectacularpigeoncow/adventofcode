#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int compare_ints(const void* a, const void* b)
{
    long arg1 = *(const long*)a;
    long arg2 = *(const long*)b;
    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
}

void sort_arr(long* arr, size_t elements){
 qsort(arr, elements, sizeof(long), compare_ints);

}

int main(int argc, char *argv[])
{
  long* in_x = malloc(1000*sizeof(long));
  long* in_y = malloc(1000*sizeof(long));

  FILE* file = fopen("task1_input", "r");
  long tempx, tempy;
  int i = 0;
  while(fscanf(file, "%li %li", &tempx, &tempy) == 2){
    in_x[i] = tempx;
    in_y[i] = tempy;
    i++;
  }
  size_t el = 1000;
  sort_arr(in_x, el);
  sort_arr(in_y, el);
  long counter = 0;
  long dist = 0;
  for(int j = 0; j < 1000; j++){
    int comp = compare_ints(&in_x[j], &in_y[j]);
    if(comp == -1){
      dist = in_y[j] - in_x[j];
    } 
    else{
      dist = in_x[j] - in_y[j];
    }
    counter += dist;
  }
  printf("Distance is %li", counter);
  
  counter = 0;
  for(int j = 0; j < 1000; j++){
    long temp = in_x[j];
    int counter2 = 0;
    for(int k = 0; k < 1000; k++){
      if(temp == in_y[k]){
        counter2 ++;
      }
    }
    counter += (counter2*temp);
  }
  printf("Similarity score %li", counter);
  free(in_x);
  free(in_y);
return 0;
}
