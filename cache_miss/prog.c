// sudo perf record -e cache-misses --call-graph=dwarf ./prog 1> /dev/null
// sudo perf report -G

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10000000
int arr[SIZE];

void init() {
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand();
    }
}

void seq_wanderer() {
    for (int i = 0; i < SIZE; i++) {
        printf("%d", arr[i]);
    }
}

void rand_wanderer() {
    for (int i = 0; i < SIZE; i++) {
        printf("%d", arr[rand() % SIZE]);
    }
}

int main() {
    srand(time(NULL));

    init();
    seq_wanderer();
    rand_wanderer();

    return 0;
}
