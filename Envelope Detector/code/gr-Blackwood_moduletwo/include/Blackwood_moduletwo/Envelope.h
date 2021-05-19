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


#ifndef INCLUDED_BLACKWOOD_MODULETWO_ENVELOPE_H
#define INCLUDED_BLACKWOOD_MODULETWO_ENVELOPE_H

#include <Blackwood_moduletwo/api.h>
#include <gnuradio/sync_block.h>

namespace gr {
  namespace Blackwood_moduletwo {

    /*!
     * \brief <+description of block+>
     * \ingroup Blackwood_moduletwo
     *
     */
    class BLACKWOOD_MODULETWO_API Envelope : virtual public gr::sync_block
    {
     public:
      typedef boost::shared_ptr<Envelope> sptr;

      /*!
       * \brief Return a shared_ptr to a new instance of Blackwood_moduletwo::Envelope.
       *
       * To avoid accidental use of raw pointers, Blackwood_moduletwo::Envelope's
       * constructor is in a private implementation
       * class. Blackwood_moduletwo::Envelope::make is the public interface for
       * creating new instances.
       */
      static sptr make(float Tau, float EnvSampRate);
    };

  } // namespace Blackwood_moduletwo
} // namespace gr

#endif /* INCLUDED_BLACKWOOD_MODULETWO_ENVELOPE_H */

