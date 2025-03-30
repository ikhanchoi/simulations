#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <typeindex>
#include <memory>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include "misc/cpp/imgui_stdlib.h"

#define TINYGLTF_IMPLEMENTATION
#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "tiny_gltf.h"


#include "ikhanchoi.h"





int main() {
	// glfw
    if (!glfwInit()) return -1;
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // for mac
    GLFWwindow* window = glfwCreateWindow(1280, 960, "GLTF Viewer", NULL, NULL);
    if (!window) return -1;
    glfwMakeContextCurrent(window);

	// glew
    glewInit();

	// imgui
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	ImGui::StyleColorsDark();
	ImGui_ImplGlfw_InitForOpenGL(window, true);
	ImGui_ImplOpenGL3_Init("#version 330");







	auto resourceManager = std::make_shared<ikhanchoi::ResourceManager>();
	auto entityManager = std::make_shared<ikhanchoi::EntityManager>();
	auto componentManager = std::make_shared<ikhanchoi::ComponentManager>();
	auto renderSystem = std::make_shared<ikhanchoi::RenderSystem>();

	renderSystem->setComponentManager(componentManager);



	auto pbrVert = resourceManager->addResource<ikhanchoi::ShaderResource>("pbr", "vert");
	auto pbrFrag = resourceManager->addResource<ikhanchoi::ShaderResource>("pbr", "frag");
	auto simpleFrag = resourceManager->addResource<ikhanchoi::ShaderResource>("simple", "frag");
	auto boomBox = resourceManager->addResource<ikhanchoi::ModelResource>("BoomBox", "gltf");
//	auto lantern = resourceManager->add<ikhanchoi::ModelResource>("Lantern", "gltf");
//	auto backpack = resourceManager->add<ikhanchoi::ModelResource>("Backpack", "gltf");
	auto damagedHelmet = resourceManager->addResource<ikhanchoi::ModelResource>("DamagedHelmet", "gltf");




	// initial entities, components, resources
	auto entity1 = entityManager->addEntity();
	auto render1 = componentManager->addComponent<ikhanchoi::RenderComponent>();
	auto transform1 = componentManager->addComponent<ikhanchoi::TransformComponent>();
	entity1->setComponent(render1);
	entity1->setComponent(transform1);
	render1->setModelResource(boomBox);
	render1->setDefaultShaderResource(pbrVert, "vert");
	render1->setDefaultShaderResource(pbrFrag, "frag");
	transform1->setScale(glm::vec4(1.0f, 1.0f, 1.0f, 100.0f));

	auto entity2 = entityManager->addEntity();
	auto render2 = componentManager->addComponent<ikhanchoi::RenderComponent>();
	auto transform2 = componentManager->addComponent<ikhanchoi::TransformComponent>();
	entity2->setComponent(render2);
	entity2->setComponent(transform2);
	render2->setModelResource(damagedHelmet);
	render2->setDefaultShaderResource(pbrVert, "vert");
	render2->setDefaultShaderResource(pbrFrag, "frag");
	transform2->setRotation(glm::vec3(-90.0f, 180.0f, 0.0f));







	bool showDemoWindow = false;

	glEnable(GL_CULL_FACE);
	glEnable(GL_DEPTH_TEST);

    while (!glfwWindowShouldClose(window)) {

		/* 1. Physics */


		/* 2. Input */

        glfwPollEvents();

		/* 3. Logic */


		/* 4. Render */

		renderSystem->render();

		// imgui
		ImGui_ImplOpenGL3_NewFrame(), ImGui_ImplGlfw_NewFrame(), ImGui::NewFrame();
		ImGui::Begin("Hello, world!");
		ImGui::Checkbox("Demo Window", &showDemoWindow);
		ImGui::Text("Application average %.3f ms/frame (%.1f FPS)",
					1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
		ImGui::End();
		if (showDemoWindow)
			ImGui::ShowDemoWindow(&showDemoWindow);

		resourceManager->show();
		entityManager->show();
		componentManager->show();

		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());


        glfwSwapBuffers(window);
    }

	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}
