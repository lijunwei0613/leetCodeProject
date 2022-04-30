//
// Created by a3412 on 2022/4/4.
//

#include <map>
#include <string>
#include <thread>
#include <list>
#include <mutex>
#include <iostream>

using namespace std;

class MyCAS  //����һ��������  ����ͨ�����������ܶ���
{
private:    //���캯��˽�л�
    MyCAS() {

    }

private:
    static MyCAS *m_instance;   //��̬��Ա������ֻ��MyCAS���������ָ�룻

public:
    static MyCAS *GetInstance() {  //����һ����̬��Ա����
        if (m_instance == nullptr) {
            m_instance = new MyCAS();  //����һ������
            static CGarhuishou cl;  //��������һֱ������������������˳��������̬����һ�����ö���������������ص��Ǿ�̬�������������ڣ�
        }
        return m_instance;
    }

    class CGarhuishou //��������-�����÷��������ͷŶ�����������
    {
    public:
        ~CGarhuishou() {  //�������������
            if (MyCAS::m_instance) {  //���new��������ִ��delete;
                delete MyCAS::m_instance;
                MyCAS::m_instance = nullptr;
            }

        }
    };


    void func() {
        cout << "����" << endl;
    }

};

//��̬������ʼ��
MyCAS *MyCAS::m_instance = nullptr;


//�߳���ں���
void mythread() {
    cout << "�ҵ��߳̿�ʼִ����" << endl;
    MyCAS *p_a = MyCAS::GetInstance();  //����ͨ·���������߳�ͬʱִ�����һ�������������⣺�ڵ���GetInstance()�����������߳�ͬʱ��ʼ��ʼִ���̺߳�����������һ���߳�ִ�н�ҪGetInstance()���������л����߳�2ִ��
    cout << "�ҵ��߳�ִ�н�����" << endl;

}


int main() {
    //һ�����ģʽ: ����д����������ά�����㣬�ӹ��Ķ��鷳��
    //���캯��˽�л�
    //����:��Ŀ�У���ĳ������ĳд������࣬���ڸ���Ķ���ֻ�ܴ���һ����
    //�������ģʽ����������������������
    //main�У������߳��У������������߳�֮ǰ���Ͱѵ��������GetInstance�����Ѹó�ʼ�������ݽ��г�ʼ����
    //��Ҫ�Լ������̣߳��������̣߳���������MyCAS���������Ķ�������������
    //��������GetInstanche()Ҫ���⣻

//    MyCAS *p_a = MyCAS::GetInstance();   //����һ�����󣬷��ظ��ࣨMyCAS�������ָ�룻
//    p_a->func();//�������ڵ���ͨ��Ա�������ӿں����������ļ��е����ݽ���װ�أ����е����ݾͱ��ֻ�������ݣ���������Ϳ��Զ����ݽ��д���
//    MyCAS::GetInstance()->func();  //Ҳ����ͨ�����ַ�ʽ���������ڵ���ͨ��Ա������װ�����ݣ�

    std::thread myobj1(mythread);
    std::thread myobj2(mythread);
    myobj1.join();
    myobj2.join();


    return 0;
}
