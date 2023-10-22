#include <iostream>
#include <random>
#include <chrono>
void bubble_sort(double arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Обмен элементов
                double temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
int main()
{
    auto seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::mt19937 generator(seed);
    std::uniform_int_distribution<int> distribution(1, 10000); std::uniform_real_distribution<double> distribution2(1, 10000);
    int n = distribution2(generator);
    double* arr = new double[n];

    // Инициализация генератора случайных чисел


    // Заполнение массива случайными числами от 1 до 100
    for (int i = 0; i < n; i++) {
        arr[i] = distribution2(generator);
    }

    std::cout << "Unsorted array: \n";
    for (int i = 0; i < n; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;

    // Засекаем время перед сортировкой
    auto start = std::chrono::steady_clock::now();

    bubble_sort(arr, n);

    // Засекаем время после сортировки
    auto end = std::chrono::steady_clock::now();

    std::cout << "Sorted array: \n";
    for (int i = 0; i < n; i++)
        std::cout << arr[i] << " ";

    // Вычисляем время выполнения сортировки
    std::chrono::duration<double> diff = end - start;
    std::cout << "\nTime taken: " << diff.count() << " seconds\n";

    delete[] arr;

    return 0;
}

