#include <algorithm>
#include <iostream>
#include <span>
#include <vector>

class Solution {
public:
  int maxArea(std::span<const int> heights) {
    auto left{0uz};
    auto right{heights.size() - 1};
    int maxArea{};

    while (left < right) {
      maxArea = std::max(maxArea, std::min(heights[left], heights[right]) *
                                      static_cast<int>(right - left));
      if (heights[left] > heights[right])
        --right;
      else
        ++left;
    }
    return maxArea;
  }
};

int main() {
  Solution solution;
  std::cout << solution.maxArea(std::vector<int>{1, 8, 6, 2, 5, 4, 8, 3, 7})
            << std::endl; // Should be 49
}
