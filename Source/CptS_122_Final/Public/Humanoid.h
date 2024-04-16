#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Humanoid.generated.h"

UCLASS()
class CPTS_122_FINAL_API AHumanoid : public AActor
{
	GENERATED_BODY()

private:
	bool isEnemy;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Sets default values for this actor's properties
	AHumanoid();
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
