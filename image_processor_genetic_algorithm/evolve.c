#include "a4.h"
#include <stdio.h>
#include <stdlib.h>

//comparison function, compares the fitness values of individuals
/*compare function referenced from https://l.facebook.com/l.php?u=http%3A%2F%2Fwww.tutorialspoint.com%2Fc_standard_library%2Fc_function_qsort.htm%3Ffbclid%3DIwAR06W5YVn4bqdPESIyy7_3lCDuwdz952_9hOMewtcEjKZdbgeGPopLVJEjc&h=AT1OOWYRk4h1KyCMvOCC7z3G2KohhSa3dpSA6j74LpC74OdpJgAplvY-lwt723UbUV0BKKNsdCvUZubWAOf6cFD1bklXCQlhypvlIf4gfYP_PBbH801rstRtT2YwwrXVwRthchPnFg4*/
static int compare (const void * a, const void * b)
{
  return (*(Individual*)a).fitness - (*(Individual*)b).fitness;
}

void free_image(PPM_IMAGE * p){
  free(p);
}

PPM_IMAGE *evolve_image(const PPM_IMAGE *image, int num_generations , int population_size , double rate){
  Individual *array_i = generate_population(population_size, image->width, image->height, image->max_color);
  comp_fitness_population(image->data, array_i , population_size);
  qsort (array_i, population_size, sizeof(Individual), compare);
  int i;
  for (i = 0; i < num_generations; i++){
    crossover(array_i, population_size);
    mutate_population(array_i ,population_size , rate);
    comp_fitness_population(image->data, array_i, population_size);
    qsort(array_i, population_size, sizeof(Individual), compare);
    //printf("%d\n", array_i[0].fitness);
  }
  int j;
  for (j = 1; j < population_size; j++){
    free_image((array_i + j)->image.data);
  }
  return &array_i[0].image;
}
