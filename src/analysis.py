import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import math
import sys

conf_name = sys.argv[1]
def cal_E(x):
    sum = 0
    for i in x:
        sum += i
    return sum/len(x)

def cal_V(x):
    res = 0
    E = cal_E(x)
    for i in x:
        res += (i - E) * (i - E)
    return res

def cal_dis_from_pi(x):
    res = 0
    p = math.pi
    for i in x:
        res += abs(i - p)
    return res

results = []
time = 0.0
with open("output/"+conf_name+"/output.txt", "r") as f:
    line = f.readline()
    results = [float(result) for result in line.strip().split(",")]
    time = f.readline().replace('\n','')

with open("output/"+conf_name+"/analysis.txt", "w") as f:
    f.write("E         : "+str(cal_E(results))+"\n")
    f.write("V         : "+str(cal_V(results))+"\n")
    f.write("V from pi : "+str(cal_dis_from_pi(results))+"\n")
    f.write("time      : "+str(time)+"ms"+"\n")