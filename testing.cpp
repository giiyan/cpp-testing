#include <iostream>
using namespace std;

void inputvalid(int num_students, double grade[], double grade_sort[]);
void display(int num_students, double grade[]);
void average(int num_students, double grade[]);
void highnlow(int num_students, double grade[]);
void failed(int num_students, double grade[], double fail_limit);
void gradecategorization(int num_students, double grade[]);
void sorting (double grade_sort[], int num_students);
void searching(int num_students, double grade[]);


int main ()
{

    double fail_limit = 50.0;
    int num_students, decision;

    cout << "Welcome to our Student Performance Tracker Program!\nBefore anything else, ";
 a: cout << "Please input the number of students and their grades.\nNumber of students: ";
    cin >> num_students;
    double grade[num_students], grade_sort[num_students];
    cout << "Their grades: \n";
    inputvalid(num_students, grade, grade_sort);

 do{
  c: cout<< "Choose the operation you'd like us to do: \n"
         <<"1 to Input new number of students and grades\n"
         << "2 to Display the grades\n"
         << "3 to Show the Average\n"
         << "4 to Show the Highest and Lowest grades\n"
         << "5 to Show how many students failed\n"
         << "6 to Categorize the grades\n"
         << "7 to Sort the grades\n"
         << "8 to Search for a specific student's grade\n"
         << "9 to Exit the program\n"
         << "Choose the operation you want to do: ";
    cin >> decision;
    cout << endl;
    if (decision > 9 || decision <1)
    {
        cout << "Invalid Operation. Please try again.\n\n";
        goto c;
    }


    switch (decision)
    {
        case 1: goto a; break;
        case 2: display(num_students, grade); break;
        case 3: average(num_students, grade); break;
        case 4: highnlow(num_students,grade); break;
        case 5: failed(num_students, grade, fail_limit); break;
        case 6: gradecategorization(num_students, grade); break;
        case 7: sorting(grade_sort, num_students); break;
        case 8: searching(num_students, grade); break;
        case 9: cout << "\nThank you for using our Student Performance Tracker Program!"; break;
        default:
            {
            cout << "Invalid Operation. Please try again.\n";
            goto c;
            break;
            }
    }

 } while (decision >= 1 && decision <= 8);


return 0;
}
void inputvalid(int num_students, double grade[], double grade_sort[])
{

    for (int i=0; i<num_students; i++)
       {
        b:
        cout << "For student " << i+1 <<":  ";
        cin >> grade[i];
        if(grade[i] < 0 || grade[i] > 100)
        {
           cout << "Grades can only be from 0-100. Please try again for student " << i+1 << "'s grade.\n";
           goto b;
        }
        grade_sort[i]=grade[i];
       }
    cout << endl;
}
void display(int num_students, double grade[])
{
    cout << "\nGrades of all students:\n";

    for (int i = 0; i < num_students; i++)
        {
        cout << "Student " << i + 1 << ": " << grade[i] << endl;
        }
    cout << endl;
}
void average(int num_students, double grade[])
{
    double sum = 0;
    for (int i = 0; i < num_students; i++) {
        sum = sum + grade[i];
    }
    cout << "Average grade: " << sum / num_students << endl << endl;
}
void highnlow(int num_students, double grade[])
{
    double highest = grade[0];
    double lowest = grade[0];

    for (int i = 1; i < num_students; i++) {
        if (grade[i] > highest) {
            highest = grade[i];
        }
        if (grade[i] < lowest) {
            lowest = grade[i];
        }
    }
    cout << "Highest grade: " << highest << endl;
    cout << "Lowest grade: " << lowest << endl << endl;

}
void failed(int num_students, double grade[], double fail_limit)
{
    int failcount=0;
    for (int i = 0; i < num_students; i++) {
        if (grade[i] < fail_limit) failcount++;
}
    cout << "There are " << failcount << " Student(s) that Failed.\n\n";
}

void gradecategorization(int num_students, double grade[])
{
    for(int i=0; i<num_students; i++)
    {
        if (grade[i] >= 0 && grade[i] <50)
        {
        cout << "Student " << i+1 << " is Failing." << endl;}
        else if (grade[i] >= 50 && grade[i] <= 69){
        cout << "Student " << i+1 << " has an Average grade." << endl;}
        else if (grade[i] >= 70 && grade[i] <= 89){
        cout << "Student " << i+1 << " received a Good grade."<< endl;}
        else if (grade[i] >= 90 && grade[i] <= 100){
        cout << "Student " << i+1 << " did an Excellent job for their grade."<< endl;}
    }
    cout << endl;
}
void sorting(double grade_sort[], int num_students)
{
    double temp;
    for (int i=0; i<num_students - 1; i++){
        for(int j = 0; j< num_students - i - 1; j++){
            if(grade_sort[j] > grade_sort[j + 1]){
                temp = grade_sort[j];
                grade_sort[j] = grade_sort[j + 1];
                grade_sort[j + 1] = temp;
            }
        }
    }
     for (int i = 0; i < num_students; i++)
     cout << grade_sort[i] << " ";
     cout << endl <<endl;
}
void searching(int num_students, double grade[])
{
    int position;
    pos:
    cout << "Enter the position of the student to search (1 to " << num_students << "): ";
    cin >> position;


    if (position < 1 || position > num_students) {
        cout << "Invalid position. Please enter a position between 1 and " << num_students << ".\n";
        goto pos;

    } else {

        cout << "The grade of the student at position " << position << " is: " << grade[position - 1] << endl << endl;
    }
}

