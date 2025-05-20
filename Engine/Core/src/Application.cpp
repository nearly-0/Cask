//
// Created by skywh on 25. 5. 21.
//

#include "include/Application.h"

using namespace Cask::Core;

extern bool g_IsApplicationRunning;
Application* Application::s_Instance = nullptr;

Application::Application()
{
    s_Instance = this;
}

Application::~Application()
{
    s_Instance = this;
}

void Application::Run()
{
    Init();

    while (_isRunning)
    {

    }

    Shutdown();
}


void Application::Close()
{
    _isRunning = false;
}

void Application::Init()
{

}


void Application::Shutdown()
{
    g_IsApplicationRunning = false;
}



inline Application& Application::Get()
{
    return *s_Instance;
}