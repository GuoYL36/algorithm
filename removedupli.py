# 移除排序好的矩阵中的重复元素，并求长度,返回的新数组超出该长度的元素不考虑

def rem(nums):
    length = 0
    if nums == []:
        return length
    for i in range(len(nums)):
        if i == 0:
            length += 1
        else:
            if nums[i-1] != nums[i]:

                nums[length] = nums[i]
                length += 1
    return length, nums

x = [1,1,2,2,2,3,4]
print(rem(x))
















