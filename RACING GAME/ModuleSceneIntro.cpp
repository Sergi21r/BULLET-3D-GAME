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
	App->camera->LookAt(vec3(-10.0f, 0.0f, 5.0f));

	s.size = vec3(5, 3, 1);
	s.SetPos(0, 2.5f, 20);

	//-------------------------------- MAP -----------------------------------------------------------
	// SUPER FLOOR
	//sf = App->physics->AddCube(500, 1, 500, 0, 1, 0, 0.0f, Green2);

	// FLOOR
	f1 = App->physics->AddCube(10, 1, 50, 10, 2, 30, 0.0f, Grey);
	f2 = App->physics->AddCube(10, 1, 40, 10, 2, -15, 0.0f, Grey);
	f3 = App->physics->AddCubeRotY(10, 1, 10, 9, 2, -35, 0.0f, Grey, 30);
	f4 = App->physics->AddCubeRotY(10, 1, 10, 6, 2, -40, 0.0f, Grey, 50);
	f5 = App->physics->AddCubeRotY(10, 1, 10, 1, 2, -43, 0.0f, Grey, 70);
	f6 = App->physics->AddCube(10, 1, 10, -7, 2, -44, 0.0f, Grey);
	f7 = App->physics->AddCubeRotY(10, 1, 10, -12, 2, -43, 0.0f, Grey, 120);
	f8 = App->physics->AddCubeRotY(10, 1, 10, -15, 2, -41, 0.0f, Grey, 140);
	f9 = App->physics->AddCubeRotY(10, 1, 10, -17, 2, -39, 0.0f, Grey, 160);
	f10 = App->physics->AddCube(10, 1, 20, -18, 2, -30, 0.0f, Grey);
	f11 = App->physics->AddCubeRotY(10, 1, 10, -19, 2, -17, 0.0f, Grey, 160);
	f12 = App->physics->AddCubeRotY(10, 1, 10, -21, 2, -14, 0.0f, Grey, 140);
	f13 = App->physics->AddCubeRotY(10, 1, 10, -23, 2, -11, 0.0f, Grey, 120);
	f14 = App->physics->AddCube(20, 1, 10, -33, 2, -9, 0.0f, Grey);

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
	//SF
	//sf.Render();
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
	f11.Render();
	f12.Render();
	f13.Render();
	f14.Render();

	// -------------------------------------------------------------------

	sensor->GetTransform(&s.transform);
	s.Render();

	return UPDATE_CONTINUE;
}

void ModuleSceneIntro::OnCollision(PhysBody3D* body1, PhysBody3D* body2)
{
	LOG("Hit!");
}

