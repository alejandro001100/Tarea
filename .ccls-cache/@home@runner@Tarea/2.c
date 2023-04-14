#include <stdio.h>
#include <stdlib.h>

int main() {
    int num_empleados, i;
    float horas, valor_hora, ventas, salario_bruto, bonificacion, aporte_iess, salario_neto, horas_extra;
    float total_nominas = 0;

    printf("Ingrese el número de empleados: ");
    if (scanf("%d", &num_empleados) != 1) {
        printf("Error: debe ingresar un número entero.\n");
        exit(1);
    }

    for (i = 1; i <= num_empleados; i++) {
        printf("\nEmpleado %d:\n", i);
        
        printf("Ingrese las horas trabajadas: ");
        if (scanf("%f", &horas) != 1 || horas < 0) {
            printf("Error: debe ingresar un número positivo.\n");
            exit(1);
        }

        printf("Ingrese el valor por hora: ");
        if (scanf("%f", &valor_hora) != 1 || valor_hora < 0) {
            printf("Error: debe ingresar un número positivo.\n");
            exit(1);
        }

        printf("Ingrese el valor de ventas: ");
        if (scanf("%f", &ventas) != 1 || ventas < 0) {
            printf("Error: debe ingresar un número positivo.\n");
            exit(1);
        }

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

    printf("\nValor total de la nómina: $%.2f\n", total_nominas);

    return 0;
}
