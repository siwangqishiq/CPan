#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Student
{
private:
	string name;
	int age;
public:
	Student(string name, int age)
	{
		this->name = name;
		this->age = age;
	}

	void show()
	{
		cout << "名称:" << name << "  年龄:" << age << endl;
	}
};

void vector_play()
{
	vector<int> list(10);

	list.push_back(1001);
	list.push_back(1002);
	list.push_back(1003);

	list[0] = 11;
	

	for (unsigned int i = 0; i < list.size(); i++)
	{
		cout << list[i] << "  ";
	}
	
	cout << endl;

	for (vector<int>::iterator it = list.begin(); it != list.end();it++)
	{
		cout << *it << endl;
	}//end for

	Student t1("呵呵",31);
	Student t2("胡友凤",34);
	Student t3("张丽萍", 31);

	vector<Student> stuList;
	stuList.push_back(t1);
	stuList.push_back(t2);
	stuList.push_back(t3);

	for (unsigned i = 0; i < stuList.size(); i++)
	{
		stuList[i].show();
	}//end for i

	cout << endl;

	for (vector<Student>::iterator it = stuList.begin(); it < stuList.end(); it++)
	{
		//Student *pStu = (Student *)it;
		//pStu->show();
		it->show();
		//Student *p = it;
	}//end for iterator
}

int main()
{
	vector_play();
	cout << "Hello World!" << endl;
	system("pause");
	return 0;
}