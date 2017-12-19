#include "Globals.h"
#include "Application.h"
#include "ModuleSceneIntro.h"
#include "Primitive.h"
#include "PhysBody3D.h"

ModuleSceneIntro::ModuleSceneIntro(Application* app, bool start_enabled) : Module(app, start_enabled)
{
}

ModuleSceneIntro::~ModuleSceneIntro()
{}

// Load assets
bool ModuleSceneIntro::Start()
{
	LOG("Loading Intro assets");
	bool ret = true;

	App->camera->Move(vec3(1.0f, 120.0f, 0.0f));
	App->camera->LookAt(vec3(-15, 0, 5));

	s.size = vec3(5, 3, 1);
	s.SetPos(0, 2.5f, 20);

	//-------------------------------- MAP -----------------------------------------------------------
	// FLOOR
	f1 = App->physics->AddCube(10, 1, 50, 10, 1, 30, 0.0f, Grey);
	f2 = App->physics->AddCube(10, 1, 40, 10, 1, -15, 0.0f, Grey);
	f3 = App->physics->AddCubeRotY(10, 1, 10, 9, 1, -35, 0.0f, Grey, 30);
	f4 = App->physics->AddCubeRotY(10, 1, 10, 6, 1, -40, 0.0f, Grey, 50);
	f5 = App->physics->AddCubeRotY(10, 1, 10, 1, 1, -43, 0.0f, Grey, 70);
	f6 = App->physics->AddCube(10, 1, 10, -7, 1, -44, 0.0f, Grey);
	f7 = App->physics->AddCubeRotY(10, 1, 10, -12, 1, -43, 0.0f, Grey, 120);
	f8 = App->physics->AddCubeRotY(10, 1, 10, -15, 1, -41, 0.0f, Grey, 140);
	f9 = App->physics->AddCubeRotY(10, 1, 10, -17, 1, -39, 0.0f, Grey, 160);
	f10 = App->physics->AddCube(10, 1, 20, -18, 1, -30, 0.0f, Grey);

	//------------------------------------------------------------------------------------------------

	sensor = App->physics->AddBody(s, 0.0f);
	sensor->SetAsSensor(true);
	sensor->collision_listeners.add(this);

	return ret;
}

// Load assets
bool ModuleSceneIntro::CleanUp()
{
	LOG("Unloading Intro scene");

	return true;
}

// Update
update_status ModuleSceneIntro::Update(float dt)
{
	Plane p(0, 1, 0, 0);
	p.axis = true;
	p.Render();

	// -------------------- MAP RENDERS ----------------------------------
	//FLOOR
	f1.Render();
	f2.Render();
	f3.Render();
	f4.Render();
	f5.Render();
	f6.Render();
	f7.Render();
	f8.Render();
	f9.Render();
	f10.Render();

	// -------------------------------------------------------------------

	sensor->GetTransform(&s.transform);
	s.Render();

	return UPDATE_CONTINUE;
}

void ModuleSceneIntro::OnCollision(PhysBody3D* body1, PhysBody3D* body2)
{
	LOG("Hit!");
}

