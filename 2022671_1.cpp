// This code serves as a database for an educational institute

#include <iostream>
using namespace std;


// This enum stores values for educational qualification of any student
enum education{Freshman = 1, Sophomore, JuniorYear, SeniorYear, M_S, P_hd};

// This enum stores values for educational qualification of any teacher
enum educationt{BSt = 1, MSt, Phdt};

// This enum stores values for the dept. of a student
enum dept{
    CE=1, CH, CS, EE, ES, HM, ME, MM, MS, MT, PE, PH, AI, CyberSecurity, DS
};

// This enum stores the gpa related to every grade
enum grade{
    A, A_neg, B_pos, B, B_neg, C_pos, C, C_neg, D_pos, D, F 
};

// This stucture stores address of any person
struct Address{
    int house_no;
    int street_no;
    string city;
};

// This structure serves as a template for storing basic personal information of any person
struct Person{
    string name;
    int age;
    Address address;
    string level;
};

// This structure stores the grades of a particular course taken by a student
struct Grade{
    string Std_grade;
    int marks;
    float gpa;
};

//This structure stores information of a student
struct Student{
    Person Std_info;
    int roll_no;
    string Std_Dept;
    Grade grade;
};

// This structures stores the list of students (every student has their complete data)
struct StudentList{
    int number_of_students;
    Student *list = new Student[100];

//This functions adds a new student to the record as per admin's command
 void AddStudent(){
        int edu;
        int dept;
        string name;
        
        
        cout << "Student's name: ";
        cin.ignore();
        getline(cin,name);
        list[number_of_students].Std_info.name = name;
        cout << "Student's age: ";
        cin >> list[number_of_students].Std_info.age;
        cout << "Student's address: " << endl;
        cout << "House No# ";
        cin >> list[number_of_students].Std_info.address.house_no;
        cout << "Street No# ";
        cin >> list[number_of_students].Std_info.address.street_no;
        cout << "City# ";
        cin >> list[number_of_students].Std_info.address.city;
        cout << "Student's education level: " << endl;
        cout << "1.Freshman\n2.Sophomore\n3.JuniorYear\n4.SeniorYear\n5.M_S\n6.P_hd\n";
        cin >> edu;

        if(edu==Freshman)
            list[number_of_students].Std_info.level = "Freshman";
        else if(edu == Sophomore)
            list[number_of_students].Std_info.level = "Sophomore";
        else if(edu == JuniorYear)
            list[number_of_students].Std_info.level = "Junior Year";
        else if(edu = SeniorYear)
            list[number_of_students].Std_info.level = "Senior Year";
        else if(edu == M_S)
            list[number_of_students].Std_info.level = "MS";
        else if(edu = P_hd)
            list[number_of_students].Std_info.level = "P.hd";
        else    
            cout << "Invalid!" << endl;

        cout << "Student's Roll No: ";
        cin >> list[number_of_students].roll_no;

        cout << "Student's department: " << endl;
        cout << "1.CE\n2.CH\n3.CS\n4.EE\n5.ES\n6.HM\n7.ME\n8.MM\n9.MS\n10.MT\n11.PE\n12.PH\n13.AI\n14.CyberSecurity\n15.DS\n";
        cin >> dept;
        if(dept == CE)
            list[number_of_students].Std_Dept = "CE";
        else if(dept == CH)
            list[number_of_students].Std_Dept = "CH";
        else if(dept == CS)
            list[number_of_students].Std_Dept = "CS";
        else if(dept == EE)
            list[number_of_students].Std_Dept = "EE";
        else if(dept == ES)
            list[number_of_students].Std_Dept = "ES";
        else if(dept == HM)
            list[number_of_students].Std_Dept = "HM";
        else if(dept == ME)
            list[number_of_students].Std_Dept = "ME";
        else if(dept == MM)
            list[number_of_students].Std_Dept = "MM";
        else if(dept == MS)
            list[number_of_students].Std_Dept = "MS";
        else if(dept == MT)
            list[number_of_students].Std_Dept = "MT";
        else if(dept == PE)
            list[number_of_students].Std_Dept = "PE";
        else if(dept == PH)
            list[number_of_students].Std_Dept = "PH";
        else if(dept == AI)
            list[number_of_students].Std_Dept = "AI";
        else if(dept == CyberSecurity)
            list[number_of_students].Std_Dept = "Cyber Security";
        else if(dept == DS)
            list[number_of_students].Std_Dept = "DS";
        else    
            cout << "Invalid!" << endl;
        number_of_students++;    
    }

    // This function removes a student from the list as per admin's command
    void RemoveStudent(){
        int roll_no;
        int index; // the index whose students needs to be removed
        bool check = false;
        cout << "Enter Roll No of the student to be removed: ";
        cin >> roll_no;
        for(int i = 0; i < number_of_students; i++){
            if(list[i].roll_no == roll_no){
                index = i;
                check = true;
                break;
            }
        }

        // now making a new dynamic array of type Student, copying everything except the 'index' location
        if (check){
        Student *temp = new Student[100];
        int t = 0;
        for(int i = 0; i < number_of_students; i++){
            if(i==index)
                continue;
            *(temp+t)= *(list+i);
            t++;
        }
        number_of_students--;

        // now copying the elements back in the list
        for(int i = 0; i < number_of_students; i++){
            *(list+i)= *(temp+i);
        }

        // deallocating temporary array of lists
        delete [] temp;
        }
        else
            cout << "No such student exists in the system" << endl << endl;

    }

    // This function update a student's details
    void updateStudent(){
        int roll_no;
        int index;
        bool check = false;

        cout << "Enter the Roll No of the student: ";
        cin >> roll_no;
        for(int i = 0; i < number_of_students; i++){
            if(list[i].roll_no == roll_no){
                index = i;
                check = true;
                break;
            }
        }

        // updating the value at 'index' index level
        if(check){
        int edu;
        int dept;
        string name;

        cout << "Student's name: ";
        cin.ignore();
        getline(cin,name);
        list[index].Std_info.name = name;
        cout << "Student's age: ";
        cin >> list[index].Std_info.age;
        cout << "Student's address: ";
        cout << "House No# ";
        cin >> list[index].Std_info.address.house_no;
        cout << "Street No# ";
        cin >> list[index].Std_info.address.street_no;
        cout << "City# ";
        cin >> list[index].Std_info.address.city;
        cout << "Student's education level: " << endl;
        cout << "1.Freshman\n2.Sophomore\n3.JuniorYear\n4.SeniorYear\n5.M_S\n6.P_hd\n";
        cin >> edu;
        if(edu==Freshman)
            list[index].Std_info.level = "Freshman";
        else if(edu == Sophomore)
            list[index].Std_info.level = "Sophomore";
        else if(edu == JuniorYear)
            list[index].Std_info.level = "Junior Year";
        else if(edu = SeniorYear)
            list[index].Std_info.level = "Senior Year";
        else if(edu == M_S)
            list[index].Std_info.level = "MS";
        else if(edu = P_hd)
            list[index].Std_info.level = "P.hd";
        else    
            cout << "Invalid!" << endl;
        cout << "Student's Roll No: ";
        cin >> list[index].roll_no;
        cout << "Student's department: ";
        cout << "1.CE\n2.CH\n3.CS\n4.EE\n5.ES\n6.HM\n7.ME\n8.MM\n9.MS\n10.MT\n11.PE\n12.PH\n13.AI\n14.CyberSecurity\n15.DS\n";
        cin >> dept;
        if(dept == CE)
            list[index].Std_Dept = "CE";
        else if(dept == CH)
            list[index].Std_Dept = "CH";
        else if(dept == CS)
            list[index].Std_Dept = "CS";
        else if(dept == EE)
            list[index].Std_Dept = "EE";
        else if(dept == ES)
            list[index].Std_Dept = "ES";
        else if(dept == HM)
            list[index].Std_Dept = "HM";
        else if(dept == ME)
            list[index].Std_Dept = "ME";
        else if(dept == MM)
            list[index].Std_Dept = "MM";
        else if(dept == MS)
            list[index].Std_Dept = "MS";
        else if(dept == MT)
            list[index].Std_Dept = "MT";
        else if(dept == PE)
            list[index].Std_Dept = "PE";
        else if(dept == PH)
            list[index].Std_Dept = "PH";
        else if(dept == AI)
            list[index].Std_Dept = "AI";
        else if(dept == CyberSecurity)
            list[index].Std_Dept = "Cyber Security";
        else if(dept == DS)
            list[index].Std_Dept = "DS";
        else    
            cout << "Invalid!" << endl;
        }
        else
            cout << "No such student exists in the system" << endl << endl;
    }

    // This functions displays the record of all students
    void showRecordofStudents(){
        if(number_of_students==0)
            cout << "No record found" << endl;
        else{
        for(int i = 0; i < number_of_students; i++){
            cout << "Student's name: "<<  list[i].Std_info.name << endl;
            cout << "Student's age: "<< list[i].Std_info.age << endl;
            cout << "Student's address: " << endl;
            cout << "House no: " << list[i].Std_info.address.house_no << endl;
            cout << "Street no: " << list[i].Std_info.address.street_no << endl;
            cout << "City: " << list[i].Std_info.address.city << endl;
            cout << "Student's education level: "<< list[i].Std_info.level << endl;
            cout << "Student's Roll No: "<< list[i].roll_no << endl;
            cout << "Student's department: "<< list[i].Std_Dept << endl;
            cout << endl << endl;
    }
    }
    }

    // This function shows the details of a student in the system
    void showStudentDetails(){
        int roll_no;
        int index;
        bool check = false; // this will check if the student has been added in the system

        cout << "Enter your roll no: ";
        cin >> roll_no;
    
        // Now looping through the list of students to find the required student's data
        for(int i = 0; i < number_of_students; i++){
            if(list[i].roll_no == roll_no){
                index = i;
                check = true;
                break;
            }
        }
        // Now displaying the details of the student at 'index' index of the list
        if(check){
        cout << "Student's name: "<<  list[index].Std_info.name << endl;
        cout << "Student's age: "<< list[index].Std_info.age << endl;
        cout << "Student's address: " << endl;
        cout <<"House no# " <<  list[index].Std_info.address.house_no << endl;
        cout <<"Street no# " <<  list[index].Std_info.address.street_no << endl;
        cout << "City# " << list[index].Std_info.address.city << endl;
        cout << "Student's education level: "<< list[index].Std_info.level << endl;
        cout << "Student's Roll No: "<< list[index].roll_no << endl;
        cout << "Student's department: "<< list[index].Std_Dept << endl;
        }
        else 
            cout << "Sorry your details have not been added by the admin yet" << endl << endl;
    }
};

// This structure stores basic information of a teacher
struct Teacher{
    Person Teacher_info;
    long int salary;
    string Teacher_Dept; 
};

// This structure stores a list of teachers
struct TeachersList{
    int number_of_teachers;
    Teacher *list = new Teacher[100];

    // This function adds a teacher to the system
    void AddTeacher(){
        string name;
        int edut;
        int deptt;
        cout << "Name of teacher: ";
        cin.ignore();
        getline(cin,name);
        list[number_of_teachers].Teacher_info.name = name;
        cout << "Teacher's age: ";
        cin >> list[number_of_teachers].Teacher_info.age;
        cout << "Teacher's address: " << endl;
        cout << "House No# ";
        cin >> list[number_of_teachers].Teacher_info.address.house_no;
        cout << "Street No# ";
        cin >> list[number_of_teachers].Teacher_info.address.street_no;
        cout << "City# ";
        cin >> list[number_of_teachers].Teacher_info.address.city;
        cout << "Teacher's level of education: ";
        cout << "Teacher's education level: " << endl;
        cout << "1.BS\n2.MS\n3.P_hd\n";
        cin >> edut;
        if(edut==BSt)
            list[number_of_teachers].Teacher_info.level = "BS";
        else if(edut == MSt)
            list[number_of_teachers].Teacher_info.level = "MS";
        else if(edut == Phdt)
            list[number_of_teachers].Teacher_info.level = "P.hd";
        else    
            cout << "Invalid!" << endl;
        cout << "Teacher's salary: ";
        cin >> list[number_of_teachers].salary;
        cout << "Teacher's department: ";
        cout << "1.CE\n2.CH\n3.CS\n4.EE\n5.ES\n6.HM\n7.ME\n8.MM\n9.MS\n10.MT\n11.PE\n12.PH\n13.AI\n14.CyberSecurity\n15.DS\n";
        cin >> deptt;
        if(deptt == CE)
            list[number_of_teachers].Teacher_Dept = "CE";
        else if(deptt == CH)
            list[number_of_teachers].Teacher_Dept = "CH";
        else if(deptt == CS)
            list[number_of_teachers].Teacher_Dept = "CS";
        else if(deptt == EE)
            list[number_of_teachers].Teacher_Dept = "EE";
        else if(deptt == ES)
            list[number_of_teachers].Teacher_Dept = "ES";
        else if(deptt == HM)
            list[number_of_teachers].Teacher_Dept = "HM";
        else if(deptt == ME)
            list[number_of_teachers].Teacher_Dept = "ME";
        else if(deptt == MM)
            list[number_of_teachers].Teacher_Dept = "MM";
        else if(deptt == MS)
            list[number_of_teachers].Teacher_Dept = "MS";
        else if(deptt == MT)
            list[number_of_teachers].Teacher_Dept = "MT";
        else if(deptt == PE)
            list[number_of_teachers].Teacher_Dept = "PE";
        else if(deptt == PH)
            list[number_of_teachers].Teacher_Dept = "PH";
        else if(deptt == AI)
            list[number_of_teachers].Teacher_Dept = "AI";
        else if(deptt == CyberSecurity)
            list[number_of_teachers].Teacher_Dept = "Cyber Security";
        else if(deptt == DS)
            list[number_of_teachers].Teacher_Dept = "DS";
        else    
            cout << "Invalid!" << endl;
        number_of_teachers++;
    }

    // This function removes a teacher from the system
    void RemoveTeacher(){
        string name;
        int index;
        bool check = false;

        cout << "Enter name of the teacher to be removed: ";
        cin.ignore();
        getline(cin,name);

        // checking what is the index of the required teacher is in the array
        for(int i = 0; i < number_of_teachers; i++){
            if(list[i].Teacher_info.name == name){
                index = i;
                check  = true;
                break;
            }
        }

        // making a temporary dynamic array to store all teachers except the one to be removed
        if(check){
        Teacher * temp_t = new Teacher[100];
        int t = 0;
        // copying all elements from list to temp_t
        for(int i = 0; i < number_of_teachers; i++){
            if(i==index)
                continue;
            temp_t[t] = list[i];
            t++; 
        }
        number_of_teachers--;

        //copying back the elements to list
        for(int i = 0; i < number_of_teachers; i++){
            list[i] = temp_t[i];
        }

        // deallocating memory
        delete [] temp_t;
        }
        else
            cout << "No such teacher exists in the system" << endl << endl;
    }

    // This function updates a teacher's details
    void updateTeacher(){
        string name;
        int index;
        bool check = false;

        cout << "Enter the name of the teacher: ";
        cin.ignore();
        getline(cin,name);

        for(int i = 0; i < number_of_teachers; i++){
            if(list[i].Teacher_info.name==name){
                index = i;
                check = true;
                break;
            }
        }
        // Now updating th data at 'index' index location
        if(check){
        int edut;
        int deptt;
        string namet;

        cout << "Name of teacher: ";
        //cin.ignore();
        getline(cin,namet);
        list[index].Teacher_info.name = namet;
        cout << "Teacher's age: ";
        cin >> list[index].Teacher_info.age;
        cout << "Teacher's address: " << endl;
        cout << "House No# ";
        cin >> list[index].Teacher_info.address.house_no;
        cout << "Street No# ";
        cin >> list[index].Teacher_info.address.street_no;
        cout << "City# ";
        cin >> list[index].Teacher_info.address.city;
        cout << "Teacher's education level: " << endl;
        cout << "1.BS\n2.MS\n3.P_hd\n";
        cin >> edut;
        if(edut==BSt)
            list[index].Teacher_info.level = "BS";
        else if(edut == MSt)
            list[index].Teacher_info.level = "MS";
        else if(edut == Phdt)
            list[index].Teacher_info.level = "P.hd";
        else    
            cout << "Invalid!" << endl;
        cout << "Teacher's salary: ";
        cin >> list[index].salary;
        cout << "Teacher's department: ";
        cout << "1.CE\n2.CH\n3.CS\n4.EE\n5.ES\n6.HM\n7.ME\n8.MM\n9.MS\n10.MT\n11.PE\n12.PH\n13.AI\n14.CyberSecurity\n15.DS\n";
        cin >> deptt;
        if(deptt == CE)
            list[index].Teacher_Dept = "CE";
        else if(deptt == CH)
            list[index].Teacher_Dept = "CH";
        else if(deptt == CS)
            list[index].Teacher_Dept = "CS";
        else if(deptt == EE)
            list[index].Teacher_Dept = "EE";
        else if(deptt == ES)
            list[index].Teacher_Dept = "ES";
        else if(deptt == HM)
            list[index].Teacher_Dept = "HM";
        else if(deptt == ME)
            list[index].Teacher_Dept = "ME";
        else if(deptt == MM)
            list[index].Teacher_Dept = "MM";
        else if(deptt == MS)
            list[index].Teacher_Dept = "MS";
        else if(deptt == MT)
            list[index].Teacher_Dept = "MT";
        else if(deptt == PE)
            list[index].Teacher_Dept = "PE";
        else if(deptt == PH)
            list[index].Teacher_Dept = "PH";
        else if(deptt == AI)
            list[index].Teacher_Dept = "AI";
        else if(deptt == CyberSecurity)
            list[index].Teacher_Dept = "Cyber Security";
        else if(deptt == DS)
            list[index].Teacher_Dept = "DS";
        else    
            cout << "Invalid!" << endl;
        }
        else
            cout << "No such teacher exists in the system" << endl << endl;
    }

    // This function shoes record of all teachers
    void showRecord(){
        if(number_of_teachers==0)
            cout << "No record found" << endl;
        else{
        for(int i = 0; i < number_of_teachers; i++){
            cout << "Name of teacher: "<< list[i].Teacher_info.name << endl;
            cout << "Teacher's age: "<< list[i].Teacher_info.age << endl;
            cout << "Teacher's address: " << endl;
            cout << list[i].Teacher_info.address.house_no << endl;
            cout << list[i].Teacher_info.address.street_no << endl;
            cout << list[i].Teacher_info.address.city << endl;
            cout << "Teacher's level of education: " << list[i].Teacher_info.level << endl;
            cout << "Teacher's salary: "<< list[i].salary << endl;
            cout << "Teacher's department: "<< list[i].Teacher_Dept << endl;
            cout << endl << endl;
    }
    }
    }

    // This function shows the details of a particular teacher
    void showTeacherDetails(){
        string name;
        int index;
        bool check = false;
        cout << "Enter your name: ";
        cin.ignore();
        getline(cin,name);
        for(int i = 0; i < number_of_teachers; i++){
            if(list[i].Teacher_info.name == name){
                index = i;
                check = true;
                break;
            }
        }

        // Now displaying the details of the teacher
        if(check){
        cout << "Name of teacher: "<< list[index].Teacher_info.name << endl;
        cout << "Teacher's age: "<< list[index].Teacher_info.age << endl;
        cout << "Teacher's address: " << endl;
        cout << list[index].Teacher_info.address.house_no << endl;
        cout << list[index].Teacher_info.address.street_no << endl;
        cout << list[index].Teacher_info.address.city << endl;
        cout << "Teacher's level of education: " << list[index].Teacher_info.level << endl;
        cout << "Teacher's salary: "<< list[index].salary << endl;
        cout << "Teacher's department: "<< list[index].Teacher_Dept << endl;
        cout << endl << endl;
        }
        else
            cout << "No such teacher exists in the system" << endl << endl;
    }
};

// This structure stores the basic information of the admin
struct Admin{
    Person Admin_info;
    int salary;

};

// This structure stores the information regarding a certain course
// It contains the list of all the sudents undertaking a certain course along with instructors
struct Course{
    string course;
    string course_code;
    string course_teacher;
    Student *enrolled_students = new Student[100]; 
    Student *dropped_students = new Student[100];
    Student *graded_students = new Student[100];
    int enrolled;
    int dropped;
    int graded;
};

// This structure stores the list of all courses(where every course itslef is a structure)
struct ListofCourses{
    int number_of_courses;
    Course *list = new Course[50];

    // starting off with zero enrolled, zero graded and zero dropped students
    void scratch(){
    for(int i = 0; i < 50; i++){
        list[i].enrolled=0;
        list[i].graded=0;
        list[i].dropped=0;
    }
    }

    void scratch2(){
    for(int i = 0; i < 50; i++){
        for(int j = 0; j < 100; j++){
                list[i].graded_students[j].grade.Std_grade="";
                list[i].graded_students[j].grade.marks = 0;
                list[i].graded_students[j].grade.gpa = 0;

        }
    }
    }

    // This function adds course to the system
    void AddCourse(){
        string coursename;
        string coursecode;
        string courseteacher;

        cout << "Course Name: ";
        cin.ignore();
        getline(cin,coursename);
        list[number_of_courses].course = coursename;
        cout << "Course Code: ";
        // cin.ignore()
        getline(cin,coursecode);
        list[number_of_courses].course_code = coursecode;
        cout << "Course Teacher: ";
        // cin.ignore()
        getline(cin,courseteacher);
        list[number_of_courses].course_teacher = courseteacher;
        number_of_courses++;
    }

    // This function removes a course from the system
    void RemoveCourse(){
        string course_code;
        int index;
        bool check = false;

        cout << "Enter the course code to be removed: ";
        cin.ignore();
        getline(cin,course_code);
        
        // checking the list list of courses for the index of the course to be removed
        for(int i = 0; i < number_of_courses; i++){
            if(list[i].course_code == course_code){
                    index = i;
                    check = true;
                    break;
            }
        }

        //making a temporary dynamic array and copying all the remaining course there
        if(check){
        Course *tempc = new Course[50];
        int t = 0;
        for(int i = 0; i < number_of_courses; i++){
            if(i==index)
                continue;
            tempc[t] = list[i];
            t++;
        }
        number_of_courses--;

        // Now copying back all the courses to list of courses
        for(int i = 0; i < number_of_courses; i++){
            list[i] = tempc[i];
        }
        delete [] tempc;
        }
        else
            cout << "No such course exists in the system" << endl << endl;
    }

    // This function updates a course
    void updateCourse(){
        string coursename;
        string coursecode;
        string courseteacher;
        int index;
        bool check = false;

        cout << "Enter the course code to be updated: ";
        cin.ignore();
        getline(cin,coursecode);

        // checking where the required course lies in the list
        for(int i = 0; i < number_of_courses; i++){
            if(list[i].course_code == coursecode){
                index = i;
                check = true;
                break;
            }
        }

        // Now updating the course at "index" index
        if(check){
        cout << "Course Name: ";
        cin.ignore();
        getline(cin,coursename);
        list[index].course = coursename;
        cout << "Course Code: ";
        // cin.ignore()
        getline(cin,coursecode);
        list[index].course_code = coursecode;
        cout << "Course Teacher: ";
        // cin.ignore()
        getline(cin,courseteacher);
        list[index].course_teacher = courseteacher;
        }
        else
            cout << "No such course exists in the system" << endl << endl;
    }

    // This function shows the record of all courses
    void courseRecord(){
    if(number_of_courses == 0){
        cout << "No record found" << endl;
    }
    else{
        for(int i = 0; i < number_of_courses; i++){
        cout << "Course Name: "<<  list[i].course << endl;
        cout << "Course Code: "<< list[i].course_code << endl;
        cout << "Course Teacher: "<<  list[i].course_teacher << endl;
        if(list[i].enrolled>0){
        cout << "Students enrolled in the course are: "<< endl;
        for(int j = 0; j < list[i].enrolled; j++){
            cout << list[i].enrolled_students[j].roll_no << endl;

        }
        }
        cout << endl << endl;
        }
    }
    }

    // This function allocates a course to a teacher
    void allocateCoursetoTeacher(){
        string course_code;
        int index;
        bool check = false;

        cout << "Enter the course code to be allocated: ";
        cin.ignore();
        getline(cin,course_code);

        // looping through the list of courses to check the location of the required course
        for(int i = 0; i < number_of_courses; i++){
            if(list[i].course_code==course_code){
                index = i;
                check = true;
                break;
            }
        }

        // Now alocating the course at "index" to a new teacher
        if(check){
        string courseteacher;
        cout << "For the course " << list[index].course_code <<":" << endl;
        cout << "Add new teacher: ";
        //cin.ignore();
        getline(cin,courseteacher);
        list[index].course_teacher = courseteacher;
        }
        else
            cout << "No such course exists" << endl << endl;
    }

    // This function deallocates a course from a teacher
    void deallocateCoursefromTeacher(){
        string course_code;
        int index;
        bool check = false;

        cout << "Enter the course code to be deallocated: ";
        cin.ignore();
        getline(cin,course_code);

        for(int i = 0; i < number_of_courses; i++){
            if(list[i].course_code==course_code){
                index = i;
                check = true;
                break;
            }
        }

        // Now deallocating the course at "index" to a new teacher
        if(check){
        list[index].course_teacher="";
        }
        else
            cout << "No such course exists" << endl << endl;
    }

    // This functions un-enrolls a student from a specific course
    void un_enrollStudent(){
        string course_code;
        int index;
        int index2;
        int roll_no;
        bool check = false, check2 = false;
    
        cout << "Enter the course code: ";
        cin.ignore();
        getline(cin,course_code);
        cout << "Enter the Roll No of the students to be un_enrolled: ";
        cin >> roll_no;

        //loop to check the index location of the required course in the course list
        for(int i = 0; i < number_of_courses; i++){
            if(list[i].course_code == course_code){
                    index = i;
                    check = true;
                    break;
            }
        }
        if(check){
        // loop to check where the required student lies in the specific course's structure
        for(int i = 0; i < list[index].enrolled; i++){
            if(list[index].enrolled_students[i].roll_no==roll_no){
                index2 = i;
                check2 = true;
                cout << list[index].enrolled_students[i].roll_no << "lies " << i << endl;
                break;
            }
        }
        if(check2){
        list[index].dropped_students[list[index].dropped].roll_no = roll_no; // adding to dropped students
        list[index].dropped++;

        // making a temporary dynamic array and copying all the elements of enrolled students' array in that
        Student *temp_c = new Student[100];
        int t = 0;
        for(int i = 0; i < list[index].enrolled ; i++){
            if(i==index2)
                continue;
            temp_c[t] = list[index].enrolled_students[i];
            t++;
        }

        list[index].enrolled--;

        // now storing back the values in enrolled students' array omitting the unenrolled one
        for(int i = 0; i < list[index].enrolled ; i++){
             list[index].enrolled_students[i] = temp_c[i];
        }
        delete [] temp_c;
        }
        else
            cout << "Student is not enrolled in the particular course " << endl << endl;
        }
        else
            cout << "No such course exists in the system" << endl << endl;
    }

    // This function shows all the allocated courses to a particular teacher
    void showAllocatedCoursestoTeacher(){
        string name;
        bool check = false;
        cout << "Enter your name:";
        cin.ignore();
        getline(cin,name);

        // looping through all the courses to see which one belongs to the required teacher
        for(int i = 0; i < number_of_courses; i++){
            if(list[i].course_teacher == name){
                cout << list[i].course << endl;
                cout << list[i].course_code << endl;
                cout << endl;
            }
        }
        if(!check)
            cout << "No courses have been allocatecd yet" << endl << endl;
    }

    // This functions shows the list of students taking the courses allocated to a particular teacher
    void listOfStudentstakingCourses(){
        string name;
        bool check = false;
        cout << "Enter your name: "; // asking the name of the teacher
        cin.ignore();
        getline(cin,name);

        // looping through all the courses to fetch the courses the teacher teaches
        for(int i = 0; i < number_of_courses; i++){
            if(list[i].course_teacher == name){
                cout << list[i].course << endl;
                cout << list[i].course_code << endl;
                for(int j = 0; j < list[i].enrolled; j++){
                    cout << list[i].enrolled_students[j].roll_no << endl;
                    check = true;
                }
            }
        }
        if(!check)
            cout << "No students have enrolled in any course allocated to you" << endl << endl;
    }

    // This function gives grade to particular student
    void giveGrade(){
        string name;
        string course_code;
        bool check = false;
        int index;
        cout << "Enter your name: ";
        cin.ignore();
        getline(cin,name);
        cout << "Enter the course code: ";
        // cin.ignore()
        getline(cin,course_code);
        for(int i = 0; i < number_of_courses; i++){
            if(list[i].course_code==course_code){
                index = i;
                if(list[i].course_teacher == name){
                    check = true; // to check if the teacher entered the course they have been allocated
            }
            }
            
        }
        if(check){

            // Giving grade to individual students, one by one
            cout << list[index].enrolled << " students are enrolled in the course" << endl;
            for(int i = 0; i < list[index].enrolled; i++){
                list[index].graded_students[i].roll_no = list[index].enrolled_students[i].roll_no;
                cout << "Student " << list[index].enrolled_students[i].roll_no << endl;
                cout << "Grade: ";
                cin >> list[index].graded_students[i].grade.Std_grade;
                cout << "Marks: ";
                cin >> list[index].graded_students[i].grade.marks;
                cout << "GPA: ";
                cin >> list[index].graded_students[i].grade.gpa;
                list[index].graded++;
            }
        }
        else    
            cout << "Either the course is not added or it has not been allocated to the said teacher" << endl << endl;
    }

    // This function displays the top students in a certain course
    void TopStudent(){
        string course_code;
        int index;
        bool check1 = false;
        cout << "Enter the course code: ";
        cin.ignore();
        getline(cin,course_code);

        // looping through the list of courses to see where the course lies
        for(int i = 0; i < number_of_courses; i++){
            if(list[i].course_code == course_code){
                index = i;
                check1 = true;
            }
        }
        
        if(check1){
        int top_student = 0;
        int top_index;
        for(int i = 0; i < list[index].graded; i++){
            if(list[index].graded_students[i].grade.gpa > top_student){
                top_index = i;
                top_student = list[index].graded_students[i].grade.gpa;
            }
        }

        // Displaying the top student
        cout << " The top student in the course is: ";
        cout << list[index].graded_students[top_index].Std_info.name << "  " << list[index].enrolled_students[top_index].roll_no << endl;
        }
        else
            cout << "No such course exists in the system" << endl << endl;

    }

    // This function sorts the students based on their grade in a particular course
    void GradeviseDivision(){
        string course_code;
        int index;
        bool check = false;
        cout << "Course code: ";
        cin.ignore();
        getline(cin,course_code);

        // looping the entire list of courses to find the index of the required one
        for(int i = 0; i < number_of_courses; i++){
            if(list[i].course_code == course_code){
                check = true;
                index = i;
                break;
            }
        }

        //Now sorting the array of graded students 
        if(check){
        for(int i = 0; i < list[index].graded; i++){
                for(int j = 0; j < list[index].graded - i; j++){
                    if(list[index].graded_students[j].grade.gpa < list[index].graded_students[j+1].grade.gpa){
                        Student temp;
                        temp = list[index].graded_students[j];
                        list[index].graded_students[j] = list[index].graded_students[j+1];
                        list[index].graded_students[j+1] = temp;
                    }
                }  
        }   

        // Now displaying the graded students grade wise
        for(int i = 0; i < list[index].graded; i++){
            cout << list[index].graded_students[i].roll_no << "   " << list[index].graded_students[i].grade.gpa << endl;
        }
        }
        else
            cout << "No such course exists in the system " << endl << endl;
    }

    // This function allows students to enroll any available course
    void enrollCourse(){
        string course_code;
        int index;
        bool check = false; // this will check if the required course has been added by the admin

        cout << "Enter the course code: ";
        cin.ignore();
        getline(cin,course_code);

        // looping through the list of courses to find the index of the required course
        for(int i = 0; i < number_of_courses; i++){
            if(list[i].course_code == course_code){
                index = i;
                check = true;
                break;
            }
        }

        // Now enrolling the student in the asked course
        if(check){
        cout << "Enter your roll_no: " << endl;
        cin >> list[index].enrolled_students[list[index].enrolled].roll_no;
        list[index].enrolled++;
        }
        else
            cout << "The course is not availabe" << endl << endl;
        
    }

    // This function shows a student their final grade in a course
    void showGradeinCourse(){
        string course_code;
        int index;
        int roll_no;
        bool check1 = false, check2 = false;
        cout << "Enter the course code: ";
        cin.ignore();
        getline(cin,course_code);

        // looping through the list of course to check the index of the required course
        for(int i = 0; i <number_of_courses; i++){
            if(list[i].course_code == course_code){
                index = i;
                check1 = true;
                break;
            }
        }

        // Now asking the student for their roll no
        if(check1){
        cout << "Enter your roll no: ";
        cin >> roll_no;

        // looping through the array of graded students in the particular course to show that of the student
        for(int i = 0; i < list[index].graded; i++){
            if(list[index].graded_students[i].roll_no == roll_no){
                check2 = true;
                if(list[index].graded_students[i].grade.Std_grade != ""){
                    cout << "Grade: " << list[index].graded_students[i].grade.Std_grade << endl;
                    cout << "Marks: " << list[index].graded_students[i].grade.marks << endl;
                    cout << "GPA: " << list[index].graded_students[i].grade.gpa << endl;
                    break;
                }
            }
        }
        if(!check2)
            cout << "The student is not graded yet" << endl;
        }else
            cout << "No such course exists in the system" << endl << endl;
    }

    // This function shows a student the list of all their teachers
    void showMyTeachers(){
        string courses[100];
        int n;
        cout << "How many courses are you undertaking? ";
        cin >> n;
        cout << "Enter the course codes of all your course: ";
        cin.ignore();
        for(int i = 0; i < n; i++){
            // cin.ignore()
            getline(cin,courses[i]);
        }

        // Now looping through the list of courses allocated to teachers and displaying the student's teachers
        for(int i = 0; i < n; i++){
                for(int j = 0; j < number_of_courses; j++){
                    if(list[j].course_code == courses[i]){
                        cout << "Course : " << list[j].course << endl;
                        cout << "Course Code: " << list[j].course_code << endl;
                        cout << "Course Teacher: " << list[j].course_teacher << endl;
                        break;
                    }
                 }
                 cout << endl;
        }
    }

    // This function shows a student the list of all their enrolled courses based on the roll no they put in
    void showMyCourses(){
        int roll_no;
        bool check = false;
        cout << "Enter your roll no: ";
        cin >> roll_no;

        // looping through the list of all courses and showung only those in which the student has enrolled
        for(int i = 0; i < number_of_courses; i++){
            for(int j = 0; j < list[i].enrolled; j++){
                if(list[i].enrolled_students[j].roll_no == roll_no){
                    check = true;
                    cout << list[i].course_code << endl;
                }
            }
        }
        if(!check)
            cout << "You have not enrolled any course yet" << endl << endl;
    }

     // This function shows a student the list of all their completed courses based on the roll no they put in
    void showMyCompletedCourses(){
        int roll_no;
        bool check = false;
        cout << "Enter your roll no: ";
        cin >> roll_no;

        // looping through the list of all courses and showung only those in which the student has enrolled
        for(int i = 0; i < number_of_courses; i++){
            for(int j = 0; j < list[i].graded; j++){
                if(list[i].graded_students[j].roll_no == roll_no){
                    check = true;
                    cout << list[i].course_code << endl;
                }
            }
        }
        if(!check)
            cout << "You have not completed any course yet" << endl << endl;
    }

     // This function shows a student the list of all their dropped courses based on the roll no they put in
    void showMyDroppedCourses(){
        int roll_no;
        bool check = false;
        cout << "Enter your roll no: ";
        cin >> roll_no;

        // looping through the list of all courses and showung only those in which the student has enrolled
        for(int i = 0; i < number_of_courses; i++){
            for(int j = 0; j < list[i].dropped; j++){
                if(list[i].dropped_students[j].roll_no == roll_no){
                    check = true;
                    cout << list[i].course_code << endl;
                }
            }
        }
        if(!check)
            cout << "You have not dropped any course yet" << endl << endl;
    }
};

// This functions defines the interface for user
void Interface(char x){

    // Admins interface
    if(x=='a'){
        cout << "Admin's Terminal" << endl;
        cout << "1.Add a new student in system" << endl;//done
        cout << "2.Remove a student from system"<< endl;//done
        cout << "3.Update student detail" << endl; // done
        cout << "4.Check record of all students" << endl; // done
        cout << "5.Un-enroll a student from a course" << endl; //done
        cout << "6.Add a new teacher in system" << endl; // done
        cout << "7.Remove a teacher from the system" << endl; // done
        cout << "8.Update teacher detail" << endl; // done
        cout << "9.Check record of all teachers" << endl; // done
        cout << "10.Add a course in the system" << endl; // done
        cout << "11.Remove course from the system" << endl; // done
        cout << "12.Update course detail" << endl; // done
        cout << "13.Check record of all courses" << endl; // done
        cout << "14.Allocate a course to teacher" << endl;  // done
        cout << "15.De-allocate a course from teacher" << endl; // done
        cout << "16.Exit" << endl;
    }

    // Teacher's interface
    if(x=='t'){
        cout << "1.Check my details in the system" << endl; // done
        cout << "2.See the list of allocated courses" << endl; // done
        cout << "3.List of students in the allocated courses" << endl; // done
        cout << "4.Assign marks and grades to students" << endl;// done
        cout << "5.See the top student" << endl; // done
        cout << "6.Grade wise division of students in the allocated courses" << endl; // done
        cout << "7.Exit" << endl; // done
    }

    // Student's inteface
    if(x=='s'){
        cout << "1. Check my details in the system" << endl; // done
        cout << "2.Enroll any available course" << endl; // done
        cout << "3.See my final grade in any course" << endl; // done
        cout << "4.See the list of all my teachers" << endl; // done
        cout << "5.See the list of enrolled courses" << endl; // done
        cout << "6.See the list dropped courses" << endl; // done
        cout << "7.See the list of completed courses" << endl; // done
        cout << "8.Exit" << endl; // done
    }
}

// This function performs the tasks for the admin
void AdminDuties(StudentList &AdminsListOfStudents, ListofCourses &AdminsListOfCourses, TeachersList &AdminsListofTeachers){
    AdminsListOfCourses.scratch(); // this function sets the entire list of enrollwd, dropped and graded students to zero
    int x = 0;
    do{
    Interface('a'); // Prints the options availabe to the admin
    cin >> x;
    switch(x){
        case 1:
            AdminsListOfStudents.AddStudent();
            break;
        case 2:
            AdminsListOfStudents.RemoveStudent();
            break;
        case 3:
            AdminsListOfStudents.updateStudent();
            break;
        case 4:
            AdminsListOfStudents.showRecordofStudents();
            break;
        case 5:
            AdminsListOfCourses.un_enrollStudent();
            break;
        case 6:
            AdminsListofTeachers.AddTeacher();
            break;
        case 7:
            AdminsListofTeachers.RemoveTeacher();
            break;
        case 8:
            AdminsListofTeachers.updateTeacher();
            break;
        case 9:
            AdminsListofTeachers.showRecord();
            break;
        case 10:
            AdminsListOfCourses.AddCourse();
            break;
        case 11:
            AdminsListOfCourses.RemoveCourse();
            break;
        case 12:
            AdminsListOfCourses.updateCourse();
            break;
        case 13:
            AdminsListOfCourses.courseRecord();
            break;
        case 14:
            AdminsListOfCourses.allocateCoursetoTeacher();
            break;
        case 15:
            AdminsListOfCourses.deallocateCoursefromTeacher();
            break;
        case 16:
            break;
        default:
            break;
    }
    }while(x!=16);
    
}

// This function performs the tasks for the teacher
void TeacherDuties(TeachersList &AdminsListofTeachers, ListofCourses &AdminsListOfCourses){
    AdminsListOfCourses.scratch2(); // this function sets the entire list of enrollwd, dropped and graded students to zero
    int x = 0;
    do{
    Interface('t');
    cin >> x;
    switch(x){
        case 1:
            AdminsListofTeachers.showTeacherDetails();
            break;
        case 2:
            AdminsListOfCourses.showAllocatedCoursestoTeacher();
            break;
        case 3:
            AdminsListOfCourses.listOfStudentstakingCourses();
            break;
        case 4:
            AdminsListOfCourses.giveGrade();
            break;
        case 5:
            AdminsListOfCourses.TopStudent();
            break;
        case 6:
            AdminsListOfCourses.GradeviseDivision();
            break;
        case 7:
            break;
    }
    }while(x!=7);   
}
    // This function performs the tasks for the student
    void StudentDuties(StudentList &AdminsListOfStudents, ListofCourses &AdminsListOfCourses){
        int x = 0;
        do{
            Interface('s');
            cin >> x;
            switch(x){
                case 1:
                    AdminsListOfStudents.showStudentDetails();
                    break;
                case 2:
                    AdminsListOfCourses.enrollCourse();
                    break;
                case 3:
                    AdminsListOfCourses.showGradeinCourse();
                    break;
                case 4:
                    AdminsListOfCourses.showMyTeachers();
                    break;
                case 5:
                    AdminsListOfCourses.showMyCourses();
                    break;
                case 6:
                    AdminsListOfCourses.showMyDroppedCourses();
                    break;
                case 7:
                    AdminsListOfCourses.showMyCompletedCourses();
                    break;
                case 8:
                    break;
             }
        }while(x!=8);
    }


int main(){

    StudentList AdminsListOfStudents;
    AdminsListOfStudents.number_of_students=0;

    ListofCourses AdminsListOfCourses;
    AdminsListOfCourses.number_of_courses=0;

    TeachersList AdminsListofTeachers;
    AdminsListofTeachers.number_of_teachers = 0;

    int user;

    do{
    cout << "Choose the category:\n1.Admin\n2.Teacher\n3.Student\n4.Exit\n";

    cin >> user;

    switch(user){
        case 1:
            AdminDuties(AdminsListOfStudents, AdminsListOfCourses, AdminsListofTeachers);
            break;
        case 2:
            TeacherDuties(AdminsListofTeachers, AdminsListOfCourses);
            break;
        case 3:
            StudentDuties(AdminsListOfStudents, AdminsListOfCourses);
            break;
        case 4:
            break;
        default:
            cout << "Sorry, can't help" << endl;
            break;
    }
    }while(user!=4);

    // deallocating all the dynamically created arrays
    delete [] AdminsListOfCourses.list;
    delete [] AdminsListOfStudents.list;
    delete [] AdminsListofTeachers.list;
    delete [] AdminsListOfCourses.list->enrolled_students;
    delete [] AdminsListOfCourses.list->graded_students;
    delete [] AdminsListOfCourses.list->dropped_students;


    return 0;
}

