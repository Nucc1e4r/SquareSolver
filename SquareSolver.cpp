#include <stdio.h>
#include <math.h>

int main (void) {
    float a, b, c;

    printf("ax^2 + bx + c = 0\n");

    printf("Input a:\n");
    scanf("%f", &a);

    printf("Input b:\n");
    scanf("%f", &b);

    printf("Input c:\n");
    scanf("%f", &c);

    float D = b * b - 4 * a * c;

    if (D > 0) {
        printf("x1 = %f\nx2 = %f", (-b + sqrt(D)) / (2 * a), (-b - sqrt(D)) / (2 * a));
    } else if (D < 0) {
        printf("No real solutions");
    } else {
        printf("x = %f", -b / (2 * a));
    }
}
