#include "a4.h"
#include <stdio.h>
#include <stdlib.h>

PPM_IMAGE *read_ppm(const char *file_name){
    char buff[3];
    PPM_IMAGE *newimg;
    FILE *fr;
    //open PPM file for reading
    newimg = (PPM_IMAGE *)malloc(sizeof(PPM_IMAGE));
    fr = fopen(file_name, "r");
    //by using fscanf, we can iterate and read through the first lines of the file

    //remove and store image identifier to buffer
    fgets(buff, 3 , fr);
    //store the image width, height and maxcolor
    fscanf(fr, "%d %d", &newimg->width, &newimg->height);

    fscanf(fr, "%d", &newimg->max_color);
    PIXEL *p_array;
    //allocate space for array that stores the pixels
    p_array = (PIXEL *)malloc(sizeof(PIXEL)*newimg->width * newimg->height);
    newimg->data = p_array;
    int i;
    //iterate through pixels
    for( i = 0; i < newimg->width * newimg->height; i++){
        fscanf(fr, "%hhu", &p_array[i].r);

        fscanf(fr, "%hhu", &p_array[i].g);

        fscanf(fr, "%hhu", &p_array[i].b);




    }
    fclose(fr);
    return newimg;
}
void write_ppm(const char *file_name, const PPM_IMAGE *image){
  FILE *fp;
  fp = fopen(file_name, "w");
  fprintf(fp, "P3\n");
  fprintf(fp, "%d %d\n", image->width, image->height);
  fprintf(fp, "%d\n", image->max_color);
  int i;
  for(i = 0; i < image->width * image->height; i++){
    fprintf(fp, "%hhu ", image->data[i].r);
    fprintf(fp, "%hhu ", image->data[i].g);
    fprintf(fp, "%hhu ", image->data[i].b);
  }
  fclose(fp);
}
