#include "AppClass.h"
void Application::InitVariables(void)
{
	////Change this to your name and email
	m_sProgrammer = "Alberto Bobadilla - labigm@rit.edu";
	vector3 v3Position(0.0f, 0.0f, 10.0f);
	vector3 v3Target = ZERO_V3;
	vector3 v3Upward = AXIS_Y;
	m_pCameraMngr->SetPositionTargetAndUpward(v3Position, v3Target, v3Upward);

	//Allocate the memory for the Meshes
	for (int i = 0; i < 46; i++) { 
		m_pMesh = new MyMesh();
		m_pMeshes.push_back(m_pMesh);
		m_pMeshes[i]->GenerateCube(1.0f, C_BLACK);
	}
		
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

	//Calculate the model, view and projection matrix
	matrix4 m4Projection = m_pCameraMngr->GetProjectionMatrix();
	matrix4 m4View = m_pCameraMngr->GetViewMatrix();
	static float fDisplacement = -5.0f;
	matrix4 m4Model = glm::translate(vector3(fDisplacement, 0.0f, 0.0f));

	m_pMeshes[0]->Render(m4Projection, m4View, m4Model);
	m_pMeshes[1]->Render(m4Projection, m4View, glm::translate(m4Model, vector3(0.0f, 1.0f, 0.0f)));
	m_pMeshes[2]->Render(m4Projection, m4View, glm::translate(m4Model, vector3(0.0f, 2.0f, 0.0f)));
	m_pMeshes[3]->Render(m4Projection, m4View, glm::translate(m4Model, vector3(1.0f, 2.0f, 0.0f)));
	m_pMeshes[4]->Render(m4Projection, m4View, glm::translate(m4Model, vector3(1.0f, 3.0f, 0.0f)));
	m_pMeshes[5]->Render(m4Projection, m4View, glm::translate(m4Model, vector3(2.0f, 0.0f, 0.0f)));
	m_pMeshes[6]->Render(m4Projection, m4View, glm::translate(m4Model, vector3(2.0f, 1.0f, 0.0f)));
	m_pMeshes[7]->Render(m4Projection, m4View, glm::translate(m4Model, vector3(2.0f, 2.0f, 0.0f)));
	m_pMeshes[8]->Render(m4Projection, m4View, glm::translate(m4Model, vector3(2.0f, 3.0f, 0.0f)));
	m_pMeshes[9]->Render(m4Projection, m4View, glm::translate(m4Model, vector3(2.0f, 4.0f, 0.0f)));
	m_pMeshes[10]->Render(m4Projection, m4View, glm::translate(m4Model, vector3(2.0f, 6.0f, 0.0f)));
	m_pMeshes[11]->Render(m4Projection, m4View, glm::translate(m4Model, vector3(3.0f, -1.0f, 0.0f)));
	m_pMeshes[12]->Render(m4Projection, m4View, glm::translate(m4Model, vector3(3.0f, 1.0f, 0.0f)));
	m_pMeshes[13]->Render(m4Projection, m4View, glm::translate(m4Model, vector3(3.0f, 2.0f, 0.0f)));
	m_pMeshes[14]->Render(m4Projection, m4View, glm::translate(m4Model, vector3(3.0f, 4.0f, 0.0f)));
	m_pMeshes[15]->Render(m4Projection, m4View, glm::translate(m4Model, vector3(3.0f, 5.0f, 0.0f)));
	m_pMeshes[16]->Render(m4Projection, m4View, glm::translate(m4Model, vector3(4.0f, -1.0f, 0.0f)));
	m_pMeshes[17]->Render(m4Projection, m4View, glm::translate(m4Model, vector3(4.0f, 1.0f, 0.0f)));
	m_pMeshes[18]->Render(m4Projection, m4View, glm::translate(m4Model, vector3(4.0f, 2.0f, 0.0f)));
	m_pMeshes[19]->Render(m4Projection, m4View, glm::translate(m4Model, vector3(4.0f, 3.0f, 0.0f)));
	m_pMeshes[20]->Render(m4Projection, m4View, glm::translate(m4Model, vector3(4.0f, 4.0f, 0.0f)));
	m_pMeshes[21]->Render(m4Projection, m4View, glm::translate(m4Model, vector3(5.0f, 1.0f, 0.0f)));
	m_pMeshes[22]->Render(m4Projection, m4View, glm::translate(m4Model, vector3(5.0f, 2.0f, 0.0f)));
	m_pMeshes[23]->Render(m4Projection, m4View, glm::translate(m4Model, vector3(5.0f, 3.0f, 0.0f)));
	m_pMeshes[24]->Render(m4Projection, m4View, glm::translate(m4Model, vector3(5.0f, 4.0f, 0.0f)));
	m_pMeshes[25]->Render(m4Projection, m4View, glm::translate(m4Model, vector3(6.0f, -1.0f, 0.0f)));
	m_pMeshes[26]->Render(m4Projection, m4View, glm::translate(m4Model, vector3(6.0f, 1.0f, 0.0f)));
	m_pMeshes[27]->Render(m4Projection, m4View, glm::translate(m4Model, vector3(6.0f, 2.0f, 0.0f)));
	m_pMeshes[28]->Render(m4Projection, m4View, glm::translate(m4Model, vector3(6.0f, 3.0f, 0.0f)));
	m_pMeshes[29]->Render(m4Projection, m4View, glm::translate(m4Model, vector3(6.0f, 4.0f, 0.0f)));
	m_pMeshes[30]->Render(m4Projection, m4View, glm::translate(m4Model, vector3(7.0f, -1.0f, 0.0f)));
	m_pMeshes[31]->Render(m4Projection, m4View, glm::translate(m4Model, vector3(7.0f, 1.0f, 0.0f)));
	m_pMeshes[32]->Render(m4Projection, m4View, glm::translate(m4Model, vector3(7.0f, 2.0f, 0.0f)));
	m_pMeshes[33]->Render(m4Projection, m4View, glm::translate(m4Model, vector3(7.0f, 4.0f, 0.0f)));
	m_pMeshes[34]->Render(m4Projection, m4View, glm::translate(m4Model, vector3(7.0f, 5.0f, 0.0f)));
	m_pMeshes[35]->Render(m4Projection, m4View, glm::translate(m4Model, vector3(8.0f, 0.0f, 0.0f)));
	m_pMeshes[36]->Render(m4Projection, m4View, glm::translate(m4Model, vector3(8.0f, 1.0f, 0.0f)));
	m_pMeshes[37]->Render(m4Projection, m4View, glm::translate(m4Model, vector3(8.0f, 2.0f, 0.0f)));
	m_pMeshes[38]->Render(m4Projection, m4View, glm::translate(m4Model, vector3(8.0f, 3.0f, 0.0f)));
	m_pMeshes[39]->Render(m4Projection, m4View, glm::translate(m4Model, vector3(8.0f, 4.0f, 0.0f)));
	m_pMeshes[40]->Render(m4Projection, m4View, glm::translate(m4Model, vector3(8.0f, 6.0f, 0.0f)));
	m_pMeshes[41]->Render(m4Projection, m4View, glm::translate(m4Model, vector3(9.0f, 2.0f, 0.0f)));
	m_pMeshes[42]->Render(m4Projection, m4View, glm::translate(m4Model, vector3(9.0f, 3.0f, 0.0f)));
	m_pMeshes[43]->Render(m4Projection, m4View, glm::translate(m4Model, vector3(10.0f, 0.0f, 0.0f)));
	m_pMeshes[44]->Render(m4Projection, m4View, glm::translate(m4Model, vector3(10.0f, 1.0f, 0.0f)));
	m_pMeshes[45]->Render(m4Projection, m4View, glm::translate(m4Model, vector3(10.0f, 2.0f, 0.0f)));

	fDisplacement += 0.03f;

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
	//Release meshes
	for (int i = 0; i < 46; i++) {
		SafeDelete(m_pMeshes[i]);
	}
	

	//release GUI
	ShutdownGUI();
}