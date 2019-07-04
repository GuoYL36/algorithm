# 给定一个输入的字符串和一个包含各种单词的字典，用空格将字符串分割成一系列字典中存在的单词。举个例子，如果输入字符串是“applepie”而字典中包含了所有的英文单词，那么我们应该得到返回值“apple pie”。

# 层次1：只考虑把字符串拆分成两个单词。

# def SegmentString(st, dic):
	# length = len(st)
	# for i in range(1, length):
		# prefix = st[0:i]
		# if prefix in dic:
			# suffix = st[i:]
			# if suffix in dic:
				# return prefix + " " + suffix
	# return None

# 层次2：将输入字符串分割成任意数量的单词
# 解法一：递归回溯法（时间复杂度：O(2^n),树形分裂）

# def SegmentString(st, dic):
	# if st in dic:
		# return st
	# length = len(st)
	# for i in range(1,length):
		# prefix = st[0:i]   
		# if prefix in dic:
			# suffix = st[i:]
			# segSuffix = SegmentString(suffix, dic)  # 递归解法
			# if segSuffix != None:
				# return prefix + " " + segSuffix
	
	# return None


# 解法二：动态规划法

dic1 = {}
def SegmentString(st, dic):
	if st in dic:
		return st
	if st in dic1.keys():
		return dic1[st]
	length = len(st)
	for i in range(1, length):
		prefix = st[0:i]
		if prefix in dic:
			suffix = st[i:]
			segSuffix = SegmentString(suffix, dic)
			if segSuffix != None:
				dic1[st] = prefix + " " + segSuffix
				return prefix + " " + segSuffix
		dic1[st] = None
	return None


print(SegmentString("applepiepieapple",["apple","pie"]))

