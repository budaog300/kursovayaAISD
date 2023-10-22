import datetime
import random
import time


def bubble_sort(arr):
    n = len(arr)
    # Проход по всем элементам
    for i in range(n):
        swapped = False
        # Последние i элементов уже были отсортированы
        for j in range(0, n - i - 1):
            # Если элемент j больше следующего за ним элемента
            if arr[j] > arr[j + 1]:
                # Поменять элементы местами
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
                swapped = True
        # if not swapped:
        #     return arr

    return arr


def bubble_sort_reverse(arr):
    n = len(arr)
    for i in range(n-1):
        for j in range(n-1-i):
            if arr[j] < arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]
    return arr


random.seed(time.time())
n = random.randint(1, 5000)
arr = [random.randint(1, 5000) for i in range(n)]
# arr = [random.uniform(1, 5000) for i in range(2616)]

print("Unsorted arr: ")
print(arr)
print(n)
# unsorted = bubble_sort_reverse(arr)
# start = time.monotonic()
# sorted_arr = bubble_sort(arr)
# end = time.monotonic()

#sorted_arr = bubble_sort(arr)
start = time.monotonic()
sort = bubble_sort(arr)
end = time.monotonic()
total_time = end - start
print("Sorted arr: ")
# print(sort)
# print(f"Time taken: {total_time.total_seconds():.10f} seconds")
print(f"Time taken: {total_time:.100f} seconds")
