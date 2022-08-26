#include "webframe.h"

class MyApp : public wxApp
{
public:
    virtual bool OnInit();
};

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
    WebFrame *frame = new WebFrame("http://jsonplaceholder.typicode.com/posts");
    frame->Show(true);
    return true;
}