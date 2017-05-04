#include "Student.h"

// overload as free
bool operator > (const Student &lhs, const Student &rhs);

// Student helper function to read and return Student object
Student getStudentData() {
	Student st;
	string name;
	int mt, fnl;
	cout << "Input student name: ";
	getline(cin, name);
	st.setName(name);
	cout << "Input midterm: ";
	cin >> mt;
	st.setMidTerm(mt);
	cout << "Input final: ";
	cin >> fnl;
	st.setFinal(fnl);
	return st;
}

// Student helper function to display values in passed Student object
void displayStudentData(Student st) {
	cout << "Student Name: " << st.getName() << endl;
	cout << "MidTerm: " << st.getMidTerm() << endl;
	cout << "Final: " << st.getFinal() << endl;
	cout << "Total: " << st.getTotalPoints() << endl;
	cout << "Average: " << st.getAverage() << endl;
}

int main() {
	cout << "Number of students objects created = " << Student::getNumObjs() << endl;
	Student st1, st2("Sally Smith", 75, 90), st3(st2), st4 = st3, st5;
	st1.setName("Billy Bob");
	st4.setName("Natasha Williams");
	cout << "Sewtting st5 = st2" << endl;
	st5 = st2;
	st1 = getStudentData();
	cout << "Number of student objects created now = " << st5.getNumObjs() << endl;
	displayStudentData(st5);
	//check for relational greater than
	if (st2 > st1)
		cout << "Stu2 is gresater than stu1" << endl;
	else
		cout << "Stu2 is NOT greater than stu1" << endl;
	cout << "**st2**\n" << st2 << endl;
	cout << "**st1**\n" << st1 << endl;

	return 0;
}