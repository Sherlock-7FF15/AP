# 数据结构

## 排序与时间复杂度

两数交换：

~~~ python
a = a^b; #^为异或操作，但是a,b为两块独立的内存,两个值不同则为1，0^N=N,N^N=0
b = a^b;
a = a^b;

~~~

时间复杂度为算法最差情况估计。如插入排序。

二分的算法为log 2为底N的对数。如果只写logN默认为2为底数。

* 冒泡排序

  ~~~python
  def bubble(array):
    i = len(array)
    while i >= 1:
      j = 1;
      while j < i:
        if array[j] < array[j-1]:
          temp = array[j]
          array[j] = array[j-1]
          array[j-1] = temp
        j = j+1
        print(j)
      print(i)
      i = i-1
  ~~~

* 插入排序

  ~~~python
  def insertRange(arr):
    for i in range(1,len(arr)):
      j = i
      while j > 0:
        if arr[j] < arr[j-1]:
          temp = array[j]
          array[j] = array[j-1]
          array[j-1] = temp
        j = j-1
  ~~~

  

* 二分查找

  ~~~python
  def binarySear(num, array):
    index = int((len(array)+1)/2)
    while array[index] != num:
      print('processing: ', index)
      if num < array[index]:
        index = int((index+1)/2)
      if num > array[index]:
        index = int((len(array)+index)/2)
      if num == array[index]:
        print(index, num)
  ~~~

  

