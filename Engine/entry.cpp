#include <Ether/Rt/application_ctx.h>

#include <glfw/glfw3.h>
#include <imgui.h>

#include <backends/imgui_impl_glfw.h>
#include <backends/imgui_impl_opengl3.h>

namespace Ether::Engine {
    class MainApplication : public Rt::ProcessContext {
    public:
        MainApplication() = default;
        ~MainApplication() = default;
    };
}

#define APPLICATION_EXPORT extern "C"
#define MAYBE_UNUSED [[maybe_unused]]

namespace Ether::Engine {

    APPLICATION_EXPORT MAYBE_UNUSED int main() {
        auto engine_entry = std::make_unique<MainApplication>();
        if (!glfwInit())
            return -1;

        const auto window = glfwCreateWindow(1280, 720, "Etherpro Layer Editor", nullptr, nullptr);
        if (!window)
        {
            glfwTerminate();
            return -1;
        }
        glfwMakeContextCurrent(window);
        // Enabling vertical sync by default
        glfwSwapInterval(1);

        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGuiIO& coreIO = ImGui::GetIO();

        ImGui_ImplGlfw_InitForOpenGL(window, true);
        ImGui_ImplOpenGL3_Init();

        ImGui::StyleColorsDark();
        while (!glfwWindowShouldClose(window))
        {
            // Cleaning the window buffer, we actually needed to do this before
            // of each "Rendering" frame!
            glClear(GL_COLOR_BUFFER_BIT);

            ImGui_ImplOpenGL3_NewFrame();
            ImGui_ImplGlfw_NewFrame();
            ImGui::NewFrame();

            ImGui::Begin("A little window");
            ImGui::End();

            ImGui::EndFrame();

            ImGui::Render();

            // Sending all data to the GPU device
            ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
            // Exchanging the GL video data between the window data
            glfwSwapBuffers(window);

            glfwPollEvents();
        }
        ImGui_ImplOpenGL3_Shutdown();
        ImGui_ImplGlfw_Shutdown();

        ImGui::DestroyContext();
        glfwDestroyWindow(window);

        glfwTerminate();
        return 0;
    }

}
