/* -*- c++ -*- */

#define BLACKWOOD_MODULETWO_API

%include "gnuradio.i"			// the common stuff

//load generated python docstrings
%include "Blackwood_moduletwo_swig_doc.i"

%{
#include "Blackwood_moduletwo/Envelope.h"
%}


%include "Blackwood_moduletwo/Envelope.h"
GR_SWIG_BLOCK_MAGIC2(Blackwood_moduletwo, Envelope);
