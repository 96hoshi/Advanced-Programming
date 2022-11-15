#include <iostream>     // std::cout
#include <algorithm>    // std::swap

// Recursive
int gcd_recursive(int a, int b){
    if (b == 0){
        return a;
    } else {
        return gcd(b, a%b);
    }
}

// Iterative
int gcd_iterative(int a, int b){
    int c = 0;
    while (b != 0){
        c = a%b;
        a = b;
        b = c;
    }
    return a;
}

// Iterative with no temporary var
int gcd_iterative2(int a, int b){
    int c = 0;
    while (b != 0){
        std::swap(a,b);
        b = b%a;
    }
    return a;
}

int main(){
    // Get the vector elements from the user
    int a;
    std::cout << "Give the value of a:\n";
    std::cin >> a;

    int b;
    std::cout << "Give the value of b:\n";
    std::cin >> b;

    std::cin.clear();
    std::cin.ignore();

    // Compute the Greatest Common Divisor
    std::cout << "gcd recursive: " << gcd_recursive(a, b) << endl;
    std::cout << "gcd iterative: " << gcd_iterative(a, b) << endl;
    std::cout << "gcd iterative2: " << gcd_iterative2(a, b) << endl;

    return 0;
}
