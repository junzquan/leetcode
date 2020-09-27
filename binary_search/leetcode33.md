# [33. 搜索旋转排序数组](https://leetcode-cn.com/problems/search-in-rotated-sorted-array/)

- 二分法，中心点两侧必有一侧是有序的

  ```cpp
  class Solution {
  public:
      int search(vector<int>& nums, int target) {
          int lo = 0, hi = nums.size() - 1;
          while (lo <= hi)
          {
              int mid = lo + (hi - lo) / 2;
              if (nums[mid] == target) return mid;
              if (nums[mid] < nums[hi])
              {
                  if (nums[mid] < target && nums[hi] >= target)
                      lo = mid + 1;
                  else
                      hi = mid - 1;
              }
              else
              {
                  if (nums[mid] > target && nums[lo] <= target)
                      hi = mid - 1;
                  else
                      lo = mid + 1;
              }
          }
          return -1;
      }
  };
  ```

  