// This is a practice template for header files
class PracticeClass{
    private:
    int num1;
    int num2;

    public:
    PracticeClass(){}
    PracticeClass(int num1, int num2){
        this->num1 = num1;
        this->num2 = num2;
    }
    PracticeClass(const PracticeClass &a){
        this->num1 = a.num1;
        this->num2 = a.num2;
    }
    void setter(int num1, int num2){
        this->num1 = num1;
        this->num2 = num2;
    }
    int getter1(){
        return num1;
    }
    int getter2(){
        return num2;
    }
    int getSum(){
        return num1+num2;
    }
};