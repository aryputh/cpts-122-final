#include "Performer.h"
#include "Camera/CameraComponent.h"

// Sets default values
APerformer::APerformer()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Player Camera"));
	Camera->SetupAttachment(RootComponent);
	Camera->bUsePawnControlRotation = true;
}

// Called when the game starts or when spawned
void APerformer::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void APerformer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void APerformer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAxis("MoveForward", this, &APerformer::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &APerformer::MoveRight);

	PlayerInputComponent->BindAxis("MouseHorizontal", this, &APerformer::MouseHorizontal);
	PlayerInputComponent->BindAxis("MouseVertical", this, &APerformer::MouseVertical);
}

void APerformer::MoveForward(float InputValue)
{
	FVector ForwardDirection = GetActorForwardVector();
	AddMovementInput(ForwardDirection, InputValue);
}

void APerformer::MoveRight(float InputValue)
{
	FVector RightDirection = GetActorRightVector();
	AddMovementInput(RightDirection, InputValue);
}

void APerformer::MouseHorizontal(float InputValue)
{
	AddControllerYawInput(InputValue);
}

void APerformer::MouseVertical(float InputValue)
{
	AddControllerPitchInput(InputValue);
}

void APerformer::IncludeTreasure(FString Treasure2Include)
{
	if (treasureChest.Contains(Treasure2Include))
	{
		EnableTreasureChestAction.Broadcast(Treasure2Include, EPlayerTreasureAction::IncludeTreasure, false);
	}
	else
	{
		treasureChest.Add(Treasure2Include);
		EnableTreasureChestAction.Broadcast(Treasure2Include, EPlayerTreasureAction::IncludeTreasure, true);
	}
}