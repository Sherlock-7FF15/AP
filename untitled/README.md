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
  
  def swap(arr, a, b):
    arr[a], arr[b] = arr[b], arr[a]
  
  def patition(arr, left, right):
    less = left-1
    more = right
    while left < more:
      if arr[left] < arr[right]:
        less = less+1
        swap(arr, less, left)
        left = left+1
        continue
      if arr[left] == arr[right]:
        left = left+1
        continue
      if arr[left] > arr[right]:
        more = more-1
        swap(arr, left, more)
        continue
    swap(arr, right, more)
    return [less+1, more]
  
  def quickSortr(arr, left, right):
    if left < right:
      seed = rd.randint(left+1, right)
      swap(arr, seed, right)
      eq = patition(arr, left, right)
      quickSortr(arr, left, eq[0]-1)
      quickSortr(arr, eq[1]+1, right)
  
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

* 单链表

  * ~~~python
    # 带头节点的单链表
    # 注意！头节点内存放着第一个结点的地址，即head.head = 第一个结点
    class singleLinkedlist():
      def __init__(self):
        self.head = None
      # 向链表尾部添加元素
      def append(self, item):
        node = Node(item)
        if self.head == None:
          self.head = node
        else:
          cur = self.head
          while cur.next != None:
            cur = cur.next
          cur.next = node
      # 在链表中删除一个元素
      def delete(self, item):
        cur = self.head
        pre = None
        # 如果链表为空，则返回true
        if self.head == None:
          return True
        while cur.next != None:
          if cur.item == item:
            if pre == None:
              self.head = cur.next
            else:
              self.next = cur.next
          else:
            pre = cur
            cur = cur.next
      # 在头节点前插入元素
      def add(self, item):
        node = Node(item)
        node.next = self.head
        self.head = node
      # 返回当前链表长度
      def length(self):
        i = 0
        cur = self.head
        if cur == None:
          return 0
        while cur != None:
          i = i+1
          cur = cur.next
        return i
      # 遍历链表
      def items(self):
        temp = []
        cur = self.head
        if cur == None:
          print('none')
          return None
        for i in range(self.length()):
          temp.append(cur.item)
          cur = cur.next
        print(temp)
        return(temp)
      # 在某个地方插入一个结点
      def insert(self, n, item):
        i = 0
        if n <= 0:
          self.add(item)
          return
        if n == self.length():
          self.append(item)
          return
        cur = self.head
        node = Node(item)
        # for i in range(n-1):
        #   cur = cur.next
        while i < n-1:
          cur = cur.next
          i = i+1
        node.next = cur.next
        cur.next = node
      def find(self, item):
        return item in self.items()
    ~~~

  * ~~~python
    # 用头插法反转单链表
    def reverseList(list):
      rever = singleLinkedlist()
      while list.head is not None:
        list.items()
        temp = Node(None)
        temp.item = list.head.item
        temp.next = rever.head
        rever.head = temp
        list.head = list.head.next
      return rever
    ~~~

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
    判断是否为回文结构，回文结构，用有限变量判断（三个指针）

    ~~~python
    # 回文结构 三指针
    def backList(list):
      sl = list.head
      fa = list.head
      le = list.head
      while fa.next is not None:
        if fa.next.next is not None:
          sl = sl.next
          fa = fa.next.next
        else:
          fa = fa.next
      fa = reverList(sl)
      while fa.next is not None:
        if fa.item == le.item:
          fa = fa.next
          le = le.next
        else:
          return False
      return True
    
    def reverList(head):
      next = None
      pre = None
      while head is not None:
        next = head.next
        head.next = pre
        pre = head
        head = next
      return pre
    ~~~

  * 将链表以某个值划分为=，<,>区域（6个变量）

逻辑问题：如果要将一个数字插入在一个数组的第n个元素之后，应该如何代码实现？

~~~python
如果要插在n之后：
for i in range(n-1):
    ***
while i < n-1:
    ...
    i = i+1
~~~

