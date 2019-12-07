/* ScummVM - Graphic Adventure Engine
 *
 * ScummVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the COPYRIGHT
 * file distributed with this source distribution.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 */

#ifndef ULTIMA8_KERNEL_HIDMANAGER_H
#define ULTIMA8_KERNEL_HIDMANAGER_H

#include "ultima8/std/containers.h"
#include "ultima8/kernel/hid_keys.h"
#include "ultima8/kernel/joystick.h"
//#include "SDL_events.h"

namespace Ultima8 {

//! Responsible to loading the keybindings and storing them
class HIDManager {
public:
	HIDManager();
	~HIDManager();

	//! obtain the singleton instance of the HIDManager
	static HIDManager *get_instance() {
		return hidmanager;
	}

	//! execute the Console command associated with the event
	//! \param key a HID_KEY used to find an appropriate Console command
	//! \param evn a HID_Event used to find an appropriate Console command
	//! \return true if a console command is executed
	bool handleEvent(const HID_Key key, const HID_Event evn);

	//! Reset the keybindings
	void resetBindings();

	//! loads the keybindings from the configuration
	void loadBindings();

	//! saves the keybindings to the configuration
	void saveBindings();

	//! loads a single keybinding
	//! \param control a key or button to bind
	//! \param bindingName name of the HIDBinding
	void bind(const Pentagram::istring &control, const Console::ArgvType &argv);

	void bind(const Pentagram::istring &control, const Console::ArgsType &args);
	void bind(HID_Key key, HID_Event event, const Console::ArgvType &argv);
	void bind(HID_Key key, HID_Event event, const Console::ArgsType &args);

	//! removes all controls to a HIDBinding or the binding to one specified key
	//! \param bindingName name of a HIDBinding or the name of key
	void unbind(const Pentagram::istring &control);

	//! "bind" console command
	static void ConCmd_bind(const Console::ArgvType &argv);

	//! "unbind" console command
	static void ConCmd_unbind(const Console::ArgvType &argv);

	//! "listbinds" console command
	static void ConCmd_listbinds(const Console::ArgvType &argv);

	//! "save" console command
	static void ConCmd_save(const Console::ArgvType &argv);

private:
	void listBindings();

	std::vector<Console::ArgvType *> commands;
	Console::ArgvType *bindings[HID_LAST][HID_EVENT_LAST];

	static HIDManager *hidmanager;
};

} // End of namespace Ultima8

#endif