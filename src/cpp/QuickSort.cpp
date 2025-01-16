#include "../h/QuickSort.h"

int QuickSort::partition(std::vector<int>& arr, int low, int high) {
    /*
     * @abrief Função para particionar o vetor
        * @param arr: vetor de inteiros
        * @param low: índice do menor elemento
        * @param high: índice do maior elemento
     * @return int: índice do pivô
    */
   
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }

    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

std::vector<int> QuickSort::sort(std::vector<int>& arr, int low, int high) {
    /*
     * @abrief Função para ordenar o vetor
        * @param arr: vetor de inteiros
        * @param low: índice do menor elemento
        * @param high: índice do maior elemento
     * @return std::vector<int>: vetor de inteiros ordenado
    */

    if (low < high) {
        int pi = partition(arr, low, high);

        sort(arr, low, pi - 1);
        sort(arr, pi + 1, high);
    }
    return arr;
}