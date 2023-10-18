#include <stdio.h>
#include <SDL2/SDL.h>

void drawPattern(SDL_Renderer *renderer, int xOffset) {
    int i;
    for (i = 0; i <= 1000; i += 10) {
        SDL_SetRenderDrawColor(renderer, i + i * 2, i + i * 2, i + i * 2, 255);
        SDL_RenderDrawLine(renderer, 50 + i + xOffset, 100, 100 + i + xOffset, 100);
        SDL_RenderDrawLine(renderer, 100 + i + xOffset, 100, 150 + i + xOffset, 50);
        SDL_RenderDrawLine(renderer, 150 + i + xOffset, 50, 400 + i + xOffset, 50);
        SDL_RenderDrawLine(renderer, 400 + i + xOffset, 50, 450 + i + xOffset, 100);
        SDL_RenderDrawLine(renderer, 450 + i + xOffset, 100, 500 + i + xOffset, 100);
        SDL_RenderDrawLine(renderer, 500 + i + xOffset, 100, 500 + i + xOffset, 150);
        SDL_RenderDrawLine(renderer, 500 + i + xOffset, 150, 450 + i + xOffset, 150);

        // Draw circles
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderDrawLine(renderer, 375 + i + xOffset, 150, 200 + i + xOffset, 150);

        // Draw outer circles
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderDrawLine(renderer, 165 + i + xOffset, 150, 50 + i + xOffset, 150);
        SDL_RenderDrawLine(renderer, 50 + i + xOffset, 150, 50 + i + xOffset, 100);

        SDL_RenderPresent(renderer);
        SDL_Delay(100);
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
    }
}

int main() {
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Event event;
    int xOffset = 0;
    int running;

    SDL_Init(SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer(800, 200, 0, &window, &renderer);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

    running = 1;
    while (running) {
        drawPattern(renderer, xOffset);

        xOffset++;
        if (xOffset > 150) {
            xOffset = 0;
        }

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = 0;
            }
        }
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
