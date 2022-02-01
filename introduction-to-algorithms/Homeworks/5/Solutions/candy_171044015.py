import sys

def cutCandy(p, n):
    arr = [None]*(n + 1)
    arr[0] = 0

    for x in range(1, n + 1):
        q = -sys.maxsize
        for y in range(1, x + 1):
            q = max(q, p[y] + arr[x - y])
        arr[x] = q

    return arr[n]


if __name__ == '__main__':
    a = {1:1, 2:5, 3:8, 4:9, 5:10, 6:17, 7:17, 8:20}
    print('Maximum obtainable value:', cutCandy(a, 8))
    b = {1: 25, 2: 1, 3: 1, 4: 1, 5: 11, 6: 700, 7: 17, 8: 20}
    print('Maximum obtainable value:', cutCandy(b, 8))

