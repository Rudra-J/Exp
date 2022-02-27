inp=1
op=0
while (inp>0):
       a=(input())
       if a=="0": break
       op+=(int(a.split(".")[0])*60)+int(a.split(".")[1])
    
print(f"{int((op-(op%60))/60)}:{op%60}")