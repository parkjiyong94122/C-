#include<iostream>
#include<cstring>
using namespace std;

/*
- 정규직은 사원이다.
- 사원명,월급을 관리할 수 있도록 클래스를 디자인하세요
- 사원을 관리할 수 있는 클래스를 디자인.
- 이번달 지불해야할 총급여 출력
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
	//디폴트 소멸자
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
	s1.AddEmployee(new Employee(17, "park"));
	s1.AddEmployee(new permanentWorker(23, "kim", 300));
	s1.AddEmployee(new permanentWorker(27, "park", 600));


	s1.ShowAllEmployee();

	s1.ShowTotalSalary();

	return 0;
}