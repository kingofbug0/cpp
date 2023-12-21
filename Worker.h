#pragma once
#include"string"
#include"iostream"
using namespace std;
class Worker//  职工的抽象类
{
public://个人信息
	virtual void showInfo() = 0;
    //岗位名称
	virtual string getDeptName() = 0;
		//编号
	int m_Id;
		//名字
	string m_Name;
		//岗位编号
	int m_DeptId;
};