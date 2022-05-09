// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Components/ActorComponent.h"
#include "RPGActionsComponent.generated.h"

class URPGBaseAction;
class ARPGCharacter;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BASERPG_API URPGActionsComponent : public UActorComponent
{
	GENERATED_BODY()


public:	
	// Sets default values for this component's properties
	URPGActionsComponent();

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category = "Actions")
	TArray<TSubclassOf<URPGBaseAction>> DefaultActions;

private:
	bool bSprint;

	UPROPERTY()
	ARPGCharacter* OwningPlayer;
	
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tags")
	FGameplayTagContainer ActiveGameplayTags;
	/*
	 * Add action to component
	 * @params Instigator Action instigator
	 * @params ActionClass Action class
	 */
	UFUNCTION(BlueprintCallable, Category = "Actions")
	void AddAction(AActor* Instigator, TSubclassOf<URPGBaseAction> ActionClass);
	/*
	 * Remove Action to component
	 * @ActionToRemove Action class
	 */
	UFUNCTION(BlueprintCallable, Category = "Actions")
	void RemoveAction(URPGBaseAction* ActionToRemove);

	/*
	 * Start action
	 * @params Instigator Action instigator
	 * @params ActionName Name of the action to start
	 */
	UFUNCTION(BlueprintCallable, Category = "Actions")
	bool StartActionByName(AActor* Instigator, FName ActionName);

	/*
	 * Start action
	 * @params ActionName Name of the action to stop
	 */
	UFUNCTION(BlueprintCallable, Category = "Actions")
	void StopActionByName(FName ActionName);

protected:
	UPROPERTY()
	TArray<URPGBaseAction*> Actions;

	// Getters
public:
	UFUNCTION(BlueprintPure, Category = Gets)
	ARPGCharacter* GetOwningCharacter() const { return OwningPlayer; }
		
};
