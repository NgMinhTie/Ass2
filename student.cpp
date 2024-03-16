#include "main.h"
#include <iomanip>
#include <cstdlib>
#include <ctime>

Student::Student()
{
}
Student::Student(string const &name, int const &score)
{
    this->name = name;
    this->score = score;
}

void Student::setName(string const &name)
{
    this->name = name;
}
string Student::getName()
{
    return this->name;
}
void Student::display()
{
    cout << "The student's name is " << setiosflags(ios::left) << setw(20) << this->name << "Score: ";
    cout << this->score << endl;
}
// void Student::remove()
//{
//      this->name = "";
// }
void Student::setScore(int const &score)
{
    this->score = score;
}
int Student::getScore()
{
    return this->score;
}

Student::~Student()
{
    //! TODO
    this->name = "";
    this->score = -1;
}

University::University(string const &name)
{
    this->student = new Student *[50];
    this->name = name;
    this->numStudent = 0;
}
University::~University()
{
    for (int i = 0; i < this->numStudent; i++)
    {
        delete student[i];
    }
    delete[] student;
}
Student **University::getStudent()
{
    return this->student;
}
string University::getName()
{
    return this->name;
}
int University::numberStudent()
{
    return this->numStudent;
}

void University::add(int &index)
{
    string name;
    cout << "Please enter the student's name." << endl;
    cin.ignore();
    getline(cin, name);
    // cout << "DEBUG" << endl;

    int score = 0;
    cout << "Please enter the student's score." << endl;
    cin >> score;
    // cout << index << endl;
    student[index] = new Student(name, score);
    // cout << "DEBUG2" << endl;

    index += 1;
    this->numStudent = index;
}
void University::display(int const &index)
{
    for (int i = 0; i < index; i++)
    {
        student[i]->display();
    }
}

//! MERGE SORT
/***
 * MERGE SORT
 *
 */
void merge(Student **temp, int leftIndex, int middleIndex, int rightIdex)
{

    int leftArrSize = middleIndex - leftIndex + 1;
    int rightArrSize = rightIdex - middleIndex;

    Student *L[leftArrSize], *R[rightArrSize];

    for (int i = 0; i < leftArrSize; i++)
    {
        L[i] = temp[leftIndex + i];
    }
    for (int j = 0; j < rightArrSize; j++)
    {
        R[j] = temp[middleIndex + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = leftIndex;
    while (i < leftArrSize && j < rightArrSize)
    {
        if (L[i]->getScore() >= R[j]->getScore())
        {
            temp[k] = L[i];
            i++;
        }
        else
        {
            temp[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < leftArrSize)
    {
        temp[k] = L[i];
        i++;
        k++;
    }
    while (j < rightArrSize)
    {
        temp[k] = R[j];
        j++;
        k++;
    }
    // cout << "DEBUG" << endl;
}
void mergeSort(Student **temp, int leftIndex, int rightIndex)
{
    if (leftIndex >= rightIndex)
    {
        return;
    }

    int middleIndex = leftIndex + (rightIndex - leftIndex) / 2;
    mergeSort(temp, leftIndex, middleIndex);
    mergeSort(temp, middleIndex + 1, rightIndex);

    merge(temp, leftIndex, middleIndex, rightIndex);
}

//! MERGE SORT

void University::bestStudent(int const &index)
{
    if (index == 0)
        return;
    int numberStudent = index;
    Student **temp = new Student *[numberStudent];
    for (int i = 0; i < numberStudent; i++)
    {
        temp[i] = student[i];
    }
    mergeSort(temp, 0, numberStudent - 1);
    int bestScore = temp[0]->getScore();
    for (int i = 0; i < numberStudent; i++)
    {
        if (temp[i]->getScore() == bestScore)
        {
            // cout << "DEBUG1" << endl;
            temp[i]->display();
            // cout << "DEBUG2" << endl;
        }
        else
            break;
    }

    delete[] temp;
}
void University::remove(int &index)
{
    string name;
    cout << "Please enter the student's name you need to remove." << endl;
    cin.ignore();
    getline(cin, name);
    // cout << name;
    bool flag = 0;
    for (int i = 0; i < index; i++)
    {
        // cout << index<<endl;
        // cout << name<<endl;
        // cout << student[i]->getName()<<endl;
        // cout << "i==" << i << endl;
        if (student[i]->getName() == name)
        {
            flag = 1;
            student[i]->~Student();
            int j = i;
            // cout << "DEBUG" << endl;
            for (; j < index - 1; j++)
            {
                student[j] = student[j + 1];
                // cout <<"j=="<<j<<"  "<< student[j]->getName() << endl;
            }
            // student[j]->setName("");
            index -= 1;
        }
    }
    if (flag == 0)
    {
        cout << "Cannot find this student's name." << endl;
    }
    this->numStudent = index;
}

void Student::setDOB(string const &DOB)
{
    this->DOB = DOB;
}
string Student::getDOB()
{
    return this->DOB;
}
void Student::setSchoolName(string const &name)
{
    this->schoolName = name;
}
string Student::getSchoolName()
{
    return this->schoolName;
}
void Student::setCourseName(string const &name)
{
    this->courseName = name;
}
string Student::getCourseName()
{
    return this->courseName;
}

void Course::DoAssignment()
{
    if (this->Uni)
    {
        for (int i = 0; i < 3; i++)
        {
            // Set the seed for the random number generator
            std::srand(static_cast<unsigned int>(std::time(0)));

            // Generate a random number between 0 and 100
            int randomNumber = std::rand() % 101; // % 101 to get a number in the range [0, 100]

            // Output the random number
            //std::cout << "Random number: " << randomNumber << std::endl;
            this->assignmentScore[i] = randomNumber;
        }
    }
    else
    {
        // Set the seed for the random number generator
        std::srand(static_cast<unsigned int>(std::time(0)));

        // Generate a random number between 0 and 100
        int randomNumber = std::rand() % 101; // % 101 to get a number in the range [0, 100]

        // Output the random number
        // std::cout << "Random number: " << randomNumber << std::endl;
        this->assignmentScore[0] = randomNumber;
    }
}
float *Course::getAss()
{
    return this->assignmentScore;
}

void Course::TakeTest()
{
    if (this->Uni)
    {
        for (int i = 0; i < 2; i++)
        {
            // Set the seed for the random number generator
            std::srand(static_cast<unsigned int>(std::time(0)));

            // Generate a random number between 0 and 100
            int randomNumber = std::rand() % 101; // % 101 to get a number in the range [0, 100]

            // Output the random number
            // std::cout << "Random number: " << randomNumber << std::endl;
            this->testScore[i] = randomNumber;
            //this->testScore[i] = score[i];
        }
    }
    else
    {
        // this->testScore[0] = score[0];
        //  Set the seed for the random number generator
        std::srand(static_cast<unsigned int>(std::time(0)));

        // Generate a random number between 0 and 100
        int randomNumber = std::rand() % 101; // % 101 to get a number in the range [0, 100]

        // Output the random number
        // std::cout << "Random number: " << randomNumber << std::endl;
        this->testScore[0] = randomNumber;
    }
}
float *Course::getTest()
{
    return this->testScore;
}

void Course::TakeExam()
{
    // Set the seed for the random number generator
    std::srand(static_cast<unsigned int>(std::time(0)));

    // Generate a random number between 0 and 100
    int randomNumber = std::rand() % 101; // % 101 to get a number in the range [0, 100]

    // Output the random number
    // std::cout << "Random number: " << randomNumber << std::endl;
    this->examScore[0] = randomNumber;
}
float *Course::getExam()
{
    return this->examScore;
}

UniStudent::UniStudent()
{
    this->numSem = 8;
}
void UniStudent::setCourse()
{
    for (int i = 0; i < 8; i++){
        this->course[i] = new Course(true);
        this->course[i]->DoAssignment();
        this->course[i]->TakeTest();
        this->course[i]->TakeExam();
    }
}
Course **UniStudent::getCourse()
{
    return this->course;
}

CollegeStudent::CollegeStudent()
{
    this->numSem = 4;
}
void CollegeStudent::setCourse()
{
    for (int i = 0; i < 4; i++)
    {
        this->course[i] = new Course(false);
        this->course[i]->DoAssignment();
        this->course[i]->TakeTest();
        this->course[i]->TakeExam();
    }
    return;
}
Course **CollegeStudent::getCourse()
{
    return this->course;
}