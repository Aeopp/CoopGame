// Fill out your copyright notice in the Description page of Project Settings.

#include "Public/SWeapon.h"
#include "Engine/World.h"
#include "DrawDebugHelpers.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ASWeapon::ASWeapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MeshComp = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("MeshComp"));
	RootComponent = MeshComp;
}

// Called when the game starts or when spawned
void ASWeapon::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ASWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ASWeapon::Fire()
{
	AActor* MyOwner = GetOwner();
	if (MyOwner)
	{
		FVector EyeLocation;
		FRotator EyeRotation;
		MyOwner->GetActorEyesViewPoint(EyeLocation ,EyeRotation);
		
		FVector ShotDirection = EyeRotation.Vector(); 
		FVector TraceEnd = EyeLocation + (ShotDirection * 10000);
		
		FCollisionQueryParams QueryParams;
		QueryParams.AddIgnoredActor(this);
		QueryParams.AddIgnoredActor(MyOwner);
		QueryParams.bTraceComplex = true;
		
		FHitResult Hit;
		  if (    GetWorld()->LineTraceSingleByChannel(Hit, EyeLocation, TraceEnd, 
			  ECC_Visibility, QueryParams ) )
		  {
			// Blocking hit ! Process Damage

			  AActor* HitActor = Hit.GetActor(); 
			  UGameplayStatics::ApplyPointDamage(HitActor, 20.f,ShotDirection,Hit,
				  MyOwner->GetInstigatorController(),this,DamageType); 
		  };

		  DrawDebugLine(GetWorld(), EyeLocation, TraceEnd, FColor::White, false
			, 1.0f, 0, 1.0f);
	};
}

