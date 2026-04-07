#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Level01Character.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnStatsChanged);

UCLASS()
class LEVEL01_API ALevel01Character : public ACharacter
{
    GENERATED_BODY()

public:
    ALevel01Character();

    virtual void BeginPlay() override;
    virtual void Tick(float DeltaTime) override;
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

    // ─── Mouvement ───────────────────────────────────────────────────────────

    UFUNCTION(BlueprintCallable, Category = "Movement")
    void MoveForward(float Value);

    UFUNCTION(BlueprintCallable, Category = "Movement")
    void MoveRight(float Value);

    UFUNCTION(BlueprintCallable, Category = "Movement")
    void StartSprint();

    UFUNCTION(BlueprintCallable, Category = "Movement")
    void StopSprint();

    // ─── Vie ─────────────────────────────────────────────────────────────────

    UFUNCTION(BlueprintCallable, Category = "Health")
    void TakeDamageAmount(float Amount);

    UFUNCTION(BlueprintPure, Category = "Health")
    float GetHealthPercent() const { return MaxHealth > 0.f ? CurrentHealth / MaxHealth : 0.f; }

    UFUNCTION(BlueprintPure, Category = "Health")
    bool IsAlive() const { return CurrentHealth > 0.f; }

    // ─── Score ───────────────────────────────────────────────────────────────

    UFUNCTION(BlueprintCallable, Category = "Score")
    void AddScore(int32 Amount);

    UFUNCTION(BlueprintPure, Category = "Score")
    int32 GetScore() const { return Score; }

    // ─── Stamina ─────────────────────────────────────────────────────────────

    UFUNCTION(BlueprintPure, Category = "Stamina")
    float GetStaminaPercent() const { return MaxStamina > 0.f ? CurrentStamina / MaxStamina : 0.f; }

    // ─── Événement HUD ───────────────────────────────────────────────────────

    UPROPERTY(BlueprintAssignable, Category = "Events")
    FOnStatsChanged OnStatsChanged;

protected:
    // Vie
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Health")
    float MaxHealth = 100.f;

    UPROPERTY(BlueprintReadOnly, Category = "Health")
    float CurrentHealth = 100.f;

    // Stamina
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stamina")
    float MaxStamina = 100.f;

    UPROPERTY(BlueprintReadOnly, Category = "Stamina")
    float CurrentStamina = 100.f;

    UPROPERTY(EditAnywhere, Category = "Stamina")
    float StaminaDrainRate = 20.f;

    UPROPERTY(EditAnywhere, Category = "Stamina")
    float StaminaRegenRate = 10.f;

    // Vitesses
    UPROPERTY(EditAnywhere, Category = "Movement")
    float WalkSpeed = 400.f;

    UPROPERTY(EditAnywhere, Category = "Movement")
    float SprintSpeed = 700.f;

private:
    bool bIsSprinting = false;
    int32 Score = 0;

    void UpdateStamina(float DeltaTime);
    void Die();
};
