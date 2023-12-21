#include"manager.h"
//构造函数
Manager::Manager(int id, string name, int dId)
{
	//自身信息初始化
	this->m_DeptId = dId;
	this->m_Id = id;
	this->m_Name = name;
}
//显示个人信息
void Manager::showInfo()
{
	cout << "职工编号:  " << this->m_Id;
	cout << "\t职工姓名:  " << this->m_Name;
	cout << "\t岗位:  " << this->m_DeptId;
	cout << "\t高级打工人，包工头" << endl;
}
//获取员工职位名称
string Manager::getDeptName()
{
	return string("经理");
}