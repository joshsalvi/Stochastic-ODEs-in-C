#!/bin/bash
#
cp test_ls.hpp /$HOME/include
#
g++ -c -I /$HOME/include test_ls.cpp
if [ $? -ne 0 ]; then
  echo "Errors compiling test_ls.cpp"
  exit
fi
#
mv test_ls.o ~/libcpp/$ARCH/test_ls.o
#
echo "Library installed as ~/libcpp/$ARCH/test_ls.o"
