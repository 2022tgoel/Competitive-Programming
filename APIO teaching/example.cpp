
// c++ is compiled while python is interpreted 

// two parts
// converting the code into instructions for you computer (compilation)
// running those instructions (executing)

// in python, these happen that the same time (alternating)
// in c++, all the compilation happens first, and then all of the executing 

// return_type name(arguments) { ..code }

// standard library

// #include <bits/stdc++.h> // importing the standard library, which includes printing stuff
#include <iostream> 
#include <vector>

using namespace std; // from std import * 

// module.function
// modlue::function

int square(int i) {
    return i*i;
}

// logical operators: operations on booleans 
// AND (&&)
// true && true = true
// true && false = false 

// OR (||)
// true || false = true

// NOT (!)
// !true = false 


int a(int n){
    if (n == 1 || n == 2) {
        return 1;
    }
    return a(n-1) + a(n-2);
}

// declaration
// declration a "promise" that the function will be defined later in the code 

int f(int n);

int g(int n){
    if (n == 1 ) {
        return 2;
    }
    return n*f(n-1);
}


int f(int n){
    if (n == 1 ) {
        return 1;
    }
    return n*g(n-1);
}


// type name[size]
// char s[6]

int arr[10];

vector<int> vec; // vec = []

int main(){ // everything in the main function will be executed 
    vec.push_back(5);
    vec.push_back(6);
    vec.push_back(10);
    // [5, 6, 10]
    vec.erase(vec.end());
    vec.push_back(8);
    // [5, 6, 8]
    for (int i = 0; i < vec.size(); i++){
        cout << vec[i] << endl;
    }

    int n = 10; int x = 10;

    // #1 initialization (run at first iteration of the for loop)
    // #2 will the checked at the start of the loop, exit if #2 not satisfied
    // #3 applied at the end of the loop

    for (int i = 1; i <= n; i++){
        cout << square(i) << endl;
    }

    // square(4.5);

    // string s = "hello"; 
    char s[6] = "hello";

    cout << s<< endl;  // "hello"

    s[5] = 6; // replaced the part telling the program where to stop priting with an actual value
    // so it will keep printing 

    // cout << s << endl;

    // int i = 1;
    // while (i <= 6){
    //     for (int j = 0; j < i; j++) 
    //         cout << s[j];
    //     cout << endl;
    //     i++;
    // }

    cout << a(6) << endl;
    cout << f(4) << endl;
}