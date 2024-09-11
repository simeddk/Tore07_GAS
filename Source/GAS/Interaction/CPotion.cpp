#include "CPotion.h"
#include "Components/StaticMeshComponent.h"
#include "Components/CAttributeComponent.h"
#include "Game/CPlayerState.h"

ACPotion::ACPotion()
{
	CreditCost = 50;
}

void ACPotion::Interact_Implementation(APawn* InstigatorPawn)
{
	if (!ensure(InstigatorPawn))
	{
		return;
	}

	UCAttributeComponent* AttributeComp = UCAttributeComponent::GetAttributes(InstigatorPawn);
	if (ensure(AttributeComp) && !AttributeComp->IsFullHealth())
	{
		ACPlayerState* PS = InstigatorPawn->GetPlayerState<ACPlayerState>();
		if (PS->RemoveCredits(CreditCost) && AttributeComp->ApplyHealthChange(this, AttributeComp->GetMaxHealth()))
		{
			HideAndCooldown();
		}
	}

}

#define LOCTEXT_NAMESPACE "InteractionMessage"

FText ACPotion::GetInteractText_Implementation(APawn* InstigatorPawn)
{
	UCAttributeComponent* AttributeComp = UCAttributeComponent::GetAttributes(InstigatorPawn);
	if (AttributeComp && AttributeComp->IsFullHealth())
	{
		//return LOCTEXT("Potion_FullHealthWarning", "Health is already full");
		return WarningMessage;
	}

	//return FText::Format(LOCTEXT("Potion_InteractionMessage", "Cost {0} Credits to Restore health"), CreditCost);
	return InteractionMessage;
}

#undef LOCTEXT_NAMESPACE