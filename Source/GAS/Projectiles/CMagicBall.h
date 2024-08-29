#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CProjectileBase.h"
#include "GameplayTagContainer.h"
#include "CMagicBall.generated.h"

class UCActionEffect;

UCLASS()
class GAS_API ACMagicBall : public ACProjectileBase
{
	GENERATED_BODY()
	
public:	
	ACMagicBall();

protected:
	virtual void BeginPlay() override;

protected:
	UFUNCTION()
	void OnActorOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

protected:
	UPROPERTY(EditDefaultsOnly, Category = "Damage")
	float DamageAmount;

	UPROPERTY(EditDefaultsOnly, Category = "Damage")
	FGameplayTag ReflectTag;

	UPROPERTY(EditDefaultsOnly, Category = "Damage")
	TSubclassOf<UCActionEffect> BurningActionClass;
};
