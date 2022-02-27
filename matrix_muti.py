from array import *

def inp(a, b, m):
    print("Enter the elements")
    if m == 1:
        arr = [[0 for i in range(b)] for j in range(a)]
        for i in range(a):
            for j in range(b):
                arr[i][j] = int(input())
    else:
        arr = [[0 for i in range(a)] for j in range(b)]
        for i in range(a):
            for j in range(b):
                arr[j][i] = int(input())

    return arr


in1 = input("Enter the dimmm of the matrices \n")
x = int(in1.split(" ")[0])
y = int(in1.split(" ")[1])
m = int(in1.split(" ")[2])
n = int(in1.split(" ")[3])

if y != m:
    print("incompatible matrices")
    exit(0)
a = inp(x, y, 1)
b = inp(m, n, 2)

op = ""
for i in range(x):
    for j in range(n):
        sum = 0
        counter = 0
        while counter < m:
            sum += a[i][counter]*b[j][counter]
            counter += 1
        op += str(sum)+" "

arr = [[0 for i in range(n)] for j in range(x)]

count = 0
for i in range(x):
    for j in range(n):
        arr[i][j] = int(op.split(" ")[count])
        count += 1

print(*arr)
