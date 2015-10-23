// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "PolCharacter.generated.h"

UCLASS()
class POL_API APolCharacter : public ACharacter
{
	GENERATED_UCLASS_BODY()

public:

	UPROPERTY(Category = "Character Movement: Jumping / Falling", EditAnywhere, BlueprintReadWrite, meta = (DisplayName = "Jump Reset Timer", ClampMin = "0", UIMin = "0"))
	float JumpResetTimer;

	UPROPERTY(Category = "Character Movement: Jumping / Falling", EditAnywhere, BlueprintReadWrite, meta = (DisplayName = "Slide Velocity", ClampMin = "0", UIMin = "0"))
	float SlideVelocity;

	UFUNCTION(BlueprintCallable, Category = "Slide")
	void SlideDash_Implementation();

	virtual void Landed(const FHitResult& Hit) override;
	virtual void OnJumped_Implementation();

private:

	FTimerHandle JumpTimerHandle;

	void ResetJumpState();
};
