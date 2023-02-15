// This enum stores values for educational qualification of any person
enum education{BS=1,MS,Phd};
// This enum stores values for the dept. of a student
enum dept{
    CE=1, CH, CS, EE, ES, HM, ME, MM, MS, MT, PE, PH, AI, CyberSecurity, DS
};
// This enum stores the gpa related to every grade
enum grade{
    A, A_neg, B_pos, B, B_neg, C_pos, C, C_neg, D_pos, D, F 
};
// This stucture stores address of any person
struct address{
    int house_no;
    int street_no;
    char city[50];
};
// This structure serves as a template for storing basic personal information of any person
struct Person{
    char name[50];
    int age;
    address Address;
    education level;
};
//This structure stores information of a student
struct Student{
    Person Std_info;
    int roll_no;
     char Std_Dept[50];
};
// This structure stores basic information of a teacher
struct Teacher{
    Person Teacher_info;
    long int salary;
    char Teacher_Dept[50]; 
};
// This structure stores the basic information of the admin
struct Admin{
    Person Admin_info;
    int salary;
};
// This structure stores the information regarding a certain course
// It contains the list of all the sudents undertaking a certain course along with instructors
struct Course{
    char course[50];
    char course_code[50];
    char course_teacher[50];
    string enrolled_students[100];
    string dropped_students[100];
    string graded_students[100];
};
// This structure stores the grades of a particular course taken by a student
struct Grade{
    char Std_grade[2];
    int marks;
    float gpa;
};

