# 二分查找模版

---

## 模版一

> 模板 #1 用于查找可以通过*访问数组中的单个索引*来确定的元素或条件。

```cpp
// 寻找一个数，基本二分查找
int binarySearch(vector<int>& nums, int target){
  if(nums.size() == 0)
    return -1;

  int left = 0;
  int right = nums.size() - 1;  // 注意
  while(left <= right){  // 注意
    // Prevent (left + right) overflow
    int mid = left + (right - left) / 2;
    if(nums[mid] == target){ return mid; }
    else if(nums[mid] < target) { left = mid + 1; }  // 注意
    else { right = mid - 1; }  // 注意
  }

  // End Condition: left > right
  return -1;
}
```

**关键属性**

> - 二分查找的最基础和最基本的形式。
> - 查找条件可以在不与元素的两侧进行比较的情况下确定（或使用它周围的特定元素）。
> - 不需要后处理，因为每一步中，你都在检查是否找到了元素。如果到达末尾，则知道未找到该元素。

---

## 模版二

> 模板 #2 是二分查找的高级模板。它用于查找需要*访问数组中当前索引及其直接右邻居索引*的元素或条件。

```cpp
// 寻找左侧边界的二分查找法
int binarySearch(vector<int>& nums, int target){
  if(nums.size() == 0)
    return -1;

  int left = 0;
  int right = nums.size();  // 注意
  while(left < right){  // 注意
    // Prevent (left + right) overflow
    int mid = left + (right - left) / 2;
    if(nums[mid] == target){ return mid; }
    else if(nums[mid] < target) { left = mid + 1; }
    else { right = mid; }
  }

  // Post-processing:
  // End Condition: left == right
  if(left != nums.size() && nums[left] == target) return left;
  return -1;
}
```

**关键属性**

> - 一种实现二分查找的高级方法。
> - 查找条件需要访问元素的直接右邻居。
> - 使用元素的右邻居来确定是否满足条件，并决定是向左还是向右。
> - 保证查找空间在每一步中至少有 2 个元素。
> - 需要进行后处理。 当你剩下 1 个元素时，循环 / 递归结束。 需要评估剩余元素是否符合条件。

---

## 模版三

> 模板 #3 是二分查找的另一种独特形式。 它用于搜索需要*访问当前索引及其在数组中的直接左右邻居索引*的元素或条件。

```cpp
int binarySearch(vector<int>& nums, int target){
    if (nums.size() == 0)
        return -1;

    int left = 0, right = nums.size() - 1;
    while (left + 1 < right){
        // Prevent (left + right) overflow
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            left = mid;
        } else {
            right = mid;
        }
    }

    // Post-processing:
    // End Condition: left + 1 == right
    if(nums[left] == target) return left;
    if(nums[right] == target) return right;
    return -1;
}
```

**关键属性**

> - 实现二分查找的另一种方法。
> - 搜索条件需要访问元素的直接左右邻居。
> - 使用元素的邻居来确定它是向右还是向左。
> - 保证查找空间在每个步骤中至少有 3 个元素。
> - 需要进行后处理。 当剩下 2 个元素时，循环 / 递归结束。 需要评估其余元素是否符合条件。

---

[二分查找算法细节详解](https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/solution/er-fen-cha-zhao-suan-fa-xi-jie-xiang-jie-by-labula)

