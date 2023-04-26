///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct  7 2009)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif //WX_PRECOMP

#include "GUIDialog.h"

///////////////////////////////////////////////////////////////////////////

GUIDialog::GUIDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer11;
	bSizer11 = new wxBoxSizer( wxVERTICAL );
	
	
	bSizer11->Add( 0, 0, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText1 = new wxStaticText( this, wxID_ANY, wxT("Octave"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1->Wrap( -1 );
	bSizer7->Add( m_staticText1, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_sliderOctave = new wxSlider( this, wxID_ANY, 0, -2, 2, wxDefaultPosition, wxDefaultSize, wxSL_AUTOTICKS|wxSL_HORIZONTAL|wxSL_LABELS );
	m_sliderOctave->SetToolTip( wxT("Specify octave shift of notes, up or down") );
	
	bSizer7->Add( m_sliderOctave, 1, wxALIGN_CENTER_VERTICAL|wxALL|wxEXPAND, 5 );
	
	bSizer11->Add( bSizer7, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer16;
	bSizer16 = new wxBoxSizer( wxHORIZONTAL );
	
	m_cbSustainMode = new wxCheckBox( this, wxID_ANY, wxT("Sustain notes mode"), wxDefaultPosition, wxDefaultSize, 0 );
	
	m_cbSustainMode->SetToolTip( wxT("Enable or disable notes sustain function") );
	
	bSizer16->Add( m_cbSustainMode, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_sliderSustainDuration = new wxSlider( this, wxID_ANY, 0, 0, 5000, wxDefaultPosition, wxDefaultSize, wxSL_AUTOTICKS|wxSL_HORIZONTAL|wxSL_LABELS );
	m_sliderSustainDuration->SetToolTip( wxT("Specify notes sustain duration") );
	
	bSizer16->Add( m_sliderSustainDuration, 3, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	bSizer11->Add( bSizer16, 1, wxEXPAND, 5 );
	
	wxString m_radioChannelChoices[] = { wxT("1"), wxT("2"), wxT("3"), wxT("4"), wxT("5"), wxT("6"), wxT("7"), wxT("8"), wxT("9"), wxT("10"), wxT("11"), wxT("12"), wxT("13"), wxT("14"), wxT("15"), wxT("16") };
	int m_radioChannelNChoices = sizeof( m_radioChannelChoices ) / sizeof( wxString );
	m_radioChannel = new wxRadioBox( this, wxID_ANY, wxT("Select output channel"), wxDefaultPosition, wxDefaultSize, m_radioChannelNChoices, m_radioChannelChoices, 8, wxRA_SPECIFY_COLS|wxRA_SPECIFY_ROWS );
	m_radioChannel->SetSelection( 3 );
	m_radioChannel->SetToolTip( wxT("Select channel to transmit notes") );
	
	bSizer11->Add( m_radioChannel, 0, wxALL, 5 );
	
	
	bSizer11->Add( 0, 0, 0, wxALL|wxEXPAND, 3 );
	
	wxBoxSizer* bSizer21;
	bSizer21 = new wxBoxSizer( wxHORIZONTAL );
	
	
	bSizer21->Add( 0, 0, 1, wxEXPAND, 5 );
	
	BtnAbout = new wxButton( this, idBtnAbout, wxT("&About"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer21->Add( BtnAbout, 0, wxALL, 5 );
	
	m_staticline11 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer21->Add( m_staticline11, 0, wxALL|wxEXPAND, 5 );
	
	BtnQuit = new wxButton( this, idBtnQuit, wxT("&Quit"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer21->Add( BtnQuit, 0, wxALL, 5 );
	
	bSizer11->Add( bSizer21, 0, wxALIGN_BOTTOM|wxEXPAND, 5 );
	
	bSizer9->Add( bSizer11, 1, wxEXPAND, 5 );
	
	bSizer1->Add( bSizer9, 1, wxEXPAND, 5 );
	
	this->SetSizer( bSizer1 );
	this->Layout();
	
	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( GUIDialog::OnClose ) );
	this->Connect( wxEVT_INIT_DIALOG, wxInitDialogEventHandler( GUIDialog::OnInitDialog ) );
	m_sliderOctave->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( GUIDialog::OnSldrOctaveChanged ), NULL, this );
	m_cbSustainMode->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( GUIDialog::OnCbSustainNotesMode ), NULL, this );
	m_sliderSustainDuration->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( GUIDialog::OnSldrSustainNotesChanged ), NULL, this );
	m_radioChannel->Connect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( GUIDialog::OnRbSelectChannel ), NULL, this );
	BtnAbout->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIDialog::OnAbout ), NULL, this );
	BtnQuit->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIDialog::OnQuit ), NULL, this );
}

GUIDialog::~GUIDialog()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( GUIDialog::OnClose ) );
	this->Disconnect( wxEVT_INIT_DIALOG, wxInitDialogEventHandler( GUIDialog::OnInitDialog ) );
	m_sliderOctave->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( GUIDialog::OnSldrOctaveChanged ), NULL, this );
	m_cbSustainMode->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( GUIDialog::OnCbSustainNotesMode ), NULL, this );
	m_sliderSustainDuration->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( GUIDialog::OnSldrSustainNotesChanged ), NULL, this );
	m_radioChannel->Disconnect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( GUIDialog::OnRbSelectChannel ), NULL, this );
	BtnAbout->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIDialog::OnAbout ), NULL, this );
	BtnQuit->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIDialog::OnQuit ), NULL, this );
}
