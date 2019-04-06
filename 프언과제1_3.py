def mergesort(arr):
    if len(arr) <= 1:
        return arr

    half = len(arr)//2

    L = mergesort(arr[:half])
    R = mergesort(arr[half:])
    sortedlist = []

    while len(L) > 0 and len(R) > 0:
        if L[0] > R[0]:
            sortedlist.append(R[0])
            R.pop(0)
        else:
            sortedlist.append(L[0])
            L.pop(0)

    if len(L) > 0:
        sortedlist += L
    if len(R) > 0:
        sortedlist += R

    return sortedlist


arr = [100, 23, 31, 123, 435, 642, 1]
print(mergesort(arr))

