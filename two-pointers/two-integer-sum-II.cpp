#include <expected>
#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
  std::expected<std::vector<int>, std::string> twoSum(std::vector<int> &numbers,
                                                      int target) {
    if (numbers.size() < 2 || numbers.size() > 30000 || target > 1000)
      return std::unexpected{"Not valid constraints"};
    auto startIdx{0uz};
    auto endIdx{numbers.size() - 1uz};

    while (startIdx < endIdx) {
      if (numbers[startIdx] > 1000 || numbers[endIdx] > 1000)
        return std::unexpected{"Not valid constraints"};
      const auto sum = numbers[startIdx] + numbers[endIdx];

      if (sum == target)
        return std::vector<int>{static_cast<int>(startIdx + 1),
                                static_cast<int>(endIdx + 1)};
      else if (sum < target)
        startIdx++;
      else
        endIdx--;
    }

    return std::unexpected{"No valid solution"};
  }
};

int main() {
  Solution s;

  auto a = std::vector<int>{2, 7, 11, 15};
  auto b = std::vector<int>{2, 3, 4};
  auto c = std::vector<int>{-5, -3, 0, 2, 8};

  for (auto [numbers, target] :
       {std::pair{a, 9}, std::pair{b, 6}, std::pair{c, 5}}) {
    auto result = s.twoSum(numbers, target);

    if (result)
      std::cout << (*result)[0] << ", " << (*result)[1] << '\n';
  }
}
