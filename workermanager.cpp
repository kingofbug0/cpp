#include"iostream"
#include"string"
#include"fstream"
#include"workermanager.h"
#include"employee.h"
#include"boss.h"
#include"manager.h"
#include"windows.h"
using namespace std;
//ְ��ϵͳ
WorkerManager::WorkerManager()
{
	ifstream ifs;
	ifs.open("Ա����Ϣ.txt", ios::in);//���ļ�
	if (!ifs.is_open())//�ļ������ڵ�״̬
	{
		cout << "�ļ�������" << endl;
		this->m_EmpNum = 0;//��ʼ������
		this->m_FileIsEmpty = true;//��ʼ���ļ�Ϊ�ձ�־
		this->m_EmpNum = 0;//��ʼ��ָ��
		this->m_EmpArray = NULL;//��ʼ������ָ��ָ���
		ifs.close();
		return;
	}
	//�ļ����ڣ���û�м�¼
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "�ļ�Ϊ��" << endl;
		this->m_EmpNum = 0;//��ʼ��ָ��
		this->m_EmpArray = NULL;//��ʼ������ָ��ָ���
		this->m_FileIsEmpty = true;//��ʼ���ļ�Ϊ�ձ�־
		ifs.close();
		return;
	}
	//���ļ����ڣ����Ҽ�¼����
	int num = this->get_EmpNum();//��ͳ����ӵ���������num
	cout << "ְ������Ϊ:  " << num << endl;
	this->m_EmpNum = num;//��������

	this->m_EmpArray = new Worker * [this->m_EmpNum];//this->m_EmpNumͳ�Ƶ���������
	this->init_Emp();//���ļ��е����ݣ��浽������
	//���Դ��� �������Ƿ��ܲ鿴Ա����Ϣ
	/*for (int i = 0; i < this->m_EmpNum; i++)
	{
		cout << "ְ�����:  " << this->m_EmpArray[i]->m_Id
			<< "����:  " << this->m_EmpArray[i]->m_Name<<"  "
			<< "���ű��:  " << this->m_EmpArray[i]->m_DeptId << endl;
	}*/
}

//�˵�
void WorkerManager::Menu()  //�˵�
{
	cout << "************************" << endl;
	cout << "**��ӭʹ��ְ������ϵͳ**" << endl;
	cout << "****0���˳��������*****" << endl;
	cout << "****1������ְ����Ϣ*****" << endl;
	cout << "****2����ʾְ����Ϣ*****" << endl;
	cout << "****3��ɾ����ְְ��*****" << endl;
	cout << "****4���޸�ְ����Ϣ*****" << endl;
	cout << "****5������ְ����Ϣ*****" << endl;
	cout << "****6�����ձ������*****" << endl;
	cout << "****7����������ĵ�*****" << endl;
	cout << "************************" << endl;
}
void WorkerManager::Exit()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);//�˳�����
}

void WorkerManager::Add_Emp()
{
	cout << "���������ְ��������:  " << endl;
	int addNum = 0;// �����û�����
	cin >> addNum;
	if (addNum > 0)
	{
		//���
		//������ӵ��¿ռ�
		int newSize = this->m_EmpNum + addNum;//�¿ռ��С����ԭ�������������¼ӵ�
		//�����¿ռ�
		Worker** newSpace = new Worker * [newSize];//���¿ռ�ȥ������
			//��ԭ���Ŀռ��µ����ݣ��������¿ռ�
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}
		//���������
		for (int i = 0; i < addNum; i++)
		{
			int id;//ְ�����
			string name;//ְ������
			int dSelect;//ְ��ְλ
				cout << "������� " << i + 1 << "��Ա���ı��" << endl;
				cin >> id;
				cout << "������� " << i + 1 << "��Ա��������" << endl;
				cin >> name;
				cout << "������� " << i + 1 << "��Ա����ְλ" << endl;
				cout << "1.Ա��" << endl;
				cout << "2.����" << endl;
				cout << "3.�ϰ�" << endl;
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
				//��������ָ��Ҫ���浽������
				newSpace[this->m_EmpNum + i] = worker;
		}
		//�ͷ�ԭ���Ŀռ�
		delete[]m_EmpArray;
		//�����¿ռ��ָ��
		this->m_EmpArray = newSpace;
		//����������
		this->m_EmpNum = newSize;
		//����ְ����Ϊ�յı�־
		this->m_FileIsEmpty = false;
		//��ʾ��ӳɹ�
		cout << "�ɹ������  " << addNum << "��Ա��" << endl;
		this->save();
	}
	else //���ʧ��
		cout << "��������" << endl;
	system("pause");
	system("cls");
}
void WorkerManager::save()//������Ϣ
{
	ofstream ofs;
	ofs.open("Ա����Ϣ.txt", ios::out);
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_Id << " "//��m_EmpArray�е�i���˵�id
			<< this->m_EmpArray[i]->m_Name << " "//��m_EmpArray�е�i���˵�����
			<< this->m_EmpArray[i]->m_DeptId << endl;//��m_EmpArray�е�i���˵Ĺ�����λ
	}
	ofs.close();
}
int WorkerManager::get_EmpNum()//ͳ������
{
	ifstream ifs;
	ifs.open("Ա����Ϣ.txt", ios::in);
	int id;
	string name;
	int dId;
	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)//������
	{
		//ͳ������
		num++;
	}
	return num;
}
void WorkerManager::init_Emp()//��ʼ��Ա��
{
	ifstream ifs;
	ifs.open("Ա����Ϣ.txt", ios::in);//���ļ�
	int id;
	string name;
	int dId;

	int index = 0;
		while (ifs >> id && ifs >> name && ifs >> dId)
		{
			Worker* worker = NULL;//����һ��ְ����ָ�� ��Ϊ��
			//Ա������
			if (dId == 1)
			{
				worker = new Employee(id, name,dId);
			}
			//��������
			else if (dId == 2)
			{
				worker = new Manager(id, name,dId);
			}
			//�ϰ�����
			else
			{
				worker = new Boss(id, name,dId);
			}
			this->m_EmpArray[index] = worker;//�����������
			index++;
		}
		ifs.close();//�ر��ļ�
}
void WorkerManager::Show_Emp()//��ʾԱ��
{
	//���ж��ļ��Ƿ�Ϊ��
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < m_EmpNum; i++)
		{
			//���ö�̬���ó���ӿ�
			this->m_EmpArray[i]->showInfo();
		}
	}
	system("pause");
	system("cls");
}
void WorkerManager::Del_Emp()//ɾ��ְ��
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��ļ�Ϊ�գ�" << endl;
	}
	else
	{
		int select;
		cout << "��ѡ��ɾ����ʽ:" << endl;
		cout << "1.�����ɾ��" << endl;
		cout << "2.������ɾ��" << endl;
		cin >> select;
		switch (select)
		{
		case 1:
		{
			cout << "��������Ҫɾ��ְ���ı�ţ� " << endl;
			int id = 0;
			cin >> id;
			int index = this->IsExist(id);
			if (index != -1)
			{
				//ɾ�����ݾ�������ǰ�Ƹ���
				for (int i = 0; i < this->m_EmpNum - 1; i++)
				{
					this->m_EmpArray[i] = this->m_EmpArray[i + 1];//����һ������ɾ����ֵ����
				}
				this->m_EmpNum--;//��¼Ա����һ��
				this->save();//����һ�µ�ǰ������
				cout << "ɾ���ɹ�" << endl;
			}
			else
			{
				cout << "ɾ��ʧ�ܣ�δ�ҵ���Ա��" << endl;
			}
		}
		break;
		case 2:
		{cout << "��������Ҫɾ��ְ�������֣� " << endl;
		string name;
		cin >> name;
		int index = this->IsExist(name);
		if (index != -1)
		{
			//ɾ�����ݾ�������ǰ�Ƹ���
			for (int i = 0; i < this->m_EmpNum - 1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];//����һ������ɾ����ֵ����
			}
			this->m_EmpNum--;//��¼Ա����һ��
			this->save();//����һ�µ�ǰ������
			cout << "ɾ���ɹ�" << endl;
		}
		else
		{
			cout << "ɾ��ʧ�ܣ�δ�ҵ���Ա��" << endl;
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
int WorkerManager::IsExist(int id)//�ж�ְ���Ƿ����
{
	int index = -1;
	for (int i = 0; i < this->m_EmpNum; i++)//����ÿһ��ID��
	{
		if (this->m_EmpArray[i]->m_Id == id)//�ҵ�ְ��
		{
			index = i;
			break;
		}
	}
	return index;
}
int WorkerManager::IsExist(string name)//ͨ������ȥ����Ա��
{
	int index = -1;
	for (int i = 0; i < this->m_EmpNum; i++)//����ÿһ��Ա��
	{
		if (this->m_EmpArray[i]->m_Name == name)//�ҵ�ְ��
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
		cout << "�ļ������ڻ��¼Ϊ��!" << endl;
	}
	else
	{
		cout << "�������޸�ְ���ı��; " << endl;
		int id;
		cin >> id;
		int ret = this->IsExist(id);
			if (ret != -1)
			{
				//���ҵ����Ա��
				this->m_EmpArray[ret]->showInfo();
				delete this->m_EmpArray[ret];
				int newId = 0;
				string newName = "";
				int dSelect = 0;
				cout << "�鵽: " << id << "��ְ�����������µ�ID" << endl;
				cin >> newId;
				cout << "�鵽: " << id << "��ְ�����������µ�����" << endl;
				cin >> newName;
				cout << "�鵽: " << id << "��ְ�����������µĸ�λ" << endl;
				cout << "1.Ա��" << endl;
				cout << "2.����" << endl;
				cout << "3.�ϰ�" << endl;
				cin >> dSelect;
				Worker* worker = NULL;//����ָ��
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
				this->m_EmpArray[ret] = worker;//���޸ĵ���Ϣ������m_EmpArray��
				cout << "�޸ĳɹ�" << endl;
				this->save();//���溯��
			}
			else
			{
				cout << "���޴���!" << endl;
			}
	} 
	system("pause");
	system("cls");
}
void WorkerManager::Find_Emp()//����ְ��
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��!" << endl;
	}
	else
	{
		int choise;
		cout << "��ѡ����ҷ�ʽ:  " << endl;
		cout << "1.����Ų���" << endl;
		cout << "2.�����ֲ���" << endl;
		cin >> choise;
		switch (choise)
		{
		case 1:
		{
			int id;
			cout << "��������Ҫ����Ա���ı��:  " << endl;
			cin >> id;
			for (int i = 0; i < this->m_EmpNum; i++)//����ÿһ��ID��
			{
				if (this->m_EmpArray[i]->m_Id == id)//�ҵ�ְ��
				{
					this->m_EmpArray[i]->showInfo();
				}
			}

			break;
		}
		case 2:
		{
			cout << "��������Ҫ����ְ�������֣� " << endl;
			string name;
			cin >> name;
			{
				//ɾ�����ݾ�������ǰ�Ƹ���
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
		cout << "�ļ������ڻ��¼Ϊ��!" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "��ѡ������ķ�ʽ ��  " << endl;
		cout << "1.��ְ���Ž������� " << endl;
		cout << "2.��ְ���Ž��н��� " << endl;
		int select = 0;
		cin >> select;
		for (int i = 0; i < m_EmpNum; i++)
		{
			int minOrMax = i;//������Сֵ�±�
				for (int j = i + 1; j < this->m_EmpNum; j++)
				{ 
					if (select == 1)//����
					{
						if (this->m_EmpArray[minOrMax]->m_Id > this->m_EmpArray[j]->m_Id)

						{
							minOrMax = j;
						}
					}
					else//�߽���
					{
						if (this->m_EmpArray[minOrMax]->m_Id < this->m_EmpArray[j]->m_Id)
						{
							minOrMax = j;
						}
					}
				}
				//�ж�һ��ʼ�ߵ���Сֵ�����ֵ�ǲ��Ǽ������Сֵ�����ֵ��������ǽ�������
				if (i != minOrMax)
				{
					Worker* temp = this->m_EmpArray[i];
					this->m_EmpArray[i] = this->m_EmpArray[minOrMax];
					this->m_EmpArray[minOrMax] = temp;
				}
		}
		cout << "����ɹ�!�����Ľ��Ϊ�� " << endl;
		this->save();//����
		this->Show_Emp();//չʾ����ְ��
	}
}
void WorkerManager::Clean_File()
{
	cout << "ȷ��Ҫɾ����·��?" << endl;
	cout << "1.ȷ��" << endl;
	cout << "2.����" << endl;
	int select = 0;
	cin >> select;
	if (select == 1)//ȷ������
	{
		//ִ������ļ��Ĳ���
		ofstream ofs("Ա����Ϣ.txt", ios::trunc);
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
			cout << endl<<"����" << endl;
			for (int i = 0; i < 5;i++)
			{
				cout << ".";
				Sleep(500);
			}
			cout << endl<<"��������" << endl;
			system("pause");
			system("cls");
	}
	else
	{
		system("pause");
		system("cls");
	}
}
WorkerManager::~WorkerManager()//�ֶ��ͷ��ڶ���������
{
	if (this->m_EmpArray != NULL)
	{
		delete[]this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}