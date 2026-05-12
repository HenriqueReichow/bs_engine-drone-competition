#include "Holodeck.h"
#include "HolybroX500ControlThrusters.h"

UHolybroX500ControlThrusters::UHolybroX500ControlThrusters(const FObjectInitializer& ObjectInitializer) :
		Super(ObjectInitializer) {}

void UHolybroX500ControlThrusters::Execute(void* const CommandArray, void* const InputCommand, float DeltaSeconds) {
	if (HolybroX500 == nullptr) {
		HolybroX500 = static_cast<AHolybroX500*>(HolybroX500Controller->GetPawn());
		if (HolybroX500 == nullptr) {

			UE_LOG(LogHolodeck, Error, TEXT("UHolybroX500ControlThrusters couldn't get HolybroX500 reference"));
			return;
		}
		HolybroX500->ForcesInMainController(false);
	}

	float* InputCommandFloat = static_cast<float*>(InputCommand);
	float* CommandArrayFloat = static_cast<float*>(CommandArray);

	HolybroX500->ApplyFlightForce();
	HolybroX500->ApplyThrusters(InputCommandFloat);
	
	// Zero out the physics based controller
	for(int i=0; i<6; i++){
		CommandArrayFloat[i] = 0;
	}
}
