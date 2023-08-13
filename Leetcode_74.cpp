/*
You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.

*/

#include <iostream>
#include <vector>

bool searchMatrix(const std::vector<std::vector<int>>& matrix, int target) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    
    int left = 0;
    int right = rows * cols - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        int midValue = matrix[mid / cols][mid % cols]; // Convert 1D index to 2D indices
        
        if (midValue == target) {
            return true;
        } else if (midValue < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return false;
}

int main() {
    std::vector<std::vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };

    int target1 = 3;
    std::cout << "Target 3: " << (searchMatrix(matrix, target1) ? "true" : "false") << std::endl;

    int target2 = 13;
    std::cout << "Target 13: " << (searchMatrix(matrix, target2) ? "true" : "false") << std::endl;

    return 0;
}
