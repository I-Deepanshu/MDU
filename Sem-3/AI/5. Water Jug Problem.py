def gcd(a, b):
    if b==0:
        return a
    return gcd(b, a%b)

def pour(to_jug_cap, from_jug_cap, desired_amount):
    from_jug = from_jug_cap
    to_jug = 0
    step = 1
    print(f"     A({to_jug_cap})  B({from_jug_cap})")
    print(f"{' '*(3-len(str(step)))}{step}:  {to_jug}      {from_jug}")
    while ((from_jug is not desired_amount) and (to_jug is not desired_amount)):
        temp = min(from_jug, to_jug_cap-to_jug)
        to_jug = to_jug + temp
        from_jug = from_jug - temp
        step = step + 1
        print(f"{' '*(3-len(str(step)))}{step}:  {to_jug}      {from_jug}")
        if ((from_jug == desired_amount) or (to_jug == desired_amount)):
            break
        if from_jug == 0:
            from_jug = from_jug_cap
            step = step + 1
            print(f"{' '*(3-len(str(step)))}{step}:  {to_jug}      {from_jug}")
        if to_jug == to_jug_cap:
            to_jug = 0
            step = step + 1
            print(f"{' '*(3-len(str(step)))}{step}:  {to_jug}      {from_jug}")
    return step

def min_steps(jugA, jugB, desired_amount):
    if jugB > jugA:
        jugA, jugB = jugB, jugA
    if (desired_amount % gcd(jugA, jugB) != 0):
        return -1
    return(min(pour(jugA, jugB, desired_amount), pour(jugB, jugA, desired_amount)))

if __name__ == '__main__':
    jugA = int(input("Enter the capacity of the first jug: "))
    jugB = int(input("Enter the capacity of the second jug: "))
    desired_amount = int(input("Enter the desired amount: "))
    if(min_steps(jugA, jugB, desired_amount) == -1):
        print("Not possible")
    else:
        print('Minimum number of steps required is', min_steps(jugA, jugB, desired_amount))