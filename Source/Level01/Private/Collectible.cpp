#include "Collectible.h"
#include "Level01Character.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/AudioComponent.h"
#include "Kismet/GameplayStatics.h"

ACollectible::ACollectible()
{
    PrimaryActorTick.bCanEverTick = true;

    SphereCollider = CreateDefaultSubobject<USphereComponent>(TEXT("SphereCollider"));
    SphereCollider->SetSphereRadius(60.f);
    SphereCollider->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
    RootComponent = SphereCollider;

    Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
    Mesh->SetupAttachment(RootComponent);
    Mesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);

    AudioComponent = CreateDefaultSubobject<UAudioComponent>(TEXT("AudioComponent"));
    AudioComponent->SetupAttachment(RootComponent);
    AudioComponent->bAutoActivate = false;
}

void ACollectible::BeginPlay()
{
    Super::BeginPlay();
    SphereCollider->OnComponentBeginOverlap.AddDynamic(this, &ACollectible::OnBeginOverlap);
}

void ACollectible::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    AddActorLocalRotation(FRotator(0.f, RotationSpeed * DeltaTime, 0.f));
}

void ACollectible::OnBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
                                   UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
                                   bool bFromSweep, const FHitResult& SweepResult)
{
    ALevel01Character* Player = Cast<ALevel01Character>(OtherActor);
    if (!Player) return;

    Player->AddScore(ScoreValue);

    if (PickupSound)
        UGameplayStatics::PlaySoundAtLocation(this, PickupSound, GetActorLocation());
    else if (AudioComponent)
        AudioComponent->Play();

    Destroy();
}
