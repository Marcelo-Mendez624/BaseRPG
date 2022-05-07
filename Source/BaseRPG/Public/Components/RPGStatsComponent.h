// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "RPGStatsComponent.generated.h"

class URPGStatsComponent;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FOnAttributeChanged, AActor*, InstigatorActor, URPGStatsComponent*, OwningComp, float, NewValue, float, Delta);


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BASERPG_API URPGStatsComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	URPGStatsComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	FVector2d Health;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stats")
	int MaxHealth;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Stats")
	float CurrentHealth;

	UPROPERTY(BlueprintAssignable, Category = "Attributes")
	FOnAttributeChanged OnHealthChange;
	
public:
	/*
 		* Apply health change and notify
 		* @params Delta Delta damage is take
 		* @params Instigator Damage instigator
 	*/
	UFUNCTION(BlueprintCallable, Category = "Attributes")
	void ApplyHealthChange(float Delta, AActor* Instigator);

	int GetMaxHealth() const { return MaxHealth; }
	int GetCurrentHealth() const { return CurrentHealth; }

		
};
