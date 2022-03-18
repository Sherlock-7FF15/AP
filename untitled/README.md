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
  class mySet(object):
    def __init__(self):
      self.publicList = []
    
    def isSameSet(self, node1, node2): # 判断两个结点是否同时在集合中
      if self.publicList.count(node1) == 0 or self.publicList.count(node2) == 0:
        return True
      else:
        return False
  
    def union(self, node1, node2): # 将两个集合合并
      if self.publicList.count(node1) == 0:
        self.publicList.append(node1)
      if self.publicList.count(node2) == 0:
        self.publicList.append(node2)
  
  def heapSort(edge):
    return edge.weight
  
  def kruscarl(graph):
    priArr = [] # 设置边的优先队列
    gra = mySet()
    for edge in graph.list: # 将所有的边依次加入队列
      priArr.append(edge)
    priArr.sort(key = heapSort, reverse = True) # 将所有的边排序
    while len(priArr) != 0:
      edge = priArr.pop()
      fro = edge.nfrom
      to = edge.to
      if gra.isSameSet(fro, to) is True:
        gra.union(fro, to)
        print(edge.weight)
  ~~~

  ~~~python
  def span_tree(g, start_label):
      """最小生成树"""
      # sys.setrecursionlimit(1500)  # set the maximum depth as 1500
      min_weights = 99999
      results = []
  
      def recurse(w, stack):
          if w.is_marked() == False:
              # 顶点未标记则入栈
              stack.push(w)
              w.set_mark()
              # 未遍历完的情况
              if stack.get_size() != g.size_vertices():
                  for x in w.neighboring_vertices():
                      # 继续从顶点的连通节点往下继续遍历
                      recurse(x, stack)
                      # 如果从w的连通节点再往下没有连通节点，
                      # 则出栈w已入栈的连通节点
                      if stack.peek() != w and \
                              stack.get_size() < g.size_vertices():
                          temp = stack.pop()
                          temp.clear_mark()
              else:
                  # 已经遍历完所有顶点，并且满足了条件，
                  # 但最后一个节点还有连通的顶点时，不再遍历
                  # if w.get_edge_count() > 0:
                  #     return None
                  pass
          else:
              return None
  
      def generate_results(sun_stack):
          temp = ""
          for v_temp in sun_stack:
              temp += v_temp.get_label() + "->"
          temp = temp[:len(temp) - 2]
          temp += ": " + str(sun_stack.get_weights())
          temp += "\n"
          results.append(temp)
  
      for v in g.vertices():
          # stack存储整个顶点, sun_stack复制stack的最新状态并继续遍历
          stack = LinkedStack()
          stack.push(v)
          sun_stack = copy.deepcopy(stack)
          for w in v.neighboring_vertices():
              # 清除所有顶点的标记状态(因为上一次的遍历顶点已经被标记)
              g.clear_vertex_marks()
              v.set_mark()
              # 递归遍历
              recurse(w, sun_stack)
              # 如果遍历结束,栈内顶点数==图的顶点数代表该次遍历成功，加入成功列表
              if sun_stack.get_size() == g.size_vertices():
                  if sun_stack.get_weights() < min_weights:
                      results.clear()
                      generate_results(sun_stack)
                      min_weights = sun_stack.get_weights()
                  elif sun_stack.get_weights() == min_weights:
                      generate_results(sun_stack)
              else:
                  # 未找到路径则继续下一个连接顶点的遍历
                  pass
              sun_stack = copy.deepcopy(stack)
  
      if results == None:
          return "No best path"
      string = "Here are " + str(len(results)) + " path:\n"
      results.insert(0, string)
      return results
  
  ~~~

  

* Dijkstra

