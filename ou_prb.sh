#!/bin/bash
#
g++ -c -I/Users/joshsalvi/GitHub/Stochastic\ ODEs\ in\ C/Stochastic-ODEs-in-C/ou_prb.cpp
if [ $? -ne 0 ]; then
  echo "Errors compiling ou_prb.cpp"
  exit
fi
#
g++ ou_prb.o /Users/joshsalvi/GitHub/Stochastic\ ODEs\ in\ C/Stochastic-ODEs-in-C/ou.o -lm
if [ $? -ne 0 ]; then
  echo "Errors linking and loading ou_prb.o."
  exit
fi
#
rm ou_prb.o
#
mv a.out ou_prb
./ou_prb > ou_prb_output.txt
if [ $? -ne 0 ]; then
  echo "Errors running ou_prb."
  exit
fi
rm ou_prb
#
echo "Program output written to ou_prb_output.txt"
