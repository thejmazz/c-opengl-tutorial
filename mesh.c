#include <stdio.h>
#include <stdlib.h>
#include "mesh.h"

void draw() {
  printf("drawing\n");

  struct Vertex *v = malloc(sizeof(struct Vertex));

  v->x = 5;
  printf("%d\n", v->x);
}
