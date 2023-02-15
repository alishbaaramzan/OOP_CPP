#include<iostream>
using namespace std;

int DecimaltoBinary(int num){
    int b = 0;
    int i = 1;
    while(num!=0){
      b = b + (num%2) * i;
      num /= 2;
      i*=10;  
    }
    return b;
}
int DecimaltoOcta(int num){
    int octa = 0;
    int i = 1;
    while(num!=0){
        octa = octa + (num%8)*i;
        num/=8;
        i*=10;
    }
    return octa;
}
int DecimaltoHexa(int num){
    int hexa = 0;
    int i = 1;  
    while(num!=0){
        hexa = hexa + (num%16)*i;
        num/=16;
        i*=10;
    }
    return hexa;
}
int BinarytoDecimal(int num){
    int i = 1;
    int dec = 0;
    while(num!=0){
        dec = dec + (num%10)*i;
        i*=2;
        num/=10;
    }
    return dec;
}
int OctatoDecimal(int num){
    int i = 1;
    int dec = 0;
    while(num!=0){
        dec = dec + (num%10)*i;
        i*=8;
        num/=10;
    }
    return dec;
}
int HexatoDecimal(int num){
    int i = 1;
    int dec = 0;
    while(num!=0){
        dec = dec + (num%10)*i;
        i*=16;
        num/=10;
    }
    return dec;
}
int main(){
    int option;
    int num;

    // Displaying options
    cout << "For conversions:\n";
    cout << "1. Binary to decimal\n";
    cout << "2. Octadecimal to decimal\n";
    cout << "3. Hexadecimal to decimal\n";
    cout << "4. Decimal to binary\n";
    cout << "5. Decimal to octadecimal\n";
    cout << "6. Decimal to hexadecimal\n";
    cin >> option;

    // Switch statement to call relevant function
    switch(option){
        case 1:
        {
            cout << "Enter number: ";
            cin >> num;
            cout << "The required conversion is " << BinarytoDecimal(num) << endl;
            break;
        }
        case 2:
        {
            cout << "Enter number: ";
            cin >> num;
            cout << "The required conversion is " << OctatoDecimal(num) << endl;
            break;
        }
        case 3:
        {
            cout << "Enter number: ";
            cin >> num;
            cout << "The required conversion is " << HexatoDecimal(num) << endl;
            break;
        }
        case 4:
        {
            cout << "Enter number: ";
            cin >> num;
            cout << "The required conversion is " << DecimaltoBinary(num) << endl;
            break;
        }
        case 5:
        {
            cout << "Enter number: ";
            cin >> num;
            cout << "The required conversion is " << DecimaltoOcta(num) << endl;
            break;
        }
        case 6:
        {
            cout << "Enter number: ";
            cin >> num;
            cout << "The required conversion is " << DecimaltoHexa(num) << endl;
            break;
        }
        default:
            cout << "Invalid!" << endl;
            break;

    }
    return 0;

}