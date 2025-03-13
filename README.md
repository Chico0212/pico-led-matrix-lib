## 📢 Pico Led Matrix Library

Uma biblioteca em C para controlar **matrizes de LED** utilizando a **Raspberry Pi Pico** e placas baseadas no **RP2040**. Permite **configurar cores individualmente** por coordenada, **limpar a matriz**, e **manipular linhas e colunas** com facilidade.

---

## 📂 Estrutura do Projeto

```
📁 pico_led_matix      # Biblioteca da matriz de LED
│── 📁 inc          # Arquivos de cabeçalho
│   ├── led_matrix.h
│
│── 📁 src          # Implementação da biblioteca
│   ├── led_matrix.c
│
│── README.md       # Documentação do projeto
```

✅ **`Código_fonte/`** → Contém os arquivos principais da biblioteca (`led_matrix.h` e `led_matrix.c`)
✅ **`pico_led_matrix.c`** → Contém todos os testes da aplicação    

---

## 🚀 Recursos

✅ Controle individual de **cores dos LEDs** por coordenada  
✅ Configuração de **linhas e colunas inteiras**  
✅ Função para **limpar a matriz** de LED  
✅ Utilização de **PIO** para comunicação eficiente  

---

## 🛠️ Como Rodar os Exemplos  

### 🔹 1️⃣ Instale a Extensão da Raspberry Pi no VS Code  
Se ainda não tiver instalado, adicione a extensão **"Raspberry Pi Pico - C/C++ Project"** no **VS Code**.

### 🔹 2️⃣ Importe o Exemplo Desejado  
1. No VS Code, clique em **"Importar Projeto"**  
2. Selecione a **pasta do exemplo** dentro de `exemplos/`  
3. Compile e **grave no microcontrolador** 🚀  

**Exemplo:**  
Se quiser testar a função `clear`, importe:  
📂 `exemplos/matrix_clear`

---

## 📜 Exemplo de Uso  

### 🔹 Inicializando a Matriz de LED
```c
init(21);  // Inicializa no pino 21
```

### 🔹 Definindo uma cor em uma posição específica
```c
set_color_by_xy(2, 3, 255, 0, 0); // Define o LED na posição (2,3) como vermelho
```

### 🔹 Definindo uma cor em uma coluna
```c
set_column(1, 0, 255, 0); // Define toda a coluna 1 como verde
```

### 🔹 Definindo uma cor em uma linha
```c
set_line(4, 0, 0, 255); // Define toda a linha 4 como azul
```

### 🔹 Limpando a Matriz
```c
clear();  // Apaga todos os LEDs
```

---

## 🔗 Contribuindo  

Sinta-se à vontade para **abrir issues e pull requests** no repositório!  
Qualquer melhoria, nova funcionalidade ou correção de bugs são bem-vindas. 😃  

---

## 📄 Licença  

Este projeto está sob a licença **MIT**, permitindo uso, modificação e distribuição livremente. 📜

