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

#ifndef INCLUDED_BLACKWOOD_MODULETWO_ENVELOPE_IMPL_H
#define INCLUDED_BLACKWOOD_MODULETWO_ENVELOPE_IMPL_H

#include <Blackwood_moduletwo/Envelope.h>

namespace gr {
  namespace Blackwood_moduletwo {

    class Envelope_impl : public Envelope
    {
     private:
      //Parameters for envelope detector
      float samp_rate;
      float dt;
      float d_Tau;
      float invTau;
      float d_EnvSampRate;

     public:
      Envelope_impl(float Tau, float EnvSampRate);
      ~Envelope_impl();

      // Where all the action really happens
      int work(int noutput_items,
         gr_vector_const_void_star &input_items,
         gr_vector_void_star &output_items);
    };

  } // namespace Blackwood_moduletwo
} // namespace gr

#endif /* INCLUDED_BLACKWOOD_MODULETWO_ENVELOPE_IMPL_H */

