#include <fstream>
#include <iostream>
#include <random>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <limits>
#include <chrono>

#include "../random_algo/lcg.hpp"

using namespace std;
using ll=long long;

bool is_inside(double x,double y){
    if(x*x+y*y <= 1)return true;
    return false;
}

ll get_next_rand(ll now, Random* rand_){
    return rand_->random(now);
}

#define LCGMAX 2147483646
double montecarlo(ll seed,ll loop_num, Random* rand_){
    ll res=0;
    ll n=seed;
    for(ll i=0;i<loop_num;i++){
        double r1=((double)n)/((double)LCGMAX);
        n=get_next_rand(n, rand_);
        double r2=((double)n)/((double)LCGMAX);
        n=get_next_rand(n, rand_);
        if(is_inside(r1,r2)){
            res++;
        }
    }
    return res;
}

void write_to_file(string file_name, vector<double> results){
    int d = numeric_limits<double>::max_digits10;
    ofstream outputfile(file_name);
    for(ll i=0;i<results.size();i++){
        outputfile << setprecision(d) << to_string(results[i]) ;
        if(i!=results.size()-1)
            outputfile << ",";
    }
    outputfile << endl;
    outputfile.close();
}

vector<double> multi_montecarlo(ll repeat_num, ll loop_num){
    Random* rand_ = new LCG();
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

int main()
{
    chrono::system_clock::time_point start, end;
    start = chrono::system_clock::now();

    ll repeat_num = 10000;
    ll loop_num_per_montecarlo = 100*1000 / 100;
    vector<double> res = multi_montecarlo(repeat_num,loop_num_per_montecarlo);
    string output_file_name = "output/output.txt";
    write_to_file(output_file_name,res);

    end = chrono::system_clock::now();
    double time = static_cast<double>(chrono::duration_cast<chrono::microseconds>(end-start).count()/1000.0);
    cout << time <<"ms"<<endl;
}