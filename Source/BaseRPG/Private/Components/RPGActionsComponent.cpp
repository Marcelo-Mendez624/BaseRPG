// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/RPGActionsComponent.h"

#include "RPGCharacter.h"
#include "Actions/RPGBaseAction.h"

/// Sets default values for this component's properties
URPGActionsComponent::URPGActionsComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	bSprint = false;
	// ...
}

void URPGActionsComponent::TickComponent(float DeltaTime, ELevelTick TickType,
	FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}


// Called when the game starts
void URPGActionsComponent::BeginPlay()
{
	Super::BeginPlay();
	
	OwningPlayer = Cast<ARPGCharacter>(GetOwner());;

	// add basic character actions
	for(const TSubclassOf<URPGBaseAction> ActionClass : DefaultActions)
		AddAction(OwningPlayer, ActionClass);
	
}

void URPGActionsComponent::AddAction(AActor* Instigator, TSubclassOf<URPGBaseAction> ActionClass)
{
	if(!ensure(ActionClass)) return;

	if( URPGBaseAction* NewAction = NewObject<URPGBaseAction>(this, ActionClass) )
	{
		Actions.Add(NewAction);
		if(NewAction->bAutoStart && NewAction->CanStartAction(Instigator))
			NewAction->StartAction(Instigator);
	}
}

void URPGActionsComponent::RemoveAction(URPGBaseAction* ActionToRemove)
{
	if(!ensure(ActionToRemove && !ActionToRemove->IsRunning())) return;
	
	Actions.Remove(ActionToRemove);
}

AActor* URPGActionsComponent::StartActionByName(AActor* Instigator, FName ActionName)
{
	for(URPGBaseAction* Action : Actions)
	{
		if(Action && Action->ActionName == ActionName)
		{
			if(!Action->CanStartAction(Instigator))
			{
				const FString FailedMSG = FString::Printf(TEXT("Faild to run: %s"), * ActionName.ToString());
				GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Red, FailedMSG);
				
				continue;
			}
			
			Action->StartAction(Instigator);
		}
	}
	return Instigator;
}

void URPGActionsComponent::StopActionByName( FName ActionName)
{
	for(URPGBaseAction* Action : Actions)
	{
		if(Action && Action->ActionName == ActionName)
			if(Action->IsRunning())
				Action->StopAction();
	}
}

