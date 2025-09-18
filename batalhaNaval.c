#include <stdio.h>

int main(){

    int tabuleiro[10][10] = {0};


    // ----------------- NAVIOS -----------------------
    int navio1[3] = {3,3,3}, navio2[3] = {3,3,3}, navio3[3] = {3,3,3}, navio4[3] = {3,3,3};


    //Navio 1 - horizontal direita
    int linha1 = 2, coluna1 = 'h' - 'a';
    if(linha1 < 0 || linha1 >= 10){
        printf("Valor da linha do navio 1 fora da área do tabuleiro. %d\n", linha1);
        return 1;
    }
    if(coluna1 < 0 || coluna1 + 2 >= 10){
        printf("Valor da coluna do navio 1 fora da área do tabuleiro. %d\n", coluna1);
        return 1;
    }

    //Navio 2 - vertical baixo
    int linha2 = 3, coluna2 ='g' - 'a';
    if(linha2 < 0 || linha2 + 2 >= 10){
        printf("Valor da linha do navio 2 fora da área do tabuleiro. %d\n", linha2);
        return 1;
    }
    if(coluna2 < 0 || coluna2 >= 10){
        printf("Valor da coluna do navio 2 fora da área do tabuleiro. %d\n", coluna2);
        return 1;
    }

    // Navio 3 - diagonal baixo direita
    int linha3 = 7, coluna3 = 'h' - 'a';
    if(linha3 < 0 || linha3 + 2 >= 10){
        printf("Valor da linha do navio 3 fora da área do tabuleiro. %d", linha3);
        return 1;
    }
    if(coluna3 < 0 || coluna3 + 2 >= 10){
        printf("Valor da coluna do navio 3 fora da área do tabuleiro. %d", linha3);
        return 1;
    }

    // Navio 4 - diagonal baixo esquerda
    int linha4 = 7, coluna4 = 'c' - 'a';
    if(linha4 < 0 || linha4 + 2 >= 10){
        printf("Valor da linha do navio 4 fora da área do tabuleiro. %d", linha3);
        return 1;
    }
    if(coluna4 - 2 < 0 || coluna4 >= 10){
        printf("Valor da coluna do navio 4 fora da área do tabuleiro. %d", linha3);
        return 1;
    }

    for (int i = 0; i < 3; i++){  //horizontal
        tabuleiro[linha1][coluna1 + i] = navio1[i];
    }
    for (int i = 0; i < 3; i++){  //vertical

        if(tabuleiro[linha2 + i][coluna2] != 0) {
            printf("Erro no tabuleiro: navios se sobrepõe.\n");
            return 1;
        }
        tabuleiro[linha2 + i][coluna2] = navio2[i];
    }
    for (int i = 0; i < 3; i++){ //diagonal direita
        if(tabuleiro[linha3+i][coluna3+i] != 0){
            printf("Erro no tabuleiro: navios se sobrepõe.\n");
            return 1;
        }
        tabuleiro[linha3 + i][coluna3 + i] = 3;
    }
        for (int i = 0; i < 3; i++){ //diagonal esquerda
        if(tabuleiro[linha4+i][coluna4+i] != 0){
            printf("Erro no tabuleiro: navios se sobrepõe.\n");
            return 1;
        }
        tabuleiro[linha4 + i][coluna4 - i] = 3;
    }
    
    // --------------------------- Habilidades ----------------------

    int linhaCone = 2, colunaCone = 'b' - 'a', tamanhoCone = 3;

    for (int i = 0; i < tamanhoCone; i++){ // CONE
        for (int j = -i; j <= i; j++){
            if(linhaCone + i  > 9 || linhaCone + i < 0 || colunaCone + j > 9 || colunaCone + j < 0){
                continue;
            }
            tabuleiro[linhaCone + i][colunaCone + j] = 5;
        }
    }// Cria uma sequência de linhas a cada linha, aumentando o tamanho a cada iteração

    int linhaCruz = 7, colunaCruz = 'c' - 'a', tamanhoCruz = 2;
    for (int i = -tamanhoCruz; i <= tamanhoCruz; i++){
        int xV = linhaCruz - i;
        int yH = colunaCruz - i;
        if(xV >= 0 && xV < 10 && colunaCruz >= 0 && colunaCruz < 10) {
            tabuleiro[xV][colunaCruz] = 5;
        };
        if(linhaCruz >= 0 && linhaCruz < 10 && yH >= 0 && yH < 10) {
            tabuleiro[linhaCruz][yH] = 5;
        }
    }// cria duas linhas se partindo

        int linhaLosango = 6, colunaLosango = 'h' - 'a', tamanhoLosango = 3;

    for (int i = 0; i < tamanhoLosango; i++){ // Losango
        for (int j = -i; j <= i; j++){
            int x = linhaLosango - tamanhoLosango + 1 + i;
            int y = colunaLosango + j;
            if(x  > 9 || x < 0 || y > 9 || colunaLosango + j < 0){
                continue;
            }
            tabuleiro[x][y] = 5;
        }// Cria cone para ser a parte de cima
        for (int j = 0 - i; j <= i; j++){
            int x = linhaLosango + tamanhoLosango - i - 1;
            int y = colunaLosango + j;
            if(x  > 9 || x < 0 || y > 9 || y < 0){
                continue;
            }
            tabuleiro[x][y] = 5;
        }
    }// cria outro cone para a parte de baixo

        // monta tabuleiro
        printf("__|");
    for (int i = 0; i < 10; i++){
        printf("%c ", 'A' + i);
    }
    printf("\n");

    for (int i = 0; i < 10; i++){
        printf("%d |", i);
        for (int j = 0; j < 10; j++){
            
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

}
