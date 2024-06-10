def selection_sort(arr):
    n = len(arr)
    for i in range(n):
        min_idx = i
        for j in range(i+1, n):
            if arr[j] < arr[min_idx]:
                min_idx = j
        arr[i], arr[min_idx] = arr[min_idx], arr[i]

# Example usage:
arr = []
num = int(input("Enter size of list : "))
print("Enter elements of list : ")
for n in range(num):
    a = int(input("-> "))
    arr.append(a)
selection_sort(arr)
print("Sorted array:", arr)