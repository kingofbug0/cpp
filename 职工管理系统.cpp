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
	//ʵ����
	WorkerManager wm;
	//ʵ�ֲ˵�����ʾ
	int select=0;
	while (true)
	{
		wm.Menu();
		cin >> select;
		switch (select)
	{
	 case 0://�˳��������
		 wm.Exit();
		break;
	 case 1://����ְ����Ϣ
		 wm.Add_Emp();
		break;
	 case 2://��ʾְ����Ϣ
		 wm.Show_Emp();
		break;
	 case 3://ɾ����ְְ��
		 wm.Del_Emp();
		break;
	 case 4://�޸�ְ����Ϣ
		 wm.Mod_Emp();
		break;
	 case 5://����ְ����Ϣ
		 wm.Find_Emp();
		break;
	 case 6://���ձ������
		 wm.Sort_Emp();
		break;
	 case 7://��������ĵ�
		 wm.Clean_File();
		break;

		default:
		{
			cout << "�����������������룡" << endl;
			system("cls");
			break;
		}
			
		}
	}
	system("pause");
		return 0;
}