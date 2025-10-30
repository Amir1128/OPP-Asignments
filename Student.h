	#include <iostream>
	#include "Course.h"
	using namespace std;
	
//	Starting Class 
		class Student
		{
			private:
				string Name;
				int rollNumber;
				float GPA;
				Course *course;
				
			public:
				
				Student()
					{
						Name = "";
						rollNumber = 0;
						GPA = 0.0;
						course = NULL;
					}
					
//				Parametrized Constructor:	
				Student( string name , int rollnum , float gpa );
					
					
//				Copy Cunstructor				
				Student (const Student &obj)
				{
					Name = obj.Name;
					rollNumber = obj.rollNumber;
					GPA = obj.GPA;
					if(obj.course != NULL)
					{
						course = new Course(*obj.course);
					}
					else
					{
						course = NULL;
					}
				}
					
//				Destructor
				~Student()
				{
					delete course;
				}
					
//				Setter
	
//				void setData( string n , int r , float g)
//				{
//					Name = n;
//					rollNumber = r;
//					GPA = g;
//				}

				void setName(string);
				void setrollNumber(int);
				void setGPA(float);
			
				void assignCourse( string name, int credits)
				{
					course = new Course(name , credits);
				}
			
//				Displaying Data	
				void display()
				{
					cout << endl << "Name : " << Name << endl;
					cout << "Roll Number : " << rollNumber << endl;
					cout << "GPA : " << GPA << endl;
					if(course != NULL)
					{
						cout << "---------Course Info : ------------\n";
						course->display();
						cout << endl;
					}
					else
					{
						cout << "No Course Assigned Yet. \n";
					}
				}
			
				int getrollNumber() const;
				float getGPA() const;
			
		};
	
//	Parametrized Constructor:
	Student::Student( string name , int rollnum , float gpa )
	{
			Name = name;
			rollNumber = rollnum;
			GPA = gpa;
			course = NULL;
		}
	
//	Setters
	void Student::setName(string n)
	{
		Name = n;
	}
	void Student::setrollNumber(int r)
	{
		rollNumber = r;
	}
	void Student::setGPA(float g)
	{
		GPA = g;
	}
	
	
//	Getters:
	int Student::getrollNumber() const
	{
		return rollNumber;
	}
	float Student::getGPA() const
	{
		return GPA;
	}
	
	
//	Overloading Operators:
	bool operator==(const Student &obj1, const Student &obj2)
	{
		return obj1.getrollNumber() == obj2.getrollNumber();
	}
	
	bool operator>(const Student &obj1, const Student &obj2)
	{
		return obj1.getGPA() > obj2.getGPA();
	}
	
	bool operator<(const Student &obj1, const Student &obj2)
	{
		return obj1.getGPA() < obj2.getGPA();
	}
