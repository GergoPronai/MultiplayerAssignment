// Fill out your copyright notice in the Description page of Project Settings.


#include "EndLevelTriggerBox.h"


#include "PlayerCharacter.h"
#include "Kismet/GameplayStatics.h"


AEndLevelTriggerBox::AEndLevelTriggerBox()
{
	checkpoint = CreateDefaultSubobject<UBoxComponent>(TEXT("Checkpoint"));
	checkpoint->SetBoxExtent(FVector(32.0f, 32.0f, 32.0f));
	checkpoint->SetCollisionProfileName("Trigger");
	RootComponent = checkpoint;

	checkpoint->OnComponentBeginOverlap.AddDynamic(this, &AEndLevelTriggerBox::BeginOverlap);
}

void AEndLevelTriggerBox::BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	gameState = Cast<AMultiplayerGameStateBase>(UGameplayStatics::GetGameState(GetWorld()));
	APlayerCharacter* player = Cast<APlayerCharacter>(OtherActor);
	if (player != nullptr)
	{
		if (gameState != nullptr && player->isFinishedLevel == false)
		{
			UE_LOG(LogTemp, Warning, TEXT("Player finished"));
			gameState->PlayerFinishedLevel();
			player->isFinishedLevel = true;
		}
	}
}
