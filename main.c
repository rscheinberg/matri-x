#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"

int main() {

  screen s;
  clear_screen(s);
  
  struct matrix *test = new_matrix(5,5);
  
  printf("\n[Testing the Creation of an Identity Matrix and the Print Function]\n");
  ident(test);
  print_matrix(test);
  
  printf("\n[Testing Matrix Multiplication]\n");
  printf("INITIAL MATRICIES:\n");
  struct matrix *a = new_matrix(2,2);
  struct matrix *b = new_matrix(2,2);
  a->m[0][0] = 1;
  a->m[0][1] = 2;
  a->m[1][0] = 1;
  a->m[1][1] = 2;
  b->m[0][0] = 3;
  b->m[1][0] = 4;
  b->m[0][1] = 3;
  b->m[1][1] = 4;
  printf("\nA:\n");
  print_matrix(a);
  printf("\nB:\n");
  print_matrix(b);
  printf("\nMULTIPLYING B * A, THEN PRINT A\n");
  matrix_mult(b, a);
  print_matrix(a);
  
  struct matrix *edges = new_matrix(4, 1);
  printf("\n[Adding 0,0,0 1,1,1 to 4x1 edge matrix]\n");
  add_edge(edges, 0, 0, 0, 1, 1, 1);
  print_matrix(edges);

  printf("\nImage name: image.png\n");
  struct matrix *image = new_matrix(4, 1);
  add_edge(image, 200, 10, 0, 400, 10, 0);
  add_edge(image, 200, 30, 0, 275, 30, 0);
  add_edge(image, 325, 30, 0, 400, 30, 0);
  add_edge(image, 200, 10, 0, 200, 30, 0);
  add_edge(image, 400, 10, 0, 400, 30, 0);
  
  add_edge(image, 275, 30, 0, 275, 200, 0);
  add_edge(image, 325, 30, 0, 325, 200, 0);
  add_edge(image, 300, 10, 0, 300, 200, 0);
  
  add_edge(image, 200, 200, 0, 400, 200, 0);
  add_edge(image, 200, 200, 0, 200, 300, 0);
  add_edge(image, 400, 200, 0, 400, 300, 0);
  add_edge(image, 200, 300, 0, 400, 300, 0);
  
  add_edge(image, 200, 300, 0, 150, 300, 0);
  add_edge(image, 150, 300, 0, 150, 150, 0);
  add_edge(image, 400, 300, 0, 450, 300, 0);
  add_edge(image, 450, 300, 0, 450, 150, 0);
  add_edge(image, 450, 150, 0, 400, 200, 0);
  add_edge(image, 150, 150, 0, 200, 200, 0);
  
  add_edge(image, 150, 150, 0, 200, 30, 0);
  add_edge(image, 450, 150, 0, 400, 30, 0);
  add_edge(image, 200, 200, 0, 200, 30, 0);
  add_edge(image, 400, 200, 0, 400, 30, 0);
  
  
  color c;
  c.red = 255;
  c.blue = 255;
  c.green = 255;
  draw_lines(image, s, c);
  save_extension(s, "image.png");
  
  free_matrix(image);
  free_matrix( edges );
  free_matrix(test);
}  
