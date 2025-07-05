#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define filename "dataset.txt"
#define DATASET_LEN 50
#define DATA_LEN 500

typedef struct{
  float f1;
  float f2;
  float f3;
  float f4;
  float f5;
  int cls;
} data;

double distance(data d, data o);
data findNearestNeighbor(data point, data* dataset, int len);
int readFromFile(data* dataset);
void printDataset(data* dataset, int len);

int main(){
  data dataset[DATASET_LEN];
  int len = readFromFile(dataset);
  printDataset(dataset, len);
  
  data input;
  printf("\nINSERT NEW POINT\n");
  printf("feature 1: ");
  scanf("%f", &input.f1);
  printf("feature 2: ");
  scanf("%f", &input.f2);
  printf("feature 3: ");
  scanf("%f", &input.f3);
  printf("feature 4: ");
  scanf("%f", &input.f4);
  printf("feature 5: ");
  scanf("%f", &input.f5);
  
  input.cls = findNearestNeighbor(input, dataset, len).cls;
  printf("\nNEW POINT CLASS: %d\n", input.cls);
  
  return 0;
}
  
double distance(data d, data o){
  return sqrt(
    pow(d.f1 - o.f1, 2) +
    pow(d.f2 - o.f2, 2) +
    pow(d.f3 - o.f3, 2) +
    pow(d.f4 - o.f4, 2) +
    pow(d.f5 - o.f5, 2)
  );
}

int readFromFile(data* dataset){
  FILE *file = fopen(filename,"r");
  if(file == NULL){
      printf("Open file error\n");
      return 0;
  }
  
  char rdata[DATA_LEN];
  char *token;
  int i=0;
  
  while (fgets(rdata, DATA_LEN, file)){
    token = strtok(rdata, ",");
    char *endptr;
    int j = 0;
    do{
      switch (j){
        case 0: dataset[i].f1 = strtod(token,NULL); break;
        case 1: dataset[i].f2 = strtod(token,NULL); break;
        case 2: dataset[i].f3 = strtod(token,NULL); break;
        case 3: dataset[i].f4 = strtod(token,NULL); break;
        case 4: dataset[i].f5 = strtod(token,NULL); break;
        case 5: dataset[i].cls = strtol(token, &endptr, 10); break;
      }
      j++;
    }while ((token = strtok(NULL, ",")) != NULL);
    i++;
  }
  fclose(file);
  return i;
}

void printDataset(data* dataset, int len){
  printf("---- DATASET ----\nfeature1,feature2,feature3,feature4,feature5,class\n");
  for(int i = 0; i< len; i++){
    printf("%.2f, %.2f, %.2f, %.2f, %.2f, %d\n", dataset[i].f1, dataset[i].f2, dataset[i].f3, dataset[i].f4, dataset[i].f5, dataset[i].cls);
  }
}

data findNearestNeighbor(data point, data* dataset, int len){
  data nearestNeighbor;
  if(dataset == NULL){
    nearestNeighbor.f1 = 0;
    nearestNeighbor.f2 = 0;
    nearestNeighbor.f3 = 0;
    nearestNeighbor.f4 = 0;
    nearestNeighbor.f5 = 0;
    nearestNeighbor.cls = 0;
    return nearestNeighbor;  
  }
  
  nearestNeighbor = dataset[0];
  double minDistance = distance(point, nearestNeighbor);
  
  for(int i = 1; i < len; i++){
    double tmpDistance = distance(point, dataset[i]);
    
    if (tmpDistance < minDistance){
      minDistance = tmpDistance;
      nearestNeighbor = dataset[i];
    }
  }
  
  return nearestNeighbor;
}
