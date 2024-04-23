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
	ColliderComponent->SetGenerateOverlapEvents(true);
	ColliderComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	ColliderComponent->SetCollisionResponseToAllChannels(ECR_Ignore);
	ColliderComponent->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);

	// Define what happens when the coin overlaps with something
	ColliderComponent->OnComponentBeginOverlap.AddDynamic(
		this, &APickupActor::OnBeginOverlapComponentEvent
	);

	// Allows the pickup to have a mesh component
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("MeshComponent");
	MeshComponent->SetupAttachment(ColliderComponent);
	MeshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	MeshComponent->SetCollisionResponseToAllChannels(ECR_Ignore);
	MeshComponent->SetGenerateOverlapEvents(false);

	// Rotates the pickup
	RotatingMovementComponent = CreateDefaultSubobject<URotatingMovementComponent>("RotatingMovementComponent");
}

void APickupActor::OnBeginOverlapComponentEvent(
	UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult
)
{
	// Ensure the overlapping item is the player
	if (!Cast<ACharacter>(OtherActor))
	{
		return;
	}

	// Print a message notifying user of collection
	if (GEngine && !PickupMessage.IsEmpty())
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::White, PickupMessage);
	}
	else if (PickupMessage.IsEmpty())
	{
		UE_LOG(LogTemp, Warning, TEXT("PickupMessage is empty, change it in the inspector."));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("GEngine isn't valid, import it to see debug messages."));
	}

	// Destroy the pickup after collection
	Destroy();
}