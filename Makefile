all : output/256thread_diff_seed/output.png output/256thread_diff_seed/output.txt output/256thread_diff_seed/analysis.txt output/8thread_diff_seed/output.png output/8thread_diff_seed/output.txt output/8thread_diff_seed/analysis.txt output/8thread_same_seed/output.png output/8thread_same_seed/output.txt output/8thread_same_seed/analysis.txt output/256thread_same_seed/output.png output/256thread_same_seed/output.txt output/256thread_same_seed/analysis.txt

output/256thread_diff_seed/output.png : output/256thread_diff_seed/output.txt
	@python3 src/draw_graph.py 256thread_diff_seed
output/256thread_diff_seed/output.txt : src/main.cpp conf/256thread_diff_seed.yaml
	@python3 src/convert_yaml_to_csv.py 256thread_diff_seed&& mkdir -p output/256thread_diff_seed&& g++ src/main.cpp && ./a.out conf/256thread_diff_seed.txt && rm a.out && rm conf/*.txt
output/256thread_diff_seed/analysis.txt : src/analysis.py output/256thread_diff_seed/output.txt
	@python3 src/analysis.py 256thread_diff_seed
output/8thread_diff_seed/output.png : output/8thread_diff_seed/output.txt
	@python3 src/draw_graph.py 8thread_diff_seed
output/8thread_diff_seed/output.txt : src/main.cpp conf/8thread_diff_seed.yaml
	@python3 src/convert_yaml_to_csv.py 8thread_diff_seed&& mkdir -p output/8thread_diff_seed&& g++ src/main.cpp && ./a.out conf/8thread_diff_seed.txt && rm a.out && rm conf/*.txt
output/8thread_diff_seed/analysis.txt : src/analysis.py output/8thread_diff_seed/output.txt
	@python3 src/analysis.py 8thread_diff_seed
output/8thread_same_seed/output.png : output/8thread_same_seed/output.txt
	@python3 src/draw_graph.py 8thread_same_seed
output/8thread_same_seed/output.txt : src/main.cpp conf/8thread_same_seed.yaml
	@python3 src/convert_yaml_to_csv.py 8thread_same_seed&& mkdir -p output/8thread_same_seed&& g++ src/main.cpp && ./a.out conf/8thread_same_seed.txt && rm a.out && rm conf/*.txt
output/8thread_same_seed/analysis.txt : src/analysis.py output/8thread_same_seed/output.txt
	@python3 src/analysis.py 8thread_same_seed
output/256thread_same_seed/output.png : output/256thread_same_seed/output.txt
	@python3 src/draw_graph.py 256thread_same_seed
output/256thread_same_seed/output.txt : src/main.cpp conf/256thread_same_seed.yaml
	@python3 src/convert_yaml_to_csv.py 256thread_same_seed&& mkdir -p output/256thread_same_seed&& g++ src/main.cpp && ./a.out conf/256thread_same_seed.txt && rm a.out && rm conf/*.txt
output/256thread_same_seed/analysis.txt : src/analysis.py output/256thread_same_seed/output.txt
	@python3 src/analysis.py 256thread_same_seed
src/main.cpp : src/montecarlo.hpp random_algo
clear:
	@rm -r output && mkdir output
