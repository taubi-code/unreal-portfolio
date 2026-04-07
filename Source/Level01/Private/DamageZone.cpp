#include "DamageZone.h"
#include "Level01Character.h"
#include "Components/BoxComponent.h"

ADamageZone::ADamageZone()
{
    PrimaryActorTick.bCanEverTick = false;

    BoxCollider = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollider"));
    BoxCollider->SetBoxExtent(FVector(200.f, 200.f, 50.f));
    BoxCollider->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
    RootComponent = BoxCollider;
}

void ADamageZone::BeginPlay()
{
    Super::BeginPlay();
    BoxCollider->OnComponentBeginOverlap.AddDynamic(this, &ADamageZone::OnBeginOverlap);
    BoxCollider->OnComponentEndOverlap.AddDynamic(this, &ADamageZone::OnEndOverlap);
}

void ADamageZone::OnBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
                                  UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
                                  bool bFromSweep, const FHitResult& SweepResult)
{
    ALevel01Character* Player = Cast<ALevel01Character>(OtherActor);
    if (!Player) return;

    PlayerInZone = Player;
    GetWorldTimerManager().SetTimer(DamageTimerHandle, this, &ADamageZone::ApplyDamageTick,
                                    DamageTickInterval, true, 0.f);
}

void ADamageZone::OnEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
                                UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
    if (Cast<ALevel01Character>(OtherActor))
    {
        GetWorldTimerManager().ClearTimer(DamageTimerHandle);
        PlayerInZone.Reset();
    }
}

void ADamageZone::ApplyDamageTick()
{
    if (!PlayerInZone.IsValid()) return;
    PlayerInZone->TakeDamageAmount(DamagePerSecond * DamageTickInterval);
}
