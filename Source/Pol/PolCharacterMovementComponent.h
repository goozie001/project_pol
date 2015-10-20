// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/CharacterMovementComponent.h"
#include "PolCharacterMovementComponent.generated.h"

/**
 * 
 */
UCLASS()
class UPolCharacterMovementComponent : public UCharacterMovementComponent
{
	GENERATED_UCLASS_BODY()

public:

	enum JumpState
	{
		First,
		Second,
		Third
	};
	
	UPROPERTY(Category = "Character Movement: Jumping / Falling", EditAnywhere, BlueprintReadWrite, meta = (DisplayName = "Jump 1 Z Velocity", ClampMin = "0", UIMin = "0"))
	float Jump1ZVelocity;

	UPROPERTY(Category = "Character Movement: Jumping / Falling", EditAnywhere, BlueprintReadWrite, meta = (DisplayName = "Jump 2 Z Velocity", ClampMin = "0", UIMin = "0"))
	float Jump2ZVelocity;

	UPROPERTY(Category = "Character Movement: Jumping / Falling", EditAnywhere, BlueprintReadWrite, meta = (DisplayName = "Jump 3 Z Velocity", ClampMin = "0", UIMin = "0"))
	float Jump3ZVelocity;

	UPROPERTY(Category = "Character Movement: Jumping / Falling", EditAnywhere, BlueprintReadWrite, meta = (DisplayName = "Min Third Jump Y Speed", ClampMin = "0", UIMin = "0", ClampMax = "1", UIMax = "1"))
	float Jump3MinSpeed;

	virtual bool DoJump(bool bReplayingMoves) override;

	void setCurrJumpState(JumpState state);

private:

	JumpState currJumpState;
	
};
