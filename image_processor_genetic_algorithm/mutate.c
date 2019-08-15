#include "a4.h"
#include <stdio.h>
#include <stdlib.h>


void mutate(Individual *individual , double rate){
  int n = individual->image.width * individual->image.height;
  int mp = (int)(n * rate/100);
  int i;
  for ( i = 0; i < mp; i++){
    individual[i].image.data[rand()%n].r = rand() % individual->image.max_color;
    individual[i].image.data[rand()%n].g = rand() % individual->image.max_color;
    individual[i].image.data[rand()%n].b = rand() % individual->image.max_color;
    }
}
void mutate_population(Individual *individual , int population_size , double rate){
  int i;
  for(i = population_size * 0.25; i < population_size; i++ ){
    mutate(individual, rate);
  }
}
