# 数据结构与算法

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

## 二叉树

* 三种遍历方法的非递归（重要，必须写会）

* * 先序：先压入头结点
    弹出一个结点
    压入右结点
    压入左结点
  * 中序：
    * 左右头

* * 后序：头左右（弹出后直接放入收集栈）

  ~~~ python
  class TreeNode():
    # 初始化二叉树
    def __init__(self, data, left = None, right= None):
      self.left = left
      self.right = right
      self.data = data
  
  # 先序遍历递归
  def frontSelf(node):
    if node is None:
      return
    print(node.data)
    frontSelf(node.left)
    frontSelf(node.right)
  
    # 先序遍历非递归
  def frontWhile(node):
    if node is not None:
      stack = []
      stack.append(node)
      while len(stack) != 0:
        node = stack.pop()
        print(node.data)
        if node.right is not None:
          stack.append(node.right)
        if node.left is not None:
          stack.append(node.left)
  
  # 中序遍历递归
  def middleSelf(node):
    if node is None:
      return
    middleSelf(node.left)
    print(node.data)
    middleSelf(node.right)
  
  # 中序遍历非递归
  def middleWhile(node):
    if node is not None:
      stack = []
      while len(stack) != 0 or node is not None:
        if node is not None:
          stack.append(node)
          node = node.left
        else:
          node = stack.pop()
          print(node.data)
          node = node.right
  
  # 后序遍历递归
  def endSelf(node):
    if node is None:
      return
    endSelf(node.left)
    endSelf(node.right)
    print(node.data)
  
  # 后序遍历非递归方法一
  def endWhile1(node):
    return
  
  # 后续递归方法二 先压左再压右，然后弹入栈
  def endWhile2(node):
    if node is not None:
      stack1 = []
      stack2 = []
      stack1.append(node)
      while len(stack1) != 0 and node is not None:
        node = stack1.pop()
        stack2.append(node)
        if node.left is not None:
          stack1.append(node.left)
        if node.right is not None:
          stack2.append(node.right)
      while len(stack2) != 0:
        node = stack2.pop()
        print(node.data)
      
  ~~~

* 宽度有限遍历：（基础）
  * 用队列，压入头左右，然后弹出一个

    ~~~python
    # 按照宽度遍历二叉树
    def withWhile(node):
      if node is None:
        return
      arr = []
      arr.append(node)
      while len(arr) != 0:
        # 出队列
        node = arr.pop(0)
        print(node.data)
        if node.left is not None:
          arr.append(node.left)
        if node.right is not None:
          arr.append(node.right)
    
    withWhile(node1)
    ~~~

  * 如何知道一个数里面最大的宽度和结点数

    ~~~python
    # 找到最大宽度
    def withMaxWhile(node):
      if node is None:
        return
      arr = []
      arr.append(node)
      dic = {node: 1} #记录结点的层数
      max = 0 # 最大的层数
      curLevel = 1 # 目前来到的层数
      curNodeNum = 0 # 当前层数的结点个数
      while len(arr) != 0:
        # 出队列
        node = arr.pop(0)
        nodeLevel = dic[node]
        if nodeLevel == curLevel:
          curNodeNum = curNodeNum+1
        else:
          curLevel = curLevel+1
          print(curLevel-1, curNodeNum)
          # max = max(max, curNodeNum)
          if max >= curNodeNum:
            max = max
          else:
            max = curNodeNum
          curNodeNum = 1
        if node.left is not None:
          arr.append(node.left)
          dic[node.left] = curLevel + 1
        if node.right is not None:
          arr.append(node.right)
          dic[node.right] = curLevel + 1
      # 比较最后一层的大小
      if max >= curNodeNum:
        max = max
      else:
        max = curNodeNum
      print(max)
    
    withMaxWhile(node1)
    ~~~

* 判断搜索二叉树（左比右边小）

  * 讲中序遍历的打印代码换成比较。设置一个preValue

    ~~~ python
    def isSearTree2(node):
      if node is None:
        return
      isSearTree2(node.left)
      global PreVal
      global flag
      print(PreVal, node.data)
      if PreVal > node.data:
        flag = False
      PreVal = node.data
      isSearTree2(node.right)
    ~~~

  * 套路

    ~~~python
    # 判断搜索二叉树（二叉树套路练习）
    class retType(object):
      def __init__(self, min, max, isa):
        self.min = min
        self.max = max
        self.isSear = isa
    
    def maxa(a, b):
      if a > b:
        return a
      else:
        return b
    
    def mina(a, b):
      if a < b:
        return a
      else:
        return b
    
    def searBiTree(node):
      if node is None:
        return None
      lRetSet = searBiTree(node.left)
      rRetSet = searBiTree(node.right)
      min = node.data
      max = node.data
      isSear = True
      if lRetSet is not None:
        min = mina(node.data, lRetSet.min)
        max = maxa(node.data, lRetSet.max)
      if rRetSet is not None:
        min = mina(node.data, rRetSet.min)
        max = maxa(node.data, rRetSet.max)
      if lRetSet is not None and (lRetSet.max >= node.data or lRetSet.isSear is False):
        isSear = False
      if rRetSet is not None and (rRetSet.min <= node.data or rRetSet.isSear is False):
        isSear = False
      ret = retType(min, max, isSear)
      return ret
    
    ~~~

* 判断完全二叉树

  * 宽度遍历（若有右无左）

    ~~~python
    # 判断一个树是否为完全二叉树
    def isCBT(node):
      if node is None:
        return True
      arr = [] # 建立队列
      flag = True # 判断一个结点的子结点是否双全，如果不是则改为false，后续结点必须为叶节点。
      arr.append(node)
      while len(arr) != 0:
        node = arr.pop(0)
        l = node.left
        r = node.right
        if (r is not None and l is None) or (flag == False and (l is not None or r is not None)):
          return False
        if node.left is not None:
          arr.append(node.left)
        if node.right is not None:
          arr.append(node.right)
        if node.left is not None and node.right is None:
          flag = False
      return True
    ~~~

* 判断满二叉树

* 判断平衡二叉树（左右子树均平衡且左右子树的高度差<1）

* 判断两个结点的公共祖先

  * 递归

    ~~~python
    # 没理解
    def selfNCA(head, node1, node2):
      if head == None or head == node1 or head == node2:
        return head
      left = selfNCA(head.left, node1, node2)
      right = selfNCA(head.right, node1, node2)
      if left is not None and right is not None:
        return head
      if left is not None:
        return left
      else:
        return right
    ~~~

  * 非递归

    ~~~python
    # 判断两个结点的公共祖先
    def NCA(head, node1, node2):
      dic = {head: head}
      process(head, dic)
      list = [] # 存放node1结点的所有父结点
      cur = node1
      while cur != dic[cur]:
        cur = dic[cur]
        list.append(cur)
      for item in list:
        print(item.data)
      cur2 = node2
      while cur2 != dic[cur2]:
        cur2 = dic[cur2]
        if list.count(cur2) != 0:
          return cur2
      return False
      
    
    # 将所有结点的父亲结点放入dic
    def process(head, dic):
      if head is None:
        return
      dic[head.left] = head
      dic[head.right] = head
      process(head.left, dic)
      process(head.right, dic)
    ~~~

* 求一个结点的后继结点（中序遍历的下一个）

  ~~~python
  class suNode(object):
    def __init__(self, data, left = None, right = None, parent = None):
      self.data = data
      self.left = left
      self.right = right
      self.parent = parent
  ~~~

* 二叉树的序列化和反序列化

* 微软折纸条问题

### 解决二叉树递归的套路：判断左子树要的信息，右的信息，然后找自己如何解决出这两种信息（树形dp：向左树和右树分别要信息）

## 图

大概每三个公司出一道题

平常自己选择一种图结构练，遇到题目后将题目上的图转换为自己熟悉的结构

~~~python
class gNode(object):
  def __init__(self, data):
    self.data = data
    self.next = [] # 直接发散出的边
    self.edges = [] # 直接发散出去边的具体参数
    self.inE = 0 # 直接进入结点的结点数
    self.outE = 0 # 直接出节点的结点数

class edge(object):
  def __init__(self, weight, nfrom, to):
    self.weight = weight
    self.nfrom = nfrom
    self.to = to

class graph(object):
  def __init__(self):
    self.node = {} # 存放结点的信息 编号:node 编号=node.data
    self.list = [] # 存放边的信息

# 构建一个图
node1 = gNode(1)
node2 = gNode(2)
node3 = gNode(3)
node4 = gNode(4)
node5 = gNode(5)

a = [edge(3, node1, node3),
edge(4, node1, node4),
edge(2, node2, node1),
edge(5, node2, node5),
edge(8, node3, node4),
edge(6, node4, node5),
edge(1, node4, node2)]

graph1 = graph()
graph1.node[1]= node1
graph1.node[2]= node2
graph1.node[3]= node3
graph1.node[4]= node4
graph1.node[5]= node5


for items in a:
  graph1.list.append(items)

for item in graph1.list:
  if item.nfrom and item.to is not None:
    item.nfrom.outE = item.nfrom.outE+1
    item.nfrom.next.append(item.to)
    item.nfrom.edges.append(item)
    item.to.inE = item.to.inE+1
~~~



* 图的宽度优先遍历（一个队列，一个list检查是否重复进队列）

  ~~~python
  def widthErgo(graph):
    arr = [] # 队列
    checkList = [] # 检查一个结点是否进入过队列
    arr.append(graph.node[1])
    checkList.append(graph.node[1])
    while len(arr) != 0:
      node = arr.pop(0)
      print(node.data)
      for item in node.next:
        if checkList.count(item) == 0:
          arr.append(item)
          checkList.append(item)
  ~~~

* 深度优先遍历

  ~~~python
  # 深度优先遍历
  def deepErgo(graph):
    stack = [] # 栈
    checkList = []
    stack.append(graph.node[1])
    checkList.append(graph.node[1])
    print(graph.node[1].data)
    while len(stack) != 0:
      node = stack.pop()
      for item in node.next:
        if checkList.count(item) == 0:
          stack.append(node)
          stack.append(item)
          print(item.data)
          checkList.append(item)
          break
  ~~~

* 拓扑排序算法

  * 先判断入度为0的点

  * 擦掉这个结点及其影响

    ~~~python
    # 拓扑排序
    def tuopuGraph(graph):
      dic = {} # 记录所有结点的入度
      inMapZero = [] # 入度为0的结点的队列
      for i in graph.node:
        dic[graph.node[i]] = graph.node[i].inE
        if graph.node[i].inE == 0:
          inMapZero.append(graph.node[i])
      while len(inMapZero) != 0:
        node = inMapZero.pop()
        print(node.data)
        for item in node.next:
          dic[item] = dic[item]-1
          if dic[item] == 0:
            inMapZero.append(item)
    ~~~

* 图的转化

  ~~~python
  # 构建一个无向图
  graph2 = [[0,2,3,-1,-1], [2,0,-1,1,5], [3,-1,-1,8,-1], [-1,1,8,0,6], [-1,5,-1,6,0]]
  graph3 = graph()
  
  # 首先创建结点
  for i in range(len(graph2)):
    node = gNode(i+1)
    graph3.node[i+1] = node
  
  # 由于无向图的边可以视为两条有向边，因此在遍历的时候直接创建
  for i in range(len(graph2)):
    index = 1
    for j in graph2[i]:
      if j > 0:
        ed = edge(j, graph3.node[i+1], graph3.node[index])
        graph3.node[i+1].outE = graph3.node[i+1].outE+1
        graph3.node[i+1].next.append(graph3.node[index])
        graph3.node[i+1].edges.append(ed)
        graph3.node[index].inE = graph3.node[index].inE+1
        if index > i:
          graph3.list.append(ed)
      index = index+1
    
  ~~~

  

* prim和克鲁斯卡尔（并查集）

  ~~~python
  # 克鲁斯卡尔 还得优化并查集结构
  class mySet(object):
    def __init__(self, graph):
      self.nodeSet = {} # 存放结点和对应集合 node: list
      self.sameSet = {} # 存放每个结点相等的集合
      for i in graph.node:
        self.nodeSet[graph.node[i]] = [graph.node[i]]
        self.sameSet[graph.node[i]] = [graph.node[i]]
    
    def isSameSet(self, nFrom, to): # 判断两个集合是否为同一个集合
      set1 = self.nodeSet[nFrom]
      set2 = self.nodeSet[to]
      return set1 == set2
      
  
    def union(self, nFrom, to): # 将两个集合合并
      set1 = self.nodeSet[nFrom]
      set2 = self.nodeSet[to]
      for item in set2:
        set1.append(item)
      set2 = set1 # 将两个结点的公共结点集合指向一个地址
      for item in self.sameSet[to]:
        self.sameSet[nFrom].append(item)
      self.sameSet[to] = self.sameSet[nFrom] # 将两个结点的相同结点列表相等
      for item in self.sameSet[to]: # 对于每个结点
        self.sameSet[item] = self.sameSet[to] # 将所有的结点的公共结点归一
        self.nodeSet[item] = self.nodeSet[to] # 将所有结点的集合归一
      
  
  def heapSort(edge):
    return edge.weight
  
  def kruscarl(graph):
    gra = mySet(graph)
    priArr = [] # 边的优先队列
    for edge in graph.list:
      priArr.append(edge)
    priArr.sort(key = heapSort, reverse = True) # 降序排序，每次取最后的一个为最小值
    while len(priArr) != 0:
      edge = priArr.pop()
      if gra.isSameSet(edge.nfrom, edge.to) is False:
        gra.union(edge.nfrom, edge.to)
        print(edge.nfrom.data, edge.to.data)
  
  
  ~~~

  ~~~python
  def heapSort(edge):
    return edge.weight
  
  def primAlgo(graph):
    arrList = [] # 小根堆，放置所有已经解锁的边
    nodeList = [] # 放置所有已经被访问的结点（to点）
    nodeList.append(graph.node[1])
    cur = graph.node[1]
    print(cur.data)
    for edge in cur.edges:
      arrList.append(edge) # 解锁所有的边
    arrList.sort(key = heapSort, reverse = True)
    while len(nodeList) != 0:
      edge = arrList.pop()
      if nodeList.count(edge.to) == 0:
        print(edge.to.data)
        nodeList.append(edge.to)
        for edg in edge.to.edges:
          arrList.append(edg) # 解锁所有的边
        arrList.sort(key = heapSort, reverse = True)
  
  ~~~

* Dijkstra （需要手动改堆优化，注意）

  ~~~python
  def getMin(a, b):
    if a>b:
      return b
    else:
      return a
  
  def dijkstra(head):
    distanceHead = {} # node: distance
    selectedNode = [] # 已经访问过的node
    distanceHead[head] = 0
    node = getMiniUnselecNode(distanceHead, selectedNode) 
    while node is not None:
      distance = distanceHead[node]
      for edge in node.edges:
        toNode = edge.to
        if toNode not in distanceHead:
          distanceHead[toNode] = edge.weight + distance
        distanceHead[toNode] = getMin(distanceHead[toNode], distance+edge.weight)
      selectedNode.append(node)
      node = getMiniUnselecNode(distanceHead, selectedNode)
    return distanceHead
  
  def getMiniUnselecNode(distanceHead, selectedNode): # 找到一个最小的未选择过的记录，此处需要优化
    min = float("inf") # 初始化最小值
    minNode = None
    for node in distanceHead:
      if distanceHead[node] < min:
        if node not in selectedNode:
          min = distanceHead[node]
          minNode = node
    return minNode
  ~~~

### 前缀树





我们知道， **python中的数字类型是不可变数据**。也就是数字类型数据在 `内存` 中是不会发生改变，当变量值发生改变时，会新申请一块[内存](https://so.csdn.net/so/search?q=%E5%86%85%E5%AD%98&spm=1001.2101.3001.7020)赋值为新值，然后将变量指向新的内存地址。 



## 贪心算法

贪心策略靠蒙，考场上不要纠结是否全局最优

对数器：

1.有一个你想要测的方法a；
2.实现一个绝对正确但是复杂度不好的方法b；
3.实现一个随机样本产生器；
4.实现对比算法a和b的方法；
5.把方法a和方法b比对多次来验证方法a是否正确；
6.如果有一个样本使得比对出错，打印样本分析是哪个方法出错；
7.当样本数量很多时比对测试依然正确，可以确定方法a已经正确。

贪心算法的策略：

1. 写出一个暴力解法
2. 设想多个贪心算法
3. 将两种算法放入对数器，检验哪种正确
4. 别证明贪心算法的正确

python函数参数传递：

http://c.biancheng.net/view/2258.html

1.  不管什么类型的参数，在 Python 函数中对参数直接使用“=”符号赋值是没用的，直接使用“=”符号赋值并不能改变参数。
2.  如果需要让函数修改某些数据，则可以通过把这些数据包装成列表、字典等可变对象，然后把列表、字典等可变对象作为参数传入函数，在函数中通过列表、字典的方法修改它们，这样才能改变这些数据。

* 随时找到一个数组的中位数
* 项目安排
* 项目时间安排
* n皇后问题及其常数时间内的优化
* 打印字符的全排列（递归）
* 抽卡策略（递归）
* 逆序栈（递归）

## 哈希表和哈希函数

* 用1G内存统计40亿个数出现最多的数用哈希函数实现



* Java 在开发中，若一个类中定义了一个静态变量并且返回一个类，在将这个类作为函数返回值的方法返回参数时可以直接classname.method()

~~~java
package Practic1;

import java.util.*;

public class main {
    public static void main(String[] args) {
        Solution a = new Solution("nimama");
        Node abc = nimama();

    }

    static Node getMinNode(HashSet<Node> selected, HashMap<Node, Integer> selectedNode) {
        Node new_node = null;
        Integer min_val = Integer.MAX_VALUE;

        for(Node node : selectedNode.keySet()){
            Integer distance = selectedNode.get(node);
            if(!selected.contains(node) && distance < min_val) {
                new_node = node;
                min_val = distance;
            }
        }
        return  new_node;

    }
    static Node nimama() {
        return Node.ab();
    }


    static class Node {
        public Integer data;
        public HashSet<Node> next;
        public int inE;
        public int outE;
        public HashSet<Edge> edges;

        public static Node ab() {
            return new Node(1);
        }

        public Node(int data) {
            this.data = data;
            this.next = new HashSet<>();
            this.inE = 0;
            this.outE = 0;
            this.edges = new HashSet<>();
        }

    }

    static class Edge {
        public int weight;
        public Node from;
        public Node to;

        public Edge(int weight, Node from, Node to){
            this.from = from;
            this.to = to;
            this.weight = weight;
        }

    }

    static class Graph {
        public HashMap<Integer, Node> nodes;
        public HashSet<Edge> edges;

        public Graph() {
            this.edges = new HashSet<>();
            this.nodes = new HashMap<>();
        }
    }
}

~~~

建议将entity中的变量名和数据库中的名字都使用小写，否则在使用Mybatis plus中的getOne查询时可能出错。

https://blog.csdn.net/weixin_44937106/article/details/125271031

## 字符串算法

1. KMP

```java
package Practic1;

public class KMP {
    public int kmp(String str1, String str2) {
        if (str1 == null || str2 == null || str2.length() > str1.length()) {
            return -1;
        }
        char[] stra = str1.toCharArray();
        char[] strb = str2.toCharArray();
        int i = 0;
        int j = 0;
        int[] next = getNextArray(strb);
        while (i < stra.length && j < strb.length) {
            if (stra[i] == strb[j]) {
                i++;
                j++;
            } else if (next[j] == -1) {
                i++;
            } else {
                j = next[j];
            }
        }
        return j == str2.length() ? i-j : -1;
    }

    public int[] getNextArray(char[] ms) {
        if(ms.length == 1) {
            return new int[] {-1};
        }
        int[] next = new int[ms.length];
        next[0] = -1;
        next[1] = 0;
        int cn = 0;
        int i = 2;
        while (i < next.length) {
            if (ms[i-1] == ms[cn]) { // please node that this must be ms[i-1].if it is i, then it will include i itself.
                next[i++] = ++cn;
            } else if (cn > 0) {
                cn = next[cn];
            } else {
                next[i++] = 0;
            }
        }
        return next;
    }
}
```

2. Manacher算法求回文字符串长度

```java
package Practic1;

public class Mannacher {

    /**
     *Manacher Algorithm
     * @param ab is the String which you want to search its maximum Patrolim
     * @return return Pa array of String ab
     */
    public int[] manacher(String ab) {
        /*
        *this part is aim to pre-process the target string to ['#', x, '#' ....]
        * */
        char[] ms = ab.toCharArray();
        char[] ori = new char[ms.length*2+1];
        int index = 1;
        int ori_index = 0;
        ori[0] = '#';
        while (index < ori.length) {
            ori[index] = ms[ori_index];
            ori[index+1] = '#';
            index = index+2;
            ori_index++;
        }

        /*
        * for this part is core of the Manacher Algo.
        * */
        int R = -1; //R indicates temporary maximum Pa right border of one center.
        int C = -1; // C is the element which has temporary maximum right border.
        int[] arr = new int[ori.length]; // target array.


        for(int i = 0; i < ori.length; i++) {

            /*
             * if current element is outside R, we assign its border with 1.
             * else we chose minimum border by comparing its own border and the distance between this element and R.
             * arr[2*C-i] is the symmetric part of i respect to B.
             * This part of border is not necessary to be considered.
             * */
            if (R > i) {
                arr[i] = Math.min(arr[2*C-i], R-i);
            } else {
                arr[i] = 1;
            }

            /*
            * See whether i can expand its border.
            * we need to first promise that i and its border is less than len(arr).
            * */
            while (i+arr[i] < arr.length && i-arr[i] > -1) {
                if (ori[i+arr[i]] == ori[i-arr[i]]) {
                    arr[i]++;
                } else {
                    break;
                }
            }

            // update C and R
            if (i+arr[i] > R) {
                C = i;
                R = i+arr[i];
            }
        }
        return arr;
    }
}
```

## 关于数据库

Order by 不可以出现在子查询中！！！

where, group by, and having can appear in one sql.

but where must occur before others.

第19，22， 25题没写

~~~mysql
set @i=0; --设置变量
select @i:=@i+1 `order`, a.s_id, a.average from
(select student.s_id, avg(score.s_score) average from student inner join score on student.s_id = score.s_id GROUP BY student.s_id ORDER BY avg(score.s_score) desc) a;
~~~

## Slidewindow

~~~java
package Practic1;

import java.util.LinkedList;

public class SlipWindow {
    public void slip(int[] target, int window) {
        // initialize left point and right point
        int L = 0;
        int R = 0;
        // initialize window, the first of element in window is the maximum value of each window.
        LinkedList<Integer> stack = new LinkedList<>();
        while (R < target.length) {
            // if r-l is larger than window size, then if the first element in window = current r, we remove it.
            if (R-L >= window) {
                if (stack.getFirst() == L) {
                    stack.removeFirst();
                }
                L++;
            }
            // if current r is greater than the top of que, then we pop it until the top of que = current r.
            while(!stack.isEmpty() && target[stack.getLast()] <= target[R]) {
                stack.removeLast();
            }
            // we add R into que
            stack.add(R);
            System.out.print(L+" ");
            System.out.print(R+" ");
            System.out.println(stack);
            R++;
        }
    }
}
~~~

leetcode 209

## 单调栈

~~~java
package Practic1;

import java.util.LinkedList;
import java.util.Stack;

/*
* 单调站主要是来求距离每个数最近的大于/小于它的那个数的位置
* */
public class SingleStack {
    public void single(int[] target) {
        Stack<LinkedList<Integer>> stack = new Stack<>();

        for (int i = 0; i < target.length; i++) {
            /*
            if stack is not 0 and top of the stack < current target, we pop the stack, and current target is its closest right
            element, and current stack top is its closest left element.
            * */
            while (stack.size() != 0 && target[stack.peek().getLast()] < target[i]) {
                LinkedList<Integer> tmp = stack.pop();
                for (int item : tmp) {
                    System.out.print(item);
                    if (stack.isEmpty()) {
                        System.out.print(" left: "+null);
                    } else {
                        System.out.print(" left: " + stack.peek().getLast());
                    }
                    System.out.println((" right: "+i));
                }
            }
            
            /*
            * if current element = top element, then we add this index to top element(LinkedList). Else we add a new element.
            * */
            if (!stack.isEmpty() && target[stack.peek().getLast()] == target[i]) {
                stack.peek().add(i);
            } else {
                LinkedList<Integer> obj = new LinkedList<>();
                obj.add(i);
                stack.add(obj);
            }
        }
        /*
        * process remaining elements in stack.
        * */
        while (!stack.isEmpty()) {
            LinkedList<Integer> tmp = stack.pop();
            for (int item : tmp) {
                System.out.print(item);
                if (stack.isEmpty()) {
                    System.out.print(" left: "+null);
                } else {
                    System.out.print(" left: " + stack.peek().getLast());
                }
                System.out.println((" right: "+null));
            }
        }

    }
}

~~~

java匹配多个空格：\\\s+

Bit operation:

leetcode 201

## 前缀树

leetcode 208, 211

```java
class Trie {

    private TrieNode root;

    public Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    public void insert(String word) {
        TrieNode node = root;
        for (int i = 0; i < word.length(); i++) {
            char currentChar = word.charAt(i);
            if (!node.containsKey(currentChar)) {
                node.put(currentChar, new TrieNode());
            }
            node = node.get(currentChar);
        }
        node.setEnd();
    }
    
    private TrieNode searchPrefix(String word) {
        TrieNode node = root;
        for (int i = 0; i < word.length(); i++) {
           char curLetter = word.charAt(i);
           if (node.containsKey(curLetter)) {
               node = node.get(curLetter);
           } else {
               return null;
           }
        }
        return node;
    }

    // Returns if the word is in the trie.
    public boolean search(String word) {
       TrieNode node = searchPrefix(word);
       return node != null && node.isEnd();
    }
    
    public boolean startsWith(String prefix) {
        TrieNode node = searchPrefix(prefix);
        return node != null;
    }
}

class TrieNode {

    // R links to node children
    private TrieNode[] links;

    private final int R = 26;

    private boolean isEnd;

    public TrieNode() {
        links = new TrieNode[R];
    }

    public boolean containsKey(char ch) {
        return links[ch -'a'] != null;
    }
    public TrieNode get(char ch) {
        return links[ch -'a'];
    }
    public void put(char ch, TrieNode node) {
        links[ch -'a'] = node;
    }
    public void setEnd() {
        isEnd = true;
    }
    public boolean isEnd() {
        return isEnd;
    }
}

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * boolean param_2 = obj.search(word);
 * boolean param_3 = obj.startsWith(prefix);
 */
```

