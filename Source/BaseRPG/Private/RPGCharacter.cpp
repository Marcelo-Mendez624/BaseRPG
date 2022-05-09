// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseRPG/Public/RPGCharacter.h"

#include "Camera/CameraComponent.h"
#include "Components/RPGActionsComponent.h"
#include "Components/RPGStatsComponent.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
ARPGCharacter::ARPGCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Arm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Arm Comp"));
	Arm->SetupAttachment(RootComponent);

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(Arm);
	
	ActionsComponent = CreateDefaultSubobject<URPGActionsComponent>(TEXT("Actions Component"));
	
	StatsComponent = CreateDefaultSubobject<URPGStatsComponent>(TEXT("Stas Component"));
}

// Called to bind functionality to input
void ARPGCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	PlayerInputComponent->BindAxis("MoveForward", this, &ARPGCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ARPGCharacter::MoveRight);
	
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);

}

void ARPGCharacter::MoveForward(float Value)
{
	if(Value != 0)
		if(ActionsComponent->StartActionByName(this, "MoveForward"))
		{
			FRotator ControlRot = GetControlRotation();
			ControlRot.Pitch = 0.0f;
			ControlRot.Roll = 0.0f;

			AddMovementInput(ControlRot.Vector(), Value);
			
			ActionsComponent->StopActionByName("MoveForward");
		}
}

void ARPGCharacter::MoveRight(float Value)
{
	if(Value != 0)
		if(ActionsComponent->StartActionByName(this, "MoveRight"))
		{
			FRotator ControlRot = GetControlRotation();
			ControlRot.Pitch = 0.0f;
			ControlRot.Roll = 0.0f;
		
			const FVector RightVector = FRotationMatrix(ControlRot).GetScaledAxis(EAxis::Y);
		
			AddMovementInput(RightVector, Value);
			ActionsComponent->StopActionByName("MoveRight");
		}
}

