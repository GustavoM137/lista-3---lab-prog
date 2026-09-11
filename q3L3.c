#include <stdio.h>

int main() {
    float a1, a2, a, p1, p2, p, dc1, dc2, acc;
    int v1, v2, v, acertos_c, acertos_m, acertos_e, n = 10;

    puts("Digite a área, o perímetro e o número de vértices do centróide 1:");
    scanf("%f %f %d", &a1, &p1, &v1);

    puts("Digite a área, o perímetro e o número de vértices do centróide 2:");
    scanf("%f %f %d", &a2, &p2, &v2);

    for (int i = 1; i <= n; i++) {
        puts("Digite a área, o perímetro e o número de vértices do objeto X:");
        scanf("%f %f %d", &a, &p, &v);

        // Chebyshev
        dc1 = abs(v - v1);

        if (fabsf(a - a1) > dc1)
            dc1 = fabsf(a - a1);

        if (fabsf(p - p1) > dc1)
            dc1 = fabsf(p - p1);

        dc2 = abs(v - v2);

        if (fabsf(a - a2) > dc2)
            dc2 = fabsf(a - a2);

        if (fabsf(p - p2) > dc2)
            dc2 = fabsf(p - p2);

        if (dc1 < dc2)
            puts("Objeto X atribuído à classe C1");
        else if (dc2 > dc1)
            puts("Obejto X atribuído à classe C2");
        else
            puts("Empate na atribuição de classe.");

        return 0;
    }