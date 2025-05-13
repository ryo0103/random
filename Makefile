all : output/output.png output/output.txt

output/output.png : output/output.txt
	python3 src/draw_graph.py

output/output.txt : src/main.cpp
	g++ src/main.cpp && ./a.out && rm a.out