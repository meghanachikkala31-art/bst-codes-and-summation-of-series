#include <stdio.h>
#include <math.h>

int main() {
    int x, n;
    double sum;

    printf("Enter X: ");
    scanf("%d", &x);

    printf("Enter n: ");
    scanf("%d", &n);

    if (x == 1) {
        sum = n + 1;
    } else {
        sum = (pow(x, n + 1) - 1) / (x - 1);
    }

    printf("Sum = %.2f\n", sum);

    return 0;
}