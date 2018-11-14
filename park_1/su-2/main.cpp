#include<iostream>
#include<cstring>
using namespace std;

/*
- �������� ����̴�.
- �����,������ ������ �� �ֵ��� Ŭ������ �������ϼ���
- ����� ������ �� �ִ� Ŭ������ ������.
- �̹��� �����ؾ��� �ѱ޿� ���
- ������ �λ���� ���α׷��� �ۼ��ϼ���.
*/

class Employee //entity class �����͸� �����ϴ� Ŭ����
{
protected:
	int age;
	char name[30];
	
public:
	Employee(int myAge, const char* myName) : age(myAge)
	{
		strcpy(name, myName);
	}
	//�޿��� ��ȯ�ϴ� �����Լ�(virtual method)
	virtual int GetSalary() const
	{
		cout << "�����Լ� " << endl;
		return 0;
	}
	virtual void ShowEmployeeInfo() const
	{
		cout << "name    : " << name << endl;
		cout << "age     : " << age << endl;
	}
	
};
class permanentWorker : public Employee
{
private:
	int salary;
	char position[20];
public:
	permanentWorker(int myAge, const char* myName, int money) : Employee(myAge, myName),salary(money)
	{
	}
	void ShowEmployeeInfo() const
	{
		cout << "name   : " << name << endl;
		cout << "age    : " << age << endl;
		cout << "salary :" << salary << endl;
	}
	int GetSalary() const
	{
		return salary;
	}
	//����Ʈ �Ҹ���
};
class EmployeeHandler //handler class ����� ����
{
private:
	// ������ 
	int count, sel_count;
	Employee* id[50];	//�߿�
public:
	EmployeeHandler() : count(0)
	{}
	void AddEmployee(Employee* employee)
	{
		if(count < 50)
			id[count++] = employee;

		else
			cout << "�� �̻������ �Ұ��� �մϴ�." << endl;
		
	}
	void ShowAllEmployee() const
	{
		for (int i = 0; i < count; i++)
		{
			id[i]->ShowEmployeeInfo();
			cout << endl;
		}
	}
	void ShowTotalSalary()
	{
		int money = 0;
		for (int i = 0; i < count; i++)
			money += id[i]->GetSalary();
		
		cout << "Total Salary : " << money << endl;
	}
	~EmployeeHandler()
	{
		for (int i = 0; i < count; i++)
			delete id[count];
	}
};
int main(void)
{
	EmployeeHandler s1;

	s1.AddEmployee(new Employee(13, "kim"));
	s1.AddEmployee(new Employee(17, "park"));
	s1.AddEmployee(new permanentWorker(23, "kim", 300));
	s1.AddEmployee(new permanentWorker(27, "park", 600));


	s1.ShowAllEmployee();

	s1.ShowTotalSalary();

	return 0;
}