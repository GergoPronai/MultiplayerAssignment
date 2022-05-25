// Fill out your copyright notice in the Description page of Project Settings.


#include "Checkpoint.h"

#include "PlayerCharacter.h"

// Sets default values
ACheckpoint::ACheckpoint()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	checkpoint = CreateDefaultSubobject<UBoxComponent>(TEXT("Checkpoint"));
	checkpoint->SetBoxExtent(FVector(32.0f, 32.0f, 32.0f));
	checkpoint->SetCollisionProfileName("Trigger");
	RootComponent = checkpoint;

	checkpoint->OnComponentBeginOverlap.AddDynamic(this, &ACheckpoint::BeginOverlap);
}

// Called when the game starts or when spawned
void ACheckpoint::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACheckpoint::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACheckpoint::BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (APlayerCharacter* player = Cast<APlayerCharacter>(OtherActor))
	{
		UE_LOG(LogTemp, Warning, TEXT("Checkpoint"));
		player->SetCheckpoint(this->GetActorLocation());
	}
}
