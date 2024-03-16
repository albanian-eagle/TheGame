// Copyright Epic Games, Inc. All Rights Reserved.

#include "MyProject1GameMode.h"
#include "MyProject1PlayerController.h"
#include "MyProject1Character.h"
#include "UObject/ConstructorHelpers.h"

AMyProject1GameMode::AMyProject1GameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = AMyProject1PlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	// set default controller to our Blueprinted controller
	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownPlayerController"));
	if(PlayerControllerBPClass.Class != NULL)
	{
		PlayerControllerClass = PlayerControllerBPClass.Class;
	}
}