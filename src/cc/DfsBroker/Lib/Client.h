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

#ifndef HYPERTABLE_DFSBROKER_CLIENT_H
#define HYPERTABLE_DFSBROKER_CLIENT_H

#include <ext/hash_map>

#include <boost/thread/mutex.hpp>

#include "Common/Properties.h"
#include "AsyncComm/DispatchHandlerSynchronizer.h"
#include "AsyncComm/ConnectionManager.h"

#include "Hypertable/Lib/Filesystem.h"

#include "ClientBufferedReaderHandler.h"

/**
 * Forward declarations
 */
namespace hypertable {
  class DispatchHandler;
  class Comm;
  class CommBuf;
  class MessageBuilderSimple;
}
namespace boost {
  class thread;
}

#include "Protocol.h"

using namespace hypertable;

namespace hypertable {

  namespace DfsBroker {

    class Client : public Filesystem {
    public:

      Client(ConnectionManagerPtr &connManagerPtr, struct sockaddr_in &addr, time_t timeout);

      Client(ConnectionManagerPtr &connManagerPtr, PropertiesPtr &propsPtr);

      bool wait_for_connection(long maxWaitSecs) {
	return m_conn_manager_ptr->wait_for_connection(m_addr, maxWaitSecs);
      }

      virtual int open(std::string &name, DispatchHandler *handler);
      virtual int open(std::string &name, int32_t *fdp);
      virtual int open_buffered(std::string &name, uint32_t bufSize, int32_t *fdp);

      virtual int create(std::string &name, bool overwrite, int32_t bufferSize,
			 int32_t replication, int64_t blockSize, DispatchHandler *handler);
      virtual int create(std::string &name, bool overwrite, int32_t bufferSize,
			 int32_t replication, int64_t blockSize, int32_t *fdp);

      virtual int close(int32_t fd, DispatchHandler *handler);
      virtual int close(int32_t fd);

      virtual int read(int32_t fd, uint32_t amount, DispatchHandler *handler);
      virtual int read(int32_t fd, uint32_t amount, uint8_t *dst, uint32_t *nreadp);

      virtual int append(int32_t fd, const void *buf, uint32_t amount, DispatchHandler *handler);
      virtual int append(int32_t fd, const void *buf, uint32_t amount);

      virtual int seek(int32_t fd, uint64_t offset, DispatchHandler *handler);
      virtual int seek(int32_t fd, uint64_t offset);

      virtual int remove(std::string &name, DispatchHandler *handler);
      virtual int remove(std::string &name);

      virtual int length(std::string &name, DispatchHandler *handler);
      virtual int length(std::string &name, int64_t *lenp);

      virtual int pread(int32_t fd, uint64_t offset, uint32_t amount, DispatchHandler *handler);
      virtual int pread(int32_t fd, uint64_t offset, uint32_t amount, uint8_t *dst, uint32_t *nreadp);

      virtual int mkdirs(std::string &name, DispatchHandler *handler);
      virtual int mkdirs(std::string &name);

      virtual int flush(int32_t fd, DispatchHandler *handler);
      virtual int flush(int32_t fd);

      virtual int rmdir(std::string &name, DispatchHandler *handler);
      virtual int rmdir(std::string &name);

      virtual int readdir(std::string &name, DispatchHandler *handler);
      virtual int readdir(std::string &name, std::vector<std::string> &listing);

      int status();

      int shutdown(uint16_t flags, DispatchHandler *handler);

      Protocol *get_protocol_object() { return m_protocol; }

      time_t get_timeout() { return m_timeout; }
    
    private:

      int send_message(CommBufPtr &cbufPtr, DispatchHandler *handler);

      typedef __gnu_cxx::hash_map<uint32_t, ClientBufferedReaderHandler *> BufferedReaderMapT;

      boost::mutex          m_mutex;
      Comm                 *m_comm;
      ConnectionManagerPtr  m_conn_manager_ptr;
      struct sockaddr_in    m_addr;
      time_t                m_timeout;
      MessageBuilderSimple *m_message_builder;
      Protocol             *m_protocol;
      BufferedReaderMapT    m_buffered_reader_map;
    };

  }

}


#endif // HYPERTABLE_DFSBROKER_CLIENT_H

