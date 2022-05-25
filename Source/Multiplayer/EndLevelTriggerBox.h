// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "MultiplayerGameStateBase.h"
#include "Components/BoxComponent.h"
#include "Engine/TriggerBox.h"
#include "EndLevelTriggerBox.generated.h"

/**
 * 
 */
UCLASS()
class MULTIPLAYER_API AEndLevelTriggerBox : public ATriggerBox
{
	GENERATED_BODY()
	
private:
	UPROPERTY()
	UBoxComponent* checkpoint;

	UPROPERTY()
	AMultiplayerGameStateBase* gameState;
	
public:
	AEndLevelTriggerBox();

	UFUNCTION()
	void BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

};
