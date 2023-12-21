#include"iostream"
#include"string"
#include"fstream"
#include"workermanager.h"
#include"employee.h"
#include"boss.h"
#include"manager.h"
#include"windows.h"
using namespace std;
//职工系统
WorkerManager::WorkerManager()
{
	ifstream ifs;
	ifs.open("员工信息.txt", ios::in);//打开文件
	if (!ifs.is_open())//文件不存在的状态
	{
		cout << "文件不存在" << endl;
		this->m_EmpNum = 0;//初始化人数
		this->m_FileIsEmpty = true;//初始化文件为空标志
		this->m_EmpNum = 0;//初始化指针
		this->m_EmpArray = NULL;//初始化数组指针指向空
		ifs.close();
		return;
	}
	//文件存在，但没有记录
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "文件为空" << endl;
		this->m_EmpNum = 0;//初始化指针
		this->m_EmpArray = NULL;//初始化数组指针指向空
		this->m_FileIsEmpty = true;//初始化文件为空标志
		ifs.close();
		return;
	}
	//当文件存在，并且记录数据
	int num = this->get_EmpNum();//让统计添加的人数覆盖num
	cout << "职工人数为:  " << num << endl;
	this->m_EmpNum = num;//更新数据

	this->m_EmpArray = new Worker * [this->m_EmpNum];//this->m_EmpNum统计的人数个数
	this->init_Emp();//将文件中的数据，存到数组中
	//测试代码 ，测试是否能查看员工信息
	/*for (int i = 0; i < this->m_EmpNum; i++)
	{
		cout << "职工编号:  " << this->m_EmpArray[i]->m_Id
			<< "姓名:  " << this->m_EmpArray[i]->m_Name<<"  "
			<< "部门编号:  " << this->m_EmpArray[i]->m_DeptId << endl;
	}*/
}

//菜单
void WorkerManager::Menu()  //菜单
{
	cout << "************************" << endl;
	cout << "**欢迎使用职工管理系统**" << endl;
	cout << "****0、退出管理程序*****" << endl;
	cout << "****1、增加职工信息*****" << endl;
	cout << "****2、显示职工信息*****" << endl;
	cout << "****3、删除离职职工*****" << endl;
	cout << "****4、修改职工信息*****" << endl;
	cout << "****5、查找职工信息*****" << endl;
	cout << "****6、按照编号排序*****" << endl;
	cout << "****7、清空所有文档*****" << endl;
	cout << "************************" << endl;
}
void WorkerManager::Exit()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);//退出函数
}

void WorkerManager::Add_Emp()
{
	cout << "请输入添加职工的数量:  " << endl;
	int addNum = 0;// 保存用户数量
	cin >> addNum;
	if (addNum > 0)
	{
		//添加
		//计算添加的新空间
		int newSize = this->m_EmpNum + addNum;//新空间大小等于原来的人数加上新加的
		//开辟新空间
		Worker** newSpace = new Worker * [newSize];//用新空间去接受他
			//将原来的空间下的数据，拷贝到新空间
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}
		//添加新数据
		for (int i = 0; i < addNum; i++)
		{
			int id;//职工编号
			string name;//职工名字
			int dSelect;//职工职位
				cout << "请输入第 " << i + 1 << "个员工的编号" << endl;
				cin >> id;
				cout << "请输入第 " << i + 1 << "个员工的名字" << endl;
				cin >> name;
				cout << "请输入第 " << i + 1 << "个员工的职位" << endl;
				cout << "1.员工" << endl;
				cout << "2.经理" << endl;
				cout << "3.老板" << endl;
				cin >> dSelect;
				
				Worker* worker = NULL;
				switch (dSelect)
				{
					case 1:
						worker = new Employee(id, name, 1);
						break;
					case 2:
						worker = new Manager(id, name, 2);
						break;
					case 3:
						worker = new Boss(id, name, 3);
						break;
				default:
					break;
				}
				//将创建的指针要保存到数组中
				newSpace[this->m_EmpNum + i] = worker;
		}
		//释放原来的空间
		delete[]m_EmpArray;
		//更改新空间的指向
		this->m_EmpArray = newSpace;
		//更改新人数
		this->m_EmpNum = newSize;
		//更新职工不为空的标志
		this->m_FileIsEmpty = false;
		//提示添加成功
		cout << "成功添加了  " << addNum << "名员工" << endl;
		this->save();
	}
	else //添加失败
		cout << "输入有误！" << endl;
	system("pause");
	system("cls");
}
void WorkerManager::save()//保存信息
{
	ofstream ofs;
	ofs.open("员工信息.txt", ios::out);
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_Id << " "//在m_EmpArray中第i个人的id
			<< this->m_EmpArray[i]->m_Name << " "//在m_EmpArray中第i个人的名字
			<< this->m_EmpArray[i]->m_DeptId << endl;//在m_EmpArray中第i个人的工作岗位
	}
	ofs.close();
}
int WorkerManager::get_EmpNum()//统计人数
{
	ifstream ifs;
	ifs.open("员工信息.txt", ios::in);
	int id;
	string name;
	int dId;
	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)//读数据
	{
		//统计数据
		num++;
	}
	return num;
}
void WorkerManager::init_Emp()//初始化员工
{
	ifstream ifs;
	ifs.open("员工信息.txt", ios::in);//读文件
	int id;
	string name;
	int dId;

	int index = 0;
		while (ifs >> id && ifs >> name && ifs >> dId)
		{
			Worker* worker = NULL;//创建一个职工的指针 置为空
			//员工数量
			if (dId == 1)
			{
				worker = new Employee(id, name,dId);
			}
			//经理数量
			else if (dId == 2)
			{
				worker = new Manager(id, name,dId);
			}
			//老板数量
			else
			{
				worker = new Boss(id, name,dId);
			}
			this->m_EmpArray[index] = worker;//存放在数组中
			index++;
		}
		ifs.close();//关闭文件
}
void WorkerManager::Show_Emp()//显示员工
{
	//先判断文件是否为空
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		for (int i = 0; i < m_EmpNum; i++)
		{
			//利用多态调用程序接口
			this->m_EmpArray[i]->showInfo();
		}
	}
	system("pause");
	system("cls");
}
void WorkerManager::Del_Emp()//删除职工
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或文件为空！" << endl;
	}
	else
	{
		int select;
		cout << "请选择删除方式:" << endl;
		cout << "1.按编号删除" << endl;
		cout << "2.按名字删除" << endl;
		cin >> select;
		switch (select)
		{
		case 1:
		{
			cout << "请输入想要删除职工的编号： " << endl;
			int id = 0;
			cin >> id;
			int index = this->IsExist(id);
			if (index != -1)
			{
				//删除数据就是数据前移覆盖
				for (int i = 0; i < this->m_EmpNum - 1; i++)
				{
					this->m_EmpArray[i] = this->m_EmpArray[i + 1];//将上一个数组删除的值覆盖
				}
				this->m_EmpNum--;//记录员工少一人
				this->save();//储存一下当前的数据
				cout << "删除成功" << endl;
			}
			else
			{
				cout << "删除失败，未找到该员工" << endl;
			}
		}
		break;
		case 2:
		{cout << "请输入想要删除职工的名字： " << endl;
		string name;
		cin >> name;
		int index = this->IsExist(name);
		if (index != -1)
		{
			//删除数据就是数据前移覆盖
			for (int i = 0; i < this->m_EmpNum - 1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];//将上一个数组删除的值覆盖
			}
			this->m_EmpNum--;//记录员工少一人
			this->save();//储存一下当前的数据
			cout << "删除成功" << endl;
		}
		else
		{
			cout << "删除失败，未找到该员工" << endl;
		}
		break;
		}
		default:
			break;
		}
	}
	system("pause");
	system("cls");
}
int WorkerManager::IsExist(int id)//判断职工是否存在
{
	int index = -1;
	for (int i = 0; i < this->m_EmpNum; i++)//遍历每一个ID号
	{
		if (this->m_EmpArray[i]->m_Id == id)//找到职工
		{
			index = i;
			break;
		}
	}
	return index;
}
int WorkerManager::IsExist(string name)//通过名字去查找员工
{
	int index = -1;
	for (int i = 0; i < this->m_EmpNum; i++)//遍历每一个员工
	{
		if (this->m_EmpArray[i]->m_Name == name)//找到职工
		{
			index = i;
			break;
		}
	}
	return index;
}
void WorkerManager::Mod_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空!" << endl;
	}
	else
	{
		cout << "请输入修改职工的编号; " << endl;
		int id;
		cin >> id;
		int ret = this->IsExist(id);
			if (ret != -1)
			{
				//查找到编号员工
				this->m_EmpArray[ret]->showInfo();
				delete this->m_EmpArray[ret];
				int newId = 0;
				string newName = "";
				int dSelect = 0;
				cout << "查到: " << id << "号职工，请输入新的ID" << endl;
				cin >> newId;
				cout << "查到: " << id << "号职工，请输入新的姓名" << endl;
				cin >> newName;
				cout << "查到: " << id << "号职工，请输入新的岗位" << endl;
				cout << "1.员工" << endl;
				cout << "2.经理" << endl;
				cout << "3.老板" << endl;
				cin >> dSelect;
				Worker* worker = NULL;//父类指针
				switch (dSelect)
				{
				case 1:
					worker = new Employee(newId, newName, dSelect);
					break;
				case 2:
					worker = new Manager(newId, newName, dSelect);
					break;
				case 3:
					worker = new Boss(newId, newName, dSelect);
					break;
				default:
					break;
				}
				this->m_EmpArray[ret] = worker;//将修改的信息更新至m_EmpArray中
				cout << "修改成功" << endl;
				this->save();//保存函数
			}
			else
			{
				cout << "查无此人!" << endl;
			}
	} 
	system("pause");
	system("cls");
}
void WorkerManager::Find_Emp()//查找职工
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空!" << endl;
	}
	else
	{
		int choise;
		cout << "请选择查找方式:  " << endl;
		cout << "1.按编号查找" << endl;
		cout << "2.按名字查找" << endl;
		cin >> choise;
		switch (choise)
		{
		case 1:
		{
			int id;
			cout << "请输入想要查找员工的编号:  " << endl;
			cin >> id;
			for (int i = 0; i < this->m_EmpNum; i++)//遍历每一个ID号
			{
				if (this->m_EmpArray[i]->m_Id == id)//找到职工
				{
					this->m_EmpArray[i]->showInfo();
				}
			}

			break;
		}
		case 2:
		{
			cout << "请输入想要查找职工的名字： " << endl;
			string name;
			cin >> name;
			{
				//删除数据就是数据前移覆盖
				for (int i = 0; i < this->m_EmpNum; i++)
				{
					if (m_EmpArray[i]->m_Name == name)
					{
						this->m_EmpArray[i]->showInfo();
					}
				}
			}
			break;
		}
		default:
			break;
		}
	}
	system("pause");
	system("cls");
}
void WorkerManager::Sort_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空!" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "请选择排序的方式 ：  " << endl;
		cout << "1.按职工号进行升序 " << endl;
		cout << "2.按职工号进行降序 " << endl;
		int select = 0;
		cin >> select;
		for (int i = 0; i < m_EmpNum; i++)
		{
			int minOrMax = i;//声明最小值下标
				for (int j = i + 1; j < this->m_EmpNum; j++)
				{ 
					if (select == 1)//升序
					{
						if (this->m_EmpArray[minOrMax]->m_Id > this->m_EmpArray[j]->m_Id)

						{
							minOrMax = j;
						}
					}
					else//走降序
					{
						if (this->m_EmpArray[minOrMax]->m_Id < this->m_EmpArray[j]->m_Id)
						{
							minOrMax = j;
						}
					}
				}
				//判断一开始走的最小值或最大值是不是计算的最小值或最大值，如果不是交换数据
				if (i != minOrMax)
				{
					Worker* temp = this->m_EmpArray[i];
					this->m_EmpArray[i] = this->m_EmpArray[minOrMax];
					this->m_EmpArray[minOrMax] = temp;
				}
		}
		cout << "排序成功!排序后的结果为： " << endl;
		this->save();//保存
		this->Show_Emp();//展示所有职工
	}
}
void WorkerManager::Clean_File()
{
	cout << "确定要删库跑路吗?" << endl;
	cout << "1.确定" << endl;
	cout << "2.返回" << endl;
	int select = 0;
	cin >> select;
	if (select == 1)//确定！！
	{
		//执行清空文件的操作
		ofstream ofs("员工信息.txt", ios::trunc);
			ofs.close();
			if (this->m_EmpArray != NULL)
		{
				for (int i = 0; i < this->m_EmpNum; i++)
				{
					delete this->m_EmpArray[i];
					this->m_EmpArray[i] = NULL;
				}
				delete[]this->m_EmpArray;
				this->m_EmpArray = NULL;
				this->m_EmpNum = 0;
				this->m_FileIsEmpty = true;
		}
			for (int i = 0; i < 3; i++)
			{
				cout << ".";
				Sleep(500);
			}
			cout << endl<<"无了" << endl;
			for (int i = 0; i < 5;i++)
			{
				cout << ".";
				Sleep(500);
			}
			cout << endl<<"彻底无了" << endl;
			system("pause");
			system("cls");
	}
	else
	{
		system("pause");
		system("cls");
	}
}
WorkerManager::~WorkerManager()//手动释放在堆区的数据
{
	if (this->m_EmpArray != NULL)
	{
		delete[]this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}