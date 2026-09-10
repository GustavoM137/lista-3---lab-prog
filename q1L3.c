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

    d_ab = (a_a - a_b > a_b - a_a) ? a_a - a_b : a_b - a_a;

    if (p_a - p_b > p_b - p_a)
        d_ab = (p_a - p_b > d_ab) ? p_a - p_b : d_ab;

    else
        d_ab = (p_b - p_a > d_ab) ? p_b - p_a : d_ab;

    if (v_a - v_b > v_b - v_a)
        d_ab = (v_a - v_b > d_ab) ? v_a - v_b : d_ab;

    else
        d_ab = (v_b - v_a > d_ab) ? v_b - v_a : d_ab;

    printf("Distância de Chebyshev = %.2f\n", d_ab);

    return 0;
}
