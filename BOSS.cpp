#include"boss.h"
#include"string"
//���캯��
Boss::Boss(int id, string name, int dId)
{
	this->m_DeptId = dId;
	this->m_Id = id;
	this->m_Name = name;
}
//��ʾ������Ϣ
void Boss::showInfo()
{
	cout << "ְ�����:  " << this->m_Id;
	cout << "\tְ������:  " << this->m_Name;
	cout << "\t��λ:  " << this->m_DeptId;
	cout << "\t�����ʱ���" << endl;
}
//��ȡԱ��ְλ����
string Boss::getDeptName()
{
	return string ("�ϰ�");
}