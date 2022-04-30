//
// Created by a3412 on 2022/4/25.
//

/*
 * ����һ������nums, ��дһ������������0�ƶ��������ĩβ��ͬʱ���ַ���Ԫ�ص����˳��
 */

#include <iostream>
#include <vector>

/*
 * ʹ��˫ָ�룬��ָ��ָ��ǰ�Ѿ�����õ����е�β������ָ��ָ����������е�ͷ��
 *
 */

using namespace std;

class Solution {
public:
    void moveZero(vector<int> &nums) {
        int left = 0, right = 0, n = nums.size();
        while (right < n) {
            if (nums[right]) {
                swap(nums[left], nums[right]);
                left++;
            }
            right++;
        }
    }
};

int main() {
    Solution p1;
    int a[] = {0, 1, 0, 3, 12};
    std::vector<int> vect(a, a + sizeof(a) / sizeof(int));

    p1.moveZero(vect);
    for (int i = 0; i < vect.size(); ++i) {
        cout << a[i]<< endl;
    }
}