#pragma once
#include"string"
#include"iostream"
#include"Worker.h"
class Manager :public Worker
{
public:
	//构造函数
	Manager(int id, string name, int dId);
	//显示个人信息
	virtual void showInfo();
	//获取员工职位名称
	virtual string getDeptName();
};