// Fill out your copyright notice in the Description page of Project Settings.


#include "ASpinArm.h"
#include "Net/UnrealNetwork.h"
#include "PlayerCharacter.h"

// Sets default values
AASpinArm::AASpinArm()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	SetRootComponent(mesh);	
	
	bReplicates = true;
}

// Called when the game starts or when spawned
void AASpinArm::BeginPlay()
{
	Super::BeginPlay();
	mesh->SetNotifyRigidBodyCollision(true);
	
	if (HasAuthority())
	{
		NetUpdateFrequency = 5;
		SetReplicates(true);
		SetReplicateMovement(true);
	}
}

// Called every frame
void AASpinArm::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AddActorLocalRotation(FRotator(0.0f, rotationRate * DeltaTime, 0.0f));
}

void AASpinArm::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AASpinArm, rotationRate);
}
