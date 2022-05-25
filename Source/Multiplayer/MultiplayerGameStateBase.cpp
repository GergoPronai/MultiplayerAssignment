// Fill out your copyright notice in the Description page of Project Settings.


#include "MultiplayerGameStateBase.h"

#include "MultiplayerGameModeBase.h"
#include "TravelGameInstance.h"
#include "Kismet/GameplayStatics.h"


void AMultiplayerGameStateBase::PlayerFinishedLevel()
{
	UE_LOG(LogTemp, Warning, TEXT("Player finished"));

	AMultiplayerGameModeBase* gameMode = Cast<AMultiplayerGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));

	if (gameMode != nullptr)
	{
		++mPlayersFinished;
		if (mPlayersFinished == gameMode->GetCurrentNumberOfPlayers())
		{
			UTravelGameInstance* gameInstance = Cast<UTravelGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
			mPlayersFinished = 0;
			gameInstance->LoadNextLevel();
		}
	}
}
