def newton_method(number, number_iters = 100):
    a = float(number)
    for i in range(number_iters):
        number = 0.5 * (number + a / number)
    return number

num=int(input("Enter a number:"))
print("Square root of ", num, "is: ", newton_method(num))