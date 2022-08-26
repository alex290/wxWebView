#ifndef WEBFRAME_H
#define WEBFRAME_H

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif
#include <wx/webview.h>
#if !wxUSE_WEBVIEW_WEBKIT && !wxUSE_WEBVIEW_WEBKIT2 && !wxUSE_WEBVIEW_IE && !wxUSE_WEBVIEW_EDGE
#error "A wxWebView backend is required by this sample"
#endif
#if wxUSE_WEBVIEW_EDGE
#include "wx/msw/webview_edge.h"
#endif
#include <wx/filename.h>
#include <wx/stdpaths.h>
#include <wx/textfile.h>


class WebFrame : public wxFrame
{
public:
    WebFrame(wxString url);
    ~WebFrame();

private:
    wxString m_url;
    wxWebView *m_browser;

    void addGui();
    void onLoad(wxWebViewEvent &event);
};

#endif