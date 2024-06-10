mylist = []
print("Enter 10 Numbers (in ascending order):")
for i in range(10):
    mylist.insert(i, int(input("- ")))
print("Enter a Number to to search:")
toSearch = int(input("-> "))
left = 0
right = 9
middle = (left+right)//2
while left <= right:
    if mylist[middle]<toSearch:
        left = middle+1
    elif mylist[middle]==toSearch:
        print("The Number Found at index:", end=" ")
        print(middle)
        break
    else:
        right = middle-1
    middle = (left+right)//2
if left>right:
    print("The Number is not Found in the List")