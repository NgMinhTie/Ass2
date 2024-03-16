#include <string>
#include <iostream>
#include <vector>

using namespace std;
class Course;
class Student
{
protected:
    string name;
    int score;
    string DOB;
    string schoolName;
    string courseName;

public:
    Student();
    Student(string const &name, int const &score);
    ~Student();

public:
    void setName(string const &name);
    string getName();

    void setScore(int const &score);
    int getScore();
    void display();
    // void remove();
    void setDOB(string const &DOB);
    string getDOB();
    void setSchoolName(string const &schoolName);
    string getSchoolName();
    void setCourseName(string const &courseName);
    string getCourseName();
};

class University
{
private:
    Student **student;
    int numStudent;
    string name;

public:
    University(string const &name);
    ~University();
    Student **getStudent();
    string getName();
    int numberStudent();
    void add(int &index);
    void display(int const &index);
    void bestStudent(int const &index);
    void remove(int &index);
};

class UniStudent : public Student
{
private:
    int numSem;
    Course **course;

public:
    UniStudent();
    void setCourse();
    Course **getCourse();
};

class CollegeStudent : public Student
{
private:
    int numSem;
    Course **course;

public:
    CollegeStudent();
    void setCourse();
    Course **getCourse();
};

class Course
{
private:
    bool Uni;
    float *assignmentScore;
    float *testScore;
    float *examScore;

public:
    Course() {}
    Course(bool Uni) : Uni(Uni) {}
    void DoAssignment();
    float *getAss();
    void TakeTest();
    float *getTest();
    void TakeExam();
    float *getExam();
};