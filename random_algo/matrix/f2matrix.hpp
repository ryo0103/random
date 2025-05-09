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
#include <initializer_list>

using namespace std;
using ll=long long;

class F2Matrix{
    public:
    vector<vector<ll>> matrix;
    ll height=0;
    ll width=0;
    
    F2Matrix(){

    }
    F2Matrix(ll h,ll w){
        height=h;
        width=w;
        matrix.resize(h);
        for(ll i=0;i<h;i++){
            matrix[i].resize(w);
        }
    }
    F2Matrix(initializer_list<initializer_list<ll>> init){
        height = init.size();
        assert(init.begin() != nullptr);
        width = init.begin()->size();
        assert(height!=0 && width!=0);
        ll i=0;
        matrix.resize(height);
        for(auto&& x:init){
            matrix[i] = vector<ll>(x);
            i++;
        }
    }
    vector<ll>& operator[](ll h){
        return matrix[h];
    }
};

ostream& operator<<(ostream& os, F2Matrix& matrix){

    for(ll i=0;i<matrix.height;i++){
        for(ll j=0;j<matrix.width;j++){
            cout << matrix[i][j] << " ";
        }
        if(i!=matrix.height-1)
            cout<<endl;
    }
    return os;
}

F2Matrix operator*(F2Matrix& l, F2Matrix& r){
    assert(l.width==r.height);
    assert(l.height != 0 && r.width!=0);
    F2Matrix res = F2Matrix(l.height,r.width);
    
    for(ll i=0;i<l.height;i++){
        for(ll j=0;j<r.width;j++){
            for(ll k=0;k<l.width;k++){
                res[i][j] = (res[i][j] + l[i][k]*r[k][j]) % 2;
            }
        }
    }
    return res;
}

F2Matrix operator+(F2Matrix& l, F2Matrix& r){
    assert(l.height == r.height);
    assert(l.width == r.width);
    F2Matrix res = F2Matrix(l.height,l.width);
    
    for(ll i=0;i<l.height;i++){
        for(ll j=0;j<l.width;j++){
            res[i][j] = (l[i][j] + r[i][j]) % 2;
        }
    }
    return res;
}

bool operator==(F2Matrix& l, F2Matrix& r){
    if(l.height != r.height || l.width != r.width)
        return false;
    for(ll i=0;i<l.height;i++){
        for(ll j=0;j<l.width;j++){
            if(l[i][j] != r[i][j])
                return false;
        }
    }
    return true;
}