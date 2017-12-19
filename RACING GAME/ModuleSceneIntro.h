#pragma once
#include "Module.h"
#include "p2DynArray.h"
#include "Globals.h"
#include "Primitive.h"

#define MAX_SNAKE 2

struct PhysBody3D;
struct PhysMotor3D;

class ModuleSceneIntro : public Module
{
public:
	ModuleSceneIntro(Application* app, bool start_enabled = true);
	~ModuleSceneIntro();

	bool Start();
	update_status Update(float dt);
	bool CleanUp();

	void OnCollision(PhysBody3D* body1, PhysBody3D* body2);

public:
	Cube s;
	//SF
	Cube sf;

	//MAP CUBES
	Cube f1;
	Cube f2;
	Cube f3;
	Cube f4;
	Cube f5;
	Cube f6;
	Cube f7;
	Cube f8;
	Cube f9;
	Cube f10;
	Cube f11;
	Cube f12;
	Cube f13;
	Cube f14;
	Cube f15;
	Cube f16;
	Cube f17;
	Cube f18;
	Cube f19;
	Cube f20;

	PhysBody3D* sensor;
};
