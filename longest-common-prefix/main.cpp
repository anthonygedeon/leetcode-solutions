#include <cassert>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
		string longest_prefix = "";
        string prefix = "";

        size_t i = 0;
        size_t j = 0;
        while (true) {
            while (true) {
                string letter{strs[i % strs.size()][j]};

                if (prefix != letter) {
                    prefix += letter;
                } else if (i == strs.size() - 1) {
                    i = 0;
                    break;
                }

                i++;

            }

            j++;

            longest_prefix.append(prefix);

            prefix = "";
        }

        return longest_prefix;
    }
};

int main() {
	Solution s = Solution();

	vector<string> strs { { "flower","flow","flight"} };
	assert(s.longestCommonPrefix(strs) == "fl");
	strs = {{ "dog","racecar","car" }};
	assert(s.longestCommonPrefix(strs) == "");

	return 0;
}
