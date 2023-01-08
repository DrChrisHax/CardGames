#Makefile Chris Manlove Jan 2023
EXE = main
CXX = @g++
CXXFLAGS = -Wall -g -std=c++17 -O2
LINKERFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

$(EXE): $(OBJ) makefile
		@rm -f $(EXE)
		$(CXX) *.cpp $(CXXFLAGS) $(LINKERFLAGS) -o $(EXE)
clean:
		@rm -f $(EXE)
run: $(EXE)
		@./$(EXE)