import sys

def findMaxProfit(a):
    n = len(a)

    firstMax = 0
    secondMax = -sys.maxsize - 1

    for i in range(n):
        firstMax = max(a[i], a[i] + firstMax)
        secondMax = max(secondMax, firstMax)

    return secondMax


if __name__ == '__main__':
    a = [3, -5, 2, 11, -8, 9, -5]
    print('Maximum profit: ', findMaxProfit(a))



