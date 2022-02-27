alpha=[]
def al():
    for i in range(33,127):
        alpha.append(chr(i))

def ind(a):
    for j in range(len(alpha)):
        if (alpha[j] ==a):
            return j
            
def encode(a,b):
    pointer=ind(a[0])
    for i in range((b%len(alpha))):
        if(pointer==len(alpha)): pointer=0
        else : pointer+=1
    print(alpha[pointer],end="")              
    
def decode(a,b):
    pointer=ind(a[0])
    for i in range((b%len(alpha))):
        if(pointer==0): pointer=len(alpha) 
        else : pointer-=1
    print(alpha[pointer],end="")               
    
a=input("Enter the sentence: \n")
c=int(input("Decode(0) or Encode(1): \n"))
al()
if(c==0):
    for i in range(len(a)): 
        if a[i]!=' ': decode(a[i],pow(i,i)+2*(i+1))
        else: print(" ",end="")   
else: 
    for i in range(len(a)): 
        if a[i]!=' ': encode(a[i],pow(i,i)+2*(i+1))
        else: print(" ",end="") 
