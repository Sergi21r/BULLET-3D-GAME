#include "Globals.h"
#include "Application.h"
#include "ModulePlayer.h"
#include "Primitive.h"
#include "PhysVehicle3D.h"
#include "PhysBody3D.h"

ModulePlayer::ModulePlayer(Application* app, bool start_enabled) : Module(app, start_enabled), vehicle(NULL)
{
	turn = acceleration = brake = 0.0f;
}

ModulePlayer::~ModulePlayer()
{}

// Load assets
bool ModulePlayer::Start()
{
	LOG("Loading player");

	VehicleInfo car;

	// Car properties ----------------------------------------
	car.chassis_size.Set(2, 2, 4);
	car.chassis_offset.Set(0, 1.5, 0);
	car.mass = 500.0f;
	car.suspensionStiffness = 15.88f;
	car.suspensionCompression = 0.83f;
	car.suspensionDamping = 0.88f;
	car.maxSuspensionTravelCm = 1000.0f;
	car.frictionSlip = 50.5;
	car.maxSuspensionForce = 6000.0f;

	// Wheel properties ---------------------------------------
	float connection_height = 1.2f;
	float wheel_radius = 0.6f;
	float wheel_width = 0.5f;
	float suspensionRestLength = 1.2f;

	// Don't change anything below this line ------------------

	float half_width = car.chassis_size.x*0.5f;
	float half_length = car.chassis_size.z*0.5f;
	
	vec3 direction(0,-1,0);
	vec3 axis(-1,0,0);
	
	car.num_wheels = 4;
	car.wheels = new Wheel[4];

	// FRONT-LEFT ------------------------
	car.wheels[0].connection.Set(half_width - 0.3f * wheel_width, connection_height, half_length - wheel_radius);
	car.wheels[0].direction = direction;
	car.wheels[0].axis = axis;
	car.wheels[0].suspensionRestLength = suspensionRestLength;
	car.wheels[0].radius = wheel_radius;
	car.wheels[0].width = wheel_width;
	car.wheels[0].front = true;
	car.wheels[0].drive = true;
	car.wheels[0].brake = false;
	car.wheels[0].steering = true;

	// FRONT-RIGHT ------------------------
	car.wheels[1].connection.Set(-half_width + 0.3f * wheel_width, connection_height, half_length - wheel_radius);
	car.wheels[1].direction = direction;
	car.wheels[1].axis = axis;
	car.wheels[1].suspensionRestLength = suspensionRestLength;
	car.wheels[1].radius = wheel_radius;
	car.wheels[1].width = wheel_width;
	car.wheels[1].front = true;
	car.wheels[1].drive = true;
	car.wheels[1].brake = false;
	car.wheels[1].steering = true;

	// REAR-LEFT ------------------------
	car.wheels[2].connection.Set(half_width - 0.3f * wheel_width, connection_height, -half_length + wheel_radius);
	car.wheels[2].direction = direction;
	car.wheels[2].axis = axis;
	car.wheels[2].suspensionRestLength = suspensionRestLength;
	car.wheels[2].radius = wheel_radius;
	car.wheels[2].width = wheel_width;
	car.wheels[2].front = false;
	car.wheels[2].drive = false;
	car.wheels[2].brake = true;
	car.wheels[2].steering = false;

	// REAR-RIGHT ------------------------
	car.wheels[3].connection.Set(-half_width + 0.3f * wheel_width, connection_height, -half_length + wheel_radius);
	car.wheels[3].direction = direction;
	car.wheels[3].axis = axis;
	car.wheels[3].suspensionRestLength = suspensionRestLength;
	car.wheels[3].radius = wheel_radius;
	car.wheels[3].width = wheel_width;
	car.wheels[3].front = false;
	car.wheels[3].drive = false;
	car.wheels[3].brake = true;
	car.wheels[3].steering = false;

	vehicle = App->physics->AddVehicle(car);
	vehicle->SetPos(12, 5, 10);

	//create second vehicle
	vehicle2 = App->physics->AddVehicle(car);
	vehicle2->SetPos(8, 5, 10);
	
	
	return true;
}

// Unload assets
bool ModulePlayer::CleanUp()
{
	LOG("Unloading player");

	return true;
}

// Update: draw background
update_status ModulePlayer::Update(float dt)
{
	turn = acceleration = brake = 0.0f;

	if(App->input->GetKey(SDL_SCANCODE_UP) == KEY_REPEAT)
	{
		acceleration = MAX_ACCELERATION;
	}

	if (vehicle->GetKmh() < 0) {
		if (App->input->GetKey(SDL_SCANCODE_UP) == KEY_DOWN)
		{
			brake = BRAKE_POWER;
		}
	}

	if(App->input->GetKey(SDL_SCANCODE_LEFT) == KEY_REPEAT)
	{
		if(turn < TURN_DEGREES)
			turn +=  TURN_DEGREES;
	}

	if(App->input->GetKey(SDL_SCANCODE_RIGHT) == KEY_REPEAT)
	{
		if(turn > -TURN_DEGREES)
			turn -= TURN_DEGREES;
	}

	if(App->input->GetKey(SDL_SCANCODE_DOWN) == KEY_REPEAT)
	{
		acceleration -= MAX_ACCELERATION;
	}

	if (App->input->GetKey(SDL_SCANCODE_DOWN) == KEY_DOWN)
	{
		brake = BRAKE_POWER;
	}

	vehicle->ApplyEngineForce(acceleration);
	vehicle->Turn(turn);
	vehicle->Brake(brake);

	vehicle->Render();

	//vehicle 2
	turn2 = acceleration2 = brake2 = 0.0f;
	if (App->input->GetKey(SDL_SCANCODE_W) == KEY_REPEAT)
	{
		acceleration2 = MAX_ACCELERATION2;
	}

	if (vehicle2->GetKmh() < 0) {
		if (App->input->GetKey(SDL_SCANCODE_W) == KEY_DOWN)
		{
			brake2 = BRAKE_POWER2;
		}
	}

	if (App->input->GetKey(SDL_SCANCODE_A) == KEY_REPEAT)
	{
		if (turn2 < TURN_DEGREES2)
			turn2 += TURN_DEGREES2;
	}

	if (App->input->GetKey(SDL_SCANCODE_D) == KEY_REPEAT)
	{
		if (turn2 > -TURN_DEGREES2)
			turn2 -= TURN_DEGREES2;
	}

	if (App->input->GetKey(SDL_SCANCODE_S) == KEY_REPEAT)
	{
		acceleration2 -= MAX_ACCELERATION2;
	}

	if (App->input->GetKey(SDL_SCANCODE_S) == KEY_DOWN)
	{
		brake2 = BRAKE_POWER2;
	}

	vehicle2->ApplyEngineForce(acceleration2);
	vehicle2->Turn(turn2);
	vehicle2->Brake(brake2);

	vehicle2->Render();


	//window title

	/*if (App->scene_intro->countdownb == true) {
		//countdownt.Start();
		countdownf = countdownt.Read()/1000;
		char time[10];
		sprintf_s(time, "%i ...", countdownf);
		App->window->SetTitle(time);
		
		if (countdownf >= 5) {
			countdownt.Stop();
			App->scene_intro->countdownb = false;
		}
	}*/

	countdownf = countdownt.Read() / 1000;
	char title[80];
	sprintf_s(title, "Player1: %.1f Km/h     Lap %i     Player2: %.1f Km/h   TIME: %i", vehicle->GetKmh(), App->scene_intro->lap1, vehicle2->GetKmh(), countdownf);
	App->window->SetTitle(title);

	if (App->scene_intro->p1win == true) {
		char p1[50];
		sprintf_s(p1, "PLAYER 1 WINS, PRESS R TO RESTART");
		App->window->SetTitle(p1);
	}
	if (App->scene_intro->p2win == true) {
		char p2[50];
		sprintf_s(p2, "PLAYER 2 WINS, PRESS R TO RESTART");
		App->window->SetTitle(p2);
	}

	//restart

	if (App->input->GetKey(SDL_SCANCODE_R) == KEY_DOWN)
	{
		vehicle->SetPos(12, 5, 10);
		vehicle2->SetPos(8, 5, 10);
		App->scene_intro->p1win = false;
		App->scene_intro->p2win = false;
		App->scene_intro->start = false;
		App->scene_intro->half = false;
		App->scene_intro->lap1 = 0;
		App->scene_intro->lap2 = 0;
	}
	

	return UPDATE_CONTINUE;
}



