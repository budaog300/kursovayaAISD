import datetime
import random
import time


# Генерируем случайный структурный тип данных
class MyStruct:
    def __init__(self):
        self.value = random.randint(0, 10)
        self.name = "".join(random.choice('abcdefghijklmnopqrstuvwxyz') for _ in range(random.randint(1, 10)))


def bubble_sort(arr):
    n = len(arr)
    for i in range(n):
        swapped = False
        for j in range(n - i - 1):
            if arr[j].value > arr[j + 1].value:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
                swapped = True
        # if not swapped:
        #     return arr
    return arr


def bubble_sort_reverse(arr):
    n = len(arr)
    for i in range(n-1):
        for j in range(n-1-i):
            if arr[j].value < arr[j+1].value:
                arr[j], arr[j+1] = arr[j+1], arr[j]
    return arr


random.seed(time.time())
n = random.randint(1, 5000)
arr = [MyStruct() for _ in range(n)]

print("Unsorted arr: ")
print([{'value': s.value, 'name': s.name} for s in arr])
print(n)
# bubble_sort_reverse(arr)
# start = time.monotonic()
# sorted_arr = bubble_sort(arr)
# end = time.monotonic()
sorted_arr = bubble_sort(arr)
start = time.monotonic()
sort = bubble_sort(sorted_arr)
end = time.monotonic()
total_time = end - start

print("Sorted arr: ")
print([{'value': s.value, 'name': s.name} for s in sort])
print(f"Time taken: {total_time:.5f} seconds")
