#include "GOHelpRequestor.h"

#include <wx/event.h>
#include <wx/log.h>

#include "GOHelpController.h"

wxDECLARE_EVENT(wxEVT_SHOWHELP, wxCommandEvent);

wxDEFINE_EVENT(wxEVT_SHOWHELP, wxCommandEvent);

wxEvtHandler *GOHelpRequestor::p_EventHandler = NULL;

void GOHelpRequestor::OnShowHelp(wxCommandEvent &event) {
}

GOHelpRequestor::GOHelpRequestor(wxEvtHandler *peh) {
}

GOHelpRequestor::~GOHelpRequestor() {
  if (p_EventHandler) {
    p_EventHandler->Unbind(wxEVT_SHOWHELP, &GOHelpRequestor::OnShowHelp, this);
    p_EventHandler = NULL;
  }
  if (m_HelpController) {
    delete m_HelpController;
    m_HelpController = NULL;
  }
}

void GOHelpRequestor::DisplayHelp(const wxString &x, const bool isModal) {
  if (p_EventHandler) {
    wxCommandEvent helpEvt(wxEVT_SHOWHELP, 0);

    helpEvt.SetString(x);
    helpEvt.SetInt(isModal);
    p_EventHandler->AddPendingEvent(helpEvt);
  }
}
