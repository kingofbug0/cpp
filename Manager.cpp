#include"manager.h"
//���캯��
Manager::Manager(int id, string name, int dId)
{
	//������Ϣ��ʼ��
	this->m_DeptId = dId;
	this->m_Id = id;
	this->m_Name = name;
}
//��ʾ������Ϣ
void Manager::showInfo()
{
	cout << "ְ�����:  " << this->m_Id;
	cout << "\tְ������:  " << this->m_Name;
	cout << "\t��λ:  " << this->m_DeptId;
	cout << "\t�߼����ˣ�����ͷ" << endl;
}
//��ȡԱ��ְλ����
string Manager::getDeptName()
{
	return string("����");
}