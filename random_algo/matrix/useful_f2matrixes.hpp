#include "f2matrix.hpp"
F2Matrix E_matrix(ll n){
    F2Matrix res = F2Matrix(n,n);
    for(ll i=0;i<n;i++)
        res[i][i] = 1;
    return res;
}

F2Matrix Rk_matrix(ll k,ll n){
    F2Matrix res = F2Matrix(n,n);
    for(ll i=0;i<n;i++){
        if(n <= i+k)
            break;
        res[i][i+k] = 1;
    }
    return res;
}

F2Matrix Lk_matrix(ll k,ll n){
    F2Matrix res = F2Matrix(n,n);
    for(ll i=0;i<n;i++){
        if(n <= i+k)
            break;
        res[i+k][i] = 1;
    }
    return res;
}

F2Matrix convert_uint32_t_to_F2_32(uint32_t n){
    F2Matrix vec = F2Matrix(1,32);
    ll i = 31;
    while(n){
        if(n&1){
            vec[0][i] = 1;
        }
        i--;
        n = n>>1;
    }
    return vec;
}

uint32_t convert_F2_32_to_uint32_t(F2Matrix vec){
    ll n=0;
    ll b=1;
    for(int i=0;i<32;i++){
        n += vec[0][31-i]*b;
        b*=2;
    }
    return n;
}