#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CInteractionComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GAS_API UCInteractionComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UCInteractionComponent();

protected:
	virtual void BeginPlay() override;
		
public:
	void PrimaryInteraction();
};
