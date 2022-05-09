// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "RPGCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;
class URPGStatsComponent;
class URPGActionsComponent;

UCLASS()
class BASERPG_API ARPGCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ARPGCharacter();
	
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	
	// Functions
protected:
	void MoveForward(float Value);
	void MoveRight(float Value);
	
	// Components
protected:
	UPROPERTY(VisibleAnywhere, Category = "Camera")
	USpringArmComponent* Arm;
	
	UPROPERTY(VisibleAnywhere, Category = "Camera")
	UCameraComponent* Camera;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	URPGActionsComponent* ActionsComponent;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	URPGStatsComponent* StatsComponent;

	//Getters
public:
	URPGStatsComponent* GetStatsComponent() const { return  StatsComponent; }
	
	
};
