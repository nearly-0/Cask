#pragma once

//
// Created by skywh on 25. 5. 20.
//

#include <cstdint>
#include <string>

namespace Cask::Platform
{
    struct WindowDesc
    {
        int _width = 1920;
        int _height = 1080;

        std::string _title = "Cask Engine";
    };

    export class IWindow
    {
    public:
        virtual ~IWindow() = default;

        virtual void Create(uint32_t width, uint32_t heigh, const char *pTitle) = 0;

        virtual void PollEvents() = 0;

        virtual void ShouldClose() const = 0;

        static IWindow *Create(const WindowDesc &desc);
    };
}
