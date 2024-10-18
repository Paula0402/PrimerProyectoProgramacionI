#include <cstdlib>
#include <stdio.h>

int main() {
    int Numero, NumeroInverso, Digito;
    char Continuar;

    do {
        
        printf("Digite un numero entero de máximo cinco dígitos: ");
        scanf("%i", &Numero);

        
        if (Numero < 1 || Numero > 99999) {
            printf("El número debe ser menor a 99999.\n");
            
        } else {
        	
            NumeroInverso = 0;  

            while (Numero > 0) {
                Digito = Numero % 10;     
				Numero = Numero / 10;             
                NumeroInverso = NumeroInverso * 10 + Digito; 
                
            }

            printf("El número inverso es: %d\n", NumeroInverso);
        }

        printf("¿Desea digitar otro número? (s/n): ");
        scanf(" %c", &Continuar); 

    } while (Continuar == 's' || Continuar == 'S');

    return 0;
}

