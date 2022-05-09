// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameplayTagContainer.h"
#include "RPGBaseAction.generated.h"

class URPGActionsComponent;

/**
 * 
 */

UCLASS(Blueprintable)
class BASERPG_API URPGBaseAction : public UObject
{
	GENERATED_BODY()
protected:
	UFUNCTION(BlueprintCallable, Category = "Action")
	URPGActionsComponent* GetOwningComponent() const;

	/*
	 * Tags to add when the action start
	 */
	UPROPERTY(EditDefaultsOnly, Category = "Tags")
	FGameplayTagContainer GrantsTags;

	/*
	 * tags to block when action is running
	 */
	UPROPERTY(EditDefaultsOnly, Category = "Tags")
	FGameplayTagContainer BlockedTags;

	bool bIsRunning;

public:
	UPROPERTY(EditDefaultsOnly, Category = "Action")
	bool bAutoStart;

	UFUNCTION(BlueprintCallable, Category = "Action")
	bool IsRunning() const;

	/*
	 * Check if the action can start
	 * @params Instigator Action instigator
	 */
	UFUNCTION(BlueprintNativeEvent, Category = "Actions")
	bool CanStartAction(AActor* Instigator);
	
	UFUNCTION(BlueprintNativeEvent, Category = "Actions")
	void StartAction(AActor* Instigator);

	/*
	 * Stop Action
	 */
	UFUNCTION(BlueprintNativeEvent, Category = "Actions")
	void StopAction();

	UPROPERTY(EditDefaultsOnly, Category = "Actions")
	FName ActionName;

};
