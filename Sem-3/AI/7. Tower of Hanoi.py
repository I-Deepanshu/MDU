def print_rods(A, B, C):
    print("A:", A)
    print("B:", B)
    print("C:", C)
    print()

def TowerOfHanoi(n , source, destination, auxiliary):
    if n==1:
        print ("Move disk 1 from source",source,"to destination",destination)
        destination.append(source.pop())
        print_rods(A, B, C)
        return
    TowerOfHanoi(n-1, source, auxiliary, destination)
    print ("Move disk",n,"from source",source,"to destination",destination)
    destination.append(source.pop())
    print_rods(A, B, C)
    TowerOfHanoi(n-1, auxiliary, destination, source)

# Driver code
n = 3
A = [3, 2, 1]
B = []
C = []
print_rods(A, B, C)
TowerOfHanoi(n, A, C, B) 