#pragma once
#include"string"
#include"iostream"
#include"Worker.h"
class Employee :public Worker
{
public:
	//���캯��
	Employee(int id, string name, int dId);
	//��ʾ������Ϣ
	virtual void showInfo();
	//��ȡԱ��ְλ����
	virtual string getDeptName();
};