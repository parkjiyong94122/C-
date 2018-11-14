#include<iostream>
#include<cstring>
using namespace std;

/*
- 정규직은 사원이다.(상속)
- 사원명,월급을 관리할 수 있도록 클래스를 디자인하세요.(캡슐화)
- 사원을 관리할 수 있는 클래스를 디자인.(다형성)
- 이번달 지불해야할 총급여 출력(virtual)
- 영업직, 임시직의 entity class 생성.
- 영업직의 급여는 기본급에 성과금 포함.
- 임시직의 급여는 시금으로 계산하여 지급
- 간단한 인사관리 프로그램을 작성하세요.
*/

class Employee //entity class 데이터를 저장하는 클래스
{
protected:
	int age;
	char name[30];
	
public:
	Employee(int myAge, const char* myName) : age(myAge)
	{
		strcpy(name, myName);
	}
	//급여를 반환하는 가상함수(virtual method)
	virtual int GetSalary() const
	{
		cout << "가상함수 " << endl;
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
	//디폴트 소멸자
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
class EmployeeHandler //handler class 기능을 관리
{
private:
	// 다형성 
	int count, sel_count;
	Employee* id[50];	//중요
public:
	EmployeeHandler() : count(0)
	{}
	void AddEmployee(Employee* employee)
	{
		if(count < 50)
			id[count++] = employee;

		else
			cout << "더 이상생성이 불가능 합니다." << endl;
		
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
	//영업직
	buisiness* seller = new buisiness(23, "ABC", 200, 0.4);
	seller->AddSalesResult(10000);
	s1.AddEmployee(seller);
	//아르바이트
	temporary* alba = new temporary(22, "aaaa", 1);
	alba->AddWorkTime(100);
	s1.AddEmployee(alba);

	s1.ShowAllEmployee();

	s1.ShowTotalSalary();

	return 0;
}