// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SCharacter.generated.h"

UCLASS()
class COOPGAME_API ASCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere ,   BlueprintReadWrite  ,  Category =  Camera) 
	class   UCameraComponent * CameraComp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Camera)
	class USpringArmComponent* SpringArm;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent
	(class UInputComponent* PlayerInputComponent) override;
	UFUNCTION()
	void MoveForward(float Value);
	UFUNCTION()
	void MoveRight(float Value);
	UFUNCTION()
		void LookUp(float Value);
	UFUNCTION()
		void TurnAround(float Value);
	UFUNCTION()
		void BeginCrouch();
	UFUNCTION()
		void EndCrouch();

	 virtual FVector GetPawnViewLocation() const override; 
};
