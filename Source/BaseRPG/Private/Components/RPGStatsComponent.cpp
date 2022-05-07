// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/RPGStatsComponent.h"

// Sets default values for this component's properties
URPGStatsComponent::URPGStatsComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	MaxHealth = 100;
}

// Called when the game starts
void URPGStatsComponent::BeginPlay()
{
	Super::BeginPlay();
	
	CurrentHealth = MaxHealth;
}

void URPGStatsComponent::ApplyHealthChange(float Delta, AActor* Instigator)
{
	const float OldHealth = CurrentHealth;
	
	const float NewHealth = FMath::Clamp(CurrentHealth + Delta, 0.0f, MaxHealth);

	// Calculate the real damage the component takes 
	const float ActualDelta = NewHealth - OldHealth;
	
	CurrentHealth += ActualDelta;
	
	OnHealthChange.Broadcast(Instigator, this, Delta, ActualDelta);
	
}





