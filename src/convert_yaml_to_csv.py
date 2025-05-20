import yaml
import sys

conf_name = sys.argv[1]
file_path="conf/"+conf_name+".yaml"
new_file_path="conf/"+conf_name+".txt"

configs = []
with open(file_path,"r") as f_r:
    config = yaml.safe_load(f_r)
    configs.append(config["montecarlo"]["montecarlo_num"])
    configs.append(config["montecarlo"]["loop_per_1montecarlo"])
    configs.append(config["multithread"]["thread_num"])
    configs.append(config["multithread"]["does_use_same_seed"])

with open(new_file_path,"w") as f_w:
    result = ""
    for i in range(len(configs)):
      result += str(configs[i])
      if i != len(configs)-1:
         result += ","
    
    f_w.write(result)