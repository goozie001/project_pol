// Fill out your copyright notice in the Description page of Project Settings.

#include "Pol.h"
#include "PolCharacterMovementComponent.h"
#include <assert.h>


UPolCharacterMovementComponent::UPolCharacterMovementComponent(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	currJumpState = First;
}

bool UPolCharacterMovementComponent::DoJump(bool bReplayingMoves)
{
	if (CharacterOwner && CharacterOwner->CanJump())
	{
		if (!bConstrainToPlane || FMath::Abs(PlaneConstraintNormal.Z) != 1.f)
		{
			switch (currJumpState)
			{
				case First:
					Velocity.Z = Jump1ZVelocity;
					currJumpState = Second;
					break;
				case Second:
	 				Velocity.Z = Jump2ZVelocity;
					currJumpState = Third;
					break;
				case Third: 
					if (FMath::Abs(CharacterOwner->GetVelocity().Y) >= GetMaxSpeed()*Jump3MinSpeed)
					{
						Velocity.Z = Jump3ZVelocity;
						currJumpState = First;
					}
					else
					{
						Velocity.Z = Jump1ZVelocity;
						currJumpState = Second;
					}
					break;
				default:
					assert(!"Invalid JumpState Enum Value");
					break;
			}
			SetMovementMode(MOVE_Falling);
			return true;
		}
	}
	return false;
}

void UPolCharacterMovementComponent::setCurrJumpState(JumpState state)
{
	currJumpState = state;
}









