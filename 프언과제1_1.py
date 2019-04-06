#!/usr/bin/env python
#-*- coding:utf-8 -*-


def binarysearch_recursion(arr, low, high, target):
    if low > high:
        return "None"

    mid = (low + high) // 2

    if target == arr[mid]:
        return mid+1
    elif target < arr[mid]:
        return binarysearch_recursion(arr, low, mid - 1, target)
    else:
        return binarysearch_recursion(arr, mid + 1, high, target)


arr = [1, 11, 15, 19, 37, 48, 59, 61]
x = int(input())
answer = binarysearch_recursion(arr, 0, 7, x)
print(answer)


