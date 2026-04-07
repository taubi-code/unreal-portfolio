#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Level01GameMode.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTimerUpdated, float, RemainingTime);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnLevelEnd);

UCLASS()
class LEVEL01_API ALevel01GameMode : public AGameModeBase
{
    GENERATED_BODY()

public:
    ALevel01GameMode();

    virtual void BeginPlay() override;

    void CheckVictoryCondition();
    void OnPlayerDied();

    UPROPERTY(EditAnywhere, Category = "Level01")
    float LevelDuration = 180.f;

    UPROPERTY(EditAnywhere, Category = "Level01")
    int32 CollectiblesRequired = 8;

    UPROPERTY(EditAnywhere, Category = "Level01")
    FName WinMap = TEXT("Level02");

    UPROPERTY(EditAnywhere, Category = "Level01")
    FName LoseMap = TEXT("Level01");

    UPROPERTY(BlueprintAssignable, Category = "Level01|Events")
    FOnTimerUpdated OnTimerUpdated;

    UPROPERTY(BlueprintAssignable, Category = "Level01|Events")
    FOnLevelEnd OnVictory;

    UPROPERTY(BlueprintAssignable, Category = "Level01|Events")
    FOnLevelEnd OnDefeat;

    UFUNCTION(BlueprintPure, Category = "Level01")
    float GetRemainingTime() const { return RemainingTime; }

private:
    FTimerHandle CountdownTimerHandle;
    float RemainingTime = 0.f;
    bool bLevelEnded = false;

    void TickCountdown();
    void TriggerVictory();
    void TriggerDefeat();
};
