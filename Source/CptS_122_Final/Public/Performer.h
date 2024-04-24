#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Performer.generated.h"

UCLASS()
class CPTS_122_FINAL_API APerformer : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APerformer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	// Adds a property in the inspector, that we can edit
	UPROPERTY(EditAnywhere)
	class UCameraComponent* Camera;

	// Define movement functions
	void MoveForward(float InputValue);
	void MoveRight(float InputValue);

	void MouseHorizontal(float InputValue);
	void MouseVertical(float InputValue);
};