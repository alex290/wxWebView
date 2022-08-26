#include "webframe.h"

WebFrame::WebFrame(wxString url)
    : wxFrame(NULL, wxID_ANY, "P2P Okx", wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE |  wxTAB_TRAVERSAL),
      m_url(url)
{
#if wxUSE_WEBVIEW_EDGE
    // Check if a fixed version of edge is present in
    // $executable_path/edge_fixed and use it
    wxFileName edgeFixedDir(wxStandardPaths::Get().GetExecutablePath());
    edgeFixedDir.SetFullName("");
    edgeFixedDir.AppendDir("edge_fixed");
    if (edgeFixedDir.DirExists())
    {
        wxWebViewEdge::MSWSetBrowserExecutableDir(edgeFixedDir.GetFullPath());
        wxLogMessage("Using fixed edge version");
    }
#endif
    // Create the webview
    m_browser = wxWebView::New();

    m_browser->Create(this, wxID_ANY, url, wxDefaultPosition, wxDefaultSize);
    m_browser->Bind(wxEVT_WEBVIEW_LOADED, &WebFrame::onLoad, this);
}

WebFrame::~WebFrame()
{
    delete m_browser;
    Destroy();
}

void WebFrame::onLoad(wxWebViewEvent &event)
{
    wxPuts("wxPuts Do");
    wxString code = m_browser->GetPageText();
    wxPuts("wxPuts");
    wxPuts(code);
}

