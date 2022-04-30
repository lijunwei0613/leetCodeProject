//
// Created by a3412 on 2022/4/2.
//

#include <map>
#include <string>
#include <thread>
#include <list>
#include <mutex>
#include <iostream>
#include <vector>
#include <list>

using namespace std;

void myprint(int inum) {
    cout << "�߳̿�ʼ���̱߳��" << endl;

    cout << "�߳̽������̱߳��" << endl;
}

class A {
public:
    //���յ�����Ϣ�뵽һ�����е��߳�
    void inMsgRecvQueue() {
        for (int i = 0; i < 10000; ++i) {
            cout << "inMSg��Ա�������ã�����һ��Ԫ��" << i << endl;
            my_mutex.lock();  //����ִ�������߳���1  �߳���ִ��ȡ����ϵͳ��������䣬������ִ���߳���1���߳���2��ס����ִ���߳���1�е�д���������߳���1�еĲ���ִ����֮����ִ���߳���2�еĶ���������֮�߳���2��ִ�ж�����ʱ���߳�1�еĶ���ס����2��ִ������ִ��1.
            msgRecvQueue.push_back(i);  //��i���뵽��Ϣ�����У�
            my_mutex.unlock();
        }
    }

//��������������ݣ�����ɵ�����������������ͽ�����
    bool outMslLULProc(int &command) {

        my_mutex.lock();//����ִ�������߳���2
        if (!msgRecvQueue.empty()) {
            //��Ϣ��Ϊ��
            command = msgRecvQueue.front();  //���ص�һ��Ԫ�أ��������Ԫ���Ƿ����
            msgRecvQueue.pop_front();//�Ƴ���һ��Ԫ�ص��ǲ����أ�
            my_mutex.unlock();
            return true;
        }

        my_mutex.unlock();
        return false;
    }

    //һ���߳̽����ݴ���������Ϣ���У���ȡ����
    void outRecvQueue() {

        int command = 0;
        for (int i = 0; i < 10000; ++i) {
            bool result = outMslLULProc(command);
            if (result == true) {
                cout << "outRecvQueue()ִ��, ȡ��һ��Ԫ��" << command << endl;
                //���ݲ�������
            } else {
                cout << "outRecvQueue()ִ�У�Ŀǰ��������Ϣ����Ϊ��" << i << endl;
            }
        }
    }


private:
    std::list<int> msgRecvQueue;  //����   �������ݣ���ס
    std::mutex my_mutex;  //������һ���������ĳ�Ա������
};


int main() {
    //���߳�ִ��˳�����ҵģ�������ϵͳ�ڲ����̵߳����е��Ȼ����йأ�
    //���̵߳ȴ��������߳����н�����������߳̽������Ƚ��ȶ���
    //��thread������뵽�������������ȥ���thread�������飬���������̲߳��Դ����߳̽��й���

    //�������ݹ����������
    //��2.1��ֻ������

    //�����������ݵı��� vector ��list ����list����Ƶ���İ�˳������ɾ������ʱЧ�ʸߣ�vector��������Ĳ����ɾ������Ч�ʸߡ�
    //�������������̵߳ĳ������߳�1��ִ����д�Ĳ������߳�2��ִ���˶��Ĳ�������ϵͳ�᲻�����л������ģ��߳�1��2����ʱִ�У���Ϳ��ܴ����߳�1����д�Ĺ������߳�2�Ϳ�ʼ���ˣ���ɳ���ִ���쳣��

    //�������÷�
    //c++������̱߳��������������롰��������  �������Ǹ�����󣬿����Ϊ��������߳���lock()��Ա������������


    //�������÷� lock(), unlock();
    //�������裺��lock(), �����������ݣ� unlock();  �ɶ�ʹ�ã�

    //std::lock_guard<std::mutex> sbguard(my_mutex, std::adopt_lock);   //adopt_lock������ã�
    //std::adopt_lock����ʾ����������Ѿ���lock�ˣ�����Ҫ�ѻ�������ǰlock������ᱨ�쳣��
    //std::adopt_lock��ǵ�Ч���ǡ�������÷� �߳��Ѿ�ӵ���˻��������Ȩ���Ѿ�loak()�ɹ��ˣ�����
    //֪ͨlock_guard����Ҫ�ڹ��캯����lock����������ˣ�
    //std::try_to_lock������mutex��lock()ȥ����mutex�����û�������ɹ������������أ������������ǣ�ǰ���ǲ����Լ���ȥlock��
    //std::defer_lock ǰ���ǲ���������lock������Ȼ��������û�и�mutex��������ʼ����һ��û�м�����mutex;
    //unique_lock��Ա������lock()������unlock()������
    //unique_lock��Ա���� try_lock(),���Ը�����������������ò���������false, ����õ���������true,���������������
    //unique_lock��Ա���� release(), �������������mutex����ָ�룬�ͷ�����Ȩ����unique_lock��mutex���ڹ�������mutex�������֮��Ҫ�Լ�����mutex��unlock;
    //��ס�����Խ��ִ��Ч��Խ�ߣ���ס�Ĵ�����ٳ�Ϊ�������ȣ�һ���ô�ϸ��������

    A myobja;
    std::thread myOutMsgObj(&A::outRecvQueue, &myobja);   //�ڶ��������� ���ã����ܱ�֤�߳������õ�ͬһ������
    std::thread myInMsgObj(&A::inMsgRecvQueue, &myobja);

    myOutMsgObj.join();
    myInMsgObj.join();

    //һ�����͵ȴ�����߳�
    vector<thread> mythreads;
//��������̣߳��߳���ں���ͳһʹ��myprint
    for (int i = 0; i < 10; i++) {
        mythreads.push_back(thread(myprint, i)); //����10���̣߳�ͬʱ��10���߳��Ѿ���ʼִ��
    }
    for (auto iter = mythreads.begin(); iter != mythreads.end(); ++iter) {
        iter->join();//�ȴ�10���̶߳����أ�
    }
    cout << "���߳�ִ��" << endl;


    return 0;
}