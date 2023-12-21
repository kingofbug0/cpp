#include"iostream"
#include"workermanager.h"
#include"Worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
#include"string"
using namespace std;
int main()
{
	//实例化
	WorkerManager wm;
	//实现菜单的显示
	int select=0;
	while (true)
	{
		wm.Menu();
		cin >> select;
		switch (select)
	{
	 case 0://退出管理程序
		 wm.Exit();
		break;
	 case 1://增加职工信息
		 wm.Add_Emp();
		break;
	 case 2://显示职工信息
		 wm.Show_Emp();
		break;
	 case 3://删除离职职工
		 wm.Del_Emp();
		break;
	 case 4://修改职工信息
		 wm.Mod_Emp();
		break;
	 case 5://查找职工信息
		 wm.Find_Emp();
		break;
	 case 6://按照编号排序
		 wm.Sort_Emp();
		break;
	 case 7://清空所有文档
		 wm.Clean_File();
		break;

		default:
		{
			cout << "输入有误请重新输入！" << endl;
			system("cls");
			break;
		}
			
		}
	}
	system("pause");
		return 0;
}