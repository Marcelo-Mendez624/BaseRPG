// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseRPG/Public/RPGCharacter.h"

#include "Components/RPGActionsComponent.h"
#include "Components/RPGStatsComponent.h"

// Sets default values
ARPGCharacter::ARPGCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	ActionsComponent = CreateDefaultSubobject<URPGActionsComponent>(TEXT("Actions Component"));
	
	StatsComponent = CreateDefaultSubobject<URPGStatsComponent>(TEXT("Stas Component"));
}

// Called to bind functionality to input
void ARPGCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("Sprint", IE_Pressed, this, &ARPGCharacter::Sprint);
	PlayerInputComponent->BindAction("Sprint", IE_Released, this, &ARPGCharacter::StopSprint);

	PlayerInputComponent->BindAction("Attack", IE_Pressed, this, &ARPGCharacter::Attack);
	
	PlayerInputComponent->BindAxis("MoveForward", this, &ARPGCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ARPGCharacter::MoveRight);
	
	PlayerInputComponent->BindAxis("Turn", this, &ARPGCharacter::Turn);
	PlayerInputComponent->BindAxis("LookUp", this, &ARPGCharacter::LookUp);

}

void ARPGCharacter::MoveForward(float Value)
{
	
}

void ARPGCharacter::MoveRight(float Value)
{
}

void ARPGCharacter::Turn(float Value)
{
}

void ARPGCharacter::LookUp(float Value)
{
}

