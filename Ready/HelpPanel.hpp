/*  Copyright 2011, 2012 The Ready Bunch

    This file is part of Ready.

    Ready is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Ready is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Ready. If not, see <http://www.gnu.org/licenses/>.         */

// wxWidgets:
#include <wx/wxprec.h>
#ifdef __BORLANDC__
    #pragma hdrstop
#endif
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

// local:
class MyFrame;
class HtmlView;

// the help panel displays .html files (stored in the Help folder or elsewhere)
class HelpPanel : public wxPanel
{
    public:

        HelpPanel(MyFrame* parent, wxWindowID id);

        // display given .html file
        void ShowHelp(const wxString& filepath);

    private:

        MyFrame* frame;   // link to parent frame

        HtmlView* html;   // child window for rendering HTML data

        wxButton* backbutt;     // back button
        wxButton* forwbutt;     // forwards button
        wxButton* contbutt;     // Contents button
        
        // event handlers
        void OnBackButton(wxCommandEvent& event);
        void OnForwardButton(wxCommandEvent& event);
        void OnContentsButton(wxCommandEvent& event);
        
        void UpdateHelpButtons();

        DECLARE_EVENT_TABLE()
};

// If ShowHelp is called with this string then a temporary .html file
// is created to show the user's current keyboard shortcuts.
const wxString SHOW_KEYBOARD_SHORTCUTS = wxT("keyboard.html");