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


求中间下表：MID = L + (R-L)/2 && L + ((R-L)>>1)

求递归时间复杂度，如果子问题规模一致，则可以用master公式。

![1644743404162](C:\Users\Soviet\AppData\Local\Temp\1644743404162.png)

* 归并排序及其改写（每年必出）

  ~~~py
  def merge(arr, l, r, mid):
    tempArr = []
    p1 = l
    p3 = mid+1
    while p1 <= mid and p3 <= r:
      if arr[p1] <= arr[p3]:
        tempArr.append(arr[p1])
        p1 = p1+1
      if arr[p1] > arr[p3]:
        tempArr.append(arr[p3])
        p3 = p3+1
    while p1 > mid and p3 <= r:
      tempArr.append(arr[p3])
      p3 = p3+1
    while p1 <= mid and p3 > r:
      tempArr.append(arr[p1])
      p1 = p1+1
    i = 0
    j = l
    while i < len(tempArr):
      arr[j] = tempArr[i]
      j = j+1
      i = i+1
  
  def mergeSort(arr, l, r):
    if l == r:
      return
    mid = int((l+r)/2)
    mergeSort(arr, l, mid)
    mergeSort(arr, mid+1, r)
    merge(arr, l, r, mid)
  ~~~

  * 递归求小和问题
  * 求逆序对数量

* 快速排序

  * 荷兰国旗问题