// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Engine/GameInstance.h"
#include "TravelGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class MULTIPLAYER_API UTravelGameInstance : public UGameInstance
{
	GENERATED_BODY()
public:
	int numberOfPlayers = 0;
	bool isGameStarted = false;
	
private:
	static const int NUMBER_OF_MAPS = 3;
	int nextLevelIndex = 1;
	FString levelNames[NUMBER_OF_MAPS] = { "Lobby", "Level1", "Level2" };
	
public:
	UFUNCTION(Exec)
	void Host();

	UFUNCTION(Exec)
	void Join(const FString IPAddress);

	UFUNCTION(Exec)
	void Warp(const FString LevelName);
	
	void LoadNextLevel();
};
