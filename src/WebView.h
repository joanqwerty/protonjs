#define WEBVIEW_IMPLEMENTATION
#include "webview.h"
#include <iostream>
#include <thread>
#include <mutex>

void openWindow(const std::string &title, const std::string &url)
{
    webview::webview window(true, nullptr);
    window.set_title(title);
    window.set_size(800, 600, WEBVIEW_HINT_NONE);
    window.navigate(url);

    window.run();
}

class WebViewWindow
{
public:
    WebViewWindow(const std::string &title, const std::string &url)
        : windowTitle(title), targetUrl(url) {}

    void createWindow()
    {
        std::thread openThread([this]()
                               { openWindow(this->windowTitle, this->targetUrl); });
        openThread.join();
    }

private:
    std::string windowTitle;
    std::string targetUrl;
};
