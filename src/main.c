#include "philos.h"

pthread_mutex_t mutex;
void *computation(void *add)
{
    pthread_mutex_lock(&mutex);
    long *add_long = (long *) add;
    (*add_long)++;
    pthread_mutex_unlock(&mutex);
    printf("add_long: %ld\n", *add_long);
    return (NULL);
}

int main(void)
{
    pthread_t   thread[10000];
    int         i;
    pthread_mutex_init(&mutex, NULL);
    long value1 = 1;
    for (int i = 0; i < 10000; i++)
        pthread_create(&thread[i], NULL, computation, (void *) &value1);

    for (i = 0; i < 10000; i++)
        pthread_join(thread[i], NULL);
    pthread_mutex_destroy(&mutex);
    printf("hi from main thread! value1 is %ld\n", value1);

    return (0);
}