// Fill out your copyright notice in the Description page of Project Settings.


#include "RPGBaseProjectile.h"

#include "RPGCharacter.h"
#include "Actions/RPGBaseAction.h"
#include "Components/RPGActionsComponent.h"
#include "Components/RPGStatsComponent.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Particles/ParticleSystemComponent.h"

// Sets default values
ARPGBaseProjectile::ARPGBaseProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = Mesh;

	ParticleSystemComponent = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("Particle System"));
	ParticleSystemComponent->SetupAttachment(Mesh);

	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere Comp"));
	SphereComponent->SetupAttachment(Mesh);
	
	ProjectileComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Projectile Comp"));
	
}

void ARPGBaseProjectile::BeginPlay()
{
	Super::BeginPlay();
	SphereComponent->OnComponentBeginOverlap.AddDynamic(this, &ARPGBaseProjectile::OnOverlapBegin);
}

void ARPGBaseProjectile::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if(GetInstigator() != OtherActor)
	{
		if(const ARPGCharacter* Character = Cast<ARPGCharacter>(OtherActor) )
		{
			Character->GetStatsComponent()->ApplyHealthChange(Damage, GetInstigator());
			
			if(ActionToAdd)
				Character->GetActionsComponent()->AddAction(this, ActionToAdd);
		}
		Destroy();
	}
}

