#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PickupActor.generated.h"

class UStaticMeshComponent;
class URotatingMovementComponent;
class USphereComponent;

UCLASS()
class CPTS_122_FINAL_API APickupActor : public AActor
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "Pickup")
	FString PickupMessage;

	UPROPERTY(EditAnywhere, Category = "Pickup")
	FColor MessageColor;

	UFUNCTION()
	void OnBeginOverlapComponentEvent(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void PrintCollectedMessage(FString CollectionMessage, FColor CollectionMessageColor);
	
public:	
	// Sets default values for this actor's properties
	APickupActor();

	// The message that's displayed on pickup
	UPROPERTY()
	FString collectionMessage;

protected:
	// The mesh of the pickup (how it looks in game)
	UPROPERTY(EditDefaultsOnly, Category = "Pickup")
	TObjectPtr<UStaticMeshComponent> MeshComponent;

	// Manages the rotating of the object
	UPROPERTY(EditDefaultsOnly, Category = "Pickup")
	TObjectPtr<URotatingMovementComponent> RotatingMovementComponent;

	// Manages the collision detection
	UPROPERTY(EditDefaultsOnly, Category = "Pickup")
	TObjectPtr<USphereComponent> ColliderComponent;
};