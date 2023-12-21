#pragma once//防止头文件重复包含
#include"iostream"
#include"Worker.h"
using namespace std;
class WorkerManager
{
public:
	//构造函数
	WorkerManager();
	void Menu();//菜单
	void Exit();//退出系统
	int m_EmpNum;//记录职工人数
	Worker** m_EmpArray;//职工的数组指针
	void Add_Emp();//添加职工
	void save();//保存文件
	bool m_FileIsEmpty;//添加一行判断是否有文件的函数
	int get_EmpNum();//统计人数
	void init_Emp();//初始化员工
	void Show_Emp();//显示员工
	void Del_Emp();//删除职工
	int IsExist(int id);//判断职工是否存在
	int IsExist(string name);//用名字查找
	void Mod_Emp();//修改职工
	void Find_Emp();//查找职工
	void Sort_Emp();//按照职工编号顺序排序
	void Clean_File();//清空数据
	//析构函数
	~WorkerManager();
	//
};