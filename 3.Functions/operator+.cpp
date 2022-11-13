#include <iostream>
#include <vector>

std::vector<double> operator+ (const std::vector<double>& vec_a,
                               const std::vector<double>& vec_b){
    assert( vec_a.size() == vec_b.size() ); // Complain if sizes are not
    auto N = vec_a.size();                  // compatible (debug only)
    
    std::vector<double> vec_sum(N, 0.0);
    for (auto i = 0; i < N; i++){
        vec_sum[i] = vec_a[i] + vec_b[i];
    }
    return vec_sum;
}

int main(){
    std::vector<double> vec_a = {1, 2, 3};
    std::vector<double> vec_b = {4, 5, 6};
    auto res = vec_a + vec_b;
    return 0;
}