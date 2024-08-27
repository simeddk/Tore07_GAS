#include "CAction.h"
#include "Components/CActionComponent.h"

bool UCAction::CanStart_Implementation(AActor* Instigator)
{
	if (IsRunning())
	{
		return false;
	}

	UCActionComponent* ActionComp = GetOwingComponent();

	if (ActionComp->ActiveGameplayTags.HasAny(BlockedTags))
	{
		return false;
	}

	return true;
}

void UCAction::StartAction_Implementation(AActor* Instigator)
{
	UE_LOG(LogTemp, Log, TEXT("Running : %s"), *GetNameSafe(this));

	UCActionComponent* ActionComp = GetOwingComponent();
	ActionComp->ActiveGameplayTags.AppendTags(GrantTags);
	
	bIsRunning = true;
}

void UCAction::StopAction_Implementation(AActor* Instigator)
{
	UE_LOG(LogTemp, Log, TEXT("Stopped : %s"), *GetNameSafe(this));

	UCActionComponent* ActionComp = GetOwingComponent();
	ActionComp->ActiveGameplayTags.RemoveTags(GrantTags);

	bIsRunning = false;
}

UWorld* UCAction::GetWorld() const
{
	UCActionComponent* ActionCopmp = Cast<UCActionComponent>(GetOuter());
	if (ActionCopmp)
	{
		return ActionCopmp->GetWorld();
	}

	return nullptr;
}

UCActionComponent* UCAction::GetOwingComponent() const
{
	return Cast<UCActionComponent>(GetOuter());
}

bool UCAction::IsRunning() const
{
	return bIsRunning;
}