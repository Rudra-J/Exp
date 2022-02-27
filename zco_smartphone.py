def sort(a):
    for i in range(len(a)):
        for j in range(len(a)):
            if(a[j]>a[i]):
                t=a[j]
                a[j]=a[i]
                a[i]=t
    return a

a=int(input("Enter the number of customers: "))
b=[]
for i in range(a):
    b.append(input("Enter the budget of this customer: "))

b=sort(b)
c=[]

for i in range(len(b)):
    c.append(int(int(b[i])*(len(b)-i)))

max=0
for i in range(len(c)):
    if(c[i]>max):
        max=c[i]

print(f"Max income: {max}")
