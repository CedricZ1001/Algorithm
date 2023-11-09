## Two sum

Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

#### Example 1:

- Input: nums = [2,7,11,15], target = 9
- Output: [0,1]
- Explanation: Because nums[0] + nums[1] == 9, return [0, 1].

#### Example 2:

- Input: nums = [3,2,4], target = 6
- Output: [1,2]

#### Example 3:

- Input: nums = [3,3], target = 6
- Output: [0,1]

#### Constraints:

- 2 <= nums.length <= 104
- -109 <= nums[i] <= 109
- -109 <= target <= 109
- Only one valid answer exists.

Follow-up: Can you come up with an algorithm that is less than O(n2) time complexity?

## 两数之和

给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出和为目标值 target 的那两个整数，并返回它们的数组下标。

你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。

你可以按任意顺序返回答案。

#### 示例 1：

- 输入：nums = [2,7,11,15], target = 9
- 输出：[0,1]
- 解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。

#### 示例 2：

- 输入：nums = [3,2,4], target = 6
- 输出：[1,2]

#### 示例 3：

- 输入：nums = [3,3], target = 6
- 输出：[0,1]

#### 提示：

- 2 <= nums.length <= 104
- -109 <= nums[i] <= 109
- -109 <= target <= 109
- 只会存在一个有效答案

进阶：你可以想出一个时间复杂度小于 O(n2) 的算法吗？
