#pragma once
#include"string"
#include"iostream"
#include"Worker.h"
class Manager :public Worker
{
public:
	//���캯��
	Manager(int id, string name, int dId);
	//��ʾ������Ϣ
	virtual void showInfo();
	//��ȡԱ��ְλ����
	virtual string getDeptName();
};