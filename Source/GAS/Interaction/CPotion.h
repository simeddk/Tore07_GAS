#pragma once

#include "CoreMinimal.h"
#include "Interaction/CPickupBase.h"
#include "CPotion.generated.h"

UCLASS()
class GAS_API ACPotion : public ACPickupBase
{
	GENERATED_BODY()

public:
	ACPotion();
	
public:
	void Interact_Implementation(APawn* InstigatorPawn) override;

protected:
	UPROPERTY(EditAnywhere, Category = "Credits")
	int32 CreditCost;
};
