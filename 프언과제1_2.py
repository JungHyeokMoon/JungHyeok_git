#!/usr/bin/env python
#-*- coding:utf-8 -*-

def swap(arr,i,j):
    arr[i],arr[j]=arr[j],arr[i]

def pivotpartition(arr,left,right):
    pivotval=arr[left]
    pivotidx=left
    while left<=right:
        while left<=right and arr[left]<=pivotval:
            left+=1
        while left<=right and arr[right]>=pivotval:
            right-=1
        if left<=right:
            swap(arr,left,right)

    print(arr)

    swap(arr,pivotidx,right)
    print(arr)
    return right

def quicksort(arr,left,right):
    if left<right:
        pivotpoint=pivotpartition(arr,left,right)
        quicksort(arr,left,pivotpoint-1)
        quicksort(arr,pivotpoint+1,right)


arr = [26, 5, 37, 1, 61, 11, 59, 15, 48, 19]
quicksort(arr,0 ,len(arr)-1)




