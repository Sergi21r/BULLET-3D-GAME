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
	w1 = App->physics->AddCube(2, 6, 95, 15, 2, -11, 0.0f, Blue);
	w2 = App->physics->AddCubeRotY(2, 6, 18, 8, 2, -64, 0.0f, Blue, 50);
	w3 = App->physics->AddCube(15, 6, 2, -5, 2, -69, 0.0f, Blue);
	w4 = App->physics->AddCubeRotY(2, 6, 18, -18, 2, -64, 0.0f, Blue, 130);
	w5 = App->physics->AddCube(2, 6, 17, -24, 2, -50, 0.0f, Blue);

	//start wall
	//wstart= App->physics->AddCube(12, 3, 1, 10, 3, 13, 0.0f, Blue);

	//------------------------------------------------------------------------------------------------

	//sensors
	s1.size = vec3(12, 3, 1);
	s1.SetPos(10, 3.0f, 14);
	sensor1 = App->physics->AddBody(s1, 0.0f);
	sensor1->SetAsSensor(true);
	sensor1->collision_listeners.add(this);

	s2.size = vec3(12, 3, 1);
	s2.SetPos(-51, 3.0f, 14);
	sensor2 = App->physics->AddBody(s2, 0.0f);
	sensor2->SetAsSensor(true);
	sensor2->collision_listeners.add(this);



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
	w1.Render();
	w2.Render();
	w3.Render();
	w4.Render();
	w5.Render();

	//wall start
	wstart.Render();

	// -------------------------------------------------------------------

	//sensor->GetTransform(&s.transform);
	s1.Render();
	s2.Render();


	return UPDATE_CONTINUE;
}

void ModuleSceneIntro::OnCollision(PhysBody3D* body1, PhysBody3D* body2)
{
	
	if (body1 == sensor1) {
		if (start == false && half == false) {
			start = true;
			lap1 = 1;
		}
		else if (half == true) {
			half = false;
			start = true;
			if (lap1 == 3) {
				p1win = true;
			}
			if (lap1 == 2) {
				lap1 = 3;
			}
			if (lap1 == 1) {
				lap1 = 2;
			}
		}
	}

	if (body1 == sensor2) {
		half = true;
		start = false;
	}

	/*if (body2 == sensor1) {
		if (lap2 == 0) {
			lap2 = 1;
		}
	}*/



}

