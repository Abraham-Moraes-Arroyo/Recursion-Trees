#include<iostream>
#include<vector>

using namespace std;


int my_sum(int a, int b){
    /*
    recursively adds two integers a and b
    i.e. a+b is computed by adding 'a' copies 
    of 1 and then the b value
    */

    if ((a == 0) or (b == 0))
       return a+b;
    else
       return 1 + my_sum(a-1,b); 
}

int collatz(int n){
    /*
    if n is even, returns n/2
    if n is odd, return 3n+1
    
    these steps fed back into the function until
    n has been reduced to 1.
    */

    if (n == 1){
       cout << n << endl;
       return 1;
    }
    else if (n%2 == 0){
       cout << n << endl;
       return collatz(n/2);
    }
    else{
       cout << n << endl;
       return collatz(3*n+1); 
    }
}

int sum_of_vector_values(vector<int> v){
    // here we want to sum up all values in a vector recursively
    if (v.size() == 1)
       return v[0];
    else{
       // here we skip the first element; like v2 = v[1:] in Python
       vector<int> v2 = vector<int>(v.begin() + 1, v.end());
       return v[0] + sum_of_vector_values(v2);
    }
}

int main(){
    cout << my_sum(5, 9) << endl;
    collatz(3);
    vector<int> v{1,3,5,7,9};
    cout << sum_of_vector_values(v) << endl; 
    return 0;
}
