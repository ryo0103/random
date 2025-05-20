#include <fstream>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <limits>
#include <iomanip>

using namespace std;
using ll = long long;

vector<string> read_config(string config_name){
    ifstream config_file(config_name);

    string line;
    getline(config_file, line);
    vector<string> res;
    string now="";
    for(ll i=0;i<line.length();i++){
        if(line[i]==','){
            res.push_back(now);
            now="";
        }else if(line[i]==' '){
            
        }else{
            now+=line[i];
        }
    }
    if(now!="")
        res.push_back(now);
    return res;
}