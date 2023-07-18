#ifndef WXTESTDIALOG2_HPP
#define WXTESTDIALOG2_HPP

#include <wx/panel.h>
#include <wx/string.h>

#include "GOSimpleDialog.h"

class wxTreeCtrl;

class WxTestDialog2 : public GOSimpleDialog {
private:
  wxTreeCtrl *m_Tmp;
  wxTreeCtrl *m_AudioOutput;

protected:
  virtual bool TransferDataToWindow() override;

public:
  WxTestDialog2(wxWindow *parent, const wxString &title);
  virtual ~WxTestDialog2();
};

#endif /* WXTESTDIALOG2_HPP */

