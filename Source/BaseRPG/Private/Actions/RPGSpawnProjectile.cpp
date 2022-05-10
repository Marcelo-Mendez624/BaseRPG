// Fill out your copyright notice in the Description page of Project Settings.


#include "Actions/RPGSpawnProjectile.h"

#include "RPGBaseProjectile.h"
#include "RPGCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/RPGActionsComponent.h"

void URPGSpawnProjectile::StartAction_Implementation(AActor* Instigator)
{
	Super::StartAction_Implementation(Instigator);
		
	
	if(ARPGCharacter* Character = Cast<ARPGCharacter>(GetOwningComponent()->GetOwner()))
	{
		if(AnimMontage)
		{
			float Timer = Character->PlayAnimMontage(AnimMontage);
			
			FTimerHandle StopHandle;
			GetWorld()->GetTimerManager().SetTimer(StopHandle, this, &URPGSpawnProjectile::StopAction_Implementation, 1, false, Timer);
		}
		const FVector Location = Character->GetMesh()->GetSocketLocation(TEXT("weapon_rSocket"));
	
		const FRotator Rotation = Character->GetCameraComponent()->GetComponentRotation();

		FActorSpawnParameters Parameters;
	
		Parameters.Instigator = Character;
	
		GetWorld()->SpawnActor<ARPGBaseProjectile>(ProjectileClass, Location, Rotation, Parameters);
	}
}

void URPGSpawnProjectile::StopAction_Implementation()
{
	Super::StopAction_Implementation();
}