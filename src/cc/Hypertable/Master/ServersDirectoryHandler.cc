/**
 * Copyright (C) 2007 Doug Judd (Zvents, Inc.)
 * 
 * This file is part of Hypertable.
 * 
 * Hypertable is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or any later version.
 * 
 * Hypertable is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#include "EventHandlerServerJoined.h"
#include "EventHandlerServerLeft.h"
#include "ServersDirectoryHandler.h"
#include "Master.h"

using namespace hypertable;

/**
 *
 */
void ServersDirectoryHandler::child_node_added(std::string name) {
  EventPtr nullEvent;
  m_app_queue_ptr->add( new EventHandlerServerJoined(m_master_ptr, name, nullEvent) );
  return;
}
