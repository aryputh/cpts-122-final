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

	UFUNCTION()
	void OnBeginOverlapComponentEvent(
		UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult
	);
	
public:	
	// Sets default values for this actor's properties
	APickupActor();

	UPROPERTY()
	FString collectionMessage;

protected:
	UPROPERTY(EditDefaultsOnly, Category = "Pickup")
	TObjectPtr<UStaticMeshComponent> MeshComponent;

	UPROPERTY(EditDefaultsOnly, Category = "Pickup")
	TObjectPtr<URotatingMovementComponent> RotatingMovementComponent;

	UPROPERTY(EditDefaultsOnly, Category = "Pickup")
	TObjectPtr<USphereComponent> ColliderComponent;
};