#include <stdio.h>

#define TAMANHO 10 // Tabuleiro 10x10
#define HABILIDADE_TAMANHO 5 // Tamanho da matriz de habilidade

int main() {
    // Inicialização do tabuleiro com zeros (posições vazias)
    int tabuleiro[TAMANHO][TAMANHO] = {0};
    
    // Matrizes para as habilidades especiais
    int habilidade_cone[HABILIDADE_TAMANHO][HABILIDADE_TAMANHO] = {0};
    int habilidade_cruz[HABILIDADE_TAMANHO][HABILIDADE_TAMANHO] = {0};
    int habilidade_octaedro[HABILIDADE_TAMANHO][HABILIDADE_TAMANHO] = {0};
    
    // Criando o padrão de cone
    // Primeira linha: apenas o centro
    habilidade_cone[0][2] = 1;
    
    // Segunda linha: centro e adjacentes
    habilidade_cone[1][1] = 1;
    habilidade_cone[1][2] = 1;
    habilidade_cone[1][3] = 1;
    
    // Terceira linha: toda a linha
    for (int j = 0; j < HABILIDADE_TAMANHO; j++) {
        habilidade_cone[2][j] = 1;
    }
    
    // Criando o padrão de cruz
    // Centro vertical
    for (int i = 0; i < HABILIDADE_TAMANHO; i++) {
        habilidade_cruz[i][2] = 1;
    }
    
    // Centro horizontal
    for (int j = 0; j < HABILIDADE_TAMANHO; j++) {
        habilidade_cruz[2][j] = 1;
    }
    
    // Criando o padrão de octaedro
    // Primeira linha: apenas o centro
    habilidade_octaedro[0][2] = 1;
    
    // Segunda linha: centro e adjacentes
    habilidade_octaedro[1][1] = 1;
    habilidade_octaedro[1][2] = 1;
    habilidade_octaedro[1][3] = 1;
    
    // Terceira linha: apenas o centro
    habilidade_octaedro[2][2] = 1;
    
    // Exibindo a habilidade em cone
    printf("Habilidade em cone:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < HABILIDADE_TAMANHO; j++) {
            printf("%d ", habilidade_cone[i][j]);
        }
        printf("\n");
    }
    
    printf("\nHabilidade em octaedro:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < HABILIDADE_TAMANHO; j++) {
            printf("%d ", habilidade_octaedro[i][j]);
        }
        printf("\n");
    }
    
    printf("\nHabilidade em cruz:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < HABILIDADE_TAMANHO; j++) {
            printf("%d ", habilidade_cruz[i][j]);
        }
        printf("\n");
    }
    
    // Aplicando uma habilidade no tabuleiro (exemplo com a cruz)
    int centro_x = 5;
    int centro_y = 5;
    int offset = HABILIDADE_TAMANHO / 2;
    
    printf("\nAplicando habilidade cruz no tabuleiro na posição (%d, %d):\n", centro_x, centro_y);
    
    // Resetando o tabuleiro
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = 0;
        }
    }
    
    // Aplicando a habilidade cruz no tabuleiro
    for (int i = 0; i < HABILIDADE_TAMANHO; i++) {
        for (int j = 0; j < HABILIDADE_TAMANHO; j++) {
            int tabuleiro_x = centro_x - offset + i;
            int tabuleiro_y = centro_y - offset + j;
            
            // Verificando se a posição está dentro dos limites do tabuleiro
            if (tabuleiro_x >= 0 && tabuleiro_x < TAMANHO && 
                tabuleiro_y >= 0 && tabuleiro_y < TAMANHO) {
                tabuleiro[tabuleiro_x][tabuleiro_y] = habilidade_cruz[i][j];
            }
        }
    }
    
    // Exibindo o tabuleiro com a habilidade aplicada
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}