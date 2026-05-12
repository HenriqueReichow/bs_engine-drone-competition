// MIT License (c) 2021 BYU FRoStLab see LICENSE file

#pragma once

#include "Holodeck.h"

#include "HolodeckPawnController.h"
#include "HolybroX500ControlThrusters.h"
// #include "HolybroX500PD.h"
#include "HolybroX500.h"


#include "HolybroX500Controller.generated.h"

/**
* A Holodeck Turtle Agent Controller
*/
UCLASS()

class HOLODECK_API AHolybroX500Controller : public AHolodeckPawnController
{
	GENERATED_BODY()

public:
	/**
	* Default Constructor
	*/
	AHolybroX500Controller(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	/**
	* Default Destructor
	*/
	~AHolybroX500Controller();

	void AddControlSchemes() override {
		// The default controller currently in ControlSchemes index 0 is the dynamics one. We push it back to index 1 with this code.

		// Thruster controller

		UHolybroX500ControlThrusters* Thrusters = NewObject<UHolybroX500ControlThrusters>();
		Thrusters->SetController(this);
		ControlSchemes.Insert(Thrusters, 0);

		// // Position / orientation controller
		// UHolybroX500PD* PD = NewObject<UHolybroX500PD>();
		// PD->SetController(this);
		// ControlSchemes.Insert(PD, 1);
	}
};

