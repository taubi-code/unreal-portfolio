#include "Level01Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Level01GameMode.h"
#include "Kismet/GameplayStatics.h"

ALevel01Character::ALevel01Character()
{
    PrimaryActorTick.bCanEverTick = true;
}

void ALevel01Character::BeginPlay()
{
    Super::BeginPlay();
    CurrentHealth = MaxHealth;
    CurrentStamina = MaxStamina;
    GetCharacterMovement()->MaxWalkSpeed = WalkSpeed;
}

void ALevel01Character::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    UpdateStamina(DeltaTime);
}

void ALevel01Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    PlayerInputComponent->BindAxis("MoveForward", this, &ALevel01Character::MoveForward);
    PlayerInputComponent->BindAxis("MoveRight",   this, &ALevel01Character::MoveRight);
    PlayerInputComponent->BindAction("Jump",   IE_Pressed,  this, &ACharacter::Jump);
    PlayerInputComponent->BindAction("Jump",   IE_Released, this, &ACharacter::StopJumping);
    PlayerInputComponent->BindAction("Sprint", IE_Pressed,  this, &ALevel01Character::StartSprint);
    PlayerInputComponent->BindAction("Sprint", IE_Released, this, &ALevel01Character::StopSprint);
}

// ─── Mouvement ────────────────────────────────────────────────────────────────

void ALevel01Character::MoveForward(float Value)
{
    if (Controller && Value != 0.f)
    {
        const FRotator Rotation = Controller->GetControlRotation();
        const FRotator YawRotation(0, Rotation.Yaw, 0);
        const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
        AddMovementInput(Direction, Value);
    }
}

void ALevel01Character::MoveRight(float Value)
{
    if (Controller && Value != 0.f)
    {
        const FRotator Rotation = Controller->GetControlRotation();
        const FRotator YawRotation(0, Rotation.Yaw, 0);
        const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
        AddMovementInput(Direction, Value);
    }
}

void ALevel01Character::StartSprint()
{
    if (CurrentStamina > 0.f)
    {
        bIsSprinting = true;
        GetCharacterMovement()->MaxWalkSpeed = SprintSpeed;
    }
}

void ALevel01Character::StopSprint()
{
    bIsSprinting = false;
    GetCharacterMovement()->MaxWalkSpeed = WalkSpeed;
}

void ALevel01Character::UpdateStamina(float DeltaTime)
{
    if (bIsSprinting && CurrentStamina > 0.f)
    {
        CurrentStamina = FMath::Max(0.f, CurrentStamina - StaminaDrainRate * DeltaTime);
        if (CurrentStamina == 0.f)
            StopSprint();
    }
    else if (!bIsSprinting && CurrentStamina < MaxStamina)
    {
        CurrentStamina = FMath::Min(MaxStamina, CurrentStamina + StaminaRegenRate * DeltaTime);
    }

    OnStatsChanged.Broadcast();
}

// ─── Vie ──────────────────────────────────────────────────────────────────────

void ALevel01Character::TakeDamageAmount(float Amount)
{
    if (!IsAlive()) return;

    CurrentHealth = FMath::Max(0.f, CurrentHealth - Amount);
    OnStatsChanged.Broadcast();

    if (CurrentHealth == 0.f)
        Die();
}

void ALevel01Character::Die()
{
    if (ALevel01GameMode* GM = Cast<ALevel01GameMode>(UGameplayStatics::GetGameMode(this)))
        GM->OnPlayerDied();

    APlayerController* PC = Cast<APlayerController>(GetController());
    if (PC) DisableInput(PC);
}

// ─── Score ────────────────────────────────────────────────────────────────────

void ALevel01Character::AddScore(int32 Amount)
{
    Score += Amount;
    OnStatsChanged.Broadcast();

    if (ALevel01GameMode* GM = Cast<ALevel01GameMode>(UGameplayStatics::GetGameMode(this)))
        GM->CheckVictoryCondition();
}
