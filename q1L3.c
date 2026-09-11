#include <math.h>
#include <stdio.h>

int main() {
    float a_a, a_b, p_a, p_b, d_ab;
    int v_a, v_b;

    do {
        puts("Digite a área de A e B:");
        scanf("%f %f", &a_a, &a_b);

        if (a_a <= 0 || a_b <= 0)
            puts("Valor inválido.");

    } while (a_a <= 0 || a_b <= 0);

    do {
        puts("Digite o perímetro de A e B:");
        scanf("%f %f", &p_a, &p_b);

        if (p_a <= 0 || p_b <= 0)
            puts("Valor inválido.");

    } while (p_a <= 0 || p_b <= 0);

    do {
        puts("Digite o número de vértices de A e B:");
        scanf("%d %d", &v_a, &v_b);

        if (v_a <= 0 || v_b <= 0)
            puts("Valor inválido.");

    } while (v_a <= 0 || v_b <= 0);

    d_ab = fabsf(a_a - a_b);

    if (fabsf(p_a - p_b) > d_ab)
        d_ab = fabsf(p_a - p_b);

    if (abs(v_a - v_b) > d_ab)
        d_ab = abs(v_a - v_b);

    printf("Distância de Chebyshev = %.2f\n", d_ab);

    return 0;
}
