//
//  main.cpp
//  DSA11
//
//  Created by ANSH BHUTADA on 06/06/23.

#include <iostream>
#include <fstream>
 #include <cstring>
using namespace std;

struct Student
{
    int rollNumber;
    char name[20];
    char division;
    char address[10];
};

// Function to add student information to the file
void addStudent()
{
    ofstream file("Rucha.txt", ios::binary | ios::app);
    if (!file)
    {
        cout << "Error opening file!";
        return;
    }

    Student student;
    cout << "Enter Roll Number: ";
    cin >> student.rollNumber;
    cout << "Enter Name: ";
    cin.ignore(); // Ignore the newline character from previous input
    cin.getline(student.name, 50);
    cout << "Enter Division: ";
    cin >> student.division;
    cout << "Enter Address: ";
    cin.ignore(); // Ignore the newline character from previous input
    cin.getline(student.address, 100);

    file.write(reinterpret_cast<char *>(&student), sizeof(Student));
    file.close();

    cout << "Student information added successfully." << endl;
}

// Function to display student information based on roll number
void displayStudent(int rollNumber)
{
    ifstream file("Rucha.txt", ios::binary);
    if (!file)
    {
        cout << "Error opening file!";
        return;
    }

    Student student;
    bool found = false;

    while (file.read(reinterpret_cast<char *>(&student), sizeof(Student)))
    {
        if (student.rollNumber == rollNumber)
        {
            cout << "Roll Number: " << student.rollNumber << endl;
            cout << "Name: " << student.name << endl;
            cout << "Division: " << student.division << endl;
            cout << "Address: " << student.address << endl;
            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "Record not found." << endl;
    }

    file.close();
}

// Function to delete student information based on roll number
void deleteStudent(int rollNumber)
{
    ifstream file("Rucha.txt", ios::binary);
    if (!file)
    {
        cout << "Error opening file!";
        return;
    }

    ofstream tempFile("temp.txt", ios::binary);
    if (!tempFile)
    {
        cout << "Error creating temporary file!";
        file.close();
        return;
    }

    Student student;
    bool found = false;

    while (file.read(reinterpret_cast<char *>(&student), sizeof(Student)))
    {
        if (student.rollNumber != rollNumber)
        {
            tempFile.write(reinterpret_cast<char *>(&student), sizeof(Student));
        }
        else
        {
            found = true;
        }
    }

    file.close();
    tempFile.close();

    remove("Rucha.txt");
    rename("temp.txt", "students.dat");

    if (found)
    {
        cout << "Student information deleted successfully." << endl;
    }
    else
    {
        cout << "Record not found ." << endl;
    }
}

void searchStudent(int rollNumber)
{
    ifstream file("Rucha.txt", ios::binary);
    if (!file)
    {
        cout << "Error opening file!";
        return;
    }

    Student student;
    bool found = false;

    while (file.read(reinterpret_cast<char *>(&student), sizeof(Student)))
    {
        if (student.rollNumber == rollNumber)
        {
            cout << "Roll Number: " << student.rollNumber << endl;
            cout << "Name: " << student.name << endl;
            cout << "Division: " << student.division << endl;
            cout << "Address: " << student.address << endl;
            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "Record not found." << endl;
    }

    file.close();
}

int main()
{
    int choice, rollNumber;

    do
    {
        cout << "\n*** Student Information System ***" << endl;
        cout << "1. Add Student\n2. Display Student\n3. Delete Student\n4. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addStudent();
            break;
        case 2:
            cout << "Enter Roll Number: ";
            cin >> rollNumber;
            displayStudent(rollNumber);
            break;
        case 3:
            cout << "Enter Roll Number: ";
            cin >> rollNumber;
            deleteStudent(rollNumber);
            break;
        case 4:
            cout << "Exiting program. Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice.Enter different choice" << endl;
        }
    } while (choice != 4);

    return 0;
//}
//#include<iostream>
//#include<string>
//#include<iomanip>
//#include<fstream>
//using namespace std;
//
//class student
//{
//private:
//    int rollno;
//    char div;
//
//    string name,address;
//public:
//
//    student()
//    {
//        rollno = 0;
//        div = ' ';
//        name = " ";
//        address = " ";
//    }
//
//    void input()
//    {
//        cout<<"\nEnter roll no of the student : ";
//        cin>>rollno;
//        cout<<"\nEnter the name of the student : ";
//        cin>>name;
//        cout<<"\nenter the division of the division :";
//        cin>>div;
//        cout<<"\nEnter the address of the student : ";
//        getline(cin>>ws , address);
//    }
//
//    void display()
//    {
//        cout<<"\n"<<rollno<<setw(15)<<name<<setw(10)<<div<<setw(10)<<address;
//    }
//
//    int getrollno()
//    {
//        return rollno;
//    }
//
//};
//
//class seq_file
//{
//    fstream file;
//    student obj;
//
//    public:
//
//    void create()
//    {
//        int ch = 0;
//        file.open("student_data.txt", ios::out | ios::binary);
//        while(ch == 0)
//        {
//            obj.input();
//            file.write((char *)&obj , sizeof(obj));
//            cout<<"\nWnat to enter more entries : ";
//            cin>>ch;
//        }
//        file.close();
//    }
//
//    void add()
//    {
//         int ch = 0;
//        file.open("student_data.txt", ios::app | ios::binary);
//        while(ch == 0)
//        {
//            obj.input();
//            file.write((char *)&obj , sizeof(obj));
//            cout<<"\nWnat to enter more entries : ";
//            cin>>ch;
//        }
//        file.close();
//    }
//
//    void print()
//    {
//        file.open("student_data.txt" , ios::in | ios::binary);
//        if(!file)
//        {
//            cout<<"file nahi hai re baba";
//        }
//        else
//        {
//            cout<<"\n"<<"rollno"<<setw(15)<<"name"<<setw(10)<<"div"<<setw(10)<<"address";
//            file.read((char *)&obj , sizeof(obj));
//            while(!file.eof())
//            {
//                obj.display();
//                cout<<endl;
//                file.read((char *)&obj , sizeof(obj));
//            }
//        }
//        file.close();
//    }
//
//    void search()
//    {
//        int n,f1 = 0;
//        cout<<"Enter the roo number ot be searched : ";
//        cin>>n;
//        file.open("student_data.txt" , ios::in | ios::binary);
//        if(!file)
//        {
//            cout<<"File nahi hai re baba";
//            exit(0);
//        }
//        else
//        {
//            file.read((char*)&obj , sizeof(obj));
//            while(!file.eof())
//            {
//                if(n == obj.getrollno())
//                {
//                    obj.display();
//                    f1 = 1;
//                    break;
//                }
//                else
//                {
//                    file.read((char*)&obj , sizeof(obj));
//                }
//            }
//            if(f1 ==0)
//            {
//                cout<<"Record not found.";
//            }
//        }
//
//    }
//};
//
//int main()
//{
//    student obj;
//    int ch;
//    char choice;
//    seq_file sobj;
//    do
//    {
//
//        cout << "\n MENU! \n";
//        cout << "1.Create\n2.Append\n3.Display\n4.Search\nEnter choice";
//        cin >> ch;
//        switch (ch)
//        {
//        case 1:
//            sobj.create();
//            break;
//        case 2:
//            sobj.add();
//            break;
//        case 3:
//            sobj.print();
//            break;
//        case 4:
//            sobj.search();
//            break;
//        default:
//            cout << "Invalid choice!";
//            break;
//        }
//        cout << "\nDo you want to continue?(y/n): ";
//        cin >> choice;
//    } while (choice == 'y' || choice == 'Y');
//    return 0;
//}
