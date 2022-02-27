def depth(a):
    b=(a.replace(" ","")).split("2")
    print(b)
    max=0
    indi =0
    ind=0
    for i in range(len(b)):
        if max<len(b[i]):
            max=len(b[i])
    for i in range(len(a)):
        if a[i]=="1":
            flag=True
            for j in range(i,max+1,2):
                if a[j]=='2':
                    flag=False
            if flag:
                ind=i
                break

    print(f"{max} {ind}")

def maxs(a):
    b=[]
    for i in range(len(a)):
        counter = 0
        if a[i]=="1":
            c=""
            for j in range(i+2,len(a)):
                if a[j]=='1':
                    counter+=1
                    c = c + a[j]
                elif a[j]=='2' and counter==0:
                    b.append(c)
                elif a[j]=='2' and counter!=0:
                    counter-=1
                    c = c + a[j]
                elif a[j]==" ":
                    c=c+" "
    max=0
    ind=0
    print(b)
    for i in range(len(b)):
        if max<len(b[i]):
            max=len(b[i])
            ind=i
    print(f"{max} {ind}")

a=input("Enter the set:\n")
b=""
for i in range(len(a)):
    if a[i]!=" ":
        b=b+a[i]
c=""
for i in range(len(b)):
    if b[i]=='1':
        c=c+'('
    else:
        c=c+')'
print(c)
depth(a)
maxs(a)

