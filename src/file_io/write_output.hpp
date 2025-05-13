#include <fstream>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <limits>
#include <iomanip>

using namespace std;
using ll = long long;

void write_to_file(string file_name, vector<double> results,double time){
    int d = numeric_limits<double>::max_digits10;
    ofstream outputfile(file_name);
    for(ll i=0;i<results.size();i++){
        outputfile << setprecision(d) << to_string(results[i]) ;
        if(i!=results.size()-1)
            outputfile << ",";
    }
    outputfile << endl;
    outputfile << time << endl;
    outputfile.close();
}