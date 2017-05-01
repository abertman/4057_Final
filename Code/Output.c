#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Output(char *name, int size, int *months, double *betas, double *alphas){
  char * name_of_the_file;
  char * buying_patterns = "_buying_patters";
  name_of_the_file = malloc(4+strlen(buying_patterns));
  strcpy(name_of_the_file,name);
  strcat(name_of_the_file,buying_patterns);

  FILE *new_file;

  new_file = fopen(name_of_the_file,"w");
  int i;
  for (i = 0; i < size; i++){
    fprintf(new_file,"%d ",months[i]);
    fprintf(new_file,"%lf ",betas[i]);
    fprintf(new_file,"%lf ",alphas[i]);
    fprintf(new_file,"\n");
  }


  fclose(new_file);
}