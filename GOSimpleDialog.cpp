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
  : GODialog(win, name, title, addStyle, buttonFlags) {
  wxBoxSizer *const pTopSizer = new wxBoxSizer(wxVERTICAL);

  p_ContentSizer = new wxBoxSizer(wxVERTICAL);
  pTopSizer->Add(p_ContentSizer, 1, wxGROW | wxEXPAND | wxALL, 5);
  pTopSizer->Add(new wxStaticLine(this), 0, wxEXPAND | wxALL, 5);
  pTopSizer->Add(GetButtonSizer(), 0, wxEXPAND | wxALL, 5);
  SetSizerAndFit(pTopSizer);

  long style = GetWindowStyle();

  // This call is necessary for the dialog not to cover the help window
  Create(
    GetParentForModalDialog(GetParent(), style),
    GetId(),
    GetTitle(),
    GetPosition(),
    GetSize(),
    style,
    GetName());
}

void GOSimpleDialog::LayoutWithInnerSizer(wxSizer *pInnerSizer) {
  p_ContentSizer->Add(pInnerSizer, 1, wxGROW | wxEXPAND);
}
