basico:
	g++ -o ./test_agar `agar-config --cflags` ./test_agar.cpp `agar-config --libs`
	
grafico:
	g++ -o ./test_agar_opengl `agar-config --cflags` ./test_agar_opengl.cpp `agar-config --libs`  -lGL -lGLU -lGLEW

