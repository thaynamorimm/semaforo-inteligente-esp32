#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

#define LED_VERMELHO 23
#define LED_AMARELO  22
#define LED_VERDE    21

void app_main(void) {

    gpio_reset_pin(LED_VERMELHO);
    gpio_set_direction(LED_VERMELHO, GPIO_MODE_OUTPUT);

    gpio_reset_pin(LED_AMARELO);
    gpio_set_direction(LED_AMARELO, GPIO_MODE_OUTPUT);

    gpio_reset_pin(LED_VERDE);
    gpio_set_direction(LED_VERDE, GPIO_MODE_OUTPUT);

    while (1) {
        
        gpio_set_level(LED_VERDE, 1);
        gpio_set_level(LED_AMARELO, 0);
        gpio_set_level(LED_VERMELHO, 0);
        vTaskDelay(6000 / portTICK_PERIOD_MS);

        gpio_set_level(LED_VERDE, 0);
        gpio_set_level(LED_AMARELO, 1);
        gpio_set_level(LED_VERMELHO, 0);
        vTaskDelay(3000 / portTICK_PERIOD_MS);

        gpio_set_level(LED_VERDE, 0);
        gpio_set_level(LED_AMARELO, 0);
        gpio_set_level(LED_VERMELHO, 1);
        vTaskDelay(6000 / portTICK_PERIOD_MS);
    }
}
