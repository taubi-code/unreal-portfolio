#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DamageZone.generated.h"

class UBoxComponent;

UCLASS()
class LEVEL01_API ADamageZone : public AActor
{
    GENERATED_BODY()

public:
    ADamageZone();

protected:
    virtual void BeginPlay() override;

    UPROPERTY(VisibleAnywhere, Category = "Components")
    UBoxComponent* BoxCollider;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Damage")
    float DamagePerSecond = 20.f;

    UPROPERTY(EditAnywhere, Category = "Damage")
    float DamageTickInterval = 0.5f;

    FTimerHandle DamageTimerHandle;
    TWeakObjectPtr<class ALevel01Character> PlayerInZone;

    UFUNCTION()
    void OnBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
                        UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
                        bool bFromSweep, const FHitResult& SweepResult);

    UFUNCTION()
    void OnEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
                      UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

    void ApplyDamageTick();
};
