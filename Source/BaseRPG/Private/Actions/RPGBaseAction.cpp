// Fill out your copyright notice in the Description page of Project Settings.


#include "Actions/RPGBaseAction.h"
#include "Components/RPGActionsComponent.h"


bool URPGBaseAction::CanStartAction_Implementation(AActor* Instigator)
{
	if(IsRunning()) return false;

	const URPGActionsComponent* Comp = GetOwningComponent();

	if(Comp->ActiveGameplayTags.HasAny(BlockedTags))
		return false;

	return true;
}

void URPGBaseAction::StartAction_Implementation(AActor* Instigator)
{
	URPGActionsComponent* Comp = GetOwningComponent();

	Comp->ActiveGameplayTags.AppendTags(GrantsTags);
	
	bIsRunning = true;
}

void URPGBaseAction::StopAction_Implementation()
{
	ensureAlways(bIsRunning);
	
	URPGActionsComponent* Comp = GetOwningComponent();

	Comp->ActiveGameplayTags.RemoveTags(GrantsTags);
	bIsRunning = false;
}

URPGActionsComponent* URPGBaseAction::GetOwningComponent() const
{
	return Cast<URPGActionsComponent>(GetOuter());
}

bool URPGBaseAction::IsRunning() const
{
	return bIsRunning;
}