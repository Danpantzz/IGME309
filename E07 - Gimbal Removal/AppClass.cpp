#include "AppClass.h"
void Application::InitVariables(void)
{
	////Change this to your name and email
	m_sProgrammer = "Alberto Bobadilla - labigm@rit.edu";
	vector3 v3Position(0.0f, 0.0f, 10.0f);
	vector3 v3Target = ZERO_V3;
	vector3 v3Upward = AXIS_Y;
	m_pCameraMngr->SetPositionTargetAndUpward(v3Position, v3Target, v3Upward);
	m_pModelMngr->LoadModel(m_sSteve);
}
void Application::Update(void)
{
	//Update the system so it knows how much time has passed since the last call
	m_pSystem->Update();

	//Is the arcball active?
	ArcBall();

	//Is the first person camera active?
	CameraRotation();

	//Update Entity Manager
	m_pEntityMngr->Update();

	//Add objects to render list
	m_pEntityMngr->AddEntityToRenderList(-1, true);
}
void Application::Display(void)
{
	// Clear the screen
	ClearScreen();

	matrix4 m4View = m_pCameraMngr->GetViewMatrix();
	matrix4 m4Projection = m_pCameraMngr->GetProjectionMatrix();

	m_m4Model = glm::rotate(IDENTITY_M4, glm::radians(m_v3Rotation.x), vector3(1.0f, 0.0f, 0.0f));
	m_m4Model = glm::rotate(m_m4Model, glm::radians(m_v3Rotation.y), vector3(0.0f, 1.0f, 0.0f));
	m_m4Model = glm::rotate(m_m4Model, glm::radians(m_v3Rotation.z), vector3(0.0f, 0.0f, 1.0f));

	/* My Solutuon */
	// not sure if this is the right way, but it is the only way I could figure out how to get everything to work, despite not using the 4th quaternion
	// quaternion q1 = glm::angleAxis(glm::radians(1.0f), vector3(1.0f, 0.0f, 0.0f));
	// quaternion q2 = glm::angleAxis(glm::radians(1.0f), vector3(0.0f, 1.0f, 0.0f));
	// quaternion q3 = glm::angleAxis(glm::radians(1.0f), vector3(0.0f, 0.0f, 1.0f));
	// 
	// if (sf::Keyboard::isKeyPressed(sf::Keyboard::X)) {
	// 	m_qOrientation = m_qOrientation * q1;
	// }
	// if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y)) {
	// 	m_qOrientation = m_qOrientation * q2;
	// }
	// if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
	// 	m_qOrientation = m_qOrientation * q3;
	// }
	// if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
	// 	m_qOrientation = quaternion();
	// }

	static quaternion qFinal;
	m_qOrientation = m_qOrientation * glm::angleAxis(glm::radians(m_v3Rotation.x), vector3(1.0f, 0.0f, 0.0f));
	m_qOrientation = m_qOrientation * glm::angleAxis(glm::radians(m_v3Rotation.y), vector3(0.0f, 1.0f, 0.0f));
	m_qOrientation = m_qOrientation * glm::angleAxis(glm::radians(m_v3Rotation.z), vector3(0.0f, 0.0f, 1.0f));

	/*
	* The following line was replaced by the model manager so we can see a model instead of a cone
	*/
	//m_pMesh->Render(m4Projection, m4View, ToMatrix4(m_m4Model));
	m_pModelMngr->AddModelToRenderList(m_sSteve,ToMatrix4(m_qOrientation));

	m_v3Rotation = ZERO_V3;

	// draw a skybox
	m_pModelMngr->AddSkyboxToRenderList();

	//render list call
	m_uRenderCallCount = m_pModelMngr->Render();

	//clear the render list
	m_pModelMngr->ClearRenderList();

	//draw gui
	DrawGUI();
	
	//end the current frame (internally swaps the front and back buffers)
	m_pWindow->display();
}
void Application::Release(void)
{
	//release GUI
	ShutdownGUI();
}