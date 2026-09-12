#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    float a1, a2, a, p1, p2, p, dc1, dc2, acc_c, acc_m, acc_e;
    int v1, v2, v, acertos_c, acertos_m, acertos_e, gt_correto, gt, n = 10;

    puts("Digite a área, o perímetro e o número de vértices do centróide 1:");
    scanf("%f %f %d", &a1, &p1, &v1);

    puts("Digite a área, o perímetro e o número de vértices do centróide 2:");
    scanf("%f %f %d", &a2, &p2, &v2);

    for (int i = 1; i <= n; i++) {
        puts("Digite a área, o perímetro e o número de vértices do objeto X:");
        scanf("%f %f %d", &a, &p, &v);

        puts("Digite a classe correta (GT), 1 para C1 e 2 para C2:");
        scanf("%d", &gt_correto);

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
            gt = 1;
        else if (dc1 > dc2)
            gt = 2;
        else
            gt = 0;

        if (gt == gt_correto)
            acertos_c++;

        // Manhattan
        dc1 = fabsf(a - a1) + fabsf(p - p1) + abs(v - v1);
        dc2 = fabsf(a - a2) + fabsf(p - p2) + abs(v - v2);

        if (dc1 < dc2)
            gt = 1;
        else if (dc1 > dc2)
            gt = 2;
        else
            gt = 0;

        if (gt == gt_correto)
            acertos_m++;

        // Euclidiana
        dc1 = sqrtf((a - a1) * (a - a1) + (p - p1) * (p - p1) + (v - v1) * (v - v1));
        dc2 = sqrtf((a - a2) * (a - a2) + (p - p2) * (p - p2) + (v - v2) * (v - v2));

        if (dc1 < dc2)
            gt = 1;
        else if (dc1 > dc2)
            gt = 2;
        else
            gt = 0;

        if (gt == gt_correto)
            acertos_e++;
    }

    // Chebyshev
    acc_c = (float)acertos_c / n * 100;
    printf("Acurácia (Chebyshev): %.3f\n", acc_c);

    // Manhattan
    acc_m = (float)acertos_m / n * 100;
    printf("Acurácia (Manhattan): %.3f\n", acc_m);

    // Euclidiana
    acc_e = (float)acertos_e / n * 100;
    printf("Acurácia (Euclidiana): %.3f\n", acc_e);

    if (acc_c > acc_m && acc_c > acc_e)
        printf("A medida de Chebyshev apresentou o melhor desempenho.\n");
    else if (acc_m > acc_e)
        printf("A medida de Manhattan apresentou o melhor desempenho.\n");
    else
        printf("A medida Euclidiana apresentou o melhor desempenho.\n");

    return 0;
}
