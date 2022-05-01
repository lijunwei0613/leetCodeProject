//
// Created by a3412 on 2022/4/30.
//

//#include <string>
#include <iostream>
//#include <algorithm>
#include <vector>
//#include <functional>
//#include <numeric>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
        //��Ž����ļ��ϣ����Ҳ��ù�ϣ������Զ�ȥ��
        unordered_set<int> result_set;
        //��nums1�е�Ԫ�ؿ�������num_set�������У�
        unordered_set<int> nums_set(nums1.begin(), nums1.end());
        for (int num: nums2) {   //�ȼ��ڣ� for(int num = 0; num < nums2.size(); num++
            //����nums2��ָ��Ԫ�أ�����ͬԪ��2������ָ��Ԫ�صĵ�������ֱ�����ؽ���������֮����ֹ������
            if (nums_set.find(num) != nums_set.end()) {
                result_set.insert(num);
                cout << "yes, it is intersection!" << endl;
                cout << *(nums_set.find(num)) << endl;
            } else{
                cout << "no intersection" << endl;
            }
        }

        return vector<int>(result_set.begin(), result_set.end());
    }
};

int main() {
    vector<int> num1 = {1, 2, 2, 1};
    vector<int> num2 = {2, 2};

    Solution p1;
    p1.intersection(num1, num2);
}