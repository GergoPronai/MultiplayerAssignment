// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

#include "TravelGameInstance.h"
#include "GameFramework/GameModeBase.h"
#include "MultiplayerGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class MULTIPLAYER_API AMultiplayerGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
			
public:
	UFUNCTION()
	void PlayerJoined();
	void Start();
	int GetCurrentNumberOfPlayers();
	
};
