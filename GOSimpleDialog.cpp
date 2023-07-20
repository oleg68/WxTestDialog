/*
 * Copyright 2006 Milan Digital Audio LLC
 * Copyright 2009-2023 GrandOrgue contributors (see AUTHORS)
 * License GPL-2.0 or later
 * (https://www.gnu.org/licenses/old-licenses/gpl-2.0.html).
 */

#include "GOSimpleDialog.h"

#include <wx/sizer.h>
#include <wx/statline.h>

GOSimpleDialog::GOSimpleDialog(
  wxWindow *win,
  const wxString &name,  // not translated
  const wxString &title, // translated
  long addStyle,
  long buttonFlags)
  : GODialog(buttonFlags) {

  long style = GetWindowStyle();

    // This call is necessary for the dialog not to cover the help window
  if (
    Create(
      GetParentForModalDialog(win, style),
      wxID_ANY,
      title,
      wxDefaultPosition,
      wxDefaultSize,
      style,
      name)) {
    
    wxBoxSizer *const pTopSizer = new wxBoxSizer(wxVERTICAL);

    p_ContentSizer = new wxBoxSizer(wxVERTICAL);
    pTopSizer->Add(p_ContentSizer, 1, wxGROW | wxEXPAND | wxALL, 5);
    pTopSizer->Add(new wxStaticLine(this), 0, wxEXPAND | wxALL, 5);
    pTopSizer->Add(GetButtonSizer(), 0, wxEXPAND | wxALL, 5);
    SetSizerAndFit(pTopSizer);
  }
}

void GOSimpleDialog::LayoutWithInnerSizer(wxSizer *pInnerSizer) {
  p_ContentSizer->Add(pInnerSizer, 1, wxGROW | wxEXPAND);
}
