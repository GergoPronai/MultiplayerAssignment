// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "GameFramework/GameStateBase.h"
#include "MultiplayerGameStateBase.generated.h"

/**
 * 
 */
UCLASS()
class MULTIPLAYER_API AMultiplayerGameStateBase : public AGameStateBase
{
	GENERATED_BODY()

private:
	int mPlayersFinished = 0;
	
public:
	void PlayerFinishedLevel();
};
