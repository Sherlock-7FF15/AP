## Easy

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

  