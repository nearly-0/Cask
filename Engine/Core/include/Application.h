#pragma once

#include <string>
#include <cstdint>

namespace Cask::Core
{
    struct ApplicationSpec
    {
        std::string Name = "Cask";
        uint32_t WindowWidth = 1920;
        uint32_t WindowHeight = 1080;
    };

    class Application
    {
    public:
        Application();
        virtual ~Application();

		void Run();
		void Close();

		virtual void Init();
		virtual void Shutdown();

		static Application* CreateApplication();
		static Application& Get();

    private:
		bool _isRunning = true;
        static Application* s_Instance;
    };

	Application* CreateApplication(int argc, char** argv);
};
