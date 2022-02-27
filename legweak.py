a={}
sum=0
num=0
print("Enter three digits")
for i in range(3):
    a[i]=int(input(""))
    sum+=pow(a[i],3)
    num=(num*10)+a[i]
print(sum)
if (num ==sum):
    print("The given number is a legweak number")
else:
    print("THe given number is not a legweak number\n")
for i in range(350,451):
    if(pow(int(str(i)[0]),3)+pow(int(str(i)[1]),3)+pow(int(str(i)[2]),3)==i): 
        print(i)    
    
