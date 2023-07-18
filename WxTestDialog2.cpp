#include "WxTestDialog2.hpp"

#include <wx/bookctrl.h>
#include <wx/button.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/treectrl.h>

class TestTreeCtrl : public wxTreeCtrl {
public:
  TestTreeCtrl(wxWindow *parent)
  : wxTreeCtrl(
    parent,
    wxID_ANY,
    wxDefaultPosition,
    wxSize(100, 100),
    wxTR_HAS_BUTTONS | wxTR_SINGLE) {}

  virtual wxSize DoGetBestSize() const override {
    return GetMinSize();
  }
};

bool WxTestDialog2::TransferDataToWindow()
{
  /*
  wxTreeItemId tmpRootNode = m_Tmp->AddRoot("Tmp Root");

  m_Tmp->AppendItem(tmpRootNode, "1");
  m_Tmp->AppendItem(tmpRootNode, "2");
  m_Tmp->Expand(tmpRootNode);

  wxTreeItemId rootNode = m_AudioOutput->AddRoot("Audio Output");

  for (int i = 1; i < 15; i++)
    m_AudioOutput->AppendItem(rootNode, wxString::Format("Child%i", i));
  m_AudioOutput->Expand(rootNode);
   */
  return true;
}

WxTestDialog2::WxTestDialog2(wxWindow *parent, const wxString &title)
  : GOSimpleDialog(parent, "Test", "Test", wxDIALOG_NO_PARENT)
{
  wxSizer *topSizer = new wxBoxSizer(wxVERTICAL);
/*
  m_Tmp = new TestTreeCtrl(this);
  topSizer->Add(m_Tmp, 1, wxEXPAND | wxALL, 5);
  topSizer->Add(
    new wxStaticText(this, wxID_ANY, "Tree:"),
    0, wxEXPAND | wxALL, 5);

  m_AudioOutput = new TestTreeCtrl(this);
  topSizer->Add(m_AudioOutput, 1, wxEXPAND | wxALL, 5);
*/
  LayoutWithInnerSizer(topSizer);
  // SetSizerAndFit(topSizer);
  // LayoutDialog();
}

WxTestDialog2::~WxTestDialog2() {}
