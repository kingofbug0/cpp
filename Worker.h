#pragma once
#include"string"
#include"iostream"
using namespace std;
class Worker//  ְ���ĳ�����
{
public://������Ϣ
	virtual void showInfo() = 0;
    //��λ����
	virtual string getDeptName() = 0;
		//���
	int m_Id;
		//����
	string m_Name;
		//��λ���
	int m_DeptId;
};