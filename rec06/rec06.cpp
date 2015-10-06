#include<iostream>
#include<vector>

using namespace std;
class Section;
class LabWorker;
class TimeSlot;
class Student;

class TimeSlot
{
  string day;
  unsigned time;
public:
  TimeSlot(const string& day, unsigned time) : day(day), time(time) {}

  void display() const
  {
    cout << " The lab meets up on " << day << " at ";
    if (time > 12)
    {
        cout << time - 12 << " PM " << endl ;
    }
    else
    {
      cout << time << " AM " << endl;
    }
  }
};

class Student
{
  string name;
  vector<int> grades;

public:
  Student(const string& name): name(name),grades(13,-1) {}
  void display() const
  {
    cout << name << " " ;
    for(int grade: grades)
    {
      cout << grade << "   ";
    }
    cout << endl;
  }

  string getName() const
  {
    return name;
  }

  void addGrade(int score,int week)
  {
    grades[week] = score;
  }
};



class Section
{
  TimeSlot time;
  string name;
  vector<Student*> students;
public:
  Section(const string& name, const string& day, unsigned time) : name(name), time(day,time) {}
  void display() const
  {
    cout << "Section is : " << name;
    time.display();
    for(const Student* s: students)
    {
      s->display();
    }
  }
  void addStudent(const string& studentName)
  {
    students.push_back(new Student(studentName));
  }

  void addGrade(const string& name, int score,int week)
  {
    for(Student*& s : students)
    {
      if(s->getName() == name)
      {
        s->addGrade(score,week);
      }
    }
  }

  void reset()
  {
    for(Student*& s : students)
      delete s;
    students.clear();
  }
};

class LabWorker
{
  string name;
  Section* section = nullptr;

public:
  LabWorker(const string& name) : name(name) {}
  void display() const
  {
    cout << "Lab worker is : " << name << endl;
  }

  void addSection(Section& section)
  {
    this->section = &section;
  }
  void displayGrades() const
  {
    cout << name << endl;
    section->display();
    cout << endl;
  }

  void addGrade(const string& studentName, int score, int week)
  {
    section->addGrade(studentName, score, week);
  }
};




int main() {

   // lab workers
   LabWorker moe( "Moe" );
   LabWorker jane( "Jane" );

   // sections and setup and testing
   Section secA2( "A2", "Tuesday", 16 );
   //secA2.loadStudentsFromFile( "A2.txt" );
   secA2.addStudent("John");
   secA2.addStudent("George");
   secA2.addStudent("Paul");
   secA2.addStudent("Ringo");

   cout << "\ntest A2\n";    // here the modeler-programmer checks that load worked
   secA2.display();          // YOU'll DO THIS LATER AS: cout << secA2 << endl;
   moe.addSection( secA2 );
   moe.displayGrades();       // here the modeler-programmer checks that adding the Section worked

   Section secB3( "B3", "Thursday", 11 );
   //secB3.loadStudentsFromFile( "B3.txt" );
   secB3.addStudent("Thorin");
   secB3.addStudent("Dwalin");
   secB3.addStudent("Balin");
   secB3.addStudent("Kili");
   secB3.addStudent("Fili");
   secB3.addStudent("Dori");
   secB3.addStudent("Nori");
   secB3.addStudent("Ori");
   secB3.addStudent("Oin");
   secB3.addStudent("Gloin");
   secB3.addStudent("Bifur");
   secB3.addStudent("Bofur");
   secB3.addStudent("Bombur");

   cout << "\ntest B3\n";    // here the modeler-programmer checks that load worked
   secB3.display();          // YOU'll DO THIS LATER AS: cout << secB3 << endl;
   jane.addSection( secB3 );
   jane.displayGrades();      // here the modeler-programmer checks that adding Instructor worked

   // week one activities
  cout << "\nModeling week: 1\n";
  moe.addGrade( "John", 7, 1 );
  moe.addGrade( "Paul", 9, 1 );
  moe.addGrade( "George", 7, 1 );
  moe.addGrade( "Ringo", 7, 1 );
  cout << "End of week one\n";
  moe.displayGrades();

  // week two activities
 cout << "\nModeling week: 2\n";
 moe.addGrade( "John", 5, 2 );
 moe.addGrade( "Paul", 10, 2 );
 moe.addGrade( "Ringo", 0, 2 );
 cout << "End of week two\n";
 moe.displayGrades();

 //test that reset works  // NOTE: can we check that the heap data was dealt with?
  cout << "\ntesting reset()\n";
  secA2.reset();
  secA2.display();
  moe.displayGrades();
}
