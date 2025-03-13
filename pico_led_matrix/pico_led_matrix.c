#include "inc/led_matrix.h"

#define SLEEP_TEST 500

void testa_led_por_index();
void testa_led_por_xy();
void testa_ascender_colunas();
void testa_ascender_linhas();
void print_diagonals(uint8_t red, uint8_t green, uint8_t blue);

int main()
{
    stdio_init_all();

    init(INPUT_PIN);

    clear();

    testa_led_por_index();
    testa_led_por_xy();
    testa_ascender_linhas();
    testa_ascender_colunas();
}

void testa_led_por_index() {
    // acende tudo vermelho
    for (uint8_t i = 0; i < LED_COUNT; i++){
        set_color_by_index(i, 255, 0, 0);
    }
    matrix_write();
    sleep_ms(SLEEP_TEST);
    clear();

    // acende tudo verde
    for (uint8_t i = 0; i < LED_COUNT; i++){
        set_color_by_index(i, 0, 255, 0);
    }
    matrix_write();
    sleep_ms(SLEEP_TEST);
    clear();

    // acende tudo azul
    for (uint8_t i = 0; i < LED_COUNT; i++){
        set_color_by_index(i, 0, 0, 255);
    }
    matrix_write();
    sleep_ms(SLEEP_TEST);
    clear();

    // acende tudo branco
    for (uint8_t i = 0; i < LED_COUNT; i++){
        set_color_by_index(i, 255, 255, 255);
    }
    matrix_write();
    sleep_ms(SLEEP_TEST);
    clear();
}

void testa_led_por_xy() {
    for (uint8_t i = 0; i < SIDE_SIZE; i++){
        for (uint8_t j = 0; j < SIDE_SIZE; j++){
            set_color_by_xy(i, j, 255, 0, 0);
        }
    }
    matrix_write();
    sleep_ms(SLEEP_TEST);
    clear();


    for (uint8_t i = 0; i < SIDE_SIZE; i++){
        for (uint8_t j = 0; j < SIDE_SIZE; j++){
            set_color_by_xy(i, j, 0, 255, 0);
        }
    }
    matrix_write();
    sleep_ms(SLEEP_TEST);
    clear();


    for (uint8_t i = 0; i < SIDE_SIZE; i++){
        for (uint8_t j = 0; j < SIDE_SIZE; j++){
            set_color_by_xy(i, j, 0, 0, 255);
        }
    }
    matrix_write();
    sleep_ms(SLEEP_TEST);
    clear();


    for (uint8_t i = 0; i < SIDE_SIZE; i++){
        for (uint8_t j = 0; j < SIDE_SIZE; j++){
            set_color_by_xy(i, j, 255, 255, 255);
        }
    }
    matrix_write();
    sleep_ms(SLEEP_TEST);
    clear();
}

void testa_ascender_linhas(){
    for (uint8_t i = 0; i < SIDE_SIZE; i++){
        set_color_by_line(i, 255, 0, 0);
        matrix_write();
        sleep_ms(SLEEP_TEST);
        clear();
    }

    for (uint8_t i = 0; i < SIDE_SIZE; i++){
        set_color_by_line(i, 0, 255, 0);
        matrix_write();
        sleep_ms(SLEEP_TEST);
        clear();
    }

    for (uint8_t i = 0; i < SIDE_SIZE; i++){
        set_color_by_line(i, 0, 0, 255);
        matrix_write();
        sleep_ms(SLEEP_TEST);
        clear();
    }

    for (uint8_t i = 0; i < SIDE_SIZE; i++){
        set_color_by_line(i, 255, 255, 255);
        matrix_write();
        sleep_ms(SLEEP_TEST);
        clear();
    }
}

void testa_ascender_colunas() {
    for (uint8_t i = 0; i < SIDE_SIZE; i++){
        set_color_by_column(i, 255, 0, 0);
        matrix_write();
        sleep_ms(SLEEP_TEST);
        clear();
    }

    for (uint8_t i = 0; i < SIDE_SIZE; i++){
        set_color_by_column(i, 0, 255, 0);
        matrix_write();
        sleep_ms(SLEEP_TEST);
        clear();
    }

    for (uint8_t i = 0; i < SIDE_SIZE; i++){
        set_color_by_column(i, 0, 0, 255);
        matrix_write();
        sleep_ms(SLEEP_TEST);
        clear();
    }

    for (uint8_t i = 0; i < SIDE_SIZE; i++){
        set_color_by_column(i, 255, 255, 255);
        matrix_write();
        sleep_ms(SLEEP_TEST);
        clear();
    }
}
