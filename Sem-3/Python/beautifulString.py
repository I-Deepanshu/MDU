def makeBeautiful(s):
    n = len(s)
    t1, t2 = 0, 0
    s1, s2 = '0', '1'

    for i in range(n):
        if s[i] == '1':
            if s1 == '0':
                t1 += 1
            else:
                t2 += 1
        else:
            if s1 == '1':
                t1 += 1
            else: 
                t2 += 1

        if s1 == '1':
            s1, s2 = '0', '1'
        else:
            s1, s2 = '1', '0'

    return min(t1, t2)

# write pass fail script for the above test cases
result = makeBeautiful('01010010101')
if result == 5:
    print('Pass')
else:
    print('Fail - Expected 5 but got ' + str(result))
	
result = makeBeautiful('10111')
if result == 1:
    print('Pass')
else:
    print('Fail - Expected 1 but got ' + str(result))
	
result = makeBeautiful('000001')
if result == 2:
    print('Pass')
else:
    print('Fail - Expected 2 but got ' + str(result))

result = makeBeautiful('101010000010110100')
if result == 6:
    print('Pass')
else:
    print('Fail - Expected 6 but got ' + str(result))