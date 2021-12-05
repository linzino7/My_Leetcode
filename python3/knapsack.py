# -*- coding: utf-8 -*-
"""
Created on Fri Jul 16 16:43:40 2021

@author: ASUS
"""


def knapsack(val, wt, W):
    
    maxval = [0] * len(val)
    maxwt = [0] * len(wt)
    maxval[0] = val[0] 
    maxwt[0] = wt[0] 
    for i in range(1, len(val)):
        if maxval[i-1] + val[i]> val[i-1] and maxwt[i-1] + wt[i]<W:
            maxval[i] = maxval[i-1] + val[i]
            maxwt[i] = maxwt[i-1] + wt[i]
    
    print(maxval)
    print(maxwt)
    return max(maxval)

#Driver Code
val = [60, 100, 120]
wt = [10, 20, 30]
W = 50
n = len(val)

print(knapsack(val, wt, W))


 
def knapSack(W, wt, val, n):
 
    # Base Case
    if n == 0 or W == 0:
        return 0
 
    # If weight of the nth item is
    # more than Knapsack of capacity W,
    # then this item cannot be included
    # in the optimal solution
    if (wt[n-1] > W):
        return knapSack(W, wt, val, n-1)
 
    # return the maximum of two cases:
    # (1) nth item included
    # (2) not included
    else:
        return max(
            val[n-1] + knapSack(
                W-wt[n-1], wt, val, n-1),
            knapSack(W, wt, val, n-1))
 
# end of function knapSack
 
 
#Driver Code
val = [60, 100, 120]
wt = [10, 20, 30]
W = 50
n = len(val)
print(knapSack(W, wt, val, n))
 
