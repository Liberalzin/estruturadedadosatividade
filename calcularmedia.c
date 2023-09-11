#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOME 100
#define MAX_LINHA 256

int main() {
    FILE *arquivoEntrada;
    FILE *arquivoSaida;
    char linha[MAX_LINHA];

    arquivoEntrada = fopen("DadosEntrada.csv", "r");
    if (arquivoEntrada == NULL) {
        printf("Erro ao abrir o arquivo de entrada.\n");
        return 1;
    }

    arquivoSaida = fopen("SituacaoFinal.csv", "w");
    if (arquivoSaida == NULL) {
        printf("Erro ao criar o arquivo de saída.\n");
        return 1;
    }

    fprintf(arquivoSaida, "Nome,Nota Media,Situacao\n");

    while (fgets(linha, sizeof(linha), arquivoEntrada) != NULL) {
        char nome[MAX_NOME];
        float notas[2];
        char telefone[MAX_NOME];
        char curso[MAX_NOME];

        sscanf(linha, "%[^,],%[^,],%[^,],%f,%f", nome, telefone, curso, &notas[0], &notas[1]);

        float media = (notas[0] + notas[1]) / 2;
        char situacao[15];

        if (media >= 7.0) {
            strcpy(situacao, "APROVADO");
        } else {
            strcpy(situacao, "REPROVADO");
        }

        fprintf(arquivoSaida, "%s,%.2f,%s\n", nome, media, situacao);
    }

    fclose(arquivoEntrada);
    fclose(arquivoSaida);

    printf("Processamento concluído. Os resultados foram gravados em 'SituacaoFinal.csv'.\n");

    return 0;
}