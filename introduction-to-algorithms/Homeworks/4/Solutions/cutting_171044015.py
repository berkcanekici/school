def minumum_cutting(n):
    if (n == 1):
        return 1

    return 1 + minumum_cutting(n // 2)

if __name__ == '__main__':
    print('Minimum value:', minumum_cutting(100))