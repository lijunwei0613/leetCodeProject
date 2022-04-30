//
// Created by a3412 on 2022/4/23.
//

#include <iostream>
#include <vector>


// ɾ�������е���val��Ԫ�أ�����������ĳ���һ��С�ڵ���;�������ĳ���->���������ֱ��д�����������ϡ�
// ʹ��˫ָ�룺��ָ��rightָ��ǰҪ�����Ԫ�أ���ָ��leftָ����һ����Ҫ��ֵ��λ�á�
/*
    *�����ָ��ָ���Ԫ�ز�����val, ��һ������������һ��Ԫ�أ��ͽ���ָ��ָ���Ԫ�ظ��Ƶ���ָ��λ�ã�Ȼ������ָ��ͬʱ���ƣ�
    *�����ָ��ָ���Ԫ�ص���val, ������������������ʱ��ָ�벻������ָ������һλ��
 */
// ����[0, left)�е�Ԫ�ض�������val,������ָ����������������Ժ�left��ֵ�����������ĳ��ȣ������ǣ�����������û��Ԫ�ص���val��, ����ָ�������������һ�Σ�

class Solution {
public:
    int removeElement(std::vector<int> &nums, int val) {
        int n = nums.size();
        int left = 0;
        for (int right = 0; right < n; ++right) {
            if (nums[right] != val) {
                nums[left] = nums[right];
                left++;
            }
        }
        return left;
    }
};


/*
 * �����ָ��leftָ���Ԫ�ص���val, ��ʱ����ָ��rightָ���Ԫ�ظ��Ƶ���ָ��leftλ�ã�Ȼ����ָ��right����һλ�������ֵ������Ԫ��ǡ��Ҳ����val,
 * ���Լ�������ָ��rightָ���Ԫ�ص�ֵ��ֵ��������ָ��leftָ��ĵ���val��Ԫ�ص�λ�ü��������ǣ���ֱ����ָ��ָ���Ԫ��ֵ������valΪֹ��
 * ������ָ���غϵ�ʱ������ָ��������������е�Ԫ�أ�
 * ��������Ҫ������Ԫ�ص��ظ���ֵ������
*/
class Slution01 {
public:
    int removeElement01(std::vector<int> &nums, int val) {
        int left = 0, right = nums.size();
        while (left < right) {
            if (nums[left] == val) {
                //�����ָ��leftָ���Ԫ�ص���val, ����ָ��rightָ���Ԫ�ظ��Ƶ���ָ��leftλ�ã�Ȼ����ָ�����ƶ�һλ��
                nums[left] = nums[right - 1]; //����Ԫ�صĸ����������鳤��-1��
                right--;
            } else {
                left++;
            }
        }
        return left;
    }

};

//

int main() {
//ģ��qiaohong������ֵ�����е����鴫�뷽����vector��ֵ��
    Solution p1;
    std::vector<int> vec;
    vec.push_back(3);
    vec.push_back(2);
    vec.push_back(2);
    vec.push_back(3);

    int a[] = {3, 2, 2,3};
    std::vector<int> vect(a, a + sizeof(a) / sizeof (int));
    Solution p2;
    std::cout << "p2��" << p2.removeElement(vect, 3) << std::endl;



    int len = vec.size();
    std::cout << "�Ƴ�ǰvec�ĳ��ȣ�" << len << std::endl;

    p1.removeElement(vec, 3);

    for (int i: vec) {
        std::cout << "vec[i]: " << i << std::endl;
    }
    std::cout << "�Ƴ���vec�ĳ��ȣ�" << vec.size() << std::endl;

    return 0;
}