.SILENT:

INC = ./include/

DEP = $(INC)exception.o $(INC)file.o 

all:	luna

luna:	./luna.cpp ./object/program.o ./object/compiler.o ./object/exception.o ./object/file.o ./object/Variable.o ./object/VariableMemory.o 
		g++ -o luna ./luna.cpp ./object/program.o ./object/compiler.o ./object/exception.o ./object/file.o ./object/Variable.o ./object/VariableMemory.o -I ./include/
		echo -e "\033[92mCreation luna...\033[0m"

./object/exception.o:	./include/exception.cpp ./include/exception.h
		g++ -o ./object/exception.o -c ./include/exception.cpp -I ./include/
		echo "Creation exception.o..."

./object/file.o:	./include/file.cpp ./include/file.h 
		g++ -o ./object/file.o -c ./include/file.cpp -I ./include/
		echo "Creation file.o..."

./object/program.o:	./include/program.cpp ./include/program.h 
		g++ -c ./include/program.cpp -o ./object/program.o -I ./include/
		echo "Creation program.o..."

./object/Variable.o:	./include/Variable.cpp ./include/Variable.h 
		g++ -c ./include/Variable.cpp -o ./object/Variable.o -I ./include/
		echo "Creation Variable.o..."

./object/VariableMemory.o:	./include/VariableMemory.cpp ./include/VariableMemory.h 
		g++ -c ./include/VariableMemory.cpp -o ./object/VariableMemory.o -I ./include/
		echo "Creation VariableMemory.o..."

./object/compiler.o:	./include/compiler.cpp ./include/compiler.h 
		g++ -c ./include/compiler.cpp -o ./object/compiler.o -I ./include/
		echo "Creation compiler.o..."


clean: 
	rm ./object/*.o
	echo "Cleaning..."
