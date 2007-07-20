#
# Copyright (C) 2007 Doug Judd (Zvents, Inc.)
# 
# This program is free software; you can redistribute it and/or
# modify it under the terms of the GNU General Public License
# as published by the Free Software Foundation; either version 2
# of the License, or any later version.
# 
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
# 
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
# 

add_library (Hyperspace HyperspaceClient.cc HyperspaceProtocol.cc)

# hsClient - Hyperspace client program
add_executable (hsClient tests/hyperspace.cc tests/CommandCreate.cc tests/CommandMkdirs.cc tests/CommandAttrSet.cc tests/CommandAttrGet.cc tests/CommandAttrDel.cc tests/CommandExists.cc)
target_link_libraries (hsClient pthread boost_thread Hyperspace AsyncComm Common log4cpp)

install (TARGETS hsClient RUNTIME DESTINATION bin)