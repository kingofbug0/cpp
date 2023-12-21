#include"boss.h"
#include"string"
//构造函数
Boss::Boss(int id, string name, int dId)
{
	this->m_DeptId = dId;
	this->m_Id = id;
	this->m_Name = name;
}
//显示个人信息
void Boss::showInfo()
{
	cout << "职工编号:  " << this->m_Id;
	cout << "\t职工姓名:  " << this->m_Name;
	cout << "\t岗位:  " << this->m_DeptId;
	cout << "\t万恶的资本家" << endl;
}
//获取员工职位名称
string Boss::getDeptName()
{
	return string ("老板");
}