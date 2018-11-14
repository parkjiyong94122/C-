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
class buisiness : public Employee
{
private:
	int salary;
	int incentive;
public:
	buisiness(int myAge, const char* myName, int money, int incentives) : Employee(myAge, myName), salary(money), incentive(incentives)
	{}
	void ShowEmployeeInfo() const
	{
		ShowInfo();
		cout << "salary :" << salary << endl;
		cout << "incentive : " << incentive << endl;
	}
	int GetSalary() const
	{
		return salary+incentive;
	}
};
class temporary : public Employee
{
private:
	int urgent;
	int hour;
public:
	temporary(int myAge, const char* myName, int myUrgent, int hours) : Employee(myAge,myName), urgent(myUrgent), hour(hours)
	{}
	void ShowEmployeeInfo() const
	{
		ShowInfo();
		cout << "urgent : " << urgent << endl;
		cout << "hour   : " << hour << endl;
	}
	int GetSalary() const
	{
		return (urgent * hour);
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
	s1.AddEmployee(new temporary(22, "qqq", 1, 10));
	s1.AddEmployee(new temporary(22, "aaaa", 1, 13));
	s1.AddEmployee(new buisiness(23, "ABC", 200, 300));
	s1.AddEmployee(new buisiness(23, "CBA", 200, 300));


	s1.ShowAllEmployee();

	s1.ShowTotalSalary();

	return 0;
}