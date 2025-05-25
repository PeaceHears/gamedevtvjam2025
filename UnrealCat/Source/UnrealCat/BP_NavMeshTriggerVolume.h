// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NavMesh/NavMeshBoundsVolume.h"
#include "BP_NavMeshTriggerVolume.generated.h"

/**
 *
 */
UCLASS(Blueprintable)
class UNREALCAT_API ABP_NavMeshTriggerVolume : public ANavMeshBoundsVolume
{
	GENERATED_BODY()

public:
	ABP_NavMeshTriggerVolume();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Collision")
	class UBoxComponent* PhaseTwoCollider;

protected:
	virtual void BeginPlay() override;

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};