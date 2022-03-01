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

* 冒泡排序 稳定

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

* 插入排序 稳定

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

* 归并排序及其改写（每年必出） 稳定

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

* 快速排序 不稳定

  ~~~python
  import random as rd
  
  def partition(arr, left, right):
    less = left-1 #小于数的右边界
    more = right #大于数的左边界
    while left < more:
      if arr[left] < arr[right]:
        less = less+1
        temp = arr[left]
        arr[left] = arr[less]
        arr[less] = temp
        left = left+1
      if arr[left] > arr[right]:
        more = more-1
        temp = arr[left]
        arr[left] = arr[more]
        arr[more] = temp
      if arr[left] == arr[right]:
        left = left+1
    # 交换最后一个数和大于区域的第一个数
    temp = arr[right]
    arr[right] = arr[more]
    arr[more] = temp
    return [less+1, more]
  
  def quickSort(arr, left, right):
    if left < right:
      # 交换最后一个数和随机数
      # print('前', array)
      # seed = rd.randint(left+1, right)
      # temp = arr[seed]
      # arr[seed] = arr[right]
      # arr[right] = temp
      equalIndex = partition(arr, left, right)
      quickSort(arr, left, equalIndex[0]-1)
      quickSort(arr, equalIndex[1]+1, right)
  
  ~~~

  

  * 荷兰国旗问题

* 堆排序 不稳定

  ~~~python
  def swap(arr, a, b):
    arr[a], arr[b] = arr[b], arr[a]
  
  def heapInsert(arr, index):
    #判断某个数是否可以向上移动
    while arr[index] > arr[int((index-1)/2)]:
      swap(arr, index, int((index-1)/2))
      index = int((index-1)/2)
  #i = len(a)-1 快一点
  #while i > 0:
  #  heapify(a, i, len(a))
  #  i = i-1
  
  def heapify(arr, index, heapSize): 
    #判断某个位置的值是否为大根堆,判断某个数是否可以向下移动
    left = 2*index+1 #构建左孩子
    while left < heapSize-1: #注意这里一定是heapsize-1
      if arr[left] < arr[left+1]:
        largest = left+1
      else:
        largest = left
      if arr[index] > arr[largest]:
        largest = index
      if largest == index:
        break
      swap(arr, largest, index)
      index = largest
      left = 2*index+1
  
  def heapSort(arr):
    for i in range(len(arr)):
      heapInsert(a, i)
    heapSize = len(a)
    heapSize = heapSize-1
    swap(arr, 0, heapSize)
    print(a)
    while(heapSize > 0):
      heapify(arr, 0, heapSize)
      print(arr)
      heapSize = heapSize-1
      swap(arr, 0, heapSize)
      print(a)
  ~~~

* 桶排序 稳定

排序稳定性：值相同的元素在排序过后的相对位置是否可以不变

## 链表

* 单，双链表反转

* 快慢指针问题

  * 快指针走到头，慢指针离中间数-1

    ~~~python
      a = [1,2,3,4,5]
      b = [1,2,3,4]
      c = [1,2,3]
      d = [1,2]
      e = [1]
      f = []
      g = [1,2,3,4,5,6]
        
    def fastSlowpoint(arr):
      fast = 0
      slow = 0
      if len(arr) == 0:
        print(fast,slow)
        return
      if len(arr)%2 == 0:
        while fast < len(arr)-1:
          if fast+2 > len(arr)-1:
            fast = fast+1
            print(fast,slow)
            return
          else:
            fast = fast+2
            slow = slow+1
      else:
        while fast < len(arr)-1:
          if fast+2 > len(arr)-1:
            print(fast, slow)
            return
          fast = fast+2
          slow = slow+1
      print(fast,slow)
    ~~~

  * 快指针走到头，慢指针在中间位置

  * 快指针走到头，慢指针离中间数+1

逻辑问题：如果要将一个数字插入在一个数组的第n个元素之后（前），应该如何代码实现？