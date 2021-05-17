#!/bin/sh
export VOLK_GENERIC=1
export GR_DONT_LOAD_PREFS=1
export srcdir=/home/ajani/sdr/gr-Blackwood_AdaptiveTime/python
export PATH=/home/ajani/sdr/gr-Blackwood_AdaptiveTime/build/python:$PATH
export LD_LIBRARY_PATH=/home/ajani/sdr/gr-Blackwood_AdaptiveTime/build/lib:$LD_LIBRARY_PATH
export PYTHONPATH=/home/ajani/sdr/gr-Blackwood_AdaptiveTime/build/swig:$PYTHONPATH
/usr/bin/python2 /home/ajani/sdr/gr-Blackwood_AdaptiveTime/python/qa_Adaptive_Time.py 
