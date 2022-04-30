//
// Created by a3412 on 2022/4/26.
//
#include <iostream>
#include <vector>

using namespace std;
//����s��t�����ַ����������Ƿֱ����뵽�հ׵��ı��༭���У������������򷵻�true;
//ƥ��ʹ��ջ

//ʱ�临�Ӷ�O(n+m) �ռ临�Ӷ�O(n+m) nΪS�ĳ��ȣ� mΪT�ĳ��ȣ�
class Slution {
public:
    string getString(const string &S) {
        string s;
        for (int i = 0; i < S.size(); i++) {
            if (S[i] != '#') s += S[i];
            else if (!s.empty()) {
                s.pop_back();
            }
        }
        return s;
    }

public:
    bool backspaceCompare(string S, string T) {  //���ظ����߼�����ɺ���
        return getString(S) == getString(T);
    }
};

//�Ż���Ŀռ临�Ӷ�O(1)�Ŀռ临�Ӷ�
//ͬʱ�Ӻ���ǰ����S��T��i��j��S��T��ĩβ���� ��¼#������ģ�������Ĳ��������#����Ϳ�ʼ�Ƚ�S[i]��S[j];
//���S[i]��T[j]����ͬ����false, �����һ��ָ�루i����j�����ߵ��ַ���ͷ��λ�ã�����false;
class Slution01 {
public:
    bool backspaceCompare(string S, string T) {
        int sSkipNum = 0;  //��¼S��#����
        int tSkipNum = 0;  //��¼T��#����
        int i = S.size() - 1;
        int j = T.size() - 1;

        while (1) {
            while (i >= 0) { //�Ӻ���ǰ����S��#;
                if (S[i] == '#') sSkipNum++;
                else {
                    if (sSkipNum > 0) sSkipNum--;
                    else break;
                }
                i--;
            }
            while (j >= 0) {   //�Ӻ���ǰ����T��#;
                if (T[j] == '#') tSkipNum++;
                else {
                    if (tSkipNum > 0) tSkipNum--;
                    else break;
                }
                j--;
            }
            if (i < 0 || j < 0) break;  //S����T������ͷ��
            if (S[i] != T[j]) return false;
            i--;
            j--;
        }
        // ˵��S��Tͬʱ�������
        if (i == -1 && j == -1) return true;
        return false;
    }
};
