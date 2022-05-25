// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "GameFramework/Actor.h"
#include "ASpinArm.generated.h"

UCLASS()
class MULTIPLAYER_API AASpinArm : public AActor
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Replicated)
	float rotationRate = 250.0f;

	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const;
	
public:	
	// Sets default values for this actor's properties
	AASpinArm();
	
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* mesh;
	
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
		
};
