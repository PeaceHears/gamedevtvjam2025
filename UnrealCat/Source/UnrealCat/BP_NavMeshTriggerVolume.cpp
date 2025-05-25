#include "BP_NavMeshTriggerVolume.h"
#include "Components/BoxComponent.h"
#include "Engine/Engine.h"

ABP_NavMeshTriggerVolume::ABP_NavMeshTriggerVolume()
{
	// Create and attach a collision box
	PhaseTwoCollider = CreateDefaultSubobject<UBoxComponent>(TEXT("PhaseTwoCollider"));
	PhaseTwoCollider->SetupAttachment(GetRootComponent());

	// Configure collision
	PhaseTwoCollider->SetGenerateOverlapEvents(true);
	PhaseTwoCollider->SetCollisionProfileName("OverlapAllDynamic");
	PhaseTwoCollider->ComponentTags.Add("PhaseTwoBox");
}

void ABP_NavMeshTriggerVolume::BeginPlay()
{
	Super::BeginPlay();

	// Bind overlap event
	if (PhaseTwoCollider)
	{
		PhaseTwoCollider->OnComponentBeginOverlap.AddDynamic(this, &ABP_NavMeshTriggerVolume::OnOverlapBegin);
	}
}

void ABP_NavMeshTriggerVolume::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && OtherActor->ActorHasTag("Spaceship"))
	{
		UE_LOG(LogTemp, Warning, TEXT("Collided"));
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Collided"));

		// Disable future overlaps
		PhaseTwoCollider->SetGenerateOverlapEvents(false);
	}
}