#include <iostream>
#include <vector>
#include "Student.h"
using namespace std;

int main()
{
	vector<Student> students;
	int choice;
	
	do
	{
		cout << "\n =============== Student Management System ================= \n";
		cout << "1. Add New Student. \n";
		cout << "2. Display All Students. \n";
		cout << "3. Search Student by Roll Number. \n";
		cout << "4. Compare Two Students. \n";
		cout << "5. Exit. \n";
		
		cout << "\n Enter your Choice : ";
		cin >> choice;
		
//		Choice 1 To Add New Student In Data.
		
		if(choice == 1)
		{
			string sname, cname;
			int rollNumber, credit;
			float gpa;
			cout << "Enter Name of Student : ";
			cin >> sname;
			cout << "Enter Roll Number Of Student : ";
			cin >> rollNumber;
			cout << "Enter GPA of Student : ";
			cin >> gpa;
			cout << "Enter Course Name of Student : ";
			cin >> cname;
			cout << "Enter Credit Hours Of Course Of Student : ";
			cin >> credit;
			
			Student s;
//			s.setData(sname, rollNumber, gpa);
			s.setName(sname);
			s.setrollNumber(rollNumber);
			s.setGPA(gpa);
			s.assignCourse(cname, credit);
			students.push_back(s);
			
			cout << "\n New Student Added. \n";
		}
		
//		Choice 2 To Display All Students Available in Data.
		
		else if(choice == 2)
		{
			if(students.empty())
			{
				cout << "\n No Student to Display! \n";
			}
			else
			{
				cout << "\n ============== Student Details. ==============\n";
				for( int i = 0; i < students.size(); i++)
				{
					cout <<"----------Student " << i+1 <<" details.---------";
					students[i].display();
				 }
			}
			
		}
		
//		Coice 3 To Find the Student by Roll Number in Data.
		
		else if(choice == 3)
		{
			int rollnum;
			cout << "\n Enter Roll Number to Search : ";
			cin >> rollnum;
			cout << endl;
			
			for(int i = 0; i < students.size(); i++)
			{
				if(students[i].getrollNumber() == rollnum)
				{
					cout << "\n Students is Found : \n";
					students[i].display();
					break;
				}
				else if(students[i].getrollNumber() != rollnum)
				{
					cout <<"\n The Roll Number You Enter Is Not Available in  Data.\n";
				}
				else
				{
					cout << "\n No Student found With the Given Roll Number. \n"; 	
				}
				
			}
		}
		
		
//		Choice 4 To Compare 2 Students.

		else if(choice == 4)
		{
			if(students.size() < 2)
			{
				cout << "\n Atleast 2 Studens Required to Compare. \n";
				continue;
			}
			int roll1, roll2;
			cout << "\n Enter First Roll Number To Compare : ";
			cin >> roll1;
			cout << "\n Enter 2nd Roll Number To Compare : ";
			cin >> roll2;
			Student *s1 = NULL, *s2 = NULL;
			
			for(int i = 0; i < students.size(); i++)
			{
				if(students[i].getrollNumber() == roll1)
				{
					s1 = &students[i];
				}
				if(students[i].getrollNumber() == roll2)
				{
					s2 = &students[i];
				}
			}
			if(s1 && s2)
			{
				if(*s1 == *s2)
				{
					cout << "\n Both Students Have the same Roll Numbers : \n";
				}
				else if(*s1 > *s2)
				{
					cout << "\n Student 1's GPA is Greater then Student 2. \n";
				}
				else if (*s1 < *s2)
				{
					cout << "\n Student 2's GPA is Greater then 1. \n ";
				}
				else
				{
					cout << "\n Both Students Have Same GPA. \n";
				}
			}
			else
			{
				cout << "\n One or Both Provided Roll Numbers Are not Available in Data. \n";
			}
		}
		
//		Choice 5 To Exit the Program
		
		else if( choice == 5)
		{
			cout << "-------------- Program Exiting ...... --------------";
		}
		 
//		 For Invalid Choice.
		
		else
		{
			cout << "\n Invalid Choice..  \n  -----------Select Again-----------";
		}
		
		
	}while( choice != 5);
	
//	For copy constructor
	return 0;
}
