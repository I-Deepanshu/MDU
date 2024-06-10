def insertion_sort(lst):
    for i in range(1, len(lst)):
        j = i
        while j > 0 and lst[j] < lst[j-1]:
            lst[j], lst[j-1] = lst[j-1], lst[j]
            j -= 1
    return lst

# Example usage:
arr = []
num = int(input("Enter size of list : "))
print("Enter elements of list : ")
for n in range(num):
    a = int(input("-> "))
    arr.append(a)
insertion_sort(arr)
print("Sorted array:", arr)