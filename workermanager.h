#pragma once//��ֹͷ�ļ��ظ�����
#include"iostream"
#include"Worker.h"
using namespace std;
class WorkerManager
{
public:
	//���캯��
	WorkerManager();
	void Menu();//�˵�
	void Exit();//�˳�ϵͳ
	int m_EmpNum;//��¼ְ������
	Worker** m_EmpArray;//ְ��������ָ��
	void Add_Emp();//���ְ��
	void save();//�����ļ�
	bool m_FileIsEmpty;//���һ���ж��Ƿ����ļ��ĺ���
	int get_EmpNum();//ͳ������
	void init_Emp();//��ʼ��Ա��
	void Show_Emp();//��ʾԱ��
	void Del_Emp();//ɾ��ְ��
	int IsExist(int id);//�ж�ְ���Ƿ����
	int IsExist(string name);//�����ֲ���
	void Mod_Emp();//�޸�ְ��
	void Find_Emp();//����ְ��
	void Sort_Emp();//����ְ�����˳������
	void Clean_File();//�������
	//��������
	~WorkerManager();
	//
};