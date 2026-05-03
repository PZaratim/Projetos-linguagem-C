#include <stdio.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

#define led_verde 32
#define led_vermelho 26

void app_main() {

    gpio_set_direction(led_verde, GPIO_MODE_OUTPUT);
    gpio_set_direction(led_vermelho, GPIO_MODE_OUTPUT);

    char senha[20];

    // Senha definida pelo sistema (num ou letras)
    char senha_correta[] = "usuário123";

    printf("Digite a senha: \n");

    // Espera até o usuário digitar a senha
    while (scanf("%19s", senha) < 1) {
        vTaskDelay(10 / portTICK_PERIOD_MS);
    }

    // Comparação das senhas
    if (strcmp(senha, senha_correta) == 0) {
        printf("Acesso permitido!\n");
        gpio_set_level(led_verde, 1);

    } 
    
    else {
        printf("Senha incorreta!\n");
        gpio_set_level(led_vermelho, 1);
    }
}