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

#include "../random_algo/lcg.hpp"

using namespace std;
using ll=long long;

const ll TEST_MAX_NUM = 100;

int main()
{
    Random* rand = new LCG();
    // check jump(n) == jump_naive(n)
    for(ll i=0;i<TEST_MAX_NUM;i++){
        assert(rand->jump_naive(1,i) == rand->jump(1,i));
    }
}