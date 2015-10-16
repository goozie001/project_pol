// Fill out your copyright notice in the Description page of Project Settings.

#include "Pol.h"
#include "PolCharacter.h"
#include "PolCharacterMovementComponent.h"


APolCharacter::APolCharacter(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer.SetDefaultSubobjectClass<UPolCharacterMovementComponent>(ACharacter::CharacterMovementComponentName))
{}

void APolCharacter::Landed(const FHitResult& Hit)
{
	GetWorldTimerManager().SetTimer(JumpTimerHandle, this, &APolCharacter::ResetJumpState, JumpResetTimer, false);
}

void APolCharacter::OnJumped_Implementation()
{
	GetWorldTimerManager().ClearTimer(JumpTimerHandle);
}

void APolCharacter::ResetJumpState()
{
	UPolCharacterMovementComponent* movementComp = Cast<UPolCharacterMovementComponent>(CharacterMovement);
	movementComp->setCurrJumpState(UPolCharacterMovementComponent::First);
}
