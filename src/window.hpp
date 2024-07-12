#pragma once

#include <GLFW/glfw3.h>
#include <assert.h>
#include <easylogging++.h>

#include <gli/gl.hpp>
#include <string>

#include "camera.hpp"
#include "constants.hpp"
#include "gfx.hpp"
#include "gfx_gl.hpp"

namespace goat {

class GameWindow {
   private:
    typedef unsigned int uint;

   protected:
    GLFWwindow *window;
    unsigned int width;
    unsigned int height;
    float deltaTime;
    float lastFrame;
    camera::Camera *camera = nullptr;

    static inline void handleKeypress(GLFWwindow *window, int key, int scancode, int action, int mods);
    static inline void logDriverInfo();

   public:
    GameWindow(std::string window_title = "GameWindow", gfx::EngineConfig = {gfx::gl::glAPI::OPENGL3_3},
               unsigned int width = gfx::DEFAULT_SCREEN_WIDTH, unsigned int height = gfx::DEFAULT_SCREEN_HEIGHT);
    inline ~GameWindow() {
        glfwTerminate();
    }

    inline void createCamera(glm::vec3 start_pos = camera::CAMERA_DEFAULT_POS);
    constexpr inline void setFeature(gfx::gl::glFeature feature, bool enable = true);
    constexpr inline GLFWwindow *getHandle() const;
    constexpr inline camera::Camera *getCamera() const;
    void loop(std::function<void()> tick_fn);
};

}  // namespace goat

#include "window.inl"