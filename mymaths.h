// returning length of a string
int len_string(char a[]){
    int len = 0;
    for(int i = 0; i < 100; i++){
        if(a[i]=='\0')
            break;
        len++;
    }
    return len;
}

// returning minimum of an array
int min(int arr[5]){
    int min = arr[0];
    for(int i = 0; i < 5; i++){
        if(arr[i]<min){
            min = arr[i];
        }
    }
    return min;
}

// retuurning maximum of an array
int max(int arr[5]){
    int max = arr[0];
    for(int i = 0; i < 5; i++){
        if(arr[i]>max){
            max = arr[i];
        }
    }
    return max;
}