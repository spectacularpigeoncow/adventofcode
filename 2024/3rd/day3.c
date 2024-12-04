#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{

  char* filename = "input";
  if( argc > 1) {
    char* filename = argv[1];
    printf("%s",filename);
  }

  FILE* file = fopen(filename,"r");
  char line[20000];
  unsigned long long total = 0;
  int do_dont = 0;
  while(fgets(line, sizeof(line),file)){
    int len = 0;
    int count = 0;

    while(line[len] != '\0')len ++;
    for(int i = 0; i < len; i ++){
      //This is a mess, but could not figure out why it did not work in one if statement
      // Also not using regex cause did not understand how the library worked
      if(line[i] == 'd' ){ 
        if(line[i+1] == 'o'){
          if(line[i+2] == '('){
            if(line[i+3] == ')'){
              do_dont = 0;
            }
          }
        }
      }
      if(line[i] == 'd'){
        if(line[i+1] == 'o'){
            if(line[i+2] == 'n'){
              if((int)line[i+3] == 39){
                if(line[i+4] == 't'){ 
                  if(line[i+5] == '('){
                      if(line[i+6] == ')' ){
                        do_dont = 1;
                          
                  }
                }
              }
            }
          }
        }
      }
      if(line[i] == 'm' && line[i+1] == 'u' && line[i+2] == 'l' && line[i+3] == '(' ){
        
        char number1[20];
        char number2[20];
        int first_num = 0;
        int ends_with = 0;
        int index = 0;
        for(int j = i+4; j < len; j++){
          if(47 < line[j] && line[j] < 58){
            if(first_num == 0){
              number1[index] = line[j];
              index ++;
            }
            else{
              number2[index] = line[j];
              index ++;
            }
            continue;
          }
          else if(line[j] == 44){
            first_num = 1;
            index = 0;
            continue;
          }
          else{
            if(line[j] == 41){
              ends_with = 1;
              break;
            }
            else{
              
              break;
            }
          }

        }
        if(ends_with == 1 && do_dont == 0){
          int num1 = atoi(number1);
          int num2 = atoi(number2);
          total += num1 * num2;
        }
        for(int j =0; j < 20; j++){
          number1[j] = 0;
          number2[j] = 0;
        }


      }
    }
  }
  printf("total = %llu ", total);

  return 0;
}



