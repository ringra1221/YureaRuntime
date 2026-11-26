module;

#include <string>
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <iostream>
#include <windows.h>

export module graphic_main;

export class graphic_control {
public:
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;

    SDL_Texture* texture = nullptr;
    std::string current_path = "";

    Uint64 last_tick = 0;

    SDL_FRect image_rect{100.0f, 100.0f, 200.0f, 200.0f};
    SDL_FRect player{100.0f, 100.0f, 50.0f, 50.0f};

    bool running = true;

    // デストラクタ
    ~graphic_control() {
        if (texture) {
            SDL_DestroyTexture(texture);
            texture = nullptr;
        }

        if (renderer) {
            SDL_DestroyRenderer(renderer);
            renderer = nullptr;
        }

        if (window) {
            SDL_DestroyWindow(window);
            window = nullptr;
        }

        SDL_Quit();
    }

    // 画像切り替え
    bool set_image(const std::string& path) {
        if (current_path == path && texture != nullptr) {
            return true;
        }

        SDL_Texture* new_texture = IMG_LoadTexture(renderer, path.c_str());

        if (!new_texture) {
            SDL_Log(
                "Image Load Error (%s): %s",
                path.c_str(),
                SDL_GetError()
            );
            return false;
        }

        if (texture) {
            SDL_DestroyTexture(texture);
        }

        texture = new_texture;
        current_path = path;

        return true;
    }

    // 初期化
    bool init(const int window_size, std::string window_title) {
        int width_size;
        int height_size;
        int window_flags;

        if (window_size == 0) {
            width_size = 0;
            height_size = 0;
            window_flags = SDL_WINDOW_FULLSCREEN;
        } 
        else if (window_size == 1) {
            width_size = 1920;
            height_size = 1080;
            window_flags = 0;
        }
        else if (window_size == 2) {
            width_size = 1280;
            height_size = 720;
            window_flags = 0;
        }
        else {
            MessageBox(
                NULL, 
                TEXT("window_sizeが無効な値です。（0から2まで）"), 
                TEXT("警告"), 
                MB_OK | MB_ICONWARNING
            );
            return false;
        }

        std::cout << "hello world" << std::endl;

        if (!SDL_Init(SDL_INIT_VIDEO)) {
            SDL_Log("SDL Init Error: %s", SDL_GetError());
            return false;
        }

        if (!SDL_CreateWindowAndRenderer(
            window_title.c_str(),
            width_size,
            height_size,
            window_flags,
            &window,
            &renderer
        )) {
            SDL_Log("Window Create Error: %s", SDL_GetError());
            return false;
        }

        // 初期画像
        set_image("sample.png");

        last_tick = SDL_GetTicks();

        return true;
    }

    // メインループ
    void graphic_run() {
        while (running) {
            // イベント処理
            SDL_Event event;

            while (SDL_PollEvent(&event)) {
                if (event.type == SDL_EVENT_QUIT) {
                    running = false;
                }

                if (
                    event.type == SDL_EVENT_KEY_DOWN &&
                    !event.key.repeat
                ) {
                    if (event.key.key == SDLK_ESCAPE) {
                        running = false;
                    }
                }
            }

            if (!running) {
                break;
            }

            // 描画処理
            SDL_SetRenderDrawColor(
                renderer,
                30, 30, 40, 255
            );

            SDL_RenderClear(renderer);

            // 背景画像
            if (texture) {
                SDL_RenderTexture(
                    renderer,
                    texture,
                    nullptr,
                    &image_rect
                );
            }

            SDL_RenderPresent(renderer);

            // CPUの過剰な占有を防ぐための簡易的なウェイト（必要に応じて調整）
            SDL_Delay(1);
        }
    }
};

// 外部起動関数
export int run_graphic_main() {
    graphic_control app;

    if (!app.init(2, "yurea-engine-test")) {
        return 1;
    }

    app.graphic_run();

    return 0;
}