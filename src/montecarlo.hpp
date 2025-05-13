#include <fstream>
#include <iostream>
#include <random>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <limits>
#include <chrono>
#include <thread>

#include "../random_algo/lcg.hpp"
#include "../random_algo/xorshift.hpp"

using namespace std;
using ll=long long;

bool is_inside(double x,double y){
    if(x*x+y*y <= 1)return true;
    return false;
}

ll get_next_rand(ll now, Random* rand_){
    return rand_->random(now);
}

double montecarlo(ll seed,ll loop_num, Random* rand_){
    ll res=0;
    ll n=seed;
    for(ll i=0;i<loop_num;i++){
        double r1=((double)n)/((double)rand_->MAX);
        n=get_next_rand(n, rand_);
        double r2=((double)n)/((double)rand_->MAX);
        n=get_next_rand(n, rand_);
        if(is_inside(r1,r2)){
            res++;
        }
    }
    return res;
}

vector<double> multi_montecarlo(ll repeat_num, ll loop_num){
    Random* rand_ = new Xorshift32();
    std::random_device seed_gen;
    vector<double> res;
    for(int i=0;i<repeat_num;i++){       
        ll seed= seed_gen();
        ll in = montecarlo(seed,loop_num, rand_);
        double calculated_pi = ((double) in*4) / ((double) loop_num);
        res.push_back(calculated_pi);
    }
    delete rand_;
    return res;
}

vector<double> multi_thread_montecarlo(ll repeat_num, ll loop_num, ll thread_num){
    
}