#include<iostream>
using namespace std;

class Matrix{
    private:
    int rows;
    int cols;
    int **data;
    public:

    Matrix(){}
    // constructor
    Matrix(int r, int c){
        rows = r;
        cols = c;
        data = new int*[rows];
        for(int i = 0; i < rows; i++){
            data[i] = new int[cols];
        }
        // initializing the data array to zero
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                data[i][j] = 0;
            }
        }
    }

    // Copy Constructor
    Matrix(const Matrix &m){
        rows = m.rows;
        cols = m.cols;
        data = new int*[rows];
        for(int i = 0; i < rows; i++){
            data[i] = new int[cols];
        }
        // initializing the data array to zero
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                data[i][j] = m.data[i][j];
            }
        }
    }

    // Overloaded assignment operator
    Matrix operator=(const Matrix &m){
        Matrix temp;
        temp.rows = m.rows;
        temp.cols = m.cols;
        temp.data = new int*[temp.rows];
        for(int i = 0; i < temp.rows; i++){
            temp.data[i] = new int[temp.cols];
        }
        // initializing the data array to zero
        for(int i = 0; i < temp.rows; i++){
            for(int j = 0; j < temp.cols; j++){
                temp.data[i][j] = m.data[i][j];
            }
        }
        return temp;
    }

    // set function
    void set(int r, int c, int v){
        data[r][c] = v;
    }

    // get function
    int set(int r, int c){
        return data[r][c];
    }

    // function to create an identity matrix
    static Matrix identity(int n){
        Matrix temp;
        temp.rows = n;
        temp.cols = n;
        temp.data = new int*[temp.rows];
        for(int i = 0; i < temp.rows; i++){
            temp.data[i] = new int[temp.cols];
        }

        for(int i = 0; i < temp.rows; i++){
            for(int j = 0; j < temp.cols; j++){
                if(i==j){
                    temp.data[i][j] = 1;
                }
                else
                    temp.data[i][j] = 0;
            }
        }
         return temp;
    }

    void displayMatrix(){
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }
    //Destructor
    ~Matrix(){
        for(int i = 0; i < rows; i++){
            delete [] data[i];
        }
        delete data;
    }
};
int main(){
    int n;
    cout << "Enter the dimensions of the identity matrix: ";
    cin >> n;
    Matrix identity = Matrix :: identity(n);
    identity.displayMatrix();
    return 0;
}