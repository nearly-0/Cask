//
// Created by skywh on 25. 5. 21.
//

module;
#include <SDL3/SDL.h>

module Platform.Window;

class SDLWindow : public IWindow {
public:
    SDLWindow(const WindowDesc& desc) {
        SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS);
        window = SDL_CreateWindow(
            desc.title.c_str(),
            SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
            desc.width, desc.height,
            SDL_WINDOW_SHOWN
        );
    }

    ~SDLWindow() {
        SDL_DestroyWindow(window);
        SDL_Quit();
    }

    void PollEvents() override {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_KEYDOWN:
                    if (OnKeyDown) OnKeyDown(event.key.keysym.sym);
                    break;
                case SDL_KEYUP:
                    if (OnKeyUp) OnKeyUp(event.key.keysym.sym);
                    break;
                case SDL_QUIT:
                    exit(0);
                    break;
            }
        }
    }

    void* GetNativeHandle() override {
        return window;
    }

private:
    SDL_Window* window = nullptr;
};

IWindow* IWindow::Create(const WindowDesc& desc) {
    return new SDLWindow(desc);
}
