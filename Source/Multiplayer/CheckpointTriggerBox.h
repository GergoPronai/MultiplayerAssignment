// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"


#include "PlayerCharacter.h"
#include "Components/BoxComponent.h"
#include "Engine/TriggerBox.h"
#include "CheckpointTriggerBox.generated.h"

/**
 * 
 */
UCLASS()
class MULTIPLAYER_API ACheckpointTriggerBox : public ATriggerBox
{
	GENERATED_BODY()

		UBoxComponent* checkpoint;
	
public:
	ACheckpointTriggerBox();

	UFUNCTION()
	void BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
