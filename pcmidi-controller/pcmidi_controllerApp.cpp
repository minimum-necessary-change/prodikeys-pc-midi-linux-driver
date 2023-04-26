/***************************************************************
 * Name:      pcmidi_controllerApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Don Prince (https://sourceforge.net/projects/pc-midi-linux/forums)
 * Created:   2009-10-07
 * Copyright: Don Prince (https://sourceforge.net/projects/pc-midi-linux/)
 * License:
     This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.

 **************************************************************/

#ifdef WX_PRECOMP
#include "wx_pch.h"
#endif

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#include "pcmidi_controllerApp.h"
#include "pcmidi_controllerMain.h"
#include "pcmidi-sysfs.h"

#include <wx/msgdlg.h>

IMPLEMENT_APP(pcmidi_controllerApp);

bool pcmidi_controllerApp::OnInit()
{
    pcmidi_init_sysfs();
    if ( pcmidi_found_sysfs )
    {
        if (!pcmidi_read_sysfs_hid_bus())
        {
            pcmidi_controllerDialog* dlg = new pcmidi_controllerDialog(0L);

            dlg->Show();
            return true;
        }
    }

    wxString msg = "\nProdikeys PC-MIDI Keyboard helper application\n\n";
    msg += "Copyright Don Prince (c) 2009\n\n";
    msg += "License: GNU General Public License (version 2 or later)\n\n\n";
    msg += wxbuildinfo(long_f);
    wxMessageBox(msg, _("Device not found...Aborting"),wxICON_ERROR | wxCENTRE);

    return false;
}
