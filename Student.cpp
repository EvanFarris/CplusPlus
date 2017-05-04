#include "Student.h"

bool operator > (const Student &lhs, const Student &rhs) {
	return lhs.getTotalPoints() > rhs.getTotalPoints();
}

ostream& operator << (ostream &lhs, const Student& rhs) {
	lhs << "Student name " << rhs.name << endl;
	lhs << "Midterm " << rhs.midTerm << endl;
	lhs << "Final " << rhs.final << endl;
	lhs << "Total " << rhs.getTotalPoints() << endl;
	lhs << "Average " << rhs.getAverage() << endl;
	return lhs;
}
// Student class definition --> implementation file

//define and initialized the static counter
int Student::numObj = 0;

int Student::getNumObjs() {
	return numObj;
}

// constructor (default)
Student::Student() {
	// for debugging only -> remove from final
	cout << "\n\tDefault constructor called.\n"; 
	this->name = "";
	(*this).midTerm = 0;
	this->final = 0;
	numObj++;
}
// constructor (parameterized)
Student::Student(string n, int mt, int fnl) {
	// for debugging only -> remove from final
	cout << "\n\tParameter constructor called.\n";
	name = n;
	midTerm = mt;
	final = fnl;
	numObj++;
}
//copy constructor
Student::Student(const Student& inpStu) {
	// for debugging only -> remove from final
	cout << "\n\tCopy constructor called,\n" << endl;
	name = inpStu.name;
	this->midTerm = inpStu.midTerm;
	this->final = inpStu.final;
	numObj++;
}
// destructor
Student::~Student() {
	// for debugging only -> remove from final
	cout << "\n\tDestructor called.\n";
	numObj--;//deccrement numObjs
}
// Student method definitions
// mutators (aka setters)
void Student::setName(string n) {
	name = n;
}
void Student::setMidTerm(int mt) {
	midTerm = mt > 0 ? mt : 0; // ensures positive values
}
void Student::setFinal(int fnl) {
	final = fnl > 0 ? fnl : 0;
}
// general behavior (calculation functions)
int Student::getTotalPoints() const {
	return midTerm + final;
}
float Student::getAverage() const {
	return static_cast<float>(midTerm + final) / 2;
}
//operator overloaded as memeber function
Student& Student::operator = (const Student &rhs) {
	//copy overvalues
	cout << "\n\tOverloaded assaignment operator\n" << endl;
	this->name = rhs.name;
	this->midTerm = rhs.midTerm;
	this->final = rhs.final;
	return *this;
}