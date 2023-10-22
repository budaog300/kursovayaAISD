#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <random>
#include <vector>
#include <string>
using namespace std;

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void bubbleSortReverse(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main()
{
    auto seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::mt19937 generator(seed);
    std::uniform_int_distribution<int> distribution(1, 5000); std::uniform_real_distribution<double> distribution2(1, 5000);
    int n = distribution(generator);
   // int n = 2616;
    int* arr = new int[n];
    //double* arr = new double[n];

    cout << "Unsorted Array: ";
    for (int i = 0; i < n; i++) {
        arr[i] = distribution(generator);    
        //cout << arr[i] << " ";      
    }
    cout << endl;
    cout << endl;
    //bubbleSortReverse(arr, n);
    /*auto start = std::chrono::steady_clock::now();

    bubbleSort(arr, n);

    auto end = std::chrono::steady_clock::now();*/
  
   /* for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << endl;*/
    bubbleSort(arr, n);
    auto start = std::chrono::steady_clock::now();    
    bubbleSort(arr, n);
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> diff = end - start;
   

    //cout << "Sorted Array: ";
    //for (int i = 0; i < n; i++) {
    //    cout << arr[i] << " ";
    //}
    //cout << endl;

    std::cout << "\nTime taken: " << diff.count() << " seconds\n";
    std::cout << n;
    return 0;
}