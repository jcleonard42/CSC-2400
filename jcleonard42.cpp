/*
	Title:  		jcleonard42.cpp
	Author:			Jonathan Leonard
	Date Created:  	June 2, 2022
	Purpose:  		Implement Euclid's algorithm to find
                    the greatest common denominator of two
                    integers.
				
*/

#include <iostream>
#include <cmath>
using namespace std;

int gcd(int, int);   // Greatest common denominator funtion prototype

int main(){
    int m, n;  // Variables respnsible for user input
    int temp;  // Variable used to swap integer values if needed
    int v;     // Greatest Common Factor value

    cout << "\nEnter two integers seperated by a space: ";   // User input section
    cin >> m >> n;
    cout << endl;

    if(n>m){    // Swaps user input values if needed
        temp = m;
        m = n;
        n = temp;
    }

    if(m != 0 && n != 0){  // This outputs starting values before any operations are performed
        cout << "gcd(" << m << ", "<< n << ") =\n";
    }

    v = gcd(m, n);   // Calls function and assigns returned value to v

    if(n == 0){    // Checks n to ensure it is not undefined
        cout << "\ngcd(" << m << ", " << n << ") is undefined" << endl;
    }
    else{
        cout <<"\nSOLUTION: gcd(" << m << ", " << n << ") is " << v << endl;
    }
    
    return 0;
}

int gcd(int m, int n){
    if(n == 0){    // Returns m if there is no remainder
        return m;
    }
    else{    // This is a recursive funtion call for any case where there is still a remainder
        cout << "gcd(" << m << ", (" << m << "%" << n << ")) =\n";
        return gcd(n, m % n);
    }
}
