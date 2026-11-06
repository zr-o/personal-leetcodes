#include <algorithm>
#include <iostream>
#include <span>
#include <vector>

class Solution {
public:
  int trap(std::span<const int> heights) {
    auto left = 0uz, right = heights.size() - 1;
    int leftMax = heights[left], rightMax = heights[right];
    int trappedWater{0};

    while (left < right) {
      if (leftMax < rightMax) {
        ++left;
        leftMax = std::max(leftMax, heights[left]);
        trappedWater += leftMax - heights[left];
      } else {
        --right;
        rightMax = std::max(rightMax, heights[right]);
        trappedWater += rightMax - heights[right];
      }
    }
    return trappedWater;
  }
};

int main() {
  Solution sol;
  std::cout << sol.trap(std::vector{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1})
            << "Should equal : " << 6 << '\n';
  std::cout << sol.trap(std::vector{4, 2, 0, 3, 2, 5}) << "Should equal : " << 9
            << '\n';
}
