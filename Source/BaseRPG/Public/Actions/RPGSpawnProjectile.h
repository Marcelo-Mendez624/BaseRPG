// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actions/RPGBaseAction.h"
#include "RPGSpawnProjectile.generated.h"

class ARPGBaseProjectile;
/**
 * 
 */
UCLASS()
class BASERPG_API URPGSpawnProjectile : public URPGBaseAction
{
	GENERATED_BODY()

	virtual void StartAction_Implementation(AActor* Instigator) override;
	virtual void StopAction_Implementation() override;

protected:
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<ARPGBaseProjectile> ProjectileClass;
	
	UPROPERTY(EditDefaultsOnly)
	UAnimMontage* AnimMontage;
	
};
