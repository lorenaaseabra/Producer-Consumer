#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>

sem_t empty;
sem_t full;


pthread_mutex_t mutex;

int in = 0;
int out = 0;
int *buffer;

int N = 0, B = 0, C = 0, P = 0;

void *producer();
void *consumer();

int main(){

    scanf(" number producer:%d,consumer:%d,buffer size:%d,N: %d", &P, &C, &B, &N);
    pthread_t * pro = (pthread_t*)malloc(sizeof(pthread_t) * P);
    pthread_t * con = (pthread_t*)malloc(sizeof(pthread_t)* C);

    buffer = (int*)malloc(sizeof(int)*B);

    pthread_mutex_init(&mutex, NULL);
    

    sem_init(&empty,0,0);
    sem_init(&full,0,B);

    int size = P > C ? P : C;
    int *index = (int *)malloc(sizeof(int)*size);

    for(int i = 0; i < size; i++){
        index[i] = i;
    }

    for(int i = 0; i < P; i++){
        pthread_create(&pro[i], NULL, producer, &index[i]);
    }

    for(int i = 0; i < C; i++){
        pthread_create(&con[i], NULL, consumer, &index[i]);
    }

    for(int i = 0; i < P; i++){
        pthread_join(pro[i], NULL);
    }
    for(int i = 0; i < C; i++){
        pthread_join(con[i], NULL);
    }


    return 0;
}

void *producer(void *pno){
    int *id = pno;
    int input;
    while(1){
        for(int i = 0; i <= N; i++){
            input = 2*i + 1;
            sem_wait(&full);
            pthread_mutex_lock(&mutex);
            buffer[in] = input;
            printf("Producer (number)%d input %d at index %d",*id, input, in);
            in = (in+1)%B;

            pthread_mutex_unlock(&mutex);
            sem_post(&empty);
            
        }
    }
}

void *consumer(void *cno){
    int *id = cno;
    int output;
    while(1){
        sem_wait(&empty);
        pthread_mutex_lock(&mutex);
        output = buffer[out]; 
        printf("Consumer %d Output %d at index %d", *id, output, out);
        out = (out+1)%B;
        
        pthread_mutex_unlock(&mutex);
        sem_post(&full);


    }

}
