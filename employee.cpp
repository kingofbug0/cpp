#include"employee.h"
//���캯��
Employee::Employee(int id, string name, int dId)
{
	//������Ϣ��ʼ��
	this->m_DeptId = dId;
	this->m_Id = id;
	this->m_Name = name;
}
//��ʾ������Ϣ
void Employee::showInfo()
{
	cout << "ְ�����:  " << this->m_Id;
	cout << "\tְ������:  " << this->m_Name;
	cout << "\t��λ:  " << this->m_DeptId ;
	cout << "\t�򹤵İ�ש��" << endl;
}
//��ȡԱ��ְλ����
string Employee::getDeptName()
{
	return string("Ա��");
}