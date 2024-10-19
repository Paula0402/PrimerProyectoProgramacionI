#include <stdio.h>

int main() {
    
    int Factura = 0, CantidadTiquetes, TipoCliente, TipoTiquete;
    char Cedula[20], Nombre[50];
    char Continuar = 'S';
    double MontoTiquete = 0, MontoVenta = 0, Descuento = 0, Subtotal = 0, Impuesto = 0, Total = 0;
    int TotalGaleria = 0, TotalPalco = 0, TotalEntradas = 0;
    double AcumuladoGaleria = 0, AcumuladoPalco = 0, AcumuladoGeneral = 0;
    
    while (Continuar == 'S' || Continuar == 's') {
       
        Factura++;

     
        printf("\nFactura No: %d\n", Factura);
        printf("Ingrese la cédula del cliente: ");
        scanf("%s", Cedula);
        printf("Ingrese el nombre del cliente: ");
        scanf("%s", Nombre);

     
        do {
            printf("Ingrese el tipo de cliente (1=Niño/Adulto mayor, 2=Adulto): ");
            scanf("%d", &TipoCliente);
            if (TipoCliente != 1 && TipoCliente != 2) {
                printf("Error: Ingrese un tipo de cliente válido (1 o 2).\n");
            }
        } while (TipoCliente != 1 && TipoCliente != 2);

     
        do {
            printf("Ingrese el tipo de tiquete (1=Galería, 2=Palco): ");
            scanf("%d", &TipoTiquete);
            if (TipoTiquete != 1 && TipoTiquete != 2) {
                printf("Error: Ingrese un tipo de tiquete válido (1 o 2).\n");
            }
        } while (TipoTiquete != 1 && TipoTiquete != 2);

    
        do {
            printf("Ingrese la cantidad de tiquetes o entradas a comprar: ");
            scanf("%d", &CantidadTiquetes);
            if (CantidadTiquetes <= 0) {
                printf("Error: La cantidad de tiquetes debe ser mayor a 0.\n");
            }
        } while (CantidadTiquetes <= 0);


        if (TipoTiquete == 1) {
            MontoTiquete = 6000; 
        } else if (TipoTiquete == 2) {
            MontoTiquete = 12000; 
        }


        MontoVenta = MontoTiquete * CantidadTiquetes;

        
        if (TipoCliente == 1) {
            Descuento = MontoVenta * 0.30; 
        } else {
            Descuento = 0;
        }

        
        Subtotal = MontoVenta - Descuento;
        Impuesto = Subtotal * 0.13;
        Total = Subtotal + Impuesto;

        
        printf("\nDetalle de la Venta\n");
        printf("Factura No: %d\n", Factura);
        printf("Cliente: %s, Cédula: %s\n", Nombre, Cedula);

        
        if (TipoCliente == 1) {
            printf("Tipo de Cliente: Niño/Adulto Mayor\n");
        } else {
            printf("Tipo de Cliente: Adulto\n");
        }

        
        if (TipoTiquete == 1) {
            printf("Tipo de Tiquete: Galería\n");
        } else {
            printf("Tipo de Tiquete: Palco\n");
        }

        printf("Cantidad de tiquetes: %d\n", CantidadTiquetes);
        printf("Monto unitario por tiquete: %.2f\n", MontoTiquete);
        printf("Monto de venta: %.2f\n", MontoVenta);
        printf("Descuento: %.2f\n", Descuento);
        printf("Subtotal de venta: %.2f\n", Subtotal);
        printf("Impuesto de venta: %.2f\n", Impuesto);
        printf("Total a pagar: %.2f\n", Total);

        
        if (TipoTiquete == 1) {
            AcumuladoGaleria += Total;
            TotalGaleria += CantidadTiquetes;
        } else if (TipoTiquete == 2) {
            AcumuladoPalco += Total;
            TotalPalco += CantidadTiquetes;
        }
        
        AcumuladoGeneral += Total;
        TotalEntradas += CantidadTiquetes;

        
        printf("\n¿Desea registrar otra venta? (S/N): ");
        scanf(" %c", &Continuar);
    }

    printf("\nEstadísticas\n");
    printf("Cantidad de entradas tiquetes galería: %d\n", TotalGaleria);
    printf("Acumulado dinero por tiquetes galería: %.2f\n", AcumuladoGaleria);
    printf("Cantidad de entradas tiquetes palco: %d\n", TotalPalco);
    printf("Acumulado dinero por tiquetes palco: %.2f\n", AcumuladoPalco);
    printf("Cantidad general de entradas: %d\n", TotalEntradas);
    printf("Acumulado general dinero por entradas: %.2f\n", AcumuladoGeneral);
    
    if (Factura > 0) {
        printf("Promedio general por venta: %.2f\n", AcumuladoGeneral / Factura);
    } else {
        printf("Promedio general por venta: 0.00\n");
    }

    return 0;
}

