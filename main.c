/*
Ejercicio Farmacia
Autor: Alejandro Paqui
*/

#include <stdio.h>

int main() {
    // Declaración de variables
    int i = 1; // Contador para el número de empleado
    float horas, valor_hora, ventas, salario_bruto, bonificacion, aporte_iess, salario_neto, horas_extra; // Variables para los cálculos de salario
    float total_nominas = 0; // Variable acumuladora para el total de nóminas
    char respuesta; // Variable para la respuesta del usuario

    // Ciclo para registrar los empleados
    while (1) {
        printf("¿Desea registrar un empleado? (s/n): ");
        scanf(" %c", &respuesta);

        // Si la respuesta es "n", se sale del ciclo
        if (respuesta == 'n') {
            break;
        }

        printf("\nEmpleado %d:\n", i++);

        // Ciclos para verificar que los datos ingresados sean positivos
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

        // Cálculo de las horas extras trabajadas
        if (horas > 40) {
            horas_extra = horas - 40;
        } else {
            horas_extra = 0;
        }

        // Cálculo del salario bruto
        salario_bruto = (horas - horas_extra) * valor_hora + horas_extra * (valor_hora * 1.1 * (horas_extra <= 10) + valor_hora * 1.15 * (horas_extra > 10 && horas_extra <= 15) + valor_hora * 1.2 * (horas_extra > 15));
        
        // Cálculo de la bonificación por ventas
        bonificacion = ventas * 0.02 * (ventas <= 800) + ventas * 0.04 * (ventas > 800 && ventas <= 1500) + ventas * 0.06 * (ventas > 1500 && ventas <= 3000) + ventas * 0.08 * (ventas > 3000);
        
        // Cálculo del aporte al IESS
        aporte_iess = salario_bruto * 0.0945;

        // Cálculo del salario neto
        salario_neto = salario_bruto - aporte_iess + bonificacion;

        // Impresión del salario neto del empleado
        printf("Salario: $%.2f\n", salario_neto);

        // Acumulación del salario neto para el total de nóminas
        total_nominas += salario_neto;
    }

    // Si se registró al menos un empleado, se imprime el valor promedio de la nómina
    if (i > 1) {
        printf("\nValor total de la nómina: $%.2f\n", total_nominas / (i - 1));
    }

    return 0;
}
