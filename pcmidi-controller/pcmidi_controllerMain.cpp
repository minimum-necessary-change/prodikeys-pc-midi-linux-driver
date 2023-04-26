/***************************************************************
 * Name:      pcmidi_controllerMain.cpp
 * Purpose:   Code for Application Frame
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

#include "pcmidi_controllerMain.h"
#include "pcmidi-sysfs.h"

#include <wx/msgdlg.h>

//helper functions

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__WXMAC__)
        wxbuild << _T("-Mac");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}



pcmidi_controllerDialog::pcmidi_controllerDialog(wxDialog *dlg)
    : GUIDialog(dlg)
{
}

pcmidi_controllerDialog::~pcmidi_controllerDialog()
{
}

void pcmidi_controllerDialog::OnInitDialog( wxInitDialogEvent& event )
{
    int channel, octave, sustain;

    channel = pcmidi_read_channel();
    m_radioChannel->SetSelection(channel);

    octave = pcmidi_read_octave();
    m_sliderOctave->SetValue(octave);

    sustain = pcmidi_read_sustain();
    m_sliderSustainDuration->SetValue(sustain);
    m_sliderSustainDuration->Enable( sustain > 0 );
    m_cbSustainMode->SetValue( sustain > 0 ? wxCHK_CHECKED : wxCHK_UNCHECKED );

    event.Skip();
}

void pcmidi_controllerDialog::OnClose(wxCloseEvent &event)
{
    Destroy();
}

void pcmidi_controllerDialog::OnQuit(wxCommandEvent &event)
{
    Destroy();
}

void pcmidi_controllerDialog::OnAbout(wxCommandEvent &event)
{
    wxString msg = "\nProdikeys PC-MIDI Keyboard helper application\n\n";
    msg += "Copyright Don Prince (c) 2009\n\n";
    msg += "License: GNU General Public License (version 2 or later)\n\n\n";
    msg += wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void pcmidi_controllerDialog::OnCbSustainNotesMode( wxCommandEvent& event )
{
    m_sliderSustainDuration->Enable( event.IsChecked() );
    if ( !event.IsChecked() )
    {
        m_sliderSustainDuration->SetValue(0);
        m_sliderSustainDuration->Disable();
    }
}

void pcmidi_controllerDialog::OnSldrSustainNotesChanged( wxScrollEvent& event )
{
    int sustain;

    if ( m_sliderSustainDuration->IsEnabled())
    {
        sustain = m_sliderSustainDuration->GetValue();

        pcmidi_write_sustain(sustain);
    }
}

void pcmidi_controllerDialog::OnSldrOctaveChanged( wxScrollEvent& event )
{
    int octave;

    if ( m_sliderOctave->IsEnabled())
    {
        octave = m_sliderOctave->GetValue();

        pcmidi_write_octave(octave);
    }
}

void pcmidi_controllerDialog::OnRbSelectChannel( wxCommandEvent& event )
{
	int channel;

	channel = m_radioChannel->GetSelection();

	pcmidi_write_channel(channel);
}

