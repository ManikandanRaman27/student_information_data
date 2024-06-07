#include <bits/stdc++.h>
#include <cstring>
#include <string>

using namespace std;

void addStudent();
void updateStudent();
void deleteStudent();
void generateReport(string criteria);
void printData(int i);

struct Student
{
    int roll_no;
    string name;
    string father_name;
    string dob;
    string branch;
    int year_admission;
    int tentative_year_passing;
    string state;
    string pin;
    string country;
};

const int MAX_STUDENTS = 100;
Student students[MAX_STUDENTS];
int num_students = 0;


void printData(int i)
{
    cout << "Roll No: " << students[i].roll_no << endl;
    cout << "Name: " << students[i].name << endl;
    cout << "Father's Name: " << students[i].father_name << endl;
    cout << "Date of Birth: " << students[i].dob << endl;
    cout << "Branch: " << students[i].branch << endl;
    cout << "Year of Admission: " << students[i].year_admission << endl;
    cout << "Tentative Year of Passing: " << students[i].tentative_year_passing << endl;
    cout << "State: " << students[i].state << endl;
    cout << "PIN: " << students[i].pin << endl;
    cout << "Country: " << students[i].country << endl;
    cout<<endl;
}

int main()
{
    int choice;

    do
    {
        cout << "\nMenu:\n";
        cout << "1-> Add Student\n";
        cout << "2-> Update Student\n";
        cout << "3-> Delete Student\n";
        cout << "4-> Generate Report\n";
        cout << "5-> Exit\n\n";
        cout << "Enter your choice: ";
        fflush(stdin);
        cin >> choice;
        cout<<endl;
        switch (choice)
        {
        case 1:
            addStudent();
            break;
        case 2:
            updateStudent();
            break;
        case 3:
            deleteStudent();
            break;
        case 4:
        {
            string criteria;
            do
            {
                cout << "Generate report based on:\n";
                cout << "(a) Common Name\n";
                cout << "(b) Common State\n";
                cin >> criteria;
            }
            while(criteria!="a"&&criteria!="b");
            generateReport(criteria);
            break;
        }
        case 5:
            cout << "Exiting...\n";
            break;
            break;
        default:
            cout << "Invalid choice!\n";
        }
    }
    while (choice != 5);

    return 0;
}

void addStudent()
{
    if (num_students == MAX_STUDENTS)
    {
        cout << "\nError: Maximum number of students reached!\n";
        return;
    }

    Student newStudent;

    cout << "Enter student details:\n\n";
    cout << "Roll No: ";
    cin >> newStudent.roll_no;
    fflush(stdin);
    cout << "Name: ";
    getline(cin, newStudent.name);
    fflush(stdin);
    cout << "Father's Name: ";
    getline(cin, newStudent.father_name);
    fflush(stdin);
    cout << "Date of Birth (DD-MM-YYYY): ";
    getline(cin, newStudent.dob);
    fflush(stdin);
    cout << "Branch: ";
    getline(cin, newStudent.branch);
    fflush(stdin);
    cout << "Year of Admission: ";
    cin >> newStudent.year_admission;
    cout << "Tentative Year of Passing: ";
    cin >> newStudent.tentative_year_passing;
    fflush(stdin);
    cout << "State: ";
    getline(cin, newStudent.state);
    fflush(stdin);
    cout << "PIN: ";
    getline(cin, newStudent.pin);
    cout << "Country: ";
    getline(cin, newStudent.country);
    cout<<endl;
    students[num_students] = newStudent;
    num_students++;

    cout << "Student added successfully!\n\n";
}

void updateStudent()
{
    int roll_no;

    cout << "\nEnter roll number of the student to update: ";
    cin >> roll_no;

    int index = -1;
    for (int i = 0; i < num_students; i++)
    {
        if (students[i].roll_no == roll_no)
        {
            index = i;
            break;
        }
    }

    if (index == -1)
    {
        cout << "\nStudent not found!\n";
        return;
    }

    Student updatedStudent;

    cout << "\nEnter updated details (leave blank to keep unchanged):\n";
    cout << "Name [" << students[index].name << "]: ";
    fflush(stdin);
    getline(cin, updatedStudent.name);
    if (!updatedStudent.name.empty())
        students[index].name = updatedStudent.name;

    cout << "Father Name [" << students[index].father_name << "]: ";
    fflush(stdin);
    getline(cin, updatedStudent.father_name);
    if (!updatedStudent.father_name.empty())
        students[index].father_name = updatedStudent.father_name;

    cout << "DOB [" << students[index].dob << "]: ";
    fflush(stdin);
    getline(cin, updatedStudent.dob);
    if (!updatedStudent.dob.empty())
        students[index].dob = updatedStudent.dob;

    cout << "Branch [" << students[index].branch << "]: ";
    fflush(stdin);
    getline(cin, updatedStudent.branch);
    if (!updatedStudent.branch.empty())
        students[index].branch = updatedStudent.branch;

    cout << "State [" << students[index].state << "]: ";
    fflush(stdin);
    getline(cin, updatedStudent.state);
    if (!updatedStudent.state.empty())
        students[index].state = updatedStudent.state;

    cout << "Country [" << students[index].country << "]: ";
    fflush(stdin);
    getline(cin, updatedStudent.country);
    if (!updatedStudent.country.empty())
        students[index].country = updatedStudent.country;

    cout << "PIN [" << students[index].pin << "]: ";
    cin>>updatedStudent.pin;
    if (!updatedStudent.pin.empty())
        students[index].pin = updatedStudent.pin;

    cout << "Year Admission [" << students[index].year_admission << "]: ";
    cin>>updatedStudent.year_admission;
    students[index].year_admission = updatedStudent.year_admission;

    cout << "Tentative Year passing [" << students[index].tentative_year_passing << "]: ";
    cin>>updatedStudent.tentative_year_passing;
    students[index].tentative_year_passing = updatedStudent.tentative_year_passing;

    cout << "\nStudent updated successfully!\n";
}

void deleteStudent()
{
    int roll_no;

    cout << "Enter roll number of the student to delete: ";
    cin >> roll_no;

    int index = -1;
    for (int i = 0; i < num_students; i++)
    {
        if (students[i].roll_no == roll_no)
        {
            index = i;
            break;
        }
    }

    if (index == -1)
    {
        cout << "Student not found!\n";
        return;
    }

    for (int i = index; i < num_students - 1; i++)
    {
        students[i] = students[i + 1];
    }

    num_students--;
    cout << "Student deleted successfully!\n";
}

void generateReport(string criteria)
{
    if (criteria == "a")
    {
        cout << "\nStudents with common name:\n";
        string name;
        cout << "Enter name: ";
        fflush(stdin);
        getline(cin,name);
        bool found = false;
        for (int i = 0; i < num_students; i++)
        {
            if (students[i].name == name)
            {
                printData(i);
                found = true;
            }
        }
        if (!found)
        {
            cout << "No student found with name " << name << endl;
        }
    }
    else if (criteria == "b")
    {
        cout << "\nStudents with common state:\n";
        string state;
        cout << "Enter state: ";
        fflush(stdin);
        getline(cin,state);
        bool found = false;
        for (int i = 0; i < num_students; i++)
        {
            if (students[i].state == state)
            {
                printData(i);
                found = true;
            }
        }
        if (!found)
        {
            cout << "No student found from state " << state << endl;
        }
    }
}

