#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Collectible.generated.h"

class USphereComponent;
class UStaticMeshComponent;
class UAudioComponent;

UCLASS()
class LEVEL01_API ACollectible : public AActor
{
    GENERATED_BODY()

public:
    ACollectible();

    virtual void Tick(float DeltaTime) override;

protected:
    virtual void BeginPlay() override;

    UPROPERTY(VisibleAnywhere, Category = "Components")
    USphereComponent* SphereCollider;

    UPROPERTY(VisibleAnywhere, Category = "Components")
    UStaticMeshComponent* Mesh;

    UPROPERTY(VisibleAnywhere, Category = "Components")
    UAudioComponent* AudioComponent;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Collectible")
    int32 ScoreValue = 10;

    UPROPERTY(EditAnywhere, Category = "Collectible")
    USoundBase* PickupSound;

    UPROPERTY(EditAnywhere, Category = "Collectible")
    float RotationSpeed = 90.f;

    UFUNCTION()
    void OnBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
                        UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
                        bool bFromSweep, const FHitResult& SweepResult);
};
