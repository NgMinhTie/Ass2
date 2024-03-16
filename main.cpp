// #include "main.h"
#include "student.cpp"
void addUniversity(University **university, int &numUni)
{
    cout << "Please enter the university'name: " << endl;
    string name;
    cin.ignore();
    getline(cin, name);
    university[numUni] = new University(name);
    numUni += 1;
}
int find(string const &name, University **university, int const &numUniversity)
{
    bool flag = false;
    int index = 0;
    // cout << numUniversity << endl;
    // cout << name << endl;
    for (int i = 0; i < numUniversity; i++)
    {
        if (university[i]->getName() == name)
        {
            index = i;
            flag = true;
            break;
        }
    }
    if (!flag)
    {
        cout << "Cannot find the university" << endl;
        return -1;
    }
    return index;
}

class Implement{
    private:
        University *university;
    public:
        void implement(){
            this->university = new University("Havard");
            //*this->university->getStudent() = new Student[5]; //For instance, this University has 5 students
            this->university->getStudent()[0] = new UniStudent();
            this->university->getStudent()[1] = new CollegeStudent();
            this->university->getStudent()[2] = new UniStudent();
            this->university->getStudent()[3] = new CollegeStudent();
            this->university->getStudent()[4] = new UniStudent();

            this->university->getStudent()[0] -> setName("A");
            this->university->getStudent()[1]->setName("B");
            this->university->getStudent()[2]->setName("C");
            this->university->getStudent()[3]->setName("D");
            this->university->getStudent()[4]->setName("E");

            this->university->getStudent()[0]->setDOB("1/1/24");
            this->university->getStudent()[1]->setDOB("2/1/24");
            this->university->getStudent()[2]->setDOB("3/1/24");
            this->university->getStudent()[3]->setDOB("4/1/24");
            this->university->getStudent()[4]->setDOB("5/1/24");

            for (int i = 0; i < 5; i++)
                this->university->getStudent()[i]->setSchoolName(this->university->getName());

            this->university->getStudent()[0]->setCourseName("UNI");
            this->university->getStudent()[1]->setCourseName("COL");
            this->university->getStudent()[2]->setCourseName("UNI");
            this->university->getStudent()[3]->setCourseName("COL");
            this->university->getStudent()[4]->setCourseName("UNI");

            for (int i = 0; i < 5; i++){
                this->university->getStudent()[i]->DoAssignment();
            }
        }
};

int main()
{
    int numUniversity = 0;
    University **university = new University *[50];
    cout << "There are 4 options:" << endl
         << "- 1 for adding a new student." << endl
         << "- 2 for displaying of all students." << endl
         << "- 3 for displaying the best students who have the highest score" << endl
         << "- 4 for removing the student by entering the name" << endl
         << "- 5 for add the new University." << endl
         << "- 6 to exit the program." << endl;
    char choice;
    int numStudent = 0;
    while (true)
    {
        int indexUni = -1;
        if (numUniversity == 0)
        {
            cout << "You have not entered the University yet. Please choose the option 5." << endl;
        }
        else if (numUniversity == 1)
        {
            numStudent = university[0]->numberStudent();
            indexUni = 0;
        }
        else
        {
            cout << "The choose the name of the University you want to see information." << endl;
            string name;
            // cin.ignore();
            getline(cin, name);
            indexUni = find(name, university, numUniversity);
            // cout << indexUni << endl;
            while (indexUni == -1)
            {
                cout << "Please enter the name of the university again." << endl;
                // cin.ignore();
                getline(cin, name);
                indexUni = find(name, university, numUniversity);
            }
            numStudent = university[indexUni]->numberStudent();
        }
        cout << "\nEnter your option: ";
        cin >> choice;
        if (choice == '1')
        {
            university[indexUni]->add(numStudent);
            cin.ignore();
        }
        else if (choice == '2')
        {
            university[indexUni]->display(numStudent);
            cin.ignore();
        }
        else if (choice == '3')
        {
            // cout << "before:" << index << endl;

            university[indexUni]->bestStudent(numStudent);
            cin.ignore();

            // cout <<"after:"<< index << endl;
        }
        else if (choice == '4')
        {
            university[indexUni]->remove(numStudent);
            // cin.ignore();
        }
        else if (choice == '5')
        {
            addUniversity(university, numUniversity);
        }
        else if (choice == '6')
        {
            break;
        }
        else
            cin.ignore();
        // index += 1;
    }

    for (int i = 0; i < numUniversity; i++)
    {
        delete university[i];
    }
    delete[] university;
    return 0;
}