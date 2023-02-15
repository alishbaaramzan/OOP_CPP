#include<iostream>
using namespace std;
struct Course{
    int ID;
    string CourseName;
    string teacher;
    int fee;
    int creditHours;
    void PrintAll(){
        cout << "Course ID: " << ID << endl;
        cout << "Course Name: " << CourseName << endl;
        cout << "Course Teacher: " << teacher << endl;
        cout << "Fee: " << fee << endl;
        cout << "Credit Hours: " << creditHours << endl;
    }
};
struct CourseList{
    Course courses[5];
    int number_of_courses = 0;
    void PrintAll(){
        for(int i = 0; i < number_of_courses; i++){
            if(courses[i].ID==0){
                continue;
            }
            courses[i].PrintAll();
            cout << endl;
        }
    }
    void AddCourse(){ 
        bool check = false;
        for(int i = 0; i < number_of_courses; i++){
            if(courses[i].ID==0){
                cout << "Adding new course :" << endl;
                cout << "Course ID: "; 
                cin >> courses[i].ID;
                cout << "Course Name: ";
                cin >> courses[i].CourseName;
                cout << "Course Teacher: ";
                cin >> courses[i].teacher;
                cout << "Fee: ";
                cin >> courses[i].fee;
                cout << "Credit Hours: ";
                cin >> courses[i].creditHours;
                check = true;
                break;
            }      
        }
        if(!check){
             cout << "Adding new course :" << endl;
                cout << "Course ID: "; 
                cin >> courses[number_of_courses].ID;
                cout << "Course Name: ";
                cin >> courses[number_of_courses].CourseName;
                cout << "Course Teacher: ";
                cin >> courses[number_of_courses].teacher;
                cout << "Fee: ";
                cin >> courses[number_of_courses].fee;
                cout << "Credit Hours: ";
                cin >> courses[number_of_courses].creditHours;
                number_of_courses++;
        }
    }

    void sort_ascending(){
        for(int i = 0; i < number_of_courses-1; i++){
            for(int j = 0; j < number_of_courses-i; j++){
                if(courses[j].ID > courses[j+1].ID){
                    Course temp = courses[j];
                    courses[j] = courses[j+1];
                    courses[j+1]=temp;
                }
            }
        }
    }
    void sort_descending(){
        for(int i = 0; i < number_of_courses-1; i++){
            for(int j = 0; j < number_of_courses-i; j++){
                if(courses[j].ID < courses[j+1].ID){
                    Course temp = courses[j];
                    courses[j] = courses[j+1];
                    courses[j+1]=temp;
                }
            }
        }
    }
    void DeleteCourse(int x){
        courses[x].ID = 0;
        courses[x].CourseName="";
        courses[x].teacher = "";
        courses[x].fee = 0;
        courses[x].creditHours=0;

        
    }
    void DeleteAll(){
        for(int i = 0; i < 5; i++){
        courses[i].ID = 0;
        courses[i].CourseName="";
        courses[i].teacher = "";
        courses[i].fee = 0;
        courses[i].creditHours=0;
        }
    }
};
    struct Student{
        int ID;
        string StdName;
        int RollNo;
        CourseList all_courses;
        void PrintAll(){
        cout << "Student ID: " << ID << endl;
        cout << "Student Name: " << StdName << endl;
        cout << "Roll No: " << RollNo << endl;
    }
    };
    struct StudentList{
        Student std[5];
        int number_of_students = 0;
        void PrintAll(){
            for(int i= 0; i < number_of_students; i++){
                if(std[i].ID==0){
                    continue;
                }
                std[i].PrintAll();
                cout << endl;
            }
        }
        void Add(){
            bool check = false;
            for(int i = 0; i < number_of_students; i++){
                if(std[i].ID==0){
                    cout << "Adding new student :" << endl;
                    cout << "Student ID: "; 
                    cin >> std[i].ID;
                    cout << "Student Name: ";
                    cin >> std[i].StdName;
                    cout << "Roll No: ";
                    cin >> std[i].RollNo;
                    check = true;
                    break;  
                }
            }
            if(!check){
            cout << "Adding new student :" << endl;
            cout << "Student ID: "; 
            cin >> std[number_of_students].ID;
            cout << "Student Name: ";
            cin >> std[number_of_students].StdName;
            cout << "Roll No: ";
            cin >> std[number_of_students].RollNo;
            number_of_students++; 
            }  
        }
        void Delete(int id){
            for(int i = 0; i < number_of_students; i++){
                if(id==std[i].ID){
                    std[i].ID = 0;
                    std[i].StdName ="";
                    std[i].RollNo=0;
                    std[i].all_courses.DeleteAll();

                }
            }
        }
    };
int main(){
    int x;
    int id;
    StudentList list;
    do{
    cout << "Main Menu: " << endl;
    cout << "1. Add new student" << endl;
    cout << "2. Delete existing student" << endl;
    cout << "3. Show all students" << endl;
    cout << "4. Add new course" << endl;
    cout << "5. Delete existing course" << endl;
    cout << "6. Show particular course" << endl;
    cout << "7. Show all courses" << endl;
    cout << "8. Sort courses in ascending order" << endl;
    cout << "9. Sort courses in descending order" << endl;
    cout << "10. Exit" << endl;
    cin >> x;
    switch(x){
        case 1:
            list.Add();
            break;
        case 2:{
            cout << "Enter the ID of students to be deleted: ";
            cin >> id;
            list.Delete(id);
            break;
        }
        case 3:
            list.PrintAll();
            break;
        case 4:{
            cout << "Enter student ID: ";
            cin >> id;
            for(int i = 0; i < 5; i++){
                if(id==list.std[i].ID){
                    list.std[i].PrintAll();
                    list.std[i].all_courses.AddCourse();

                }
            }
        break;
        }
        case 5:{
            cout << "Enter student ID: ";
            cin >> id;
            for(int i = 0; i < 5; i++){
                int c_id;
                if(id==list.std[i].ID){
                    cout << "Enter course ID to be deleted: ";
                    cin >> c_id;
                    for(int j = 0; j < list.std[i].all_courses.number_of_courses; j++){
                            if(c_id==list.std[i].all_courses.courses[j].ID){
                                list.std[i].all_courses.DeleteCourse(j);
                            }

                    }
                 }
            }
            break;
        }
        case 6:{
             cout << "Enter student ID: ";
            cin >> id;
            for(int i = 0; i < 5; i++){
                int c_id;
                if(id==list.std[i].ID){
                    cout << "Enter course ID to be shown: ";
                    cin >> c_id;
                    for(int j = 0; j < list.std[i].all_courses.number_of_courses; j++){
                            if(c_id==list.std[i].all_courses.courses[j].ID){
                                list.std[i].all_courses.courses[j].PrintAll();
                            }

                    }
                 }
            }
            break;
        }
        case 7:{
            cout << "Enter student ID: ";
            cin >> id;
            for(int i = 0; i < list.number_of_students; i++){
                if(id==list.std[i].ID){
                    list.std[i].all_courses.PrintAll();
                }

            }
            break;
        }
        case 8:{
            cout << "Enter student ID: ";
            cin >> id;
            for(int i = 0; i < list.number_of_students; i++){
                 if(id==list.std[i].ID){
                    list.std[i].all_courses.sort_ascending();
                 }
            }
            break;
         }
         case 9:{
            cout << "Enter student ID: ";
            cin >> id;
            for(int i = 0; i < list.number_of_students; i++){
                 if(id==list.std[i].ID){
                    list.std[i].all_courses.sort_descending();
                 }
            }
            break;
         }
         case 10:
            break;
}
    }while(x!=10);
    return 0;
}