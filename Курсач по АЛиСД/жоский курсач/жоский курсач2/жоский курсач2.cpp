#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <random>
#include <vector>
#include <string>
using namespace std;

void bubbleSort(string arr[], int n)
{
    bool swapped = true;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
    }
}

bool isSorted(string arr[], int n) {
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[i - 1]) {
            return false;
        }
    }
    return true;
}

void bubbleSortReverse(string arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
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
    string* arr = new string[n];  

    for (int i = 0; i < n; i++)
    {
        string s = ""; // создаем пустую строку
        int length = distribution2(generator);; // генерируем случайную длину строки от 1 до 10 символов

        for (int j = 0; j < length; j++)
        {
            char c = rand() % 26 + 'a'; // генерируем случайный символ русского алфавита от 'а' до 'я'
            s += c; // добавляем символ в строку
        }

        arr[i] = s; // добавляем строку в массив
    }

    cout << "Unsorted Array: ";
    for (int i = 0; i < n; i++) {        
       // cout << arr[i] << " ";      
    }
    cout << endl;
    cout << endl;
    bubbleSortReverse(arr, n);
    /*auto start = std::chrono::steady_clock::now();

    bubbleSort(arr, n);

    auto end = std::chrono::steady_clock::now();*/
  //  bubbleSort(arr, n); 
     
    auto start = std::chrono::steady_clock::now();
    bubbleSort(arr, n);
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> diff = end - start;
          
      

    


    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++) {
       // cout << arr[i] << " ";
    }
    cout << endl;
    std::cout << "\nTime taken: " << diff.count() << " seconds\n";
    
    std::cout << n;
    return 0;
}