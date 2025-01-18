#include <JavaScriptCore/JavaScript.h>
#include "WebView.h"

class JSBridge
{
public:
    JSBridge()
    {
        context = JSGlobalContextCreate(nullptr);
    }

    ~JSBridge()
    {
        JSGlobalContextRelease(context);
    }

    void registerFunction()
    {
        JSObjectRef globalObject = JSContextGetGlobalObject(context);
        JSStringRef functionName = JSStringCreateWithUTF8CString("openWebView");

        // Registrar la función openWebView
        JSObjectRef functionObject = JSObjectMakeFunctionWithCallback(context, functionName, openWebViewJS);
        JSObjectSetProperty(context, globalObject, functionName, functionObject, kJSPropertyAttributeNone, nullptr);
        JSStringRelease(functionName);
    }

    void executeScript(const std::string &script)
    {
        JSStringRef scriptJS = JSStringCreateWithUTF8CString(script.c_str());
        JSValueRef exception = nullptr;
        JSEvaluateScript(context, scriptJS, nullptr, nullptr, 1, &exception);

        if (exception)
        {
            JSStringRef exceptionMessage = JSValueToStringCopy(context, exception, nullptr);
            size_t exceptionLength = JSStringGetMaximumUTF8CStringSize(exceptionMessage);
            char *exceptionCString = new char[exceptionLength];
            JSStringGetUTF8CString(exceptionMessage, exceptionCString, exceptionLength);
            std::cout << "Excepción: " << exceptionCString << std::endl;
            delete[] exceptionCString;
            JSStringRelease(exceptionMessage);
        }
        JSStringRelease(scriptJS);
    }

    static JSValueRef openWebViewJS(JSContextRef context, JSObjectRef function, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef *exception)
    {
        if (argumentCount > 0)
        {
            JSStringRef urlStr = JSValueToStringCopy(context, arguments[1], exception);
            size_t urlSize = JSStringGetMaximumUTF8CStringSize(urlStr);
            std::string url(urlSize, '\0');
            JSStringGetUTF8CString(urlStr, &url[0], urlSize);

            JSStringRef titleStr = JSValueToStringCopy(context, arguments[0], exception);
            size_t titleSize = JSStringGetMaximumUTF8CStringSize(urlStr);
            std::string title(titleSize, '\0');
            JSStringGetUTF8CString(titleStr, &title[0], titleSize);

            // Llamar a la función que abre el WebView
            openWebView(title, url);
            JSStringRelease(urlStr);
            JSStringRelease(titleStr);
        }
        return JSValueMakeUndefined(context);
    }

    static void openWebView(const std::string &title, const std::string &url)
    {
        WebViewWindow window(title, url);
        window.createWindow();
    }

private:
    JSGlobalContextRef context;
};
