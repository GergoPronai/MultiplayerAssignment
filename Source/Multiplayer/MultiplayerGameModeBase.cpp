// Copyright Epic Games, Inc. All Rights Reserved.


#include "MultiplayerGameModeBase.h"

#include "Kismet/GameplayStatics.h"

void AMultiplayerGameModeBase::PlayerJoined()
{
	UTravelGameInstance* gameInstance = Cast<UTravelGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
	UE_LOG(LogTemp, Warning, TEXT("Players joined"));
	if(gameInstance != nullptr)
	{
		gameInstance->numberOfPlayers = GetNumPlayers();
		if(gameInstance->numberOfPlayers == 4 && gameInstance->isGameStarted == false)
		{
			UE_LOG(LogTemp, Warning, TEXT("Game starts"));
			gameInstance->isGameStarted = true;
			FTimerHandle timer;
			GetWorld()->GetTimerManager().SetTimer(timer, this, &AMultiplayerGameModeBase::Start, 5.0f, false);
			
		}
	}
}

void AMultiplayerGameModeBase::Start()
{
	UTravelGameInstance* gameInstance = Cast<UTravelGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
	if (gameInstance != nullptr)
	{
		if(HasAuthority())
		{
			gameInstance->LoadNextLevel();
		}
	}
}

int AMultiplayerGameModeBase::GetCurrentNumberOfPlayers()
{
	return GetNumPlayers();
}

