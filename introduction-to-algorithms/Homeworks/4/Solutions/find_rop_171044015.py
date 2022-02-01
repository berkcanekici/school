
def mergeAndCount(array, low, mid, high):
    count = 0
    tempArray = [None] * (high - low + 1)

    i = low
    j = mid + 1
    k = 0

    while i <= mid and j <= high:
        if array[i] > array[j]:
            count += (mid - i + 1)
            tempArray[k] = array[j]
            j += 1
        else:
            tempArray[k] = array[i]
            i += 1
        k += 1

    while i <= mid:
        tempArray[k] = array[i]
        k += 1
        i+= 1

    while j <= high:
        tempArray[k] = array[j]
        k += 1
        j += 1

    for i in range(low, k + low):
        array[i] = tempArray[i - low]

    return count


def countRop(array, low, high):
    if low >= high:
        return 0

    mid = low + (high - low) // 2

    inversionsLeft = countRop(array, low, mid)
    inversionsRight = countRop(array, mid + 1, high)
    inversionsMerge = mergeAndCount(array, low, mid, high)

    return inversionsLeft + inversionsRight + inversionsMerge


if __name__ == '__main__':
    array = [4, 3, 2, 5, 6, 1, -5]

    print('Number of count:', countRop(array, 0, len(array) - 1))
