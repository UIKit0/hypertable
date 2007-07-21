/**
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

#ifndef HYPERTABLE_REQUESTHANDLERGETSCHEMA_H
#define HYPERTABLE_REQUESTHANDLERGETSCHEMA_H

#include "Common/Runnable.h"

#include "AsyncComm/Event.h"

using namespace hypertable;

namespace hypertable {

  class Comm;
  class Master;

  class RequestHandlerGetSchema : public Runnable {
  public:
    RequestHandlerGetSchema(Comm *comm, Master *master, Event &event) : mComm(comm), mMaster(master), mEvent(event) {
      return;
    }

    virtual void run();

  private:
    Comm   *mComm;
    Master *mMaster;
    Event   mEvent;
  };

}

#endif // HYPERTABLE_REQUESTHANDLERGETSCHEMA_H
