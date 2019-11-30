// Fill out your copyright notice in the Description page of Project Settings.

#include "Public/SCharacter.h"



// Sets default values
ASCharacter::ASCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	AutoPossessPlayer = EAutoReceiveInput::Player0; 
}

// Called when the game starts or when spawned
void ASCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("MoveForward",this,
	&ASCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this,
	&ASCharacter::MoveRight);
	PlayerInputComponent->BindAxis("LookUp", this,
	&ASCharacter::LookUp);
	PlayerInputComponent->BindAxis("TurnAround", this,
	&ASCharacter::TurnAround);
}

void ASCharacter::MoveForward(float Value)
{
	if(! FMath::IsNearlyZero(Value ))
	AddMovementInput(GetActorForwardVector()*Value,1.f);
}

void ASCharacter::MoveRight(float Value)
{
	if (!FMath::IsNearlyZero(Value))
	AddMovementInput(GetActorRightVector()*Value,1.f);
}

void ASCharacter::LookUp(float Value)
{
	if (!FMath::IsNearlyZero(Value))
		AddControllerPitchInput(Value);
}

void ASCharacter::TurnAround(float Value)
{
	if(! FMath::IsNearlyZero(     Value   ))   
	AddControllerYawInput(Value);
}

