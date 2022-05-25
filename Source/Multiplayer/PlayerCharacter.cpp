// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"


APlayerCharacter::APlayerCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
}

void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	checkpoint = this->GetActorLocation();
	
	AMultiplayerGameModeBase* gameMode = Cast<AMultiplayerGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
	
	if(gameMode != nullptr)
	{
		gameMode->PlayerJoined();
	}
}

void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	FHitResult outHit;

	GetCharacterMovement()->SafeMoveUpdatedComponent(FVector(0.0f, 0.0f, 0.01f), GetActorRotation(), true, outHit);
	GetCharacterMovement()->SafeMoveUpdatedComponent(FVector(0.0f, 0.0f, -0.01f), GetActorRotation(), true, outHit);
		
	if(this->GetActorLocation().Z < -150.0f)
	{
		UE_LOG(LogTemp, Warning, TEXT("Player position should be set to checkpoint position"));
		this->SetActorLocation(checkpoint);
	}
}

void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &APlayerCharacter::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &APlayerCharacter::MoveRight);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &APlayerCharacter::LookUp);
	PlayerInputComponent->BindAxis(TEXT("Turn"), this, &APlayerCharacter::Turn);
	PlayerInputComponent->BindAction(TEXT("Jump"), IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction(TEXT("Dive"), IE_Pressed, this, &APlayerCharacter::Dive);
}

void APlayerCharacter::MoveForward(float amount)
{
	AddMovementInput(GetActorForwardVector() * amount);
}

void APlayerCharacter::MoveRight(float amount)
{
	AddMovementInput(GetActorRightVector() * amount);
}

void APlayerCharacter::LookUp(float amount)
{
	AddControllerPitchInput(amount);
}

void APlayerCharacter::Turn(float amount)
{
	AddControllerYawInput(amount);
}


void APlayerCharacter::Dive()
{
	ServerDive();
}

void APlayerCharacter::ServerDive_Implementation()
{
	UE_LOG(LogTemp, Warning, TEXT("Dive"));
	LaunchCharacter(GetActorForwardVector() * mDivePower, false, false);
}

void APlayerCharacter::SetCheckpoint(FVector _checkPoint)
{
	checkpoint = _checkPoint;
}
