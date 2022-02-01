import sys

# Function to evalueate polynom.
def evaluatePolynom(x, coefficients):
    n = len(coefficients)

    result = 0

    for i in range(0, n - 1):
        result += coefficients[i] * pow(x, n - 1 - i)

    result += coefficients[n - 1]

    return result

if __name__ == '__main__':
    # 3 * x^4 + 4 * x^3 + 5 * x^2 + 6 * x^1 + 7
    coefficients = [3, 4, 5, 6, 7]

    x = 2

    print('Result:', evaluatePolynom(x, coefficients))