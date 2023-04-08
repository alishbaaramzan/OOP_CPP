#include<iostream>
#include<iomanip>
using namespace std;

enum Rivaj{LIPSTICK=1, NAIL_POLISH, EYE_LINER}; 

// structure to store name and price of the order 
struct Cust_order{
    string name;
    float price;
};
// forward declaration
class Order;
class ShoppingClass;
// class for storing details of products in the market
class Product{
    string name;
    string desc;
    float price;
    bool avail;
    static int number;

    public:
    Product(){
        // constructor for initializing the products
        cout << "PRODUCT " << number+1 << endl;
        cout << "Enter name of product: ";
        cin >> name;
        cin.ignore();
        cout << "Enter description of product: ";
        getline(cin,desc);
        cout << "Enter price of product: ";
        cin >> price;
        avail = true;
        number++;
    }

    // display available products
    void displayProducts(){
        if(avail == true){
            cout << name <<endl;
            cout << desc <<endl;
            cout << price << endl << endl;
        }
    }
    friend class Order;
};
class Order{
    private:
    Cust_order *order;
    static int number_of_orders; // keep track of the number of orders
    public:
    Order(){
        order = new Cust_order[10];
    }
     // This function displays the values of the 
    void takeOrder(Product arr[]){
        Rivaj ord; // instance of enums 
        while(true){
        int n;
        cout << "Order from the following list: " << endl;
        for(int i = 0; i < Product :: number; i++){
            cout << "Product " << i+1 <<": ";
            arr[i].displayProducts();
        }
        cout << "Place your order :";
        cin >> n;
        // setting enum values
        if(n==1) ord = LIPSTICK;
        if(n==2) ord = NAIL_POLISH;
        if(n==3) ord = EYE_LINER;
        // now placing the order
        if(ord==LIPSTICK){
            order[number_of_orders].name = arr[ord-1].name;
            order[number_of_orders].price = arr[ord-1].price;
            arr[ord-1].avail = false;
            number_of_orders++;
            }
        else if(ord==NAIL_POLISH){
            order[number_of_orders].name = arr[ord-1].name;
            order[number_of_orders].price = arr[ord-1].price;
            arr[ord-1].avail = false;
            number_of_orders++;
            }
        else if(ord==EYE_LINER){
            order[number_of_orders].name = arr[ord-1].name;
            order[number_of_orders].price = arr[ord-1].price;
            arr[ord-1].avail = false;
            number_of_orders++;
    }
    char option;
    cout << "Do you wish to order more? (y/n)";
    cin >> option;
    if(option=='n')break;
    }
    }
    friend class ShoppingCart;
    ~Order(){
        delete [] order;
    }
};

class ShoppingCart{
    float total_price;
    Cust_order *cart;
    
    public:
    ShoppingCart(){
        cart = new Cust_order[Order :: number_of_orders];
        total_price = 0;
    }
    void updateCart(Order &o){
        for(int i = 0; i < Order :: number_of_orders; i++){
            cart[i] = o.order[i]; 
            total_price += o.order[i].price;
        }
    }
    // displaying bill and stuff
    void displayBill(){
        cout << "Your Shopping Cart is as follows: " << endl << endl;
        for(int i = 0; i < Order :: number_of_orders; i++){
            cout << setw(10) << cart[i].name;
            cout << setw(10) << cart[i].price << endl;
        }
        cout << "Total price is : " << total_price << endl;
    }

    ~ShoppingCart(){
        delete [] cart;
    }

};
int Order :: number_of_orders = 0;
int Product :: number = 0;
int main(){
    Product p[3];
    Order order;
    order.takeOrder(p); // taking order
    ShoppingCart cart;
    cart.updateCart(order);
    cart.displayBill();
    return 0;
}