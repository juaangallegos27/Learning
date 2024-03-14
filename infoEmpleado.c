#include <stdio.h>
#define PRECIO_HORA_EXTRA 500
#define BONIFICACION_DEPARTAMENTO_A 10000
#define ANIO_ACTUAL 2024

float calcularSueldoAnual(float ingresosMensualesDuranteUnAnio[]){
    float sueldoAnual = 0;
    for (int mes = 0; mes < 12; mes++){
        sueldoAnual = sueldoAnual + ingresosMensualesDuranteUnAnio[mes];
    }
    return sueldoAnual;
}

int main(){

    int edad;
    float sueldoAnual, sueldoTotalAnual, ingresosMensualesDuranteUnAnio[12];
    char departamento;

    int anioNacimiento;

    int horasExtraTrabajadas, haRealizadoHorasExtra;
    float horasExtraAPagar;

    printf("\n\nA continuación vamos a pedirle algunos datos personales:\n");
    
    printf("¿Qué edad tiene?: ");
    scanf("%d", &edad);

    for (int mes = 0; mes < 12; mes++){
        printf("¿Cuál fue su sueldo en el mes %d: ", mes+1);
        scanf("%f", &ingresosMensualesDuranteUnAnio[mes]);
    }

    printf("¿A qué departamento pertenece?: ");
    scanf(" %c", &departamento);

    printf("¿Cuántas horas extra ha trabajado este año?: ");
    scanf("%d", &horasExtraTrabajadas);

    anioNacimiento = ANIO_ACTUAL - edad;

    horasExtraAPagar = horasExtraTrabajadas * PRECIO_HORA_EXTRA;
    haRealizadoHorasExtra = horasExtraAPagar;

    sueldoAnual = calcularSueldoAnual(ingresosMensualesDuranteUnAnio);

    if (departamento == 'A' || departamento == 'a'){
        sueldoTotalAnual = sueldoAnual + BONIFICACION_DEPARTAMENTO_A;
    }
    else {
        sueldoTotalAnual = sueldoAnual;
    }

    printf("\n\nGracias por confiar en este programa, a continuación le mostramos los calculos realizados: \n");
    printf(" - Su año de nacimiento es: %d\n", anioNacimiento);
    printf(" - Su sueldo total anual (incluyendo bonificaciones) es de: %.2f$ MXN.\n", sueldoTotalAnual);
    printf(" - Además se abonarán %.2f$ MXN por concepto de horas extra trabajadas.\n\n", horasExtraAPagar);

    return 0;
}