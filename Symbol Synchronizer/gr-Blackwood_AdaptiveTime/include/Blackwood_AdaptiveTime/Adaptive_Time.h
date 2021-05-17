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


#ifndef INCLUDED_BLACKWOOD_ADAPTIVETIME_ADAPTIVE_TIME_H
#define INCLUDED_BLACKWOOD_ADAPTIVETIME_ADAPTIVE_TIME_H

#include <Blackwood_AdaptiveTime/api.h>
#include <gnuradio/block.h>

namespace gr {
  namespace Blackwood_AdaptiveTime {

    /*!
     * \brief <+description of block+>
     * \ingroup Blackwood_AdaptiveTime
     *
     */
    class BLACKWOOD_ADAPTIVETIME_API Adaptive_Time : virtual public gr::block
    {
     public:
      typedef boost::shared_ptr<Adaptive_Time> sptr;

      /*!
       * \brief Return a shared_ptr to a new instance of Blackwood_AdaptiveTime::Adaptive_Time.
       *
       * To avoid accidental use of raw pointers, Blackwood_AdaptiveTime::Adaptive_Time's
       * constructor is in a private implementation
       * class. Blackwood_AdaptiveTime::Adaptive_Time::make is the public interface for
       * creating new instances.
       */
      static sptr make();
    };

  } // namespace Blackwood_AdaptiveTime
} // namespace gr

#endif /* INCLUDED_BLACKWOOD_ADAPTIVETIME_ADAPTIVE_TIME_H */

