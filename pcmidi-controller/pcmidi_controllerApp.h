/***************************************************************
 * Name:      pcmidi_controllerApp.h
 * Purpose:   Defines Application Class
 * Author:    Don Prince (https://sourceforge.net/projects/pc-midi-linux/forums)
 * Created:   2009-10-07
 * Copyright: Don Prince (https://sourceforge.net/projects/pc-midi-linux/)
 * License:
 **************************************************************/

#ifndef PCMIDI_CONTROLLERAPP_H
#define PCMIDI_CONTROLLERAPP_H

#include <wx/app.h>

class pcmidi_controllerApp : public wxApp
{
    public:
        virtual bool OnInit();
};

#endif // PCMIDI_CONTROLLERAPP_H
