#include "led_matrix.h"

PIO np_pio;
uint sm;
Pixel matrix[LED_COUNT];

int get_index(uint8_t x, uint8_t y) {
    if (x % 2 == 0)
        return 4 + 5*x - y;
    else return 5*x + y;
}

void set_color_by_index(uint8_t index, uint8_t red, uint8_t green, uint8_t blue) {
    Pixel* pixel = &matrix[index];

    pixel->red = red;
    pixel->green = green;
    pixel->blue = blue;
}

void set_color_by_xy(uint8_t x, uint8_t y, uint8_t red, uint8_t green, uint8_t blue) {
    uint8_t index = get_index(x, y);

    set_color_by_index(index, red, green, blue);
}

void clear() {
    for (uint8_t i = 0; i < LED_COUNT; i++) {
        set_color_by_index(i, 0, 0, 0);
    }
    matrix_write();
}

void init(uint8_t pin) {
    uint offset = pio_add_program(pio0, &ws2818b_program);
    np_pio = pio0;

    sm = pio_claim_unused_sm(np_pio, false);
    if (sm < 0) {
        np_pio = pio1;
        sm = pio_claim_unused_sm(np_pio, true);
    }

    ws2818b_program_init(np_pio, sm, offset, pin, 800000.f);

    clear();
}

void matrix_write() {
    for (uint8_t i = 0; i < LED_COUNT; i++) {
        Pixel *current_pixel = &matrix[i];

        pio_sm_put_blocking(np_pio, sm, current_pixel->green);
        pio_sm_put_blocking(np_pio, sm, current_pixel->red);
        pio_sm_put_blocking(np_pio, sm, current_pixel->blue);
    }
}

void set_color_by_column(uint8_t column, uint8_t red, uint8_t green, uint8_t blue) {
    for (int i = 0; i < SIDE_SIZE; i++) {
        set_color_by_xy(i, column, red, green, blue);
    }
}

void set_color_by_line(uint8_t line, uint8_t red, uint8_t green, uint8_t blue) {
    for (int i = 0; i < SIDE_SIZE; i++) {
        set_color_by_xy(line, i, red, green, blue);
    }
}

