BINPATH='bin'
BIN='main'

mkdir -p ${BINPATH} && g++ Controller/main.cpp -I./View View/*.cpp -I./Config -I./Model Model/*.cpp -lncurses -std=c++11 -o ./${BINPATH}/${BIN}
