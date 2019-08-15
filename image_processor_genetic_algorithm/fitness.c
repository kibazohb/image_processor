#include "a4.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double comp_distance(const PIXEL *A, const PIXEL *B, int image_size){
  double dist = 0;
  double r,g,b;
  int i;
  for (i = 0;i < image_size; i++){
    r = (A[i].r - B[i].r);
    g = (A[i].g - B[i].g);
    b = (A[i].b - B[i].b);
    dist = dist + (r * r) + (g * g) + (b * b);

  }
  double ans = sqrt(dist);
  return ans;
}

void comp_fitness_population(const PIXEL *image, Individual * individual , int population_size){
  int i;
  for (i = 0; i < population_size; i++){
    individual[i].fitness = comp_distance(image, individual[i].image.data, individual[i].image.width * individual[i].image.height);
  }
}
