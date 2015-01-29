#include <string>
#include <cstdlib>
#include <iostream>
using namespace std;
class Employee
{
	public:
		Employee( );
    		Employee(string theName, string theSsn);
    		string getName( );
    		string getSsn( );
    		double getNetPay( );
    		void setName(string newName); 
    		void setSsn(string newSsn);
    		void setNetPay(double newNetPay);
    		void printCheck( );
  	protected: 
    		string name; 
    		string ssn; 
    		double netPay;
};
class SalariedEmployee : public Employee
{
  	public:
    		SalariedEmployee( );
    		SalariedEmployee (string theName, string theSsn,
               	double theWeeklySalary);
    		double getSalary();
    		void setSalary(double newSalary); 
    		void printCheck( );
  	protected:
    		double salary; //weekly
};
class Administrator : public SalariedEmployee
{
	public:
		Administrator( );
		Administrator(string aName, string anSSn, string aTitle, string aResponsibility,
				string aSupervisor, double aSalary);

		void getAdminData();
		void changeSupervisor(string newSuper);//change
		void print();
		void printCheck();
		void giveRaise(double amount);

	protected:
		string title, responsibility, supervisor;
		double annualSalary;
};
Administrator::Administrator( ) : SalariedEmployee()
{/*Go blank yourself*/}
Administrator::Administrator(string aName, string anSSn, string aTitle, string aResponsibility,
                                string aSupervisor, double aSalary)
			: SalariedEmployee (aName, anSSn, 0.0), title(aTitle), 
			responsibility(aResponsibility), supervisor(aSupervisor),
			annualSalary(aSalary)
{/*So blank right now*/}
void Administrator::changeSupervisor(string newSuper)
{
	supervisor = newSuper;
}
void Administrator::getAdminData()
{
	char n[100];
	string a, b, c, d; 
	cout << "Enter the administrator's name \n";
	cin >> a;
	name = a;
	cout << "Enter the title\n";
	cin >> b;
	title = b;
	cout << "Enter responsibility\n";
	cin >> c;
	responsibility = c;
	cout << "Enter the employee's supervisor\n";
	cin >> d;
	supervisor = d;
	cout << "Enter salary\n";
	double k;
	cin >> k;
	annualSalary = k;
}
void Administrator::print()
{
	cout << "Name: " << name << endl;
	cout << "Title: " << title << endl;
	cout << "Responsibility: " << responsibility << endl;
	cout << "Salary: $" << annualSalary << endl;
	cout << name << "'s supervisor: " << supervisor << endl;
}
void Administrator::printCheck()
{
	double monthlyPay = annualSalary / 12;
	cout << "\n_______________________________________________\n";
        cout << "Pay to the order of " << name << endl;
        cout << "The sum of $" << monthlyPay << " Dollars\n";
        cout << "_________________________________________________\n";
        cout << "Check Stub NOT NEGOTIABLE \n";
        cout << "_________________________________________________\n";

}
Employee::Employee( ) : name("No name yet"),
                          ssn("No number yet"),
                          netPay(0)
{/*empty*/ }
void Administrator::giveRaise(double amount)
{
	annualSalary += amount;
}
Employee::Employee(string theName, string theNumber) 
                               : name(theName), 
                                 ssn(theNumber), 
                                 netPay(0) 
{ /*deliberately empty*/ }
string Employee::getName( ) 
{
	return name;
}
string Employee::getSsn( ) 
{
	return ssn;
}
double Employee::getNetPay( ) 
{
       	return netPay;
}
void Employee::setName(string newName)
{
       	name = newName;
}
void Employee::setSsn(string newSsn)
{
       	ssn = newSsn;
}
void Employee::setNetPay (double newNetPay)
{
       	netPay = newNetPay;
}
void Employee::printCheck( ) 
{
       	cout << "\nERROR: printCheck FUNCTION CALLED FOR AN \n"
	<< "UNDIFFERENTIATED EMPLOYEE. Aborting the program.\n" 
       	<< "Check with the author of the program about this bug.\n";
       	exit(1);
}
SalariedEmployee::SalariedEmployee( ):Employee( ), salary(0)
{ /* deliberately empty */ }
SalariedEmployee::SalariedEmployee(string newName,
	string newNumber, double newWeeklyPay)
           	: Employee(newName, newNumber),
            salary(newWeeklyPay)
{ /*/deliberately empty*/}
double SalariedEmployee::getSalary( ) 
{
	return salary;
}
void SalariedEmployee::setSalary(double newSalary)
{
	salary = newSalary;
}
void SalariedEmployee::printCheck( )
{
	setNetPay(salary);
	cout << "\n_______________________________________________\n";
	cout << "Pay to the order of " << getName( ) << endl;
	cout << "The sum of " << getNetPay( ) << " Dollars\n";
	cout << "_________________________________________________\n";
	cout << "Check Stub NOT NEGOTIABLE \n";
	cout << "Employee Number: " << getSsn( ) << endl;
	cout << "Salaried Employee. Regular Pay: " << salary << endl; 
	cout << "_________________________________________________\n";
}

int main()
{
	Administrator adminObj;
	adminObj.getAdminData();
	adminObj.print();
	adminObj.printCheck();
	return 0;
}

