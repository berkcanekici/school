import sys

# Function to find the number of substrings
def numberOfSubstrings(text, firstLetter, lastLetter):
    if not text:
        return 0

    # Get length of text
    n = len(text)

    # Count of substrings
    count = 0

    # Brute force search
    for i in range(n):
        if text[i] == firstLetter:
            for j in range(i + 1, n):
                if text[j] == lastLetter:
                    count += 1

    return count

if __name__ == '__main__':
    text = 'TXZXXJZWX'
    firstLetter = 'X'
    lastLetter = 'Z'

    print('The count of substrings:', numberOfSubstrings(text, firstLetter, lastLetter))