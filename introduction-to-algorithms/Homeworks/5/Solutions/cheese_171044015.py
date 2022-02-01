
class Cheese:
    def __init__(self, price, weight):
        self.price = price
        self.weight = weight
        self.cost = price / weight
    def __lt__(self, other):
        return self.cost < other.cost

def createAmountArray(prices, weights):
    amountArray = []

    for i in range(len(weights)):
        amountArray.append(Cheese(prices[i], weights[i]))

    amountArray.sort(reverse=True)

    return amountArray


def findMaxPrice(prices, weights, fullCapacity):
    amountArray = createAmountArray(prices, weights)

    maxPrice = 0
    filledCapacity = 0

    for i in range(len(amountArray)):
        if filledCapacity + amountArray[i].weight <= fullCapacity:
            maxPrice += amountArray[i].price
            filledCapacity += amountArray[i].weight
        else:
            leftCapacity = fullCapacity - filledCapacity
            maxPrice += leftCapacity * amountArray[i].cost
            break

    return maxPrice

if __name__ == '__main__':
    weight = [10, 40, 20, 30]
    price = [60, 40, 100, 120]
    capacity = 50

    print('Maximum price: ', findMaxPrice(price, weight, capacity))
