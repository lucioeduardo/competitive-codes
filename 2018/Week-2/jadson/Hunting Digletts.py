# -*- coding: utf-8 -*-

def calculate_time_away(index_ini,index_curr,array,time_away=1):
    if(index_ini==index_curr):
        return time_away
    
    time_away=time_away+1
    return calculate_time_away(index_ini,array[index_curr]-1,array,time_away)

def mdc(a,b):
    if(b>a):
        return mdc(b,a)
    
    if(a%b==0):
        return b
    
    return mdc(b,a%b)

def mmc(a,b):
    return int((a*b)/mdc(a,b))

size_array=int(input())
array=[int(value) for value in input().split(" ")]

time_away=[calculate_time_away(cont,array[cont]-1,array) for cont in range(0,len(array))]
mmc_time_away=1

for cont in range(0,len(time_away)):
    mmc_time_away=mmc(mmc_time_away,time_away[cont])

print(mmc_time_away)
