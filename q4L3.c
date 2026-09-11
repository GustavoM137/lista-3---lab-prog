#include <stdio.h>

int main() {
    unsigned char x, e, n;
    float e_medio = 0;

    puts("Digite a quantidade n de amostras do sinal:");
    scanf("%hhu", &n);

    for (unsigned char i = 1; i <= n; i++) {
        puts("Digite o valor da amostra:");
        scanf("%hhu", &x);

        e = x & 0x0F; // |x - ^x| = |x - (x & 0xF0)| = |XXXX XXXX - XXXX 0000| = |0000 XXXX| = 0000 XXXX = x & 0x0F

        printf("Valor original: %hhu\n", x);
        printf("Valor quantizado: %hhu\n", x >> 4);
        printf("Valor reconstruído: %hhu\n", x & 0xF0);
        printf("Erro de quantização: %hhu\n", e);

        e_medio += e;
    }

    printf("Erro médio de quantização: %.2f\n", e_medio / n);

    return 0;
}
