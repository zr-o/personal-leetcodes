#include <algorithm>
#include <iostream>
#include <span>
#include <vector>

class Solution {
public:
  std::vector<std::vector<int>> threeSum(std::span<int> nums) {
    std::ranges::sort(nums);
    std::vector<std::vector<int>> solutions;

    for (auto i{0uz}; i + 2 < nums.size(); ++i) {
      if (i > 0 && nums[i] == nums[i - 1])
        continue;

      auto left = i + 1;
      auto right = nums.size() - 1;

      while (left < right) {
        const auto sum = nums[i] + nums[left] + nums[right];

        if (sum < 0)
          ++left;
        else if (sum > 0)
          --right;
        else {
          solutions.push_back({nums[i], nums[left], nums[right]});
          ++left;
          --right;

          while (left < right && nums[left] == nums[left - 1])
            ++left;
          while (left < right && nums[right] == nums[right + 1])
            --right;
        }
      }
    }
    return solutions;
  }
};

int main() {
  std::vector<int> nums{-1, 0, 1, 2, -1, -4};

  Solution sol;
  auto results = sol.threeSum(nums);

  for (const auto &triplet : results) {
    for (int n : triplet)
      std::cout << n << ' ';

    std::cout << '\n';
  }
}
