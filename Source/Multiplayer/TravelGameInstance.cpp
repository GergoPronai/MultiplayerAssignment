// Fill out your copyright notice in the Description page of Project Settings.


#include "TravelGameInstance.h"


void UTravelGameInstance::Host()
{
	UWorld* world = GetWorld();
	numberOfPlayers = 1;
	if (world != nullptr)
	{
		FString destination = FString::Printf(TEXT("/Game/Scenes/Level1?listen"));
		world->ServerTravel(destination);
	}
}

void UTravelGameInstance::Join(const FString IPAddress)
{
	APlayerController* playerController = GetFirstLocalPlayerController();
	numberOfPlayers++;
	if(playerController != nullptr)
	{
		playerController->ClientTravel(IPAddress,ETravelType::TRAVEL_Absolute);
	}
}

void UTravelGameInstance::Warp(const FString LevelName)
{
	UWorld* world = GetWorld();

	if (world != nullptr)
	{
		FString destination = FString::Printf(TEXT("/Game/Scenes/%s?listen"), *LevelName);
		world->ServerTravel(destination);
	}
}

void UTravelGameInstance::LoadNextLevel()
{
	UWorld* world = GetWorld();

	if (world != nullptr)
	{
		FString destination;
		if(nextLevelIndex >= NUMBER_OF_MAPS)
		{
			destination = FString::Printf(TEXT("/Game/Scenes/Level1?listen"));
		}
		else
		{
			FString nextLevel = levelNames[nextLevelIndex];
			destination = FString::Printf(TEXT("/Game/Scenes/%s?listen"), *nextLevel);
			++nextLevelIndex;
		}
		world->ServerTravel(destination);
	}
}
