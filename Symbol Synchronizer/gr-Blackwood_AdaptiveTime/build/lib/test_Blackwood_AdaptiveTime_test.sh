#!/bin/sh
export VOLK_GENERIC=1
export GR_DONT_LOAD_PREFS=1
export srcdir=/home/ajani/sdr/gr-Blackwood_AdaptiveTime/lib
export PATH=/home/ajani/sdr/gr-Blackwood_AdaptiveTime/build/lib:$PATH
export LD_LIBRARY_PATH=/home/ajani/sdr/gr-Blackwood_AdaptiveTime/build/lib:$LD_LIBRARY_PATH
export PYTHONPATH=$PYTHONPATH
test-Blackwood_AdaptiveTime 
