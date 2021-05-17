/* -*- c++ -*- */

#define BLACKWOOD_ADAPTIVETIME_API

%include "gnuradio.i"			// the common stuff

//load generated python docstrings
%include "Blackwood_AdaptiveTime_swig_doc.i"

%{
#include "Blackwood_AdaptiveTime/Adaptive_Time.h"
%}


%include "Blackwood_AdaptiveTime/Adaptive_Time.h"
GR_SWIG_BLOCK_MAGIC2(Blackwood_AdaptiveTime, Adaptive_Time);
