// int prev = -1;
// // testa vermelho
// for (int i = 0; i < LED_COUNT; ++i) {
//     set_color(i, 255, 0, 0);
//     if (prev != -1) {
//         set_color(prev, 0, 0, 0);
//     }
//     prev = i;
//     // matrix_write();
//     sleep_ms(500);
// }
// // testa verde
// for (int i = 0; i < LED_COUNT; ++i) {
//     set_color(i, 0, 255, 0);
//     if (prev != -1) {
//         set_color(prev, 0, 0, 0);
//     }
//     prev = i;
//     // matrix_write();
//     sleep_ms(500);
// }
// // testa azul
// for (int i = 0; i < LED_COUNT; ++i) {
//     set_color(i, 0, 0, 255);
//     if (prev != -1) {
//         set_color(prev, 0, 0, 0);
//     }
//     prev = i;
//     // matrix_write();
//     sleep_ms(500);
// }

// void color(uint8_t red, uint8_t green, uint8_t blue) {
//     for (int i = 0; i < 5; ++i) {
//         for (int j = 0; j < 5; ++j) {
//             set_color_by_xy(i, j, red, green, blue);
//             sleep_ms(500);
//             matrix_write();
//             set_color_by_xy(i, j, 0, 0, 0);
//             matrix_write();
//         }
//     }
// }

// void testa_vermelho