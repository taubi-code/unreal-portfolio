#include "Level01GameMode.h"
#include "Level01Character.h"
#include "Kismet/GameplayStatics.h"

ALevel01GameMode::ALevel01GameMode()
{
    DefaultPawnClass = ALevel01Character::StaticClass();
}

void ALevel01GameMode::BeginPlay()
{
    Super::BeginPlay();
    RemainingTime = LevelDuration;
    GetWorldTimerManager().SetTimer(CountdownTimerHandle, this, &ALevel01GameMode::TickCountdown,
                                    1.f, true, 1.f);
}

void ALevel01GameMode::TickCountdown()
{
    if (bLevelEnded) return;
    RemainingTime = FMath::Max(0.f, RemainingTime - 1.f);
    OnTimerUpdated.Broadcast(RemainingTime);
    if (RemainingTime <= 0.f) TriggerDefeat();
}

void ALevel01GameMode::CheckVictoryCondition()
{
    if (bLevelEnded) return;
    APlayerController* PC = UGameplayStatics::GetPlayerController(this, 0);
    if (!PC) return;
    ALevel01Character* Player = Cast<ALevel01Character>(PC->GetPawn());
    if (Player && Player->GetScore() >= CollectiblesRequired * 10)
        TriggerVictory();
}

void ALevel01GameMode::OnPlayerDied()
{
    TriggerDefeat();
}

void ALevel01GameMode::TriggerVictory()
{
    if (bLevelEnded) return;
    bLevelEnded = true;
    GetWorldTimerManager().ClearTimer(CountdownTimerHandle);
    OnVictory.Broadcast();
    FTimerHandle Delay;
    GetWorldTimerManager().SetTimer(Delay, [this]() { UGameplayStatics::OpenLevel(this, WinMap); }, 2.f, false);
}

void ALevel01GameMode::TriggerDefeat()
{
    if (bLevelEnded) return;
    bLevelEnded = true;
    GetWorldTimerManager().ClearTimer(CountdownTimerHandle);
    OnDefeat.Broadcast();
    FTimerHandle Delay;
    GetWorldTimerManager().SetTimer(Delay, [this]() { UGameplayStatics::OpenLevel(this, LoseMap); }, 2.f, false);
}
