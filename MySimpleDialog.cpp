/////////////////////////////////////////////////////////////////////////////
// Name:        src/generic/propdlg.cpp
// Purpose:     MySimpleDialog
// Author:      Julian Smart
// Modified by:
// Created:     2005-03-12
// Copyright:   (c) Julian Smart
// Licence:     wxWindows licence
/////////////////////////////////////////////////////////////////////////////

// For compilers that support precompilation, includes "wx.h".
#include "MySimpleDialog.h"

#include "wx/wxprec.h"

#if wxUSE_BOOKCTRL

#ifndef WX_PRECOMP
    #include "wx/button.h"
    #include "wx/sizer.h"
    #include "wx/intl.h"
    #include "wx/log.h"
    #include "wx/msgdlg.h"
#endif

#include "wx/bookctrl.h"

#if wxUSE_NOTEBOOK
#include "wx/notebook.h"
#endif
#if wxUSE_CHOICEBOOK
#include "wx/choicebk.h"
#endif
#if wxUSE_TOOLBOOK
#include "wx/toolbook.h"
#endif
#if wxUSE_LISTBOOK
#include "wx/listbook.h"
#endif
#if wxUSE_TREEBOOK
#include "wx/treebook.h"
#endif

#include "wx/sysopt.h"

//-----------------------------------------------------------------------------
// MySimpleDialog
//-----------------------------------------------------------------------------

MySimpleDialog::MySimpleDialog(wxWindow* parent, wxWindowID id,
                   const wxString& title,
                   const wxPoint& pos,
                   const wxSize& sz,
                   long style,
                   const wxString& name)
{
    m_sheetStyle = wxPROPSHEET_DEFAULT;
    m_innerSizer = nullptr;
    m_bookCtrl = nullptr;
    m_sheetOuterBorder = 2;
    m_sheetInnerBorder = 5;

    parent = GetParentForModalDialog(parent, style);

    if (wxDialog::Create(parent, id, title, pos, sz, style|wxCLIP_CHILDREN, name)) {
      wxBoxSizer *topSizer = new wxBoxSizer( wxVERTICAL );
      SetSizer(topSizer);

      // This gives more space around the edges
      m_innerSizer = new wxBoxSizer( wxVERTICAL );

      topSizer->Add(m_innerSizer, 1, wxGROW|wxALL, m_sheetOuterBorder);

      m_bookCtrl = CreateBookCtrl();
      AddBookCtrl(m_innerSizer);
    }
}

// Layout the dialog, to be called after pages have been created
void MySimpleDialog::LayoutDialog(int centreFlags)
{
    GetSizer()->SetSizeHints(this);
    if (centreFlags)
        Centre(centreFlags);
}

// Creates the buttons, if any
void MySimpleDialog::CreateButtons(int flags)
{
    wxSizer *buttonSizer = CreateButtonSizer(flags);
    if( buttonSizer )
    {
        m_innerSizer->Add( buttonSizer, wxSizerFlags().Expand().Border(wxALL, 2) );
        m_innerSizer->AddSpacer(2);
    }
}

// Creates the book control
wxBookCtrlBase* MySimpleDialog::CreateBookCtrl()
{
    int style = wxCLIP_CHILDREN | wxBK_DEFAULT;

    wxBookCtrlBase* bookCtrl = nullptr;

#if wxUSE_NOTEBOOK
    if (GetSheetStyle() & wxPROPSHEET_NOTEBOOK)
        bookCtrl = new wxNotebook(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, style );
#endif
#if wxUSE_CHOICEBOOK
    if (GetSheetStyle() & wxPROPSHEET_CHOICEBOOK)
        bookCtrl = new wxChoicebook(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, style );
#endif
#if wxUSE_TOOLBOOK
#if defined(__WXMAC__) && wxUSE_TOOLBAR && wxUSE_BMPBUTTON
    if (GetSheetStyle() & wxPROPSHEET_BUTTONTOOLBOOK)
        bookCtrl = new wxToolbook(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, style|wxTBK_BUTTONBAR );
    else
#endif
    if ((GetSheetStyle() & wxPROPSHEET_TOOLBOOK) || (GetSheetStyle() & wxPROPSHEET_BUTTONTOOLBOOK))
        bookCtrl = new wxToolbook(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, style );
#endif
#if wxUSE_LISTBOOK
    if (GetSheetStyle() & wxPROPSHEET_LISTBOOK)
        bookCtrl = new wxListbook(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, style );
#endif
#if wxUSE_TREEBOOK
    if (GetSheetStyle() & wxPROPSHEET_TREEBOOK)
        bookCtrl = new wxTreebook(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, style );
#endif
    if (!bookCtrl)
        bookCtrl = new wxBookCtrl(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, style );

    if (GetSheetStyle() & wxPROPSHEET_SHRINKTOFIT)
        bookCtrl->SetFitToCurrentPage(true);

    return bookCtrl;
}

// Adds the book control to the inner sizer.
void MySimpleDialog::AddBookCtrl(wxSizer* sizer)
{
    sizer->Add( m_bookCtrl, wxSizerFlags(1).Expand().Border(wxALL, m_sheetInnerBorder) );
}

// Override function in base
wxWindow* MySimpleDialog::GetContentWindow() const
{
    return GetBookCtrl();
}

#endif // wxUSE_BOOKCTRL
