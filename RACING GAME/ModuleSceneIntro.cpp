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

	App->camera->Move(vec3(10.0f, 100.0f, 0.0f));
	App->camera->LookAt(vec3(-5.0f, 0.0f, 5.0f));

	s.size = vec3(5, 3, 1);
	s.SetPos(0, 2.5f, 20);

	//-------------------------------- MAP -----------------------------------------------------------
	// SUPER FLOOR
	//sf = App->physics->AddCube(500, 1, 500, 0, 1, 0, 0.0f, Green2);

	// FLOOR
	f1 = App->physics->AddCube(10, 1, 50, 10, 2, 10, 0.0f, Grey);
	f2 = App->physics->AddCube(10, 1, 40, 10, 2, -35, 0.0f, Grey);
	f3 = App->physics->AddCubeRotY(10, 1, 10, 9, 2, -55, 0.0f, Grey, 30);
	f4 = App->physics->AddCubeRotY(10, 1, 10, 6, 2, -60, 0.0f, Grey, 50);
	f5 = App->physics->AddCubeRotY(10, 1, 10, 1, 2, -63, 0.0f, Grey, 70);
	f6 = App->physics->AddCube(10, 1, 10, -7, 2, -64, 0.0f, Grey);
	f7 = App->physics->AddCubeRotY(10, 1, 10, -12, 2, -63, 0.0f, Grey, 120);
	f8 = App->physics->AddCubeRotY(10, 1, 10, -15, 2, -61, 0.0f, Grey, 140);
	f9 = App->physics->AddCubeRotY(10, 1, 10, -17, 2, -59, 0.0f, Grey, 160);
	f10 = App->physics->AddCube(10, 1, 20, -18, 2, -50, 0.0f, Grey);
	f11 = App->physics->AddCubeRotY(10, 1, 10, -19, 2, -37, 0.0f, Grey, 160);
	f12 = App->physics->AddCubeRotY(10, 1, 10, -21, 2, -34, 0.0f, Grey, 140);
	f13 = App->physics->AddCubeRotY(10, 1, 10, -23, 2, -31, 0.0f, Grey, 120);
	f14 = App->physics->AddCube(20, 1, 10, -33, 2, -29, 0.0f, Grey);
	f15 = App->physics->AddCubeRotY(10, 1, 10, -45, 2, -28, 0.0f, Grey, 120);
	f16 = App->physics->AddCubeRotY(10, 1, 10, -48, 2, -26, 0.0f, Grey, 140);
	f17 = App->physics->AddCubeRotY(10, 1, 10, -50, 2, -23, 0.0f, Grey, 160);
	f18 = App->physics->AddCube(10, 1, 40, -51, 2, -3, 0.0f, Grey);
	f19 = App->physics->AddCubeRotY(10, 1, 10, -50, 2, 19, 0.0f, Grey, 120);
	f20 = App->physics->AddCubeRotY(10, 1, 10, -47, 2, 21, 0.0f, Grey, 140);
	f21 = App->physics->AddCubeRotY(10, 1, 10, -44, 2, 23, 0.0f, Grey, 160);
	f22 = App->physics->AddCube(20, 1, 10, -33, 2, 24, 0.0f, Grey);
	f23 = App->physics->AddCubeRotY(10, 1, 10, -22, 2, 25, 0.0f, Grey, 160);
	f24 = App->physics->AddCubeRotY(10, 1, 10, -19, 2, 27, 0.0f, Grey, 140);
	f25 = App->physics->AddCubeRotY(10, 1, 10, -16, 2, 29, 0.0f, Grey, 120);
	f26 = App->physics->AddCube(10, 1, 40, -14, 2, 51, 0.0f, Grey);
	f27 = App->physics->AddCubeRotY(10, 1, 10, -13, 2, 72, 0.0f, Grey, 120);
	f28 = App->physics->AddCubeRotY(10, 1, 10, -10, 2, 74, 0.0f, Grey, 140);
	f29 = App->physics->AddCubeRotY(10, 1, 10, -7, 2, 76, 0.0f, Grey, 160);
	f30 = App->physics->AddCube(35, 1, 10, 13, 2, 77, 0.0f, Grey);
	f31 = App->physics->AddCubeRotY(10, 1, 10, 32, 2, 76, 0.0f, Grey, 120);
	f32 = App->physics->AddCubeRotY(10, 1, 10, 35, 2, 74, 0.0f, Grey, 140);
	f33 = App->physics->AddCubeRotY(10, 1, 10, 37, 2, 71, 0.0f, Grey, 160);
	f34 = App->physics->AddCube(10, 1, 20, 38, 2, 60, 0.0f, Grey);
	f35 = App->physics->AddCubeRotY(10, 1, 10, 37, 2, 49, 0.0f, Grey, 120);
	f36 = App->physics->AddCubeRotY(10, 1, 10, 35, 2, 47, 0.0f, Grey, 140);
	f37 = App->physics->AddCubeRotY(10, 1, 10, 32, 2, 45, 0.0f, Grey, 160);
	f38 = App->physics->AddCube(12, 1, 10, 23, 2, 44, 0.0f, Grey);
	f39 = App->physics->AddCubeRotY(10, 1, 10, 15, 2, 43, 0.0f, Grey, 160);
	f40 = App->physics->AddCubeRotY(10, 1, 10, 12, 2, 41, 0.0f, Grey, 140);
	f41 = App->physics->AddCubeRotY(10, 1, 10, 11, 2, 39, 0.0f, Grey, 120);

	//WALLS


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
	f15.Render();
	f16.Render();
	f17.Render();
	f18.Render();
	f19.Render();
	f20.Render();
	f21.Render();
	f22.Render();
	f23.Render();
	f24.Render();
	f25.Render();
	f26.Render();
	f27.Render();
	f28.Render();
	f29.Render();
	f30.Render();
	f31.Render();
	f32.Render();
	f33.Render();
	f34.Render();
	f35.Render();
	f36.Render();
	f37.Render();
	f38.Render();
	f39.Render();
	f40.Render();
	f41.Render();

	//WALLS


	// -------------------------------------------------------------------

	sensor->GetTransform(&s.transform);
	s.Render();

	return UPDATE_CONTINUE;
}

void ModuleSceneIntro::OnCollision(PhysBody3D* body1, PhysBody3D* body2)
{
	LOG("Hit!");
}

