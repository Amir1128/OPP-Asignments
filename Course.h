#include<iostream>
using namespace std;

class Course
{
	private:
		string courseName;
		int creditHours;
		
	public:
		Course()
		{
			courseName = "";
			creditHours = 0;
		}
		
		Course( string cname , int chours )
		{
			courseName = cname;
			creditHours = chours;
		}
		
//		Copy Constructor

		Course( const Course &c)
		{
			courseName = c.courseName;
			creditHours = c.creditHours;
		}
		
		void setCourse( string name, int hours)
		{
			courseName = name;
			creditHours = hours;
		}
		
		void display()
		{
			cout << "Course Name : " << courseName << ", Credit Hours : " << creditHours;
		}
		
		string getcourseName() const;
		int getcreditHours() const;
};


string Course::getcourseName() const
{
	return courseName;
}
int Course::getcreditHours() const
{
	return creditHours;
}
