/*

Ejercicio Farmacia
Autor: Alejandro Paqui
*/
#include <stdio.h>

int main() {
    int i = 1;
    float horas, valor_hora, ventas, salario_bruto, bonificacion, aporte_iess, salario_neto, horas_extra;
    float total_nominas = 0;
    char respuesta;

    while (1) {
        printf("¿Desea registrar un empleado? (s/n): ");
        scanf(" %c", &respuesta);

        if (respuesta == 'n') {
            break;
        }

        printf("\nEmpleado %d:\n", i++);

        do {
            printf("Ingrese las horas trabajadas: ");
            scanf("%f", &horas);
        } while (horas < 0);

        do {
            printf("Ingrese el valor por hora: ");
            scanf("%f", &valor_hora);
        } while (valor_hora < 0);

        do {
            printf("Ingrese el valor de ventas: ");
            scanf("%f", &ventas);
        } while (ventas < 0);

        if (horas > 40) {
            horas_extra = horas - 40;
        } else {
            horas_extra = 0;
        }

        salario_bruto = (horas - horas_extra) * valor_hora + horas_extra * (valor_hora * 1.1 * (horas_extra <= 10) + valor_hora * 1.15 * (horas_extra > 10 && horas_extra <= 15) + valor_hora * 1.2 * (horas_extra > 15));
        
        bonificacion = ventas * 0.02 * (ventas <= 800) + ventas * 0.04 * (ventas > 800 && ventas <= 1500) + ventas * 0.06 * (ventas > 1500 && ventas <= 3000) + ventas * 0.08 * (ventas > 3000);
        
        aporte_iess = salario_bruto * 0.0945;
        salario_neto = salario_bruto - aporte_iess + bonificacion;

        printf("Salario: $%.2f\n", salario_neto);

        total_nominas += salario_neto;
    }

    if (i > 1) {
        printf("\nValor total de la nómina: $%.2f\n", total_nominas / (i - 1));
    }

    return 0;
}
