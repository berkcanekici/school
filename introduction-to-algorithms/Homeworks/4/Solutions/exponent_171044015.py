def bruteForceSolution(a, n):
    if a <= 0 or n <= 0:
        return 0

    result = 1

    for i in range(n):
        result *= a

    return result

def divideConquerSolution(a, n):
    if n == 0:
        return 1
    else:
        m = divideConquerSolution(a, n // 2)

        if n % 2 == 0:
            return m * m
        else:
            return a * m * m

if __name__ == '__main__':
    a = 5
    n = 4

    print('Brute force solution: ', bruteForceSolution(a, n))
    print('Divide and conquer solution: ', divideConquerSolution(a, n))