/** -*- C++ -*-
 * Copyright (C) 2007 Doug Judd (Zvents, Inc.)
 * 
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#ifndef HYPERTABLE_REQUESTHANDLERLOADRANGE_H
#define HYPERTABLE_REQUESTHANDLERLOADRANGE_H

#include "Common/Runnable.h"

#include "AsyncComm/ApplicationHandler.h"
#include "AsyncComm/Comm.h"
#include "AsyncComm/Event.h"

using namespace hypertable;

namespace hypertable {

  class RangeServer;

  class RequestHandlerLoadRange : public ApplicationHandler {
  public:
    RequestHandlerLoadRange(Comm *comm, RangeServer *rangeServer, EventPtr &eventPtr) : ApplicationHandler(eventPtr), mComm(comm), mRangeServer(rangeServer) {
      return;
    }

    virtual void run();

  private:
    Comm        *mComm;
    RangeServer *mRangeServer;
  };

}

#endif // HYPERTABLE_REQUESTHANDLERLOADRANGE_H