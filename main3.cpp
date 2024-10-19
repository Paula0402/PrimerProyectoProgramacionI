#include <cstdlib>
#include <stdio.h>

int main() {
    int Numero, NumeroInverso, Digito, NumeroOriginal;  
    char Continuar;

    do {
        printf("Digite un n�mero entero de m�ximo cinco d�gitos: ");
        scanf("%i", &Numero);

        if (Numero < 1 || Numero > 99999) {
            printf("El n�mero debe ser menor a 99999.\n");
        } else {
            NumeroOriginal = Numero;  
            NumeroInverso = 0;

            while (Numero > 0) {
                Digito = Numero % 10;
                Numero = Numero / 10;
                NumeroInverso = NumeroInverso * 10 + Digito;
            }

            printf("El n�mero ingresado es: %i\n", NumeroOriginal); 
            printf("El n�mero inverso es: %d\n", NumeroInverso);
        }

        printf("�Desea digitar otro n�mero? (s/n): ");
        scanf(" %c", &Continuar);

    } while (Continuar == 's' || Continuar == 'S');

    return 0;
}

