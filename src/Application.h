#include <iostream>
#include <atomic>
#include <memory>
#include "JSBridge.h"

class Application
{
public:
    Application() : jsBridge(std::make_unique<JSBridge>()) {}

    void run(std::string source)
    {
        jsBridge->registerFunction();
        jsBridge->executeScript(source);
    }

private:
    std::unique_ptr<JSBridge> jsBridge;
};