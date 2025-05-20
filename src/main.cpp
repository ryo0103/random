#include "file_io/read_config.hpp"
#include "file_io/write_output.hpp"
#include "montecarlo.hpp"

string trim(string s){
    string res="";
    bool f=false;
    for(ll i=0;i<s.length();i++){
        if(s[i]=='/'){
            f=true;
            continue;
        }
        if(f){
            if(s[i]=='.')
                return res;
            res+=s[i];
        }
    }
    return res;
}

int main(int argc,char *argv[])
{
    assert(argc==2);
    vector<string> config = read_config(argv[1]);
    ll repeat_num = stol(config[0]);
    ll loop_num_per_montecarlo = stol(config[1]);
    ll thread_num = stol(config[2]);
    bool does_use_same_seed = false;
    if(config[3] == "True")
        does_use_same_seed = true;
    
    chrono::system_clock::time_point start, end;
    start = chrono::system_clock::now();


    vector<double> res = multi_thread_montecarlo(repeat_num,loop_num_per_montecarlo,thread_num,does_use_same_seed);
    end = chrono::system_clock::now();
    double time = static_cast<double>(chrono::duration_cast<chrono::microseconds>(end-start).count()/1000.0);
    
    string output_file_name = "output/"+trim((string)argv[1])+"/output.txt";
    write_to_file(output_file_name,res,time);
}