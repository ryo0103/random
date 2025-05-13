#include <fstream>
#include <iostream>
#include <random>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <limits>

#include "matrix/useful_f2matrixes.hpp"
#include "random_interface.hpp"
using namespace std;
using ll=long long;

class Xorshift32:public Random{
    private:
    const uint32_t A = 13;
    const uint32_t B = 17;
    const uint32_t C = 5;

    // this param determine max length of your jump
    const uint32_t TABLE_SIZE = 100;
    
    vector<F2Matrix> params_table;
    bool is_params_table_constructed = false;
    void make_table(){
        if(!is_matrix_constructed)
            make_matrix();
        params_table = vector<F2Matrix>();
        params_table.push_back(matrix);
        for(ll i=0;i<TABLE_SIZE;i++){
            F2Matrix prev_matrix = params_table[i];
            params_table.push_back(prev_matrix * prev_matrix);
        }
        is_params_table_constructed = true;
    }

    public:
    Xorshift32(){
        MAX = 4294967295;
    }

    // matrix corresponds to xorshift32
    // xorshift(x) == Ax
    F2Matrix matrix;
    bool is_matrix_constructed = false;
    void make_matrix(){
        F2Matrix E = E_matrix(32);
        F2Matrix L_13 = Lk_matrix(A,32);
        F2Matrix R_17 = Rk_matrix(B,32);
        F2Matrix L_5 = Lk_matrix(C,32);

        F2Matrix M1 = E + L_13;
        F2Matrix M2 = E + R_17;
        F2Matrix M3 = E + L_5;

        F2Matrix t = M1*M2;
        matrix = t * M3;
    }

    uint32_t random(uint32_t now){
        now ^= now << A;
        now ^= now >> B;
        now ^= now << C;
        return now;
    }

    F2Matrix pow_matrix_with_table(ll n){
        if(!is_params_table_constructed)
            make_table();
        F2Matrix res = E_matrix(32);
        ll i=0;
        while(n){
            if(n&1){
                res = res * params_table[i];
            }
            n = n >> 1;
            i++;
        }
        return res;
    }
    uint32_t jump(uint32_t now, ll jump_length){
        ll n = jump_length;
        F2Matrix matrix_n = pow_matrix_with_table(n);

        F2Matrix vec = convert_uint32_t_to_F2_32(now);
        F2Matrix y = vec * matrix_n;
        uint32_t res = convert_F2_32_to_uint32_t(y);
        return res;
    }
};