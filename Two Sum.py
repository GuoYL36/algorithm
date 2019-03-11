
def twoSum(nums, target):
    if len(nums) < 1:
        return False
    for i in range(len(nums)):
        if target-nums[i] in nums and i != nums.index(target-nums[i]):
            return [i, nums.index(target-nums[i])]


num = [3, 2, 4]
t = 6
print(twoSum(num, t))














