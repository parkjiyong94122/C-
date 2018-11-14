#include<iostream>
#include<cstring>
using namespace std;

/*
- �������� ����̴�.(���)
- �����,������ ������ �� �ֵ��� Ŭ������ �������ϼ���.(ĸ��ȭ)
- ����� ������ �� �ִ� Ŭ������ ������.(������)
- �̹��� �����ؾ��� �ѱ޿� ���(virtual)
- ������, �ӽ����� entity class ����.
- �������� �޿��� �⺻�޿� ������ ����.
- �ӽ����� �޿��� �ñ����� ����Ͽ� ����
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
	void ShowInfo() const
	{
		cout << "name    : " << name << endl;
		cout << "age     : " << age << endl;
	}
	virtual void ShowEmployeeInfo() const
	{
	}
	
};
class permanentWorker : public Employee
{
private:
	int salary;
	char position[20];
public:
	permanentWorker(int myAge, const char* myName, int money) : Employee(myAge, myName),salary(money)
	{}
	void ShowEmployeeInfo() const
	{
		ShowInfo();
		cout << "salary :" << salary << endl;
	}
	int GetSalary() const
	{
		return salary;
	}
	//����Ʈ �Ҹ���
};
class buisiness : public permanentWorker
{
private:
	int salesResult;
	double incentive;
public:
	buisiness(int myAge, const char* myName, int money, double incentives) : permanentWorker(myAge, myName, money), incentive(incentives), salesResult(0)
	{}
	void AddSalesResult(int value)
	{
		salesResult += value;
	}
	void ShowSalaryInfo() const
	{
		ShowInfo();
		cout << "salary :" << GetSalary() << endl;
	}
	int GetSalary() const
	{
		return (int)(salesResult*incentive) + permanentWorker::GetSalary();
	}
};
class temporary : public Employee
{
private:
	int urgent;
	int hour;
public:
	temporary(int myAge, const char* myName, int myUrgent) : Employee(myAge, myName), urgent(myUrgent), hour(0)
	{}
	void AddWorkTime(int time)
	{
		hour += time;
	}
	void ShowEmployeeInfo() const
	{
		ShowInfo();
		cout << "salary : " << urgent << endl;
	}
	int GetSalary() const
	{
		return (urgent * hour);
	}
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
	s1.AddEmployee(new permanentWorker(23, "kim", 300));
	//������
	buisiness* seller = new buisiness(23, "ABC", 200, 0.4);
	seller->AddSalesResult(10000);
	s1.AddEmployee(seller);
	//�Ƹ�����Ʈ
	temporary* alba = new temporary(22, "aaaa", 1);
	alba->AddWorkTime(100);
	s1.AddEmployee(alba);

	s1.ShowAllEmployee();

	s1.ShowTotalSalary();

	return 0;
}