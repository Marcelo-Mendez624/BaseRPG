// Fill out your copyright notice in the Description page of Project Settings.


#include "Actions/RPGBaseActionEffect.h"

#include "Components/RPGActionsComponent.h"

URPGBaseActionEffect::URPGBaseActionEffect()
{
	bAutoStart = true;
}

void URPGBaseActionEffect::StartAction_Implementation(AActor* Instigator)
{
	Super::StartAction_Implementation(Instigator);

	if(Duration > 0.0f)
	{
		FTimerDelegate Delegate;
		Delegate.BindUFunction(this, "StopAction", Instigator);

		GetWorld()->GetTimerManager().SetTimer(DurationHandle, Delegate, Duration, false);
	}
	
	if(Period > 0.0f)
	{
		FTimerDelegate Delegate;
		Delegate.BindUFunction(this, "ExecutePeriodicEffect", Instigator);

		GetWorld()->GetTimerManager().SetTimer(PeriodHandle, Delegate, Period, true);
	}
}

void URPGBaseActionEffect::StopAction_Implementation()
{
	// if(GetWorld()->GetTimerManager().GetTimerRemaining(DurationHandle) > KINDA_SMALL_NUMBER)
	// 	ExecutePeriodicEffect();
	
	Super::StopAction_Implementation();

	GetWorld()->GetTimerManager().ClearTimer(PeriodHandle);
	GetWorld()->GetTimerManager().ClearTimer(DurationHandle);

	GetOwningComponent()->RemoveAction(this);
}

void URPGBaseActionEffect::ExecutePeriodicEffect_Implementation(AActor* Instigator)
{
}

float URPGBaseActionEffect::GetTimeRemaining() const
{
	return GetWorld()->GetTimerManager().GetTimerRemaining(DurationHandle);
}