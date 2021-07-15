#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#ifdef _OPENMP
#include <omp.h>
#else
#define omp_get_thread_num() 0
#endif
int main(int argc, char const *argv[]) {
  int **matrix;
  int *vec, *res;
  int tamanio, suma,j;
  time_t t
  double inicio, tiempo;
  // Inicializamos la semilla del rand
  srand((unsigned) time(&t));
  if(argc < 2){
    fprintf(stderr, "\nFalta tamanioaño de filas/columnas\n");
    exit(-1);
  }
  tamanio = atoi(argv[1]);
  // Reservo memoria
  vec = (int *) malloc(tamanio*sizeof(int));
  res = (int *) malloc(tamanio*sizeof(int));
  matrix = (int **) malloc(tamanio*sizeof(int*));
  // Inicializar vec y reservar memoria para matrix
  for (int i = 0; i < tamanio; i++) {
    matrix[i] = (int *) malloc(tamanio*sizeof(int));
  }
  // Inicializar matrix a 0
  for (int i = 0; i < tamanio; i++) {
    for (int j = 0; j < tamanio; j++) {
      matrix[i][j] = 0;
    }
  }
  // Inicializar valores por encima de diagonal principal de la matrix
  // e inicializar valores del vec
  for (int i = 0; i < tamanio; i++) {
    // vec[i] = rand() % 20;
  vec[i] = i + 1;
    for (int j = 0 + i; j < tamanio; j++) {
      matrix[i][j] = j + 1;
      // matrix[i][j] = rand() % 20;
    }
  }
  inicio = omp_get_wtime();
  // Realizar calculo
  #pragma omp parallel for private(suma,j) schedule(runtime)
  for (int i = 0; i < tamanio; i++) {
    suma = 0;
    for (j = 0 + i; j < tamanio; j++) {
      suma += vec[j] * matrix[i][j];
    }
    res[i] = suma;
  }
  tiempo = omp_get_wtime() - inicio;
  // Mostrar res
  printf("Tiempo empleado: %11.9f\n",tiempo);
  printf("Primer elemento res: %d\n",res[0]);
  printf("Ultimo elemento res: %d\n",res[tamanio-1]);
  //Liberar memoria
  for (int i = 0; i < tamanio; i++) {
    free(matrix[i]);
  }
  free(matrix);
  free(vec);
  free(res);
  return 0;
}
