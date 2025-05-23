#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

class Employee
{
private:
    int age, experience;
    double salary;

    void ageCheck(int a)
    {
        if (a < 18 || a > 70)
        {
            throw out_of_range("age is not valid");
        }
    }
    void experienceCheck(int exp, int currentAge)
    {
        if (exp < 0 || exp > (currentAge - 18))
        {
            throw invalid_argument("experience is not valid");
        }
    }
    void salaryCheck(int sal)
    {
        if (sal < 300)
        {
            throw domain_error("salary is not valid");
        }
    }

public:
    Employee(int a, int exp, double sal)
    {
        setAge(a);
        setExperience(exp);
        setSalary(sal);
    }
    void setAge(int a)
    {
        ageCheck(a);
        age = a;
        experienceCheck(experience, age);
    }
    void setExperience(int exp)
    {
        experienceCheck(exp, age);
        experience = exp;
    }
    void setSalary(int sal)
    {
        salaryCheck(sal);
        sal = salary;
    }
    int getAge() const { return age; }
    int getExperience() const { return experience; }
    int getSalary() const { return salary; }

    void show()
    {
        cout << "age: " << age << ", experience: " << experience << ", salary: " << salary << endl;
    }
};

int main()
{
    try
    { // valid case
        Employee emp1(25, 5, 1500);
        emp1.show();
    }
    catch (const exception &e)
    {
        cout << "error creating employee: " << e.what() << endl;
    }
    try
    { // age is not valid
        Employee emp2(17, 5, 1500);
        emp2.show();
    }
    catch (const exception &e)
    {
        cout << "error creating employee: " << e.what() << endl;
    }
    try
    { // experience is not valid
        Employee emp3(19, 20, 1500);
        emp3.show();
    }
    catch (const exception &e)
    {
        cout << "error creating employee: " << e.what() << endl;
    }
    try
    { // salary is not valid
        Employee emp4(25, 5, 200);
        emp4.show();
    }
    catch (const exception &e)
    {
        cout << "error creating employee: " << e.what() << endl;
    }

    return 0;
}