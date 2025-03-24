
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Interfaces/HitInterface.h"
#include "Enemy.generated.h"
#include "Characters/CharacterTypes.h"
class UAttributeComponent;
class UAnimMontage;
class UHealthBarComponent;
UCLASS()
class SLASH_API AEnemy : public ACharacter, public IHitInterface
{
	GENERATED_BODY()

public:
	AEnemy();
	
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void GetHit_Implementation(const FVector& ImpactPoint) override;

	virtual float TakeDamage(float DamageAmout, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AACtor* DamageCauser) override;
	


private:
	UPROPERTY(EditDefaultsOnly, Categtory = Montages)
	UAnimMontage* HitReactMontage;

	UPROPERTY(EditAnywhere, Categtory = Sounds)
	USoundBase* HitSound;

	UPROPERTY(EditAnywhere, Categtory = VisualEffects)
	UParticleSystem* HitParticles;
	
	UPROPERTY(VisibleAnywhere)
	UAttributeComponent* Attributes;

	UPROPERTY(VisibleAnywhere)
	UHealthBarComponent* HealthBarWidget;

	UPROPERTY(EditAnywhere, Categtory = Montages)
	UanimMontage* DeathMontage;
	

protected:
	virtual void BeginPlay() override;

	void PlayHitReactMontage(const FName& SectionName);
	void DirectionalHitReact(const FVector& ImpactPoint);

 	void Die();
public:	

	
};