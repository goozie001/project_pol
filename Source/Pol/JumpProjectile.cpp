// Fill out your copyright notice in the Description page of Project Settings.

#include "Pol.h"
#include "JumpProjectile.h"


// Sets default values
AJumpProjectile::AJumpProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AJumpProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AJumpProjectile::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

