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

#include "../random_algo/xorshift.hpp"

using namespace std;
using ll=long long;

const ll TEST_MAX_NUM = 100;

int main()
{
    Xorshift32* rand = new Xorshift32();
    rand -> make_matrix();
    for(ll i=1;i<100;i++){
        F2Matrix vec = convert_uint32_t_to_F2_32(i);
        F2Matrix res = vec * rand->matrix;
        ll next_m = convert_F2_32_to_uint32_t(res);
        ll next = rand -> random(i);
        assert(next_m == next);
    }
}