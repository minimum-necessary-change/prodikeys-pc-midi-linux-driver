/***************************************************************
 * Name:      pcmidi_controllerMain.h
 * Purpose:   Defines Application Frame
 * Author:    Don Prince (https://sourceforge.net/projects/pc-midi-linux/forums)
 * Created:   2009-10-07
 * Copyright: Don Prince (https://sourceforge.net/projects/pc-midi-linux/)
 * License:
 **************************************************************/

#ifndef PCMIDI_CONTROLLERMAIN_H
#define PCMIDI_CONTROLLERMAIN_H


#include "pcmidi_controllerApp.h"
#include "GUIDialog.h"


class pcmidi_controllerDialog: public GUIDialog
{
    public:
        pcmidi_controllerDialog(wxDialog *dlg);
        ~pcmidi_controllerDialog();
    private:
        virtual void OnClose( wxCloseEvent& event );
		virtual void OnInitDialog( wxInitDialogEvent& event );
        virtual void OnQuit( wxCommandEvent& event );
        virtual void OnAbout( wxCommandEvent& event );
        virtual void OnCbSustainNotesMode( wxCommandEvent& event );
        virtual void OnSldrSustainNotesChanged( wxScrollEvent& event );
		virtual void OnSldrOctaveChanged( wxScrollEvent& event );
		virtual void OnRbSelectChannel( wxCommandEvent& event );
};


enum wxbuildinfoformat {
    short_f, long_f };

extern wxString wxbuildinfo(wxbuildinfoformat format);

#endif // PCMIDI_CONTROLLERMAIN_H
