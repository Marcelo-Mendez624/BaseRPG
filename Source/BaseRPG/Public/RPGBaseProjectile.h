// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RPGBaseProjectile.generated.h"

class UProjectileMovementComponent;
class UParticleSystemComponent;
class USphereComponent;
class URPGBaseAction;

UCLASS()
class BASERPG_API ARPGBaseProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARPGBaseProjectile();

protected:
	virtual void BeginPlay() override;
	
protected:
	UPROPERTY(EditDefaultsOnly, Category = "Defaults")
	UStaticMeshComponent* Mesh;

	UPROPERTY(EditDefaultsOnly, Category = "Defaults", BlueprintReadOnly)
	USphereComponent* SphereComponent;
	
	UPROPERTY(EditDefaultsOnly, Category = "Defaults")
	UParticleSystemComponent* ParticleSystemComponent;
	
	UPROPERTY(EditDefaultsOnly, Category = "Defaults")
	UProjectileMovementComponent* ProjectileComponent;

	UPROPERTY(EditDefaultsOnly, Category = "Defaults")
	float Damage;

	UPROPERTY(EditDefaultsOnly, Category = "Defaults")
	TSubclassOf<URPGBaseAction>ActionToAdd;

public:
	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	

};
