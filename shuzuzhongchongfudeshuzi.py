#  数组中重复的数字

def duplicate(numbers, duplication):
    if numbers == None or len(numbers) == 0:
        return False
    length = len(numbers)
    i = 0
    while i < length:
        if numbers[i] < 0 or numbers[i] >= length:
            return False
        i += 1
    j = 0
    while j < length:
        while j != numbers[j]:
            if numbers[j] == numbers[numbers[j]]:
                duplication[0] = numbers[j]
                return True
            else:
                tmp = numbers[j]
                numbers[j] = numbers[tmp]
                numbers[tmp] = tmp

        j += 1
    return False

numbers = [2, 3, 1, 0, 2, 5, 3]
n = []
n.append(0)

print(duplicate(numbers, n))







