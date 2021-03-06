#include <stdio.h>

#ifdef _OPENMP
#include <omp.h>
#else
#define omp_get_thread_num() 0
#endif

int main(int argc, char const *argv[]) {
  int i, n = 7;
  int a[n], suma;

  for (i=0; i<n; i++)
  a[i] = i;

  // suma = 50;

  #pragma omp parallel private(suma)
  {
    suma = 50;

    printf("Valor inicial de suma: %d\n",suma);

    #pragma omp barrier

    #pragma omp for
    for (i=0; i<n; i++){
      suma = suma + a[i];
      printf("thread %d suma a[%d] / ", omp_get_thread_num(), i);
    }
    printf("\n* thread %d suma= %d", omp_get_thread_num(), suma);
  }

  printf("\nValor fuera de region paralela de suma: %d\n",suma);
}
