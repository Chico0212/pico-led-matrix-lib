#include "inc/led_matrix.h"

void testa_led_por_index();
void testa_led_por_xy();
void testa_ascender_colunas();
void testa_ascender_linhas();

int main()
{
    stdio_init_all();

    init(INPUT_PIN);

    clear();

    testa_led_por_index();
    testa_led_por_xy();
    testa_ascender_colunas();
    testa_ascender_linhas();
}

void testa_led_por_index() {
    for (uint8_t i = 0; i < LED_COUNT; i++){
        set_color_by_index(i, 255, 0, 0);
    }
    matrix_write();
    sleep_ms(500);
    clear();

    for (uint8_t i = 0; i < LED_COUNT; i++){
        set_color_by_index(i, 0, 255, 0);
    }
    matrix_write();
    sleep_ms(500);
    clear();

    for (uint8_t i = 0; i < LED_COUNT; i++){
        set_color_by_index(i, 0, 0, 255);
    }
    matrix_write();
    sleep_ms(500);
    clear();
    
    for (uint8_t i = 0; i < LED_COUNT; i++){
        set_color_by_index(i, 255, 255, 255);
    }
    matrix_write();
    sleep_ms(500);
    clear();
}

void testa_led_por_xy() {
    for (uint8_t i = 0; i < LED_COUNT; i++){
        for (uint8_t j = 0; j < LED_COUNT; j++){
            set_color_by_xy(i, j, 255, 0, 0);
        }
    }
    matrix_write();
    sleep_ms(500);
    clear();

    for (uint8_t i = 0; i < LED_COUNT; i++){
        for (uint8_t j = 0; j < LED_COUNT; j++){
            set_color_by_xy(i, j, 0, 255, 0);
        }
    }
    matrix_write();
    sleep_ms(500);
    clear();

    for (uint8_t i = 0; i < LED_COUNT; i++){
        for (uint8_t j = 0; j < LED_COUNT; j++){
            set_color_by_xy(i, j, 0, 0, 255);
        }
    }
    matrix_write();
    sleep_ms(500);
    clear();

    for (uint8_t i = 0; i < LED_COUNT; i++){
        for (uint8_t j = 0; j < LED_COUNT; j++){
            set_color_by_xy(i, j, 255, 255, 255);
        }
    }
    matrix_write();
    sleep_ms(500);
    clear();
}

void testa_ascender_linhas(){
    for (uint8_t i = 0; i < LED_COUNT; i++){
        set_color_by_line(i, 255, 0, 0);
    }
    matrix_write();
    sleep_ms(500);
    clear();

    for (uint8_t i = 0; i < LED_COUNT; i++){
        set_color_by_line(i, 0, 255, 0);
    }
    matrix_write();
    sleep_ms(500);
    clear();

    for (uint8_t i = 0; i < LED_COUNT; i++){
        set_color_by_line(i, 0, 0, 255);
    }
    matrix_write();
    sleep_ms(500);
    clear();

    for (uint8_t i = 0; i < LED_COUNT; i++){
        set_color_by_line(i, 255, 255, 255);
    }
    matrix_write();
    sleep_ms(500);
    clear();
}

void testa_ascender_colunas() {
    for (uint8_t i = 0; i < LED_COUNT; i++){
        set_color_by_column(i, 255, 0, 0);
    }
    matrix_write();
    sleep_ms(500);
    clear();

    for (uint8_t i = 0; i < LED_COUNT; i++){
        set_color_by_column(i, 0, 255, 0);
    }
    matrix_write();
    sleep_ms(500);
    clear();

    for (uint8_t i = 0; i < LED_COUNT; i++){
        set_color_by_column(i, 0, 0, 255);
    }
    matrix_write();
    sleep_ms(500);
    clear();

    for (uint8_t i = 0; i < LED_COUNT; i++){
        set_color_by_column(i, 255, 255, 255);
    }
    matrix_write();
    sleep_ms(500);
    clear();
}
