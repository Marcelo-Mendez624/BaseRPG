// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actions/RPGBaseAction.h"
#include "RPGBaseActionEffect.generated.h"

/**
 * 
 */
UCLASS()
class BASERPG_API URPGBaseActionEffect : public URPGBaseAction
{
	GENERATED_BODY()
public:
	URPGBaseActionEffect();

	virtual void StartAction_Implementation(AActor* Instigator) override;
	
	virtual void StopAction_Implementation() override;
	
protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Effects")
	float Duration;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Effects")
	float Period;

	FTimerHandle PeriodHandle;
	FTimerHandle DurationHandle;

	/*
	 * this class in its default version does not have any implementation this will e added in each of its children
	 * @params Instigator Effect instigator
	 */
	UFUNCTION(BlueprintNativeEvent, Category = "Effects")
	void ExecutePeriodicEffect(AActor* Instigator);

	// Getters
public:
	UFUNCTION(BlueprintCallable)
	float GetTimeRemaining() const; // returns the time is left to end the effect
};
