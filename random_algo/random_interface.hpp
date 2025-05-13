#pragma once
using namespace std;
using ll=long long;

class Random{
    public:
    ll MAX = 0;
    virtual uint32_t random(uint32_t now) = 0;
    virtual uint32_t jump(uint32_t now, ll jump_length) = 0;
    uint32_t jump_naive(uint32_t now, ll jump_length){
        for(ll i=0;i<jump_length;i++){
            now = random(now);
        }
        return now;
    }
};