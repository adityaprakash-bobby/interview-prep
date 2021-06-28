#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int size = height.size();
        int ptr1 = 0, ptr2 = size - 1;
        int area = (ptr2-ptr1) * min(height[ptr1], height[ptr2]);

        while (ptr1 != ptr2) {
            area = max(area, (ptr2-ptr1) * min(height[ptr1], height[ptr2]));

            if (height[ptr1] < height[ptr2]) {
                ptr1++;
            } else if (height[ptr1] > height[ptr2]) {
                ptr2--;
            } else {
                if (height[ptr1+1] > height[ptr2-1]) {
                    ptr1++;
                } else {
                    ptr2--;
                }
            }
        }

        return area;
    }
};