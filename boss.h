#pragma once
#include"Worker.h"
#include"string"
#include"iostream"
class Boss :public Worker
{
public:
	    //���캯��
	    Boss(int id, string name, int dId);
		//��ʾ������Ϣ
		virtual void showInfo();
		//��ȡԱ��ְλ����
		virtual string getDeptName();
};