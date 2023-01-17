import numpy as np
import time
import sys

sys.setrecursionlimit(10**6)

def is_sorted(a):
    for i in range(len(a)-1):
        if a[i] > a[i+1]: return False
    return True

def partition(a, lo, hi):
    i = lo + 1
    j = hi
    while 1<2:
        while a[i] < a[lo]:
            if i == hi: break
            i += 1
        while a[j] >= a[lo]:
            if j == lo: break
            j -= 1
        if i >= j: break
        a[i],a[j]=a[j],a[i]
    a[lo],a[j]=a[j],a[lo]
    return j

def find_median(a, lo, hi, l, h):
    n = len(a)
    m = (n-1)//2
    if hi < lo: return
    j = partition(a, lo, hi)
    if j == m:
        if n % 2 != 0: print(a[j])
        else: print((a[j]+a[j+1])/2)
    elif j < m: find_median(a, j+1, hi, 0, n-1)
    else: find_median(a, lo, j-1, 0, n-1)

n = 999999
start = time.time()
arr = np.random.randint(0, n, size=n, dtype=int)
find_median(arr, 0, n-1, 0, n-1)
print(f"Time taken: {time.time() - start}")