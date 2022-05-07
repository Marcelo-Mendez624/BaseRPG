// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "RPGCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;
class URPGStatsComponent;

UCLASS()
class BASERPG_API ARPGCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ARPGCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Functions
protected:
	void MoveForward(float Value);
	void MoveRight(float Value);
	void Turn(float Value);
	void LookUp(float Value);

	void Sprint();
	void StopSprint();
	
	void Attack();

	
	// Components
protected:
	UPROPERTY(VisibleAnywhere, Category = "Camera")
	USpringArmComponent* Arm;
	
	UPROPERTY(VisibleAnywhere, Category = "Camera")
	UCameraComponent* Camera;

	// UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	// UCharacterActionsComponent* ActionsComponent;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	URPGStatsComponent* StatsComponent;

public:
	URPGStatsComponent* GetStatsComponent() const { return  StatsComponent; }
	
	
};
