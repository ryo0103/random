all : output/conf/output.png output/conf/output.txt output/conf/analysis.txt output/conf2/output.png output/conf2/output.txt output/conf2/analysis.txt

output/conf/output.png : output/conf/output.txt
	@python3 src/draw_graph.py conf
output/conf/output.txt : src/main.cpp
	@mkdir output/conf&& g++ src/main.cpp && ./a.out conf/conf.txt && rm a.out
output/conf/analysis.txt : src/analysis.py output/conf/output.txt
	@python3 src/analysis.py conf
output/conf2/output.png : output/conf2/output.txt
	@python3 src/draw_graph.py conf2
output/conf2/output.txt : src/main.cpp
	@mkdir output/conf2&& g++ src/main.cpp && ./a.out conf/conf2.txt && rm a.out
output/conf2/analysis.txt : src/analysis.py output/conf2/output.txt
	@python3 src/analysis.py conf2
src/main.cpp : src/montecarlo.hpp random_algo
clear:
	@rm -r output && mkdir output
