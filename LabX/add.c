#include <stdio.h>

int add(int *a, int *b, int *c) {
    return *a + *b + *c;
}

int main() {
    int x = 5, y = 10, z = 15;
    int sum = add(&x, &y, &z);
    printf("Sum: %d\n", sum);
    return 0;
}
