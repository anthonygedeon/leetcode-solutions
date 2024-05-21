#include <cassert>
#include <map>
#include <string>

class Solution {
private:
    std::map<char, int> symbols {
        { 'I', 1 },
        { 'V', 5 },
        { 'X', 10 },
        { 'L', 50 },
        { 'C', 100 },
        { 'D', 500 },
        { 'M', 1000 }
    };

public:
    int romanToInt(std::string s) {
        int number = 0;

        for (std::size_t i = 0; i < s.length(); i++) {
			auto cur  = s[i];
			auto peek = s[i + 1];

			switch(cur) {
				case 'I':
					if (peek == 'V' || peek == 'X') {
						number += symbols[peek] - symbols[cur];
						i++;
					} else {
						number += symbols[cur];
					}
					break;
				case 'X':
					if (peek == 'L' || peek == 'C') {
						number += symbols[peek] - symbols[cur];
						i++;
					} else {
						number += symbols[cur];
					}
					break;
				case 'C':
					if (peek == 'D' || peek == 'M') {
						number += symbols[peek] - symbols[cur];
						i++;
					} else {
						number += symbols[cur];
					}
					break;
				default:
					number += symbols[cur];
					break;
			}
        }

		return number;
    }
};

int main() {
	Solution s = Solution();
	assert(s.romanToInt("III") == 3);
	assert(s.romanToInt("LVIII") == 58);
	assert(s.romanToInt("MCMXCIV") == 1994);
	return 0;
}
