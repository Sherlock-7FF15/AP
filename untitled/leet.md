## Leetcode

* 两数和

~~~ python
class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        result = ListNode(0)
        result_tail = result
        carry = 0
                
        while l1 or l2 or carry:            
            val1  = (l1.val if l1 else 0)
            val2  = (l2.val if l2 else 0)
            carry, out = divmod(val1+val2 + carry, 10)    
                      
            result_tail.next = ListNode(out)
            result_tail = result_tail.next                      
            
            l1 = (l1.next if l1 else None)
            l2 = (l2.next if l2 else None)
               
        return result.next
~~~

* 最大面积

~~~python
class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        if len(height) < 2:
            return 0
        maxVol = 0
        i = 0
        j = len(height)-1
        while i < j:
            maxVol = max(maxVol, min(height[i], height[j])*(j-i))
            if height[i] < height[j]:
                i = i+1
            else:
                j = j-1
        return maxVol
~~~

* 三。。。N元素之和问题：

  ~~~python
  class Solution(object):
      def threeSum(self, nums):
          """
          :type nums: List[int]
          :rtype: List[List[int]]
          """
          nums.sort()
          reList = []
          print(nums)
          for i in range(len(nums)):
              if(nums[i] > 0):
                  break
              j = i+1
              k = len(nums)-1
              if i != 0 and nums[i] == nums[i-1]:
                  continue
              while j < k:
                  if -nums[i] == nums[j] + nums[k]:
                      print(i,j,k)
                      reList.append([nums[i], nums[j], nums[k]])
                      j = j+1
                      k = k-1
                      while j < k and nums[j] == nums[j-1]:
                          j = j+1
                      while j < k and nums[k] == nums[k+1]:
                          k = k-1
                  if -nums[i] > nums[j] + nums[k]: # 如果这两个条件放在等于前就错
                      j = j+1
                  if -nums[i] < nums[j] + nums[k]:
                      k = k-1
          return reList
  ~~~

  `注意！判断等式的位置非常重要！！！！如果while的判断条件做了变动后一定要continue或者是把变动放在最后。`

  16：

  ~~~python
  class Solution(object):
      def threeSumClosest(self, nums, target):
          """
          :type nums: List[int]
          :type target: int
          :rtype: int
          """
          nums.sort()
          thSum = float('inf')
          print(nums)
          for i in range(len(nums)):
              j = i+1
              k = len(nums)-1
              while j < k:
                  if nums[i] + nums[j] + nums[k] == target:
                      return nums[i] + nums[j] + nums[k]
                  if fabs(target-(nums[i] + nums[j] + nums[k])) < fabs(target-thSum):
                          thSum = nums[i] + nums[j] + nums[k]
                  if nums[i] + nums[j] + nums[k] < target:
                      j = j+1
                      continue
                  if nums[i] + nums[j] + nums[k] > target:
                      k = k-1
                      continue
          return thSum
  ~~~

  递归匹配以及字符串

  ~~~python
  class Solution(object):
      def letterCombinations(self, digits):
          """
          :type digits: str
          :rtype: List[str]
          """
          if len(digits) == 0:
              return []
          digits = list(digits)
          digList = []
          ret = []
          for item in digits:
              digList.append(matchNum(item))
          print(digList)
          search(digList, ret, '', 0)
          return ret
      
  def matchNum(dig):
      mapDig = {}
      asc = 97
      for i in range(2, 7):
          mapDig[str(i)] = [chr(asc), chr(asc+1), chr(asc+2)]
          asc = asc+3
      mapDig['7'] = ['p', 'q', 'r', 's']
      mapDig['8'] = ['t', 'u', 'v']
      mapDig['9'] = ['w', 'x', 'y', 'z']
      return mapDig[dig]
      
  def search(digList, ret, letter, i):
      if i == len(digList):
          ret.append(letter)
          return
      for item in digList[i]:
          letter = letter+item
          search(digList, ret, letter, i+1)
          letter = list(letter)
          letter.remove(item)
          letter = ''.join(letter)
  ~~~

  20:

  ~~~python
  class Solution(object):
      def isValid(self, s):
          """
          :type s: str
          :rtype: bool
          """
          s = list(s)
          stack = []
          dic = {']' = '[', '}' = '{', ')' = '('}
          while len(s) != 0:
              cha = s.pop(0)
              stack.append(cha)
              print(s, stack)
              if cha == ']' or cha == '}' or cha == ')':
                  a = stack.pop()
                  if len(stack) == 0:
                      return False
                  else:
                      b = stack.pop()
                      if b+a != '()' and  b+a !='[]' and b+a != '{}':
                          return False
          if len(stack) != 0:
              return False
          else:
              return True
              
  ~~~

  ~~~python
  # faster
  class Solution(object):
      def isValid(self, s):
          """
          :type s: str
          :rtype: bool
          """
          s = list(s)
          stack = []
          dic = {']': '[', '}': '{', ')': '('}
          while len(s) != 0:
              cha = s.pop(0)
              if cha == '[' or cha == '{' or cha == '(':
                  stack.append(cha)
              else:
                  if len(stack) == 0:
                      return False
                  a = dic[cha]
                  b = stack.pop()
                  if a != b:
                      return False
          if len(stack) != 0:
              return False
          else:
              return True
  ~~~

* 链表合并

  ~~~python
  # Definition for singly-linked list.
  # class ListNode(object):
  #     def __init__(self, val=0, next=None):
  #         self.val = val
  #         self.next = next
  class Solution(object):
      def mergeTwoLists(self, list1, list2):
          """
          :type list1: Optional[ListNode]
          :type list2: Optional[ListNode]
          :rtype: Optional[ListNode]
          """
          if list1 == None:
              return list2
          if list2 == None:
              return list1
          head = ListNode(None)
          cur = head
          while list1 != None and list2 != None:
              if list1.val < list2.val:
                  cur.next = list1
                  list1 = list1.next
              else:
                  cur.next = list2
                  list2 = list2.next
              cur = cur.next
          if list1 is None:
              cur.next = list2
          if list2 is None:
              cur.next = list1
          return head.next
                  
  ~~~

* 链表中结点的交换

  ~~~python
  # Definition for singly-linked list.
  # class ListNode(object):
  #     def __init__(self, val=0, next=None):
  #         self.val = val
  #         self.next = next
  class Solution(object):
      def swapPairs(self, head):
          """
          :type head: ListNode
          :rtype: ListNode
          """
          if head is None:
              return None
          if head.next is None:
              return head
          # 交换头两个结点
          cur1 = head
          cur2 = cur1.next
          nextN = cur2.next
          cur1.next = nextN
          cur2.next = cur1
          head = cur2
          temp = cur1
          cur1 = cur2
          cur2 = temp
          # 用三个指针完成结点的交换。交换过程中cur1指向两个结点的前一个结点，cur2指向第一个，nextN指		# 向第二个
          while cur1 is not None and cur2 is not None:
              if cur2.next is not None:
                  if cur2.next.next is not None:
                      cur2 = cur2.next
                      cur1 = cur1.next
                      nextN = cur2.next
                      cur1.next = nextN
                      cur2.next = nextN.next
                      nextN.next = cur2
                      cur1 = cur1.next
                  else:
                      break
              else:
                  break
          return head
  # 反转第K组
  # Definition for singly-linked list.
  # class ListNode(object):
  #     def __init__(self, val=0, next=None):
  #         self.val = val
  #         self.next = next
  class Solution(object):
      def reverseKGroup(self, head, k):
          """
          :type head: ListNode
          :type k: int
          :rtype: ListNode
          """
          if head is None:
              return head
          if head.next is None:
              return head
          cur1 = head.next
          cur2 = cur1.next
          if cur2 is None:
              head.next = None
              cur1.next = head
              return cur1
          nextN = cur2.next
          k = k-1
          while k > 0:
              if cur1 is None or cur2 is None:
                  return head
              if k == 1:
                  nextN = cur2.next
                  cur2.next = nextN.next
                  cur1.next = nextN
                  nextN.next = cur2
                  print(cur1.val, cur2.val)
                  return head
              else:
                  cur1 = cur2.next
                  cur2 = cur1.next
                  k = k-1
          return head
              
              
  ~~~

  ###思考！head = cur2 cur2 = cur2.next 则head 的值为？以及a=1 b = a a=2则b为？两者的区别是什么？



25 链表反转k个一组的数

~~~python
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def reverseKGroup(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        if head is None or head.next is None or k == 1:
            return head
        pre = None
        cur1 = head
        cur2 = head
        while cur2 is not None and cur1 is not None:
            pre, cur1, cur2 = movePoint(pre, cur1, cur2, head, k)
            if cur1 == None or cur2 == None:
                return head
            if cur2 is not None:
                pre, cur1, cur2, head = swap(pre, cur1, cur2, head, k)
            else:
                return head
        return head
            
def movePoint(pre, cur1, cur2, head, k):
    if pre == None and cur2 == head:
        for i in range(k-1):
            if cur2 is not None:
                cur2 = cur2.next
            else:
                return None, None, None
        return pre, cur1, cur2
    if pre == None and cur2 != head:
        for i in range(k):
            if cur2 is not None and cur1 is not None:
                cur2 = cur2.next
                cur1 = cur1.next
            else:
                return None, None, None
        pre = head
        for i in range(k-1):
            pre = pre.next
        return pre, cur1, cur2
    for i in range(k):
        if cur2 is not None and cur1 is not None:
            cur2 = cur2.next
            cur1 = cur1.next
            pre = pre.next
        else:
            return None, None, None
    return pre, cur1, cur2

def swap(pre, cur1, cur2, head, k):
    if pre is None:
        while cur2 != cur1:
            nextN = cur1.next
            cur1.next = cur2.next
            cur2.next = cur1
            cur1 = nextN
        for i in range(k-1):
            cur2 = cur2.next
        head = cur1
        return pre, cur1, cur2, head
    while cur2 != cur1:
        nextN = cur1.next
        pre.next = nextN
        cur1.next = cur2.next
        cur2.next = cur1
        cur1 = nextN
    for i in range(k-1):
        cur2 = cur2.next
    return pre, cur1, cur2, head
    
~~~

* 86链表国旗问题[Partition Array According to Given Pivot](https://leetcode.com/problems/partition-array-according-to-given-pivot/) 

  ~~~python
  # Definition for singly-linked list.
  # class ListNode(object):
  #     def __init__(self, val=0, next=None):
  #         self.val = val
  #         self.next = next
  class Solution(object):
      def partition(self, head, x):
          """
          :type head: ListNode
          :type x: int
          :rtype: ListNode
          """
          node = ListNode(x)
          sortH = node
          pre = None
          sortr = node
          cur = head
          while cur is not None:
              nextN = cur.next
              if cur.val >= node.val:
                  sortr.next = cur
                  cur.next = None
                  sortr = cur
                  cur = nextN
                  continue
              if cur.val < node.val:
                  if pre == None:
                      cur.next = node
                      pre = cur
                      sortH = cur
                      cur = nextN
                  else:
                      cur.next = node
                      pre.next = cur
                      pre = cur
                      cur = nextN
                  continue
              # 如果等于放在一起
              # if cur.val == node.val:
              #     if sortr == node:
              #         node.next = cur
              #         cur.next = None
              #         sortr = cur
              #         cur = nextN
              #     else:
              #         cur.next = node.next
              #         node.next = cur
              #         cur = nextN
          if pre is not None:
              pre.next = node.next
          else:
              return node.next
          return sortH
              
  ~~~

  