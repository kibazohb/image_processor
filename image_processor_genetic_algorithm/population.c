#include "a4.h"
#include <stdio.h>
#include <stdlib.h>
PIXEL *generate_random_image(int width, int height, int max_color){
  PIXEL *p_array = malloc(sizeof(PIXEL) * width * height);
  int i;
  for (i = 0; i < width * height; i++){
    p_array[i].r = rand() % max_color + 1;
    p_array[i].g = rand() % max_color + 1;
    p_array[i].b = rand() % max_color + 1;
  }

return p_array;
}
Individual *generate_population(int population_size, int width, int height , int max_color){
  Individual *array = malloc(sizeof(Individual) * population_size);
  int i;
  for(i = 0; i < population_size; i++){
    PIXEL *info = generate_random_image(width, height, max_color);
    array[i].image.width = width;
    array[i].image.height = height;
    array[i].image.max_color = max_color;
    array[i].image.data = info;

  }
  return array;
}
