//
// Created by a3412 on 2022/4/24.
//

#include <iostream>
#include <vector>

using namespace std;
/*
 * Ҫ���ǶԸ�������������numsɾ���ظ�Ԫ�أ���ɾ���ظ�Ԫ��֮��ÿ��Ԫ��ֻ����һ�Σ��������µĳ��ȣ���ͨ��ԭ���޸�����ķ�����
 * ͨ��˫ָ�룺�������nums����Ϊ0�������鲻�����κ�Ԫ�أ�����0��
 * �����鳤�ȴ���0ʱ�����������ٰ���һ��Ԫ�أ���ɾ���ظ�Ԫ��֮��Ҳ����ʣ��һ��Ԫ�أ����nums[0]����ԭ״�����±�1��ʼɾ���ظ�Ԫ�أ�
 * ������ָ�����ָ�룬��ָ��������鵽���±�λ�ã���ָ����һ����ͬԪ��Ҫ������±�λ�ã�
 * ��ָ�����1��n-1��ÿ��λ�ã�����ÿ��λ��Ԫ�أ�����nums[right] != nums[right-1],˵��nums[right] ��ֵ��֮ǰ������ͬ����nums[right]��
 * �Ƶ�nums[left], Ȼ��left++ ��ָ����һ��λ��, ��������֮�󣬴� \textit{nums}[0]nums[0] �� \textit{nums}[\textit{slow}-1]nums[slow?1] ��ÿ��Ԫ�ض�����ͬ�Ұ���ԭ�����е�ÿ����ͬ��Ԫ�أ�
 * ����µĳ��ȼ�Ϊ left������ left ����
 */
class Solution {
public:
    // for(vector<int>::iterator it=vec.begin(); it!=vec.end(); it++)
    int removeDuplicates(vector<int> &nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        int fast = 1, slow = 1;
        while (fast < n) {
            if (nums[fast] != nums[fast - 1]) {
                nums[slow] = nums[fast];
                ++slow;
            }
            ++fast;
        }
        return slow;
    }
};
