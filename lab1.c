#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <math.h>

void swap(double *a, double *b) {
    double temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(double array[], int size) {
    for (int step = 0; step < size - 1; step++) {
        int min_idx = step;
        for (int i = step + 1; i < size; i++) {
            if (array[i] < array[min_idx])
                min_idx = i;
        }
        swap(&array[min_idx], &array[step]);
    }
}

int main(int argc, char *argv[]) {
    int i, N, j;
    unsigned int seed = 1;
    struct timeval T1, T2;
    long delta_ms;
    N = atoi(argv[1]); // N равен первому параметру командной строки
    gettimeofday(&T1, NULL); // запомнить текущее время T1
    for (i = 0; i < 100; i++) { // 100 экспериментов
        srand(seed);
        // Этап 1
        double M1[N], M2[N/2], M2Copy[N/2];
        //printf("\n M1: ");
        for (j = 0; j < N; j++) {
            M1[j] = rand_r(&seed) % 240 + 1;
            //printf("%f, ", M1[j]);
        }
        //printf("\n M2: ");
        for (j = 0; j < N/2; j++) {
            M2[j] = rand_r(&seed) % 2160 + 240;
            //printf("%f, ", M2[j]);
        }
        //printf("\nSTEP 2\n");
        // Этап 2
        for (j = 0; j < N; j++) {
            M1[j] = cbrt(M1[j]/ exp(1));
            //printf("%f, ", M1[j]);
        }
        for (j = 0; j < N/2; j++) {
            M2Copy[j] = M2[j];
        }
        //printf("\n");
        M2[0] = pow(log10(M2[0]), exp(1));
        for (j = 1; j < N/2; j++) {
            M2[j] = pow(log10(M2[j] + M2Copy[j-1]), exp(1));
            //printf("%f, ", M2[j]);
        }
        //printf("\nSTEP 3\n");
        // Этап 3
        for (j = 0; j < N/2; j++) {
            M2[j] = fabs(M1[j] - M2[j]);
            //printf("%f, ", M2[j]);
        }
        //printf("\nSTEP 4\n");
        // Этап 4
        selectionSort(M2, N/2);
        for (j = 0; j < N/2; j++) {
            //printf("%f, ", M2[j]);
        }
        //printf("\nSTEP 5\n");
        // Этап 5
        double minM2 = 0;
        double X = 0;
        j = 0;
        while (minM2 == 0){
            if (M2[j] > 0) {
                minM2 = M2[j];
            }
            j++;
        }
        for (j = 0; j < N/2; j++) {
            if (fmod(floor(M2[j]/minM2), 2) == 0){
                X += sin(M2[j]);
            }
        }
        printf("%f, ", X);
    }
    gettimeofday(&T2, NULL); // запомнить текущее время T2
    delta_ms = (T2.tv_sec - T1.tv_sec) * 1000 +
               (T2.tv_usec - T1.tv_usec) / 1000;
    printf("\nN=%d. Milliseconds passed: %ld\n", N, delta_ms);
    return 0;
}


