FLAGS = -Wall -Werror -ansi -pedantic
COMP = g++

all:
	mkdir -p ./bin
	$(COMP) $(FLAGS) ./src/main.cpp ./src/PipeCommand.cpp ./src/Shell.cpp ./src/Command.cpp -o ./bin/rshell

rshell:
	$(COMP) $(FLAGS) ./src/main.cpp ./src/PipeCommand.cpp ./src/Shell.cpp ./src/Command.cpp -o ./bin/rshell
	
clean:
	rm -rf ./bin

