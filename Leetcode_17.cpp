/*
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
Example 1:

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
Example 2:

Input: digits = ""
Output: []
Example 3:

Input: digits = "2"
Output: ["a","b","c"]

*/

#include <iostream>
#include <vector>
#include <string>

std::vector<std::string> letterCombinationsHelper(const std::string& digits, const std::vector<std::string>& digitToLetters, int index) {
    if (index == digits.length()) {
        return {""};
    }

    int digit = digits[index] - '0';
    const std::string& letters = digitToLetters[digit];
    
    std::vector<std::string> combinations;
    for (char letter : letters) {
        std::vector<std::string> suffixCombinations = letterCombinationsHelper(digits, digitToLetters, index + 1);
        for (const std::string& suffix : suffixCombinations) {
            combinations.push_back(letter + suffix);
        }
    }
    
    return combinations;
}

std::vector<std::string> letterCombinations(const std::string& digits) {
    if (digits.empty()) {
        return {};
    }

    std::vector<std::string> digitToLetters = {
        "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
    };
    
    return letterCombinationsHelper(digits, digitToLetters, 0);
}

int main() {
    std::string digits = "23";
    std::vector<std::string> result = letterCombinations(digits);

    for (const std::string& combination : result) {
        std::cout << combination << " ";
    }

    return 0;
}
