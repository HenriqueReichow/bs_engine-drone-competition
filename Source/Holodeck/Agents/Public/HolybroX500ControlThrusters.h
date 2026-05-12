#pragma once

#include "Holodeck.h"

#include "HolodeckPawnController.h"
#include "HolybroX500.h"
#include "HolodeckControlScheme.h"
#include "SimplePID.h"
#include <math.h>

#include "HolybroX500ControlThrusters.generated.h"

/**
* UHolybroX500ControlThrusters
*/
UCLASS()
class HOLODECK_API UHolybroX500ControlThrusters : public UHolodeckControlScheme {
public:
	GENERATED_BODY()

	UHolybroX500ControlThrusters(const FObjectInitializer& ObjectInitializer);

	void Execute(void* const CommandArray, void* const InputCommand, float DeltaSeconds) override;

	/** NOTE: These go counter-clockwise, starting in front right

	*/
	unsigned int GetControlSchemeSizeInBytes() const override {
		return 8 * sizeof(float);
	}

	void SetController(AHolodeckPawnController* const Controller) { HolybroX500Controller = Controller; };

private:
	AHolodeckPawnController* HolybroX500Controller;
	AHolybroX500* HolybroX500;

};

