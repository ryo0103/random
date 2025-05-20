import os

conf_names = []
for conf_name in os.listdir("conf"):
    if conf_name.split(".")[1] == "yaml":
        conf_names.append(conf_name.split(".")[0])

targets = []
for conf_name in conf_names:
    targets.append("output/"+conf_name+"/output.png")
    targets.append("output/"+conf_name+"/output.txt")
    targets.append("output/"+conf_name+"/analysis.txt")

etc = ""
for conf_name in conf_names:
    etc+="output/"+conf_name+"/output.png : output/"+conf_name+"/output.txt\n"
    etc+="\t@python3 src/draw_graph.py "+conf_name+"\n"
    etc+="output/"+conf_name+"/output.txt : src/main.cpp conf/"+conf_name+".yaml\n"
    etc+="\t@python3 src/convert_yaml_to_csv.py "+conf_name+"&& mkdir -p output/"+conf_name+"&& g++ src/main.cpp && ./a.out conf/"+conf_name+".txt && rm a.out && rm conf/*.txt\n"
    etc+="output/"+conf_name+"/analysis.txt : src/analysis.py output/"+conf_name+"/output.txt\n"
    etc+="\t@python3 src/analysis.py "+conf_name+"\n"

etc+="src/main.cpp : src/montecarlo.hpp random_algo\n"
etc+="clear:\n"
etc+="\t@rm -r output && mkdir output\n"

with open("Makefile", "w") as f:
    f.write("all : {}\n\n".format(" ".join(targets)))
    f.write(etc)