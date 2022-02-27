def tint(a):
    for i in range(len(a)):
        a[i]=int(a[i])
    return a

no=int(input("Enter the no. of stacks: "))
mxh=int(input("Enter the max height: "))
start=tint(input("Enter the initial boxes per stack: ").split(" "))
com=tint((input("Enter the commands: ")).split(" "))

runner=0
end=False

for i in range(len(com)):
    if com[i]==1 and not end:
        if runner!=0:
            runner-=1
    if com[i]==2 and not end:
        if runner!=(len(start)-1):
            runner+=1
    if com[i]==3 and not end:
        if start[runner]>0:
            start[runner]-=1
    if com[i]==4 and not end:
        if start[runner]!=mxh:
            start[runner]+=1
    if com[i]==0 and not end:
        end=True
print(*start)
