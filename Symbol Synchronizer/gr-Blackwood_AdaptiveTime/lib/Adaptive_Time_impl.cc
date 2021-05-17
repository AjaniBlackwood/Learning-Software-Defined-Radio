/* -*- c++ -*- */
/* 
 * Copyright 2020 Ajani Blackwood.
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
#include "Adaptive_Time_impl.h"

namespace gr {
  namespace Blackwood_AdaptiveTime {

    Adaptive_Time::sptr
    Adaptive_Time::make()
    {
      return gnuradio::get_initial_sptr
        (new Adaptive_Time_impl());
    }

    /*
     * The private constructor
     */
    Adaptive_Time_impl::Adaptive_Time_impl()
      : gr::block("Adaptive_Time",
              gr::io_signature::make(1, 1, sizeof(float)),
              gr::io_signature::make(1, 1, sizeof(float)))
              
    {
     //default parameters
   
     
    }

    /*
     * Our virtual destructor.
     */
    Adaptive_Time_impl::~Adaptive_Time_impl()
    {
    }

    void
    Adaptive_Time_impl::forecast (int noutput_items, gr_vector_int &ninput_items_required)
    {
      /* <+forecast+> e.g. ninput_items_required[0] = noutput_items */
      unsigned ninputs = ninput_items_required.size();
      for (unsigned i=0; i < ninputs; i++)
      {
        ninput_items_required[i] = (int) ceil((noutput_items * 40)+20*40+1);
      }
    }

    int
    Adaptive_Time_impl::general_work (int noutput_items,
                       gr_vector_int &ninput_items,
                       gr_vector_const_void_star &input_items,
                       gr_vector_void_star &output_items)
    {
      const float *in = (const float*) input_items[0];
      float *out = (float*) output_items[0];
      

      // Do <+signal processing+>
      // Tell runtime system how many input items we consumed on
      // each input stream.
      //consume_each (noutput_items);

      int ii = 0; // input index
      int oo = 0; // output index
      int ni = ninput_items[0] - (20*40+1); // don't use more than needed
    
     
      int offset_move[3] = {-1, 0, 1};
      float sume;
      float sumc;
      float suml;
      int pos_large;
      

      while(oo < noutput_items && ii < ni)
      {
        out[oo] = in[ii];
        sume = 0.0f;
        sumc = 0.0f;
        suml = 0.0f;
       

        for(int n=0; n<20; n++)
        {
          //in this for loop, get the sume,sumc,suml
          //sume is early sum
          //sumc is current sum
          //suml is late sum

         
          
          sume += pow(fabs(in[ii+n*40-1]), 2);
          sumc += pow(fabs(in[ii+n*40]), 2);
          suml += pow(fabs(in[ii+n*40+1]), 2);
          
          
        }

        float sum_list[] = {sume,sumc,suml};
        float largest_sum;
        int pos_large = 0;
        largest_sum = sum_list[0];

        for(int k = 0; k<3; k++)
        {
          //in this for loop, find the largest in [sume,sumc,suml] and get 

          if (sum_list[k] > largest_sum)
          {
            largest_sum = sum_list[k];
            pos_large = k;
          }
          //the index

        }


        //ii += 40 + offset_move[pos_large]; // +the correction to make time offset correct
        ii += 40 + offset_move[pos_large];
        oo++;
        
      }

      // Tell runtime system how many output items we produced.
      consume_each(ii);
      //out[i - 20] =  ii;
      
      return oo;
      //return noutput_items;
    }

  } /* namespace Blackwood_AdaptiveTime */
} /* namespace gr */

