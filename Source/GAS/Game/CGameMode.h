#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "EnvironmentQuery/EnvQueryTypes.h"
#include "Engine/DataTable.h"
#include "CGameMode.generated.h"

class UEnvQuery;
class UCSaveGame;
class UCSpawnBotDataAsset;

USTRUCT(BlueprintType)
struct FSpawnBotRow : public FTableRowBase
{
	GENERATED_BODY()

public:
	FSpawnBotRow()
	{
		Weight = 1.f;
		Cost = 5.f;
		KillReward = 20.f;
	}

public:
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	UCSpawnBotDataAsset* BotDataAsset;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	float Weight;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	float Cost;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	float KillReward;
};

UCLASS()
class GAS_API ACGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	ACGameMode();

protected:
	virtual void InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage) override;
	virtual void StartPlay() override;
	void HandleStartingNewPlayer_Implementation(APlayerController* NewPlayer) override;

	//Kill
public:
	UFUNCTION(Exec)
	void KillAll();

	virtual void OnActorKilled(AActor* VictimActor, AActor* Killer);

	UFUNCTION()
	void RespawnPlayerElapsed(AController* Controller);

protected:
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Credits")
	int32 CreditsPerKill;

	//Spawn Bots
protected:
	FTimerHandle TimerHandle_SpawnBots;

	UPROPERTY(EditDefaultsOnly, Category = "AI")
	float SpawnTimerDelay;

	UFUNCTION()
	void SpawnBotTimerElapsed();

	UPROPERTY(EditDefaultsOnly, Category = "AI")
	UEnvQuery* SpawnBotQuery;

	UFUNCTION()
	void OnSpawnBotQueryFinished(UEnvQueryInstanceBlueprintWrapper* QueryInstance, EEnvQueryStatus::Type QueryStatus);

	UPROPERTY(EditDefaultsOnly, Category = "AI")
	UCurveFloat* SpawnCurve;

	UPROPERTY(EditDefaultsOnly, Category = "AI")
	UDataTable* SpawnBotDataTable;

	//Spawn Pickup
protected:
	UPROPERTY(EditDefaultsOnly, Category = "Pickup")
	UEnvQuery* SpawnPickupQuery;

	UPROPERTY(EditDefaultsOnly, Category = "Pickup")
	TArray<TSubclassOf<AActor>> PickupClassess;

	UPROPERTY(EditDefaultsOnly, Category = "Pickup")
	float MinimumPickupDistance;

	UPROPERTY(EditDefaultsOnly, Category = "Pickup")
	int32 MaxPickupCount;

	UFUNCTION()
	void OnSpawnPickupQueryFinished(UEnvQueryInstanceBlueprintWrapper* QueryInstance, EEnvQueryStatus::Type QueryStatus);

	//SaveGame
protected:
	UPROPERTY()
	UCSaveGame* CurrentSaveGame;

	FString SlotName;

public:
	UFUNCTION(BlueprintCallable, Category = "SaveGame")
	void WriteSaveGame();

	void LoadSaveGame();
	
};
