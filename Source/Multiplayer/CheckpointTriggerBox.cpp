// Fill out your copyright notice in the Description page of Project Settings.


#include "CheckpointTriggerBox.h"


ACheckpointTriggerBox::ACheckpointTriggerBox()
{
	checkpoint = CreateDefaultSubobject<UBoxComponent>(TEXT("Checkpoint"));
	checkpoint->SetBoxExtent(FVector(32.0f, 32.0f, 32.0f));
	checkpoint->SetCollisionProfileName("Trigger");
	RootComponent = checkpoint;

	checkpoint->OnComponentBeginOverlap.AddDynamic(this, &ACheckpointTriggerBox::BeginOverlap);
}

void ACheckpointTriggerBox::BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if(APlayerCharacter* player = Cast<APlayerCharacter>(OtherActor))
	{
		UE_LOG(LogTemp, Warning, TEXT("Trigger box Checkpoint"));
		player->SetCheckpoint(this->GetActorLocation());
	}
}
