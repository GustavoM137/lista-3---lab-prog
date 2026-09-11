#include <stdio.h>

int main() {
    unsigned char x, e, e_medio = 0, n;

    puts("Digite a quantidade n de amostras do sinal:");
    scanf("%hhu", &n);

    for (unsigned char i = 1; i <= n; i++) {
        puts("Digite o valor da amostra:");
        scanf("%hhu", &x);

        e = (x > (x & 0xF0)) ? x - (x & 0xF) : (x & 0xF) - x;

        printf("Valor original: %hhu\n", x);
        pritnf("Valor quantizado: %hhu\n", x >> 4);
        printf("Valor reconstruído: %hhu\n", x & 0xF0);
        printf("Erro de quantização: %hhu\n", e);

        e_medio += e;
    }

    printf("Erro médio de quantização: %.2f\n", (float)e_medio / n);

    return 0;
}
