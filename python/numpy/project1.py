import numpy as np

# 在二维数组中寻找一定范围的值，并求其中位数和均值
array = np.array([[1, 2, 5], [4, 5, 6], [6, 8, 10]])
array_1 = (array > 2) & (array < 8)
array_2 = array * array_1
print(array_2)

# 获取范围内的数目
print(np.count_nonzero(array_2))

# 获取范围内的索引
print(np.nonzero(array_2))

# 输出数值大于零的值（索引一定要用中括号）
array_3 = array_2[array_2 > 0]
print(array_3)

# 输出中位数和均值
print(f'均值：{np.mean(array_3)}')
print(f"中位数：{np.median(array_3)}")

# 按照某列排序
idex = np.lexsort([array_2[:, 2]])
print(array_2[idex, :])

# 删除含0的行
print(array_2[np.all(array_2 != 0, axis=1)])

# 删除含0的列
print(array_2[np.all(array_2!=0,axis=0)])
