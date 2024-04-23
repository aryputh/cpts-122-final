#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Performer.generated.h"

UENUM(BlueprintType)
enum class EPlayerTreasureAction : uint8
{
	IncludeTreasure UMETA(Tooltip = "Add treasure to player's chest.")
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FTreasureChest, FString, TreasureString, EPlayerTreasureAction, TreasureAbility, bool, AllGood);

UCLASS()
class CPTS_122_FINAL_API APerformer : public ACharacter
{
	GENERATED_BODY()

	TArray<FString> treasureChest;

public:
	// Sets default values for this character's properties
	APerformer();

#pragma region Treasure

	UFUNCTION(BlueprintCallable, Category = "Player Treasure Chest")
	void IncludeTreasure(FString Treasure2Include);

	UPROPERTY(BlueprintAssignable, Category = "Player Treasure Chest ")
	FTreasureChest EnableTreasureChestAction;

#pragma endregion

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	UPROPERTY(EditAnywhere)
	class UCameraComponent* Camera;
	void MoveForward(float InputValue);
	void MoveRight(float InputValue);

	void MouseHorizontal(float InputValue);
	void MouseVertical(float InputValue);
};