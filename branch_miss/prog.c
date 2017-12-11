// sudo perf record -e branch-misses --call-graph=dwarf ./prog 1> /dev/null
// sudo perf report -G

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rand_or(int a, int b) {
    return rand() % 2 ? a : b;
}

int main() {
    srand(time(NULL));

    for (int i = 0; i <= 300 * 1000 * 1000; i++) {       
        if (i % 3 == 0) {
            printf("Fizz\n");
        }
        
        if (i % 5 == 0) {
            printf("Buzz\n");
        }

        int r = rand_or(3, 5);
        if (i % r == 0) {
            printf("Rand\n");
        }
    }

    return 0;
}
