#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 2

// Estrutura para passar argumentos para a função da thread
typedef struct {
    int thread_id;
    double result;
} ThreadData;

// Função que será executada por cada thread
void *thread_function(void *threadarg) {
    ThreadData *my_data;
    my_data = (ThreadData *) threadarg;
    int thread_id = my_data->thread_id;
    int i;

    // Exemplo de tarefa da thread
    double partial_result = 0.0;
    for (i = 0; i < 1000000; ++i) {
        partial_result += (thread_id == 0) ? 0.000001 : -0.000001;
    }
    my_data->result = partial_result;

    printf("Thread %d finalizada com resultado parcial: %f\n", thread_id, my_data->result);

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    ThreadData thread_data[NUM_THREADS];

    int rc, t;
    double final_result = 0.0;

    // Criar threads
    for (t = 0; t < NUM_THREADS; ++t) {
        thread_data[t].thread_id = t;
        rc = pthread_create(&threads[t], NULL, thread_function, (void *)&thread_data[t]);
        if (rc) {
            printf("ERRO: retorno do pthread_create() é %d\n", rc);
            exit(-1);
        }
    }

    // Aguardar término das threads e acumular resultados
    for (t = 0; t < NUM_THREADS; ++t) {
        pthread_join(threads[t], NULL);
        final_result += thread_data[t].result;
    }

    printf("Resultado final: %f\n", final_result);

    pthread_exit(NULL);
}

