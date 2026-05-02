#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

void app_main() {
    char nome[50];
    int data_nascimento = 0;
    const int ano_atual = 2026;

    // 1. Lendo o Nome
    printf("Digite seu nome: \n");
    // Espera até que algo seja digitado no console
    while (scanf("%s", nome) < 1) {
        vTaskDelay(10 / portTICK_PERIOD_MS); 
    }

    // 2. Lendo o Ano
    printf("Digite seu ano de nascimento: \n");
    // Espera até que um número seja digitado
    while (scanf("%d", &data_nascimento) < 1) {
        fgetc(stdin); // Limpa caracteres inválidos que sobraram
        vTaskDelay(10 / portTICK_PERIOD_MS);
    }

    int idade = ano_atual - data_nascimento;

    printf("\nOlá %s, sua idade é %d anos.\n", nome, idade);
}