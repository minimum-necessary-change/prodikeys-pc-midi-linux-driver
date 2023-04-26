///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct  7 2009)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __GUIDialog__
#define __GUIDialog__

#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/slider.h>
#include <wx/sizer.h>
#include <wx/checkbox.h>
#include <wx/radiobox.h>
#include <wx/button.h>
#include <wx/statline.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// Class GUIDialog
///////////////////////////////////////////////////////////////////////////////
class GUIDialog : public wxDialog 
{
	private:
	
	protected:
		enum
		{
			idBtnAbout = 1000,
			idBtnQuit,
		};
		
		
		wxStaticText* m_staticText1;
		wxSlider* m_sliderOctave;
		wxCheckBox* m_cbSustainMode;
		wxSlider* m_sliderSustainDuration;
		wxRadioBox* m_radioChannel;
		
		
		wxButton* BtnAbout;
		wxStaticLine* m_staticline11;
		wxButton* BtnQuit;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnClose( wxCloseEvent& event ){ event.Skip(); }
		virtual void OnInitDialog( wxInitDialogEvent& event ){ event.Skip(); }
		virtual void OnSldrOctaveChanged( wxScrollEvent& event ){ event.Skip(); }
		virtual void OnCbSustainNotesMode( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnSldrSustainNotesChanged( wxScrollEvent& event ){ event.Skip(); }
		virtual void OnRbSelectChannel( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnAbout( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnQuit( wxCommandEvent& event ){ event.Skip(); }
		
	
	public:
		GUIDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Prodikeys PC-MIDI Controller"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 338,231 ), long style = wxDEFAULT_DIALOG_STYLE|wxMINIMIZE_BOX );
		~GUIDialog();
	
};

#endif //__GUIDialog__
