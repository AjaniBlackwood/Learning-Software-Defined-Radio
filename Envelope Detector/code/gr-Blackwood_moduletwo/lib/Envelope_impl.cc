/* -*- c++ -*- */
/* 
 * Copyright 2020 gr-Blackwood_moduletwo author.
 * 
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 * 
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <gnuradio/io_signature.h>
#include "Envelope_impl.h"

namespace gr {
  namespace Blackwood_moduletwo {

    Envelope::sptr
    Envelope::make(float Tau, float EnvSampRate)
    {
      return gnuradio::get_initial_sptr
        (new Envelope_impl(Tau, EnvSampRate));
    }

    /*
     * The private constructor
     */
    Envelope_impl::Envelope_impl(float Tau, float EnvSampRate)
      : gr::sync_block("Envelope",
              gr::io_signature::make(1,1, sizeof(float)),
              gr::io_signature::make(1, 1, sizeof(float))),
              d_Tau(Tau),
              d_EnvSampRate(EnvSampRate)
           
    {
      //Default parameters
      
    invTau = 10000.0f;
    samp_rate = 1000000.0f;
    EnvSampRate = 1000000.0f;
    Tau = 1 / invTau;
    dt = 1/EnvSampRate;

    }

    /*
     * Our virtual destructor.
     */
    Envelope_impl::~Envelope_impl()
    {
    }

    int
    Envelope_impl::work(int noutput_items,
        gr_vector_const_void_star &input_items,
        gr_vector_void_star &output_items)
    {
      const float *in = (const float *) input_items[0];
      float *out = (float *) output_items[0];

      // Do <+signal processing+>

      out[0] = in[0];

      for(int i = 1; i<noutput_items;i++)
      {
        if(in[i] >= out[i-1])
        {
          out[i] = in[i];
        }
        else
        {
          out[i] = out[i-1] * exp(-1*dt/d_Tau);
        }
        
      }

      // Tell runtime system how many output items we produced.

      
      return noutput_items;
    }

  } /* namespace Blackwood_moduletwo */
} /* namespace gr */
