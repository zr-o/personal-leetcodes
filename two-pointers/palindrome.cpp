#include <cctype>
#include <iostream>
#include <string_view>

class Solution {
public:
  static bool isPalindrome(std::string_view s) {

    auto startIdx{0uz};
    auto endIdx{s.size() - 1uz};

    while (startIdx < endIdx) {
      if (!std::isalnum(static_cast<unsigned char>(s[startIdx]))) {
        startIdx++;
        continue;
      }

      if (!std::isalnum(static_cast<unsigned char>(s[endIdx]))) {
        endIdx--;
        continue;
      }

      if (std::tolower(static_cast<unsigned char>(s[endIdx])) !=
          std::tolower(static_cast<unsigned char>(s[startIdx])))
        return false;

      startIdx++;
      endIdx--;
    }

    return true;
  }
};

int main() {
  std::cout << std::boolalpha;

  std::cout << Solution::isPalindrome("aba") << " Expected: true\n";
  std::cout << Solution::isPalindrome("abc") << " Expected: false\n";
  std::cout << Solution::isPalindrome("racecar") << " Expected: true\n";
  std::cout << Solution::isPalindrome("hello") << " Expected: false\n";
  std::cout << Solution::isPalindrome("RaceCar") << " Expected: true\n";
  std::cout << Solution::isPalindrome("Aa") << " Expected: true\n";
  std::cout << Solution::isPalindrome("Ab") << " Expected: false\n";

  std::cout << Solution::isPalindrome("A man, a plan, a canal: Panama")
            << " Expected: true\n";
  std::cout << Solution::isPalindrome("race a car") << " Expected: false\n";
  std::cout << Solution::isPalindrome("Was it a car or a cat I saw?")
            << " Expected: true\n";
  std::cout << Solution::isPalindrome("No 'x' in Nixon") << " Expected: true\n";

  std::cout << Solution::isPalindrome("12321") << " Expected: true\n";
  std::cout << Solution::isPalindrome("12345") << " Expected: false\n";
  std::cout << Solution::isPalindrome("1a2a1") << " Expected: true\n";
  std::cout << Solution::isPalindrome("0P") << " Expected: false\n";

  std::cout << Solution::isPalindrome("a") << " Expected: true\n";
  std::cout << Solution::isPalindrome(" ") << " Expected: true\n";
  std::cout << Solution::isPalindrome("!!!") << " Expected: true\n";
  std::cout << Solution::isPalindrome("a.") << " Expected: true\n";
  std::cout << Solution::isPalindrome(".a") << " Expected: true\n";

  std::cout << Solution::isPalindrome("a!b") << " Expected: false\n";
  std::cout << Solution::isPalindrome("a!a") << " Expected: true\n";
  std::cout << Solution::isPalindrome("a!!a") << " Expected: true\n";
  std::cout << Solution::isPalindrome("a!!b") << " Expected: false\n";

  std::cout << Solution::isPalindrome("ab") << " Expected: false\n";
  std::cout << Solution::isPalindrome("a b a") << " Expected: true\n";
  std::cout << Solution::isPalindrome("a b c") << " Expected: false\n";
  std::cout << Solution::isPalindrome("....a....") << " Expected: true\n";
  std::cout << Solution::isPalindrome("1a1") << " Expected: true\n";
  std::cout << Solution::isPalindrome("1a2") << " Expected: false\n";
}
