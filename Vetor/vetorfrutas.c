#include <stdio.h>
#include <string.h>

void swap(char **str1, char **str2) {
    char *temp = *str1;
    *str1 = *str2;
    *str2 = temp;
}

int partition(char **arr, int low, int high, int *comparisons, int *swaps) {
    char *pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        (*comparisons)++;
        if (strcmp(arr[j], pivot) < 0) {
            i++;
            (*swaps)++;
            swap(&arr[i], &arr[j]);
        }
    }
    (*swaps)++;
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quicksort(char **arr, int low, int high, int *comparisons, int *swaps) {
    if (low < high) {
        int pi = partition(arr, low, high, comparisons, swaps);
        quicksort(arr, low, pi - 1, comparisons, swaps);
        quicksort(arr, pi + 1, high, comparisons, swaps);
    }
}

int main() {
    char *arr[20] = {
        "maca", "banana", "pera", "uva", "laranja", "abacaxi", "limão", "manga", "abacate", "kiwi",
        "cereja", "morango", "pêssego", "goiaba", "melancia", "framboesa", "amora", "caqui", "figo", "papaya"
    };

    int comparisons = 0;
    int swaps = 0;
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Vetor original:\n");
    for (int i = 0; i < n; i++) {
        printf("%s ", arr[i]);
    }
    printf("\n\n");

    quicksort(arr, 0, n - 1, &comparisons, &swaps);

    printf("Vetor ordenado:\n");
    for (int i = 0; i < n; i++) {
        printf("%s ", arr[i]);
    }
    printf("\n\n");

    printf("Número de comparações: %d\n", comparisons);
    printf("Número de trocas: %d\n", swaps);

    FILE *arquivoSaida;
    arquivoSaida = fopen("ordenado.txt", "w");
    if (arquivoSaida == NULL) {
        printf("Erro ao criar o arquivo de saída.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        fprintf(arquivoSaida, "%s\n", arr[i]);
    }

    fclose(arquivoSaida);

    int mediana_index = n / 2;
    char *mediana = arr[mediana_index];

    printf("\nMediana do conjunto de dados: %s\n", mediana);

    return 0;
}
