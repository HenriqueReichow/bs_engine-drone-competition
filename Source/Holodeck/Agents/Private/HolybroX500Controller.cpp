
#include "Holodeck.h"
#include "HolybroX500Controller.h"

AHolybroX500Controller::AHolybroX500Controller(const FObjectInitializer& ObjectInitializer)
	: AHolodeckPawnController(ObjectInitializer) {
	UE_LOG(LogTemp, Warning, TEXT("HolybroX500 Controller Initialized"));
}

AHolybroX500Controller::~AHolybroX500Controller() {}

