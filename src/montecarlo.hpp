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
#include <mutex>

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

double montecarlo(ll &n,ll loop_num, Random* rand_){
    ll res=0;
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

ll in_sum = 0;
vector<vector<double>> results;


class Args{
    public:
    ll repeat_num;
    ll loop_num;
    ll seed;
    ll tid;
};

void multi_montecarlo(Args& args){
    Random* rand_ = new Xorshift32();
    vector<double> res;
    ll n = args.seed;
    for(int i=0;i<args.repeat_num;i++){
        ll in = montecarlo(n,args.loop_num, rand_);
        double calculated_pi = ((double) in*4) / ((double) args.loop_num);
        res.push_back(calculated_pi);
    }
    delete rand_;
    results[args.tid]=res;

}

vector<double> multi_thread_montecarlo(ll repeat_num, ll loop_num, ll thread_num){
    results = vector<vector<double>>(thread_num);
    vector<Args> args(thread_num);
    std::random_device seed_gen;
    for(ll i=0;i<thread_num;i++){
        args[i].repeat_num=repeat_num;
        args[i].loop_num=loop_num;
        args[i].seed=seed_gen();
        args[i].tid=i;
    }
    
    vector<thread> threads;
    for(ll i=0;i<thread_num;i++){
        threads.emplace_back(multi_montecarlo,ref(args[i]));
    }
    for(int i=0;i<thread_num;i++){
        threads[i].join();
    }
    vector<double> res;
    for(ll i=0;i<thread_num;i++){
        for(double r:results[i]){
            res.push_back(r);
        }
    }
    return res;
}