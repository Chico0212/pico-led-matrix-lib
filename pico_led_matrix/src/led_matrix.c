#include "led_matrix.h"

PIO np_pio;
uint sm;
Pixel matrix[LED_COUNT];

int get_index(uint8_t x, uint8_t y) {
    // funcao para achar o indice na lista baseado nas coordenadas
    if (x % 2 == 0)
        return 4 + 5*x - y;
    else return 5*x + y;
}

void set_color_by_index(uint8_t index, uint8_t red, uint8_t green, uint8_t blue) {
    Pixel* pixel = &matrix[index]; // acessa o pixel

    // configura as cores
    pixel->red = red; 
    pixel->green = green;
    pixel->blue = blue;

    sleep_ms(DELAY_MS);
}

void set_color_by_xy(uint8_t x, uint8_t y, uint8_t red, uint8_t green, uint8_t blue) {
    // acha o indice
    uint8_t index = get_index(x, y);

    // ativa o pixel
    set_color_by_index(index, red, green, blue);
}

void clear() {
    for (uint8_t i = 0; i < LED_COUNT; i++) {
        set_color_by_index(i, 0, 0, 0); // desativa cada pixel
    }
    matrix_write(); // envia o dado pra placa
}

void init(uint8_t pin) {
    // adiciona o programa pio para controle dos leds ws2812b e obtém o offset
    uint offset = pio_add_program(pio0, &ws2818b_program);
    
    // define o pio inicial como pio0
    np_pio = pio0;

    // tenta obter uma state machine livre no pio0
    sm = pio_claim_unused_sm(np_pio, false);
    
    // se não houver state machine disponível no pio0, usa o pio1
    if (sm < 0) {
        np_pio = pio1;
        sm = pio_claim_unused_sm(np_pio, true);
    }

    // inicializa o programa pio com a state machine selecionada e configura o pino de controle
    ws2818b_program_init(np_pio, sm, offset, pin, 800000.f);

    // limpa a matriz de leds para garantir que todos os leds estejam apagados
    clear();
}


void matrix_write() {
    for (uint8_t i = 0; i < LED_COUNT; i++) {
        Pixel *current_pixel = &matrix[i]; // acessa o pixel atual

        // envia o valor das cores do pixel atual para a state machine do pio de forma bloqueante
        pio_sm_put_blocking(np_pio, sm, current_pixel->green);
        pio_sm_put_blocking(np_pio, sm, current_pixel->red);
        pio_sm_put_blocking(np_pio, sm, current_pixel->blue);
    }
}

void set_color_by_column(uint8_t column, uint8_t red, uint8_t green, uint8_t blue) {
    // percorre todas as posições da coluna especificada
    for (int i = 0; i < SIDE_SIZE; i++) {
        // define a cor do pixel na posição (linha = i, coluna = column)
        set_color_by_xy(i, column, red, green, blue);
    }
}

void set_color_by_line(uint8_t line, uint8_t red, uint8_t green, uint8_t blue) {
    // percorre todas as posições da linha especificada
    for (int i = 0; i < SIDE_SIZE; i++) {
        // define a cor do pixel na posição (linha = line, coluna = i)
        set_color_by_xy(line, i, red, green, blue);
    }
}
