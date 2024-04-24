#include "PickupActor.h"

#include "Components/SphereComponent.h"
#include "GameFramework/Character.h"
#include "GameFramework/RotatingMovementComponent.h"

// Sets default values
APickupActor::APickupActor()
{
 	// Set this actor to not call Tick() every frame.
	PrimaryActorTick.bCanEverTick = false;

	// Manages the collider for the pickup
	ColliderComponent = CreateDefaultSubobject<USphereComponent>("ColliderComponent");
	SetRootComponent(ColliderComponent);

	// Allows the generating of overlap events, like triggers
	ColliderComponent->SetGenerateOverlapEvents(true);

	// Disables physics and only collides with stuff we specify
	ColliderComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);

	// Set collisions to be ignored by everything, except for detecting overlapping on Pawns (like triggers)
	ColliderComponent->SetCollisionResponseToAllChannels(ECR_Ignore);
	ColliderComponent->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);

	// Define what happens when the coin overlaps with something
	ColliderComponent->OnComponentBeginOverlap.AddDynamic(
		this, &APickupActor::OnBeginOverlapComponentEvent
	);

	// Allows the pickup to have a mesh component
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("MeshComponent");
	MeshComponent->SetupAttachment(ColliderComponent);

	// Removes all collisions
	MeshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	// Ignores collisions by everything
	MeshComponent->SetCollisionResponseToAllChannels(ECR_Ignore);

	// Blocks the generating of overlap events, like triggers
	MeshComponent->SetGenerateOverlapEvents(false);

	// Rotates the pickup
	RotatingMovementComponent = CreateDefaultSubobject<URotatingMovementComponent>("RotatingMovementComponent");
}

void APickupActor::OnBeginOverlapComponentEvent(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// Ensure the overlapping item is the player
	if (!Cast<ACharacter>(OtherActor))
	{
		return;
	}

	// Print a message notifying user of collection
	if (GEngine && !PickupMessage.IsEmpty())
	{
		// Let player know they picked up an item
		PrintCollectedMessage(PickupMessage, MessageColor);
	}
	else
	{
		// Warn about missing libraries
		UE_LOG(LogTemp, Warning, TEXT("GEngine isn't valid, import it to see debug messages."));
	}

	// Destroy the pickup object after collection
	Destroy();
}

void APickupActor::PrintCollectedMessage(FString CollectionMessage, FColor CollectionMessageColor)
{
	// Add a debug message on the screen with out chosen message and color
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, MessageColor, CollectionMessage);
}