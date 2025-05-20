//
// Created by skywh on 25. 5. 21.
//

#pragma once

#include <EASTL/allocator.h>

#include "Engine/Core/include/Application.h"

extern Cask::Application* Cask::CreateApplication(int argc, char** argv);
bool g_ApplicationRunning = true;

namespace Cask {
    class CaskDefaultAllocator : public eastl::allocator {
    public:
        void* allocate(size_t n, int flags = 0) {
            return malloc(n); // Replace with your own allocator logic
        }

        void deallocate(void* p, size_t n) {
            free(p); // Replace with your own logic
        }
    };

    // Required for EASTL to use your allocator
    eastl::allocator* eastl::GetDefaultAllocator() {
        static CaskDefaultAllocator allocator;
        return &allocator;
    }

    int Main(int argc, char** argv)
    {
        while (g_ApplicationRunning)
        {
            Application* app = CreateApplication(argc, argv);
            app->Run();
            delete app;
        }

        return 0;
    }

}

int main(int argc, char** argv)
{
    return Cask::Main(argc, argv);
}
