#!/bin/sh

# might need to chmod +x ./compile.sh
cd parser && bisonc++ -V grammar && cd ../scanner && flexc++ lexer && cd .. && make -j4 && ./main
