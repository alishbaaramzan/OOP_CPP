
struct Person{
    char *name;
    int age;
};

Person myfunc(Person a, Person b){
    a=b;
    return a;
}