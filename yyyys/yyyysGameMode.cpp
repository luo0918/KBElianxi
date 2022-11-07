// Copyright Epic Games, Inc. All Rights Reserved.

#include "yyyysGameMode.h"
#include "yyyysCharacter.h"
#include "UObject/ConstructorHelpers.h"

AyyyysGameMode::AyyyysGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
