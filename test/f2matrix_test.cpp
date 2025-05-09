#include <fstream>
#include <iostream>
#include <random>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <limits>
#include <chrono>
#include <cassert>

#include "../random_algo/matrix/useful_f2matrixes.hpp"

using namespace std;
using ll=long long;


int main()
{
    F2Matrix m1=F2Matrix(2,2);
    m1.matrix[0][0] = 1;
    m1.matrix[0][1] = 1;
    m1.matrix[1][0] = 1;
    m1.matrix[1][1] = 1;
    
    F2Matrix m1_ = F2Matrix({{1,1},
                             {1,1}});
    assert(m1==m1_);

    F2Matrix m2=F2Matrix(2,2);
    m2.matrix[0][0] = 1;
    m2.matrix[0][1] = 1;
    m2.matrix[1][0] = 0;
    m2.matrix[1][1] = 1;
    
    F2Matrix m3 = m1*m2;
    F2Matrix m3_ = F2Matrix({{1,0},
                             {1,0}});
    assert(m3==m3_);
    cout << m1 << endl;
    cout << "*" << endl;
    cout << m2 << endl;
    cout << "=" << endl;
    cout << m3 << endl;
    cout << endl;

    F2Matrix m4 = m1+m2;
    F2Matrix m4_ = F2Matrix({{0,0},
                             {1,0}});
    assert(m4==m4_);
    
    cout << m1 << endl;
    cout << "+" << endl;
    cout << m2 << endl;
    cout << "=" << endl;
    cout << m4 << endl;
    
    for(ll i=0;i<1000;i++)
        assert(convert_F2_32_to_uint32_t(convert_uint32_t_to_F2_32(i)) == i);
}