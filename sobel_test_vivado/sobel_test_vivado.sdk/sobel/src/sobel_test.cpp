
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sobel.h"
#include "base.h"
#include "sobel_hw.h"

//Arrays to send and receive data from the accelerator
//AXI_PIXEL in_pix[MAX_HEIGHT][MAX_WIDTH];
//AXI_PIXEL out_pix[MAX_HEIGHT][MAX_WIDTH];

int main () {
  char *tempbuf;
  char *tempbuf1;
  int check_results = 0;

  tempbuf = (char *)malloc(2000 * sizeof(char));
  tempbuf1 = (char *)malloc(2000 * sizeof(char));


  // Arrays to store image data
  unsigned char *R;
  unsigned char *G;
  unsigned char *B;
  

  R = (unsigned char *)malloc(MAX_HEIGHT * MAX_WIDTH * sizeof(unsigned char));
  G = (unsigned char *)malloc(MAX_HEIGHT * MAX_WIDTH * sizeof(unsigned char));
  B = (unsigned char *)malloc(MAX_HEIGHT * MAX_WIDTH * sizeof(unsigned char));

  //Get image data from disk
  sprintf(tempbuf, "%s.bmp", INPUT_IMAGE_BASE);
  printf("Read img %s\n",tempbuf);
  // Fill a frame with data
  int read_tmp = BMP_Read(tempbuf, MAX_HEIGHT, MAX_WIDTH, R, G, B);
  if(read_tmp != 0) {
    printf("%s Loading image failed\n", tempbuf);
    exit (1);
  }
  printf("Read img ok\n");

  
  printf("Copy RGB to Share Memory\n");
  copy_mem2dev(R, G, B, MAX_WIDTH, MAX_HEIGHT, 0x10000000);
  printf("Copy RGB to Share Memory OK\n");
  printf("SOBEL START\n");
  SOBEL_HW(MAX_WIDTH, MAX_HEIGHT);
  printf("SOBEL START OK\n");
  printf("DMA\n");
  DMA_HW(MAX_WIDTH,MAX_HEIGHT,0x10000000,0x12000000);
  printf("DMA OK\n");
  printf("Copy Share Memory to RGB\n");
  copy_dev2mem(R, G, B, MAX_WIDTH, MAX_HEIGHT,0x12000000);
  printf("Copy Share Memory to RGB OK\n");

  //Write the image back to disk
  sprintf(tempbuf1, "%s.bmp", OUTPUT_IMAGE_BASE);
  printf("Write img %s\n",tempbuf1);
  int write_tmp = BMP_Write(tempbuf1, MAX_HEIGHT, MAX_WIDTH, R, G, B);
  if(write_tmp != 0){
    printf("WriteBMP %s failed\n", tempbuf);
    exit(1);
  }
  printf("Write img ok\n");

  free(R);
  free(G);
  free(B);
  free(tempbuf);
  free(tempbuf1);
  printf("Complete\n");

  return check_results;
}
