// This programs computes the factorial of a number by recursion
// This is to be used as a custom header file

int factorial(int n){
    if (n==1)
        return 1;
    return n * factorial(n-1);
}