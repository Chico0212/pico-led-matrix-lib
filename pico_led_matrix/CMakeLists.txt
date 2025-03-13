cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Initialize pico_sdk (certifique-se que pico_sdk_import.cmake está no local correto)
include(pico_sdk_import.cmake)

project(pico_led_matrix C CXX ASM)

# Inicializa o SDK do Pico
pico_sdk_init()

# --- Biblioteca led_matrix ---
add_library(led_matrix
    src/led_matrix.c
)

# Inclua os headers públicos da sua biblioteca
target_include_directories(led_matrix PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/inc
)

# Vincule as dependências do Pico SDK à biblioteca
target_link_libraries(led_matrix PRIVATE
    pico_stdlib       # Adicione outras dependências se necessário (ex: hardware_pio)
    hardware_pio
)

# --- Executável principal ---
add_executable(pico_led_matrix pico_led_matrix.c)

# Configurações do projeto
pico_set_program_name(pico_led_matrix "pico_led_matrix")
pico_set_program_version(pico_led_matrix "0.1")

# Habilite stdio
pico_enable_stdio_uart(pico_led_matrix 1)
pico_enable_stdio_usb(pico_led_matrix 1)

# Vincule as bibliotecas ao executável
target_link_libraries(pico_led_matrix
    led_matrix
    pico_stdlib
    hardware_pio      # Se estiver usando PIO
)

# Gere arquivos adicionais (UF2, etc)
pico_add_extra_outputs(pico_led_matrix)