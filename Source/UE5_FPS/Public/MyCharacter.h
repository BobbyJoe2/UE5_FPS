// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MyCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;

UCLASS()
class UE5_FPS_API AMyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyCharacter();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void MoveForward(float Value);
	void MoveRight(float Value);

	void BeginCrouch();
	void EndCrouch();

	void StartJump();

	/*UPROPERTY(EditDefaultsOnly, Category = "Player")
	float ZoomedFOV;*/

	//default FOV set during begin play
	float DefaultFOV;

	UPROPERTY(EditDefaultsOnly, Category = "Player", meta = (ClampMin = 0.1, ClampMax = 100))
		float ZoomInterpSpeed;

	void BeginZoom();
	void EndZoom();

	/*UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	ASWeapon* CurrentWeapon;*/

	/*void StartFire();

	void StopFire();

	UPROPERTY(EditDefaultsOnly, Category = "Player")
	TSubclassOf<ASWeapon> StartWeaponClass;*/

	/*UPROPERTY(EditDefaultsOnly, Category = "Player")
	FName WeaponAttachSocketName;*/

	//void Reload();

	UPROPERTY(EditDefaultsOnly, Category = "Player")
		float ADSSpeedMultiplier = 0.5;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
		bool bWantsToZoom;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual FVector GetPawnViewLocation() const override;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
		UCameraComponent* CameraComp;
};
