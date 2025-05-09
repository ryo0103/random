#include <fstream>
#include <iostream>
#include <random>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <limits>

#include "random_interface.hpp"
using namespace std;
using ll=long long;

class LCG:public Random{
    private:
    const uint32_t A=48271;
    const uint32_t B=0;
    const uint32_t M=2147483647;
    
    // this param determine max length of your jump
    const uint32_t TABLE_SIZE = 100;
    
    struct Params{
        uint32_t Ai;
        uint32_t Bi;
    };

    // params_table[i] == 2^i jump 
    vector<Params> params_table;
    bool is_params_table_constructed = false;
    void make_table(){
        params_table = vector<Params>();
        params_table.push_back({A,B});
        for(ll i=0;i<TABLE_SIZE;i++){
            uint64_t prev_Ai=params_table[i].Ai;
            uint64_t prev_Bi=params_table[i].Bi;
            params_table.push_back({(prev_Ai*prev_Ai) % M, (prev_Ai*prev_Bi+prev_Bi) % M});
        }
        is_params_table_constructed = true;
    }

    public:
    LCG(){
        
    }
    uint32_t random(uint32_t now){
        now = now % M;
        return ( ((uint64_t)A) * ((uint64_t)now) ) % M;
    }

    uint32_t jump(uint32_t now, ll jump_length){
        if(!is_params_table_constructed)
            make_table();
        ll n = jump_length;
        ll i = 0;
        while(n){
            if(n & 1){
                now = (((uint64_t)params_table[i].Ai)*((uint64_t)now) + params_table[i].Bi) % M;
            }
            i++;
            n = n >> 1;
        }
        return now;
    }
};