#include <stdio.h>

// Función para intercambiar dos elementos en un arreglo
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Función para particionar el arreglo utilizando el último elemento como pivote
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // Tomamos el último elemento como pivote
    int i = (low - 1);  // Índice del menor elemento

    for (int j = low; j <= high - 1; j++) {
        // Si el elemento actual es más pequeño o igual que el pivote
        if (arr[j] <= pivot) {
            i++;  // Incrementamos el índice del menor elemento
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Función de Quicksort recursivo
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Obtenemos el índice de partición
        int p = partition(arr, low, high);

        // Ordenamos los elementos antes y después de la partición
        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}

// Función para imprimir el arreglo
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Ejemplo de uso
int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Arreglo original:\n");
    printArray(arr, n);

    quickSort(arr, 0, n - 1);

    printf("Arreglo ordenado:\n");
    printArray(arr, n);

    return 0;
}
