lst = [1,2,3,4,5]

try:
    print(lst.index(6))
except ValueError:
    print("Value not found")