#pragma once
#include"Worker.h"
#include"string"
#include"iostream"
class Boss :public Worker
{
public:
	    //构造函数
	    Boss(int id, string name, int dId);
		//显示个人信息
		virtual void showInfo();
		//获取员工职位名称
		virtual string getDeptName();
};