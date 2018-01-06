#pragma once
#include "Module.h"
#include "p2DynArray.h"
#include "Globals.h"
#include "Primitive.h"
#include "p2Point.h"

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
	//Cube sensor
	Cube s1;
	Cube s2;

	//sensors
	PhysBody3D* sensor1;
	PhysBody3D* sensor2;

	//SF
	Cube sf;

	//MAP CUBES
	Cube f1, f2, f3, f4, f5, f6, f7, f8, f9, f10;
	Cube f11, f12, f13, f14, f15, f16, f17, f18, f19, f20;
	Cube f21, f22, f23, f24, f25, f26, f27, f28, f29, f30;
	Cube f31, f32, f33, f34, f35, f36, f37, f38, f39, f40, f41;

	//WALLS
	Cube w1, w2, w3, w4, w5, w6, w7, w8, w9, w10;
	Cube w11, w12, w13, w14, w15, w16, w17, w18, w19, w20;
	Cube w21, w22, w23, w24, w25, w26, w27, w28, w29, w30;
	Cube w31, w32, w33, w34, w35, w36, w37, w38, w39, w40;

	int lap1 = 0;
	int lap2 = 0;

	bool start = false;
	bool half = false;

	bool p1win = false;
	bool p2win = false;
	
	bool countdownb = true;

	uint music;
};
