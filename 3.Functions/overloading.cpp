#include <iostream>     // std::cout
#include <vector>
#include <cassert>


void print_vector(const std::vector<int> &v) {
    std::cout << " [ ";
    for (const auto &elem : v) {
        std::cout << elem << " ";
    }
    std::cout << "]" << std::endl;
}

void print_matrix(const std::vector<std::vector<int>> &A) {
    std::cout << "[" << std::endl;
    for (const auto &row : A) {
        for (const auto &elem : row) {
            std::cout << elem << " ";
        }
    std::cout << std::endl;
    }
    std::cout << "]" << std::endl;
}

void print_vector(const std::vector<double> &v) {
    std::cout << " [ ";
    for (const auto &elem : v) {
        std::cout << elem << " ";
    }
    std::cout << "]" << std::endl;
}

void print_matrix(const std::vector<std::vector<double>> &A) {
    std::cout << "[" << std::endl;
    for (const auto &row : A) {
        for (const auto &elem : row) {
            std::cout << elem << " ";
            }
        std::cout << std::endl;
        }
    std::cout << "]" << std::endl;
}

template <typename T>
void template_print_vector(T v){
    return print_vector(static_cast<T>(v));
}

template <typename T>
void template_print_matrix(T A){
    return print_matrix(static_cast<T>(A));
}

template <typename T>
std::vector<T> operator* (const std::vector<std::vector<T>> & Matrix,
                          const std::vector<T>& vec){
    int N = vec.size();
    assert( Matrix[0].size() == N ); // Complain if sizes are not
    //auto N = vec_a.size();           // compatible (debug only)

    std::vector<T> m(N, 0);
    for (auto i = 0; i < N; ++i) {
        for (auto j = 0; j < N; ++j) {
            m[i] += Matrix[i][j] * vec[j];
        }
    }
    return m;
}

bool test_matrix_vector_product(){
    std::vector<std::vector<int>> mat = {{1, 2, 3}, {1, 2, 3}, {1, 2, 3}};
    std::vector<int> vec = {1, 2, 3};
    int N = 3;
    int result = 14;

    std::vector<int> test = mat*vec;

    for (auto i = 0; i < N; ++i) {
        for (auto j = 0; j < N; ++j) {
            if (test[i] != result) {
                return false;
            }
        }
    }
    return true;
}


int main(){
    // Get the vector elements from the user
    std::vector<double> v{};
    std::cout << "Give elements to the vector v\n";
    double x;
    while (std::cin >> x) {
        v.push_back(x);
    }
    std::cin.clear();
    std::cin.ignore();

    // Print the vector v
    std::cout << "Vector v is:\n";
    template_print_vector(v);

    // Get a square matrix A
    const auto N = v.size();
    std::cout << "Give the " << N * N << " elements of matrix A (row-first)\n";
    std::vector<std::vector<double>> A(N); // We define just the lines for now
    for (auto i = 0; i < N; ++i) {
        for (auto j = 0; j < N; ++j) {
            double y;
            std::cin >> y;
            A[i].push_back(y);
        }
    }

    // Print the matrix A
    std::cout << "Matrix A is:" << std::endl;
    template_print_matrix(A);

    // Multiply A * v and store it to a vector m
    std::vector<double> m(N, 0);
    for (auto i = 0; i < N; ++i) {
        for (auto j = 0; j < N; ++j) {
            m[i] += A[i][j] * v[j];
        }
    }

    // Print the vector m
    std::cout << "Vector m = A * v is:" << std::endl;
    template_print_vector(m);

    std::cout << "Vector m = A * v with operator* is:" << std::endl;
    template_print_vector(A*v);

    if (test_matrix_vector_product()){
        std::cout << "TEST_RES: The operator* works fine!" << std::endl;
    } else {
        std::cout << "TEST_RES: The operator* does not work. :c" << std::endl;
    }

    return 0;
}
