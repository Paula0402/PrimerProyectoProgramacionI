#include <stdio.h>

int main() {

    int Numero, CantidadNumeros;
    int Mayor = 0;
    int PosicionMayor = -1;
    int CantidadPrimos = 0;
    int CantidadNoPrimos = 0;
    double SumatoriaPrimos = 0; 
    double SumatoriaNoPrimos = 0; 
    double PromPrimos = 0;  
    double PromNoPrimos = 0; 

    
    printf("¿Cuantos numeros desea ingresar?\n");
    scanf("%d", &CantidadNumeros);

    
    for (int Contador = 1; Contador <= CantidadNumeros; Contador++) {
        printf("Digite un numero entero: ");
        scanf("%d", &Numero);

        
        int ContadorDivisores = 0;
        int I = 1;

        
        while (I <= Numero) {
            if (Numero % I == 0) {
                ContadorDivisores++;
            }
            I++;
        }

        
        if (ContadorDivisores == 2) {
            printf("El número %d es un numero primo.\n", Numero);
            CantidadPrimos++;
            SumatoriaPrimos += Numero;
        } else {
            printf("El número %d no es un numero primo.\n", Numero);
            CantidadNoPrimos++;
            SumatoriaNoPrimos += Numero;
        }

        
        if (Contador == 1 || Numero > Mayor) {
            Mayor = Numero;
            PosicionMayor = Contador;
        }
    }

    if (CantidadPrimos > 0) {
        PromPrimos = SumatoriaPrimos / CantidadPrimos;  
    } 
    if (CantidadNoPrimos > 0) {
        PromNoPrimos = SumatoriaNoPrimos / CantidadNoPrimos;  
    } 

    printf("\nEstadísticas:\n");
    printf("El numero mayor ingresado: %d en la posicion %d\n", Mayor, PosicionMayor);
    printf("Cantidad numeros primos: %d\n", CantidadPrimos);
    printf("Sumatoria de los numeros primos: %.2f\n", SumatoriaPrimos);
    printf("Promedio de los Numeros Primos: %.2f\n", PromPrimos);
    printf("Cantidad numeros no primos: %d\n", CantidadNoPrimos);
    printf("Sumatoria numeros no primos: %.2f\n", SumatoriaNoPrimos);
    printf("Promedio de los numeros no primos: %.2f\n", PromNoPrimos);

    return 0;
}

