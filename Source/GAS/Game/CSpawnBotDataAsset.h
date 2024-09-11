// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "CSpawnBotDataAsset.generated.h"

class UCAction;

UCLASS()
class GAS_API UCSpawnBotDataAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UCSpawnBotDataAsset();

public:
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Spawn")
	TSubclassOf<AActor> BotClass;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Spawn")
	TArray<TSubclassOf<UCAction>> ACtions;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Spawn")
	FLinearColor BotColor;
	
};
